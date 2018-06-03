//#include "stdAfx.h"
#include "WeightCenters.h"
#include "stdio.h"
#include "stdlib.h"
#include "highgui.h"
#include <cv.h>
#include <cxcore.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
using namespace cv;
using namespace std;

WeightCenters::WeightCenters(void)
{
	th=127;//初始阈值设置为250
	his=0.5;//直方图阈值设置为0.5
	MaxV = 250;//最大亮度值250
	Minr = 5.0;//最小半径值
	Maxr = 200.0;//最大半径值
	Divr = 100.f;//
	lowthred =200;
	highthred = 200;
	image=NULL;
	gray=NULL;
}
WeightCenters::~WeightCenters(void)
{
}
//画点
void WeightCenters::DrawPoint(IplImage*image,vector<CvPoint2D32f> allPoints)
{
	for(int i=0;i<allPoints.size();i++){	
		cvCircle(image,cvPoint((int)allPoints[i].x,allPoints[i].y),1,CV_RGB(0,255,0),10);
	}
}
//重心法，灰度化图像，再图像增强F：系统标定模块，亮点提取（输入，图像数据，点数组）
void WeightCenters::WeightCenterMethod(IplImage  *pic,vector<CvPoint2D32f> &allPoints){
	allPoints.clear();
	IplImage *gray=cvCreateImage(cvGetSize(pic),IPL_DEPTH_8U,1);
	cvZero(gray);
	//IplImage* dstGrayImage = cvCreateImage(cvGetSize(pic), IPL_DEPTH_8U, 1);
	//cvZero(dstGrayImage);
	//光斑标定，转化为灰度图
	cvCvtColor(pic,gray,CV_BGR2GRAY);
	
	//二极管提取
	//cvCopy(pic,gray);
	
	//cvShowImage("gray",gray);
	//ImageStretchByHistogram(gray,dstGrayImage);
	//cvShowImage("dstGrayImage",dstGrayImage); 

	int height=pic->height;
	int width=pic->width;
	int data;
	int LeftSum=0;
	int RightSum=0;
	float Avg;
	for(int i=0;i<height; i++)    //横坐标；F：纵坐标
	{
		LeftSum = 0;
		RightSum = 0;
		int tempthre=0;//临时阈值
		bool flag=true;int left=0;int right=0;

		for(int j=0;j<width; j++)	  //处理一张图片；
		{
			data=(uchar)gray->imageData[i*gray->widthStep+j];
			if(data>th)  //F：该点比阈值还要更亮
			{
				if(flag){
					left=j; //将j（横坐标值赋值给left）
					flag=false; 
				}
				LeftSum = LeftSum+data*(j+1);
				RightSum = RightSum+data;
				right=j;	//j赋值right ，left和right表示的什么?

			}				
		}
		//printf("%d  %d\n",down,up);
		flag=true;
		if(RightSum>0)//线条宽度不大于10个像素&&((right-left)<400)
		{
			Avg = (float)LeftSum/RightSum;	
			//show->imageData[(int)Avg*gray->widthStep+j]=255;
			allPoints.push_back(cvPoint2D32f(Avg,i));
		}
	} 
	//DrawPoint(pic,allPoints);
	cvReleaseImage(&gray);
	//cvReleaseImage(&dstGrayImage); //释放图像
}
//图像增强函数
int WeightCenters::ImageStretchByHistogram(IplImage *src,IplImage *dst)
{
	//p[]存放图像各个灰度级的出现概率；
	//p1[]存放各个灰度级之前的概率和，用于直方图变换；
	//num[]存放图象各个灰度级出现的次数;

	assert(src->width==dst->width);

	float p[256],p1[256],num[256];
	//清空三个数组
	memset(p,0,sizeof(p));
	memset(p1,0,sizeof(p1));
	memset(num,0,sizeof(num));

	int height=src->height;
	int width=src->width;
	long wMulh = height * width;

	//求存放图象各个灰度级出现的次数
	// to do use openmp
	for(int x=0;x<width;x++)
	{
		for(int y=0;y<height;y++)
		{
			uchar v=((uchar*)(src->imageData + src->widthStep*y))[x];
			num[v]++;
		}
	}

	//求存放图像各个灰度级的出现概率
	for(int i=0;i<256;i++)
	{
		p[i]=num[i]/wMulh;
	}

	//求存放各个灰度级之前的概率和
	for(int i=0;i<256;i++)
	{
		for(int k=0;k<=i;k++)
			p1[i]+=p[k];
	}

	//直方图变换
	// to do use openmp
	for(int x=0;x<width;x++)
	{
		for(int y=0;y<height;y++)
		{
			uchar v=((uchar*)(src->imageData + src->widthStep*y))[x];
			((uchar*)(dst->imageData + dst->widthStep*y))[x]= p1[v]*255+this->his;            
		}
	}

	return 0;

}
//----------------------------------------图像采集------------------------------------
void WeightCenters::setImage(IplImage *simg)   //将图像转换成单通道图，并保存；
{
	this->image = simg;
	centerx = image->width/2*1.f - 0.5f;
	centery = image->height/2*1.f - 0.5f;
	//zf = 531*image->width/640*1.f;
	if(gray!=NULL)
	{
		cvReleaseImage(&gray);
		if(cannyImage!=NULL)
		{
			cvReleaseImage(&cannyImage);		
		}
	}
	gray = cvCreateImage(cvGetSize(simg), 8, 1);
	cvCvtColor(simg, gray, CV_BGR2GRAY);
	cannyImage=cvCloneImage(gray);
	cvThreshold(cannyImage,cannyImage,50,255,CV_THRESH_BINARY);
	//cvShowImage("canny",cannyImage);
}
////直接从canny轮廓图中读取值；
void WeightCenters::FindSrcPoint(map<float,CvPoint2D32f> &sp)
{
	sp.clear();
	CvMemStorage *storage = cvCreateMemStorage(0);
	CvSeq *seq = cvCreateSeq(CV_SEQ_ELTYPE_POINT, sizeof(CvSeq),sizeof(CvPoint),storage);
	cvFindContours(cannyImage, storage, &seq, sizeof(CvContour), CV_RETR_EXTERNAL);
	//cvDrawContours(cannyImage,seq, CV_RGB(0,0,255),CV_RGB(255,0,0),2,2,8,cvPoint(0,0));
	//cvShowImage("showImage",cannyImage);
	for(; seq; seq = seq->h_next)
	{
		int count = seq->total;
		//轮廓转换为矩阵点；
		CvMat *points_f = cvCreateMat(1, count, CV_32FC2);
		cvCvtSeqToArray(seq, points_f->data.ptr, CV_WHOLE_SEQ);
		CvMat points_i = cvMat(1, count, CV_32SC2, points_f->data.ptr);
		cvConvert(&points_i, points_f);

		//最小逼近多边形求解
		double length = cvArcLength(points_f,CV_WHOLE_SEQ,0);  //最小逼近圆弧的长度；
		double area = cvContourArea(points_f);
		area = fabs(area);                                    //计算得到的面积；

		double compare = (length*length)/area;  //求解周长平方与面积的比值   约等于4*PI

		double ml = length*640/cannyImage->width;
		if(compare > Maxr || compare < Minr || ml<10 || ml>200)  //比值不在这个区间则视为当前轮廓不是圆形状
			continue;
		//比值初始化原始值；
		float R = (float)(2*area/length);//计算逼近的轮廓的半径；
		CvPoint2D32f centp;
		float radium;
		cvMinEnclosingCircle(points_f, &centp, &radium);

		if(radium < R+Divr*cannyImage->width/640 && radium > R)
		{
			if(IsCircleCenterPixel(cvPoint((int)centp.x, (int)centp.y)))
			{
				sp.insert(make_pair(centp.x, centp));
				//cvCircle(image,cvPoint((int)centp.x, (int)centp.y),1,CV_RGB(255,0,0),30);
			}
		}
		cvReleaseMat(&points_f);
	}
	cvReleaseMemStorage(&storage);
}
bool WeightCenters::IsCircleCenterPixel(const CvPoint &p)
{
	int D  = 255;
	D = (uchar)gray->imageData[p.y*gray->widthStep+p.x];
	if(D<this->MaxV)//if(D>this->MaxV)
		return true;
	else
		return false;
}
void WeightCenters::CannyContourDeal(){
	cvCanny(cannyImage, cannyImage, this->lowthred, this->highthred);
}
//将这些点分开，得到点；
bool WeightCenters::SortFourPoints(map<float, CvPoint2D32f> pointsmap,vector<CvPoint2D32f>&points){
	//计算这四个点之间的距离，距离较大的两个点为相对点
	points.clear();
	CvPoint2D32f tempPoint;
	map<float, CvPoint2D32f>::iterator it;
	//按照x的大小取出元素
	if(pointsmap.size()==4){//-------------
		int i=0;
		for(it=pointsmap.begin();it!=pointsmap.end();it++){
			tempPoint=it->second;
			points.push_back(tempPoint);
			cvCircle(image,cvPoint((int)tempPoint.x,(int)tempPoint.y),1,CV_RGB(255,i*60,0),30);
			i++;
		}
		cvCircle(image,cvPoint((int)image->width/2,(int)image->height/2),1,CV_RGB(0,0,255),30);
		return true;
	}
	else{
		//cout<<"The number of  points is not 4!"<<endl;
		return false;
	}
}
//找图中的标定点2d（系统标定模块）
bool WeightCenters::findPoints(IplImage*left,IplImage*right){
	//对背景板进行提取
	bool isfind=false;
	//左图
	setImage(left);
	CannyContourDeal();   //Canny运算；
	//cvShowImage("cannyLeft",cannyImage);
	FindSrcPoint(leftCenters2dmap);
	if(SortFourPoints(leftCenters2dmap,leftCenters2d)){
		isfind=true;
	}
	//右图
	setImage(right);
	CannyContourDeal();   //Canny运算；
	//cvShowImage("cannyRight",cannyImage);
	FindSrcPoint(rightCenters2dmap);

	if(SortFourPoints(rightCenters2dmap,rightCenters2d)){
		if(isfind){
			return true;
		}
		else{
			return false;
		}
	}else{
		return false;
	}
}
//找图像中最亮的光斑（输入左右图像数据）
void WeightCenters::findMaxPoints(IplImage*left,IplImage*right){
	IplImage* leftImage=cvCreateImage(cvSize(left->width,left->height),IPL_DEPTH_8U,1);
	//cvZero()；是让矩阵的值都为0，有初始化的作用，或者说清零
	cvZero(leftImage);
	//左图
	setImage(left);

	int D  = 255;
	//F遍历所有的像素点 灰度图像中0是黑，255是白
	for(int y=0;y<gray->height;y++){
		for(int x=0;x<gray->width;x++){
			D = (uchar)gray->imageData[y*gray->widthStep+x];
			//该点的像素值大于阈值
			if(D>this->MaxV){
				leftImage->imageData[y*leftImage->widthStep+x]=255;    //F设置灰度图片中该点的亮度为255（白色）
			}
		}
	}
	//cvShowImage("left",leftImage);
	cvReleaseImage(&leftImage);
	
	//右图,和左图的操作一样
	IplImage* rightImage=cvCreateImage(cvSize(left->width,left->height),IPL_DEPTH_8U,1);
	cvZero(rightImage);
	setImage(right);
	D  = 255;
	for(int y=0;y<gray->height;y++){
		for(int x=0;x<gray->width;x++){
			D = (uchar)gray->imageData[y*gray->widthStep+x];
			if(D>this->MaxV){
				rightImage->imageData[y*rightImage->widthStep+x]=255;
				//cvCircle(rightImage,cvPoint(x,y),1,CV_RGB(255,0,0),1);
			}
		}
	}
	//cvShowImage("right",rightImage);
	cvReleaseImage(&rightImage);
}