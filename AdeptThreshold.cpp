//#include "stdafx.h"
#include "AdeptThreshold.h"
using namespace cv;
using namespace std;

AdeptThreshold::AdeptThreshold(void)
{
}
AdeptThreshold::~AdeptThreshold(void)
{
}
//画点
void AdeptThreshold::DrawPoint(IplImage*image,vector<CvPoint2D32f> allPoints)
{
	for(int i=0;i<allPoints.size();i++){	
		cvCircle(image,cvPoint((int)allPoints[i].x,allPoints[i].y),1,CV_RGB(0,255,0),1);
	}

}
IplImage* AdeptThreshold::ResizeImage(IplImage* img)  //   mymfc是我的项目名字 你自己换
{
	float scale = 1; //缩放比例  
	CvSize dst_cvsize;  
	dst_cvsize.width = img->width*scale; //目标图像宽度  
	dst_cvsize.height = img->height*scale; //目标图像高度  
	IplImage*pdst = cvCreateImage(dst_cvsize, img->depth, img->nChannels); //创建一个目标图像  
	cvResize(img, pdst, CV_INTER_LINEAR); //缩放 
	cvReleaseImage(&img);
	return pdst;
}
//计算每一列的自适应阈值(横向光条)   
int AdeptThreshold::adaptThreshold(IplImage* pic,int height,int j){
	int data=0;int maxdata=0;
	for(int i=0; i<height; i++)	  //处理一张图片；
	{
		data=(uchar)pic->imageData[i*pic->widthStep+j];
		//自适应阈值的产生
		if(data>maxdata){
			maxdata=data;
		}
	}
	//if(maxdata<150){
	//maxdata=220;
	//return -1;
	//}
	printf("maxdata=%d\n",maxdata);
	return maxdata-10;
}
//计算每一行的自适应阈值(纵向光条)
int AdeptThreshold::adaptThresholdVertical(IplImage* pic,int width,int j,int& maxDataPos){
	int data=0;int maxdata=0;
	for(int i=0; i<width; i++)	  //处理一张图片；
	{
		data=(uchar)pic->imageData[j*pic->widthStep+i];
		if (data>175) {
			maxdata = data;
			maxDataPos = i;
		}
		//自适应阈值的产生
		/*
		if(data>maxdata){
			maxdata=data;
			maxDataPos = i;
		}
		*/
	}
	//if(maxdata<150){
	//maxdata=220;
	//return -1;
	//}
	//printf("maxdata=%d\n",maxdata);
	return maxdata-50;
}
//去除假光条
vector<CvPoint2D32f> AdeptThreshold::NoiseRemove(IplImage* image,vector<CvPoint2D32f> allPoints,vector<CvPoint2D32f> allPoints2){
	vector<int> Mvalue;
	//画黑白图像
	IplImage *blackWhite=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,1);
	cvZero(blackWhite);
	for(int j=0;j<allPoints.size();j++){
		CvPoint2D32f point=allPoints[j];
		//for(int i=0;i<blackWhite->height;i++){
		blackWhite->imageData[(int)point.y*blackWhite->widthStep+(int)point.x]=255;
		//}
	}
	//cvShowImage("blackWhite",blackWhite);
	//模板计算
	int a,b,c,d,e,f;
	//边缘像素不进行滤波
	for(int j=1;j<blackWhite->width-1; j++) 
	{
		for(int i=1;i<blackWhite->height-1; i++)	  
		{

			a=(uchar)blackWhite->imageData[(i-1)*blackWhite->widthStep+j-1]/255;
			b=(uchar)blackWhite->imageData[(i-1)*blackWhite->widthStep+j]/255;
			c=(uchar)blackWhite->imageData[(i-1)*blackWhite->widthStep+j+1]/255;

			d=(uchar)blackWhite->imageData[(i+1)*blackWhite->widthStep+j-1]/255;
			e=(uchar)blackWhite->imageData[(i+1)*blackWhite->widthStep+j]/255;
			f=(uchar)blackWhite->imageData[(i+1)*blackWhite->widthStep+j+1]/255;

			int M=(a-1)*(a-1)+(b-1)*(b-1)+(c-1)*(c-1)+(d-1)*(d-1)+(e-1)*(e-1)+(f-1)*(f-1);
			//	Mvalue.push_back(M);
			if(M==4){//线条上的点
				//保留
				//printf("M=%d\n",M);
				//allPoints2.push_back(cvPoint2D32f(i,j));
			}else if(M==5){
				////printf("M=%d  ",M);
				//if(Mvalue.size()!=0){
				//	int m=Mvalue[Mvalue.size()-1];
				//	if(m==5){//噪声
				//		blackWhite->imageData[i*blackWhite->widthStep+j]=0;
				//		blackWhite->imageData[(i-1)*blackWhite->widthStep+j]=0;
				//	}else{//线段开头或者结尾

				//	}
				int M1=(a-1)*(a-1)+(b-1)*(b-1)+(c-1)*(c-1);
				int M2=(d-1)*(d-1)+(e-1)*(e-1)+(f-1)*(f-1);
				//printf("M1=%d\n",M1);
				if(M1==3){//线条起点
					//保留
					//allPoints2.push_back(cvPoint2D32f(i,j));
				}else if(M1==2){//噪声
					blackWhite->imageData[i*blackWhite->widthStep+j]=0;
					blackWhite->imageData[(i-1)*blackWhite->widthStep+j]=0;
				}
			}else if(M==6){
				//blackWhite->imageData[i*blackWhite->widthStep+j]=0;
				//allPoints2.push_back(cvPoint2D32f(i,j));
			}

		}
	} 
	for(int j=1;j<blackWhite->width-1; j++) 
	{
		for(int i=1;i<blackWhite->height-1; i++)	  
		{
			int data=(uchar)blackWhite->imageData[i*blackWhite->widthStep+j];
			if(data==255)
			{
				allPoints2.push_back(cvPoint2D32f(j,i));
			}
		}
	}
	//cvShowImage("blackWhite2",blackWhite);
	return allPoints2;
}

//自适应阈值法改进重心法(横向光条)
vector<CvPoint2D32f> AdeptThreshold::advancedAdeThreWeight(IplImage  *pic){
	IplImage *gray=cvCreateImage(cvGetSize(pic),IPL_DEPTH_8U,1);
	//cvSmooth(pic, pic, CV_MEDIAN,3);   // 7*7中值滤波 	
	vector<CvPoint2D32f> allPoints;
	cvZero(gray);

	//转化为灰度图
	cvCvtColor(pic,gray,CV_BGR2GRAY);
	int height=pic->height;
	int width=pic->width;
	int data;
	int UPSum=0;
	int DSum=0;
	float Avg;
	for(int j=0;j<width; j++)    //横坐标；
	{
		UPSum = 0;
		DSum = 0;
		int tempthre=0;//临时阈值
		bool flag=true;int up=0;int down=0;
		//自适应阈值的产生
		tempthre=adaptThreshold(gray,height,j);

		for(int i=0;i<height; i++)	  //处理一张图片；
		{
			data=(uchar)gray->imageData[i*gray->widthStep+j];
			if(data>tempthre)
			{
				if(flag){
					up=i;
					flag=false;
				}
				UPSum = UPSum+data*(i+1);
				DSum = DSum+data;
				down=i;	
			}				
		}
		//printf("%d  %d\n",down,up);
		flag=true;
		if((DSum>0)&&((down-up)<100))//线条宽度不大于10个像素
		{
			Avg = (float)UPSum/DSum;	
			//show->imageData[(int)Avg*gray->widthStep+j]=255;
			allPoints.push_back(cvPoint2D32f(j,Avg));
		}
	} 
	DrawPoint(pic,allPoints);
	cvShowImage("pic",pic); 
	cvReleaseImage(&gray);
	return allPoints;
}
//自适应阈值法改进重心法(纵向光条)
vector<CvPoint2D32f> AdeptThreshold::advancedAdeThreWeightVertical(IplImage  *pic){

	//IplImage *gray=cvCreateImage(cvGetSize(pic),IPL_DEPTH_8U,1);
	//cvSmooth(pic, pic, CV_MEDIAN,3);   // 7*7中值滤波 	
	vector<CvPoint2D32f> allPoints;
	//cvZero(gray);

	//转化为灰度图
	//cvCvtColor(pic,gray,CV_BGR2GRAY);
	int height=pic->height;
	int width=pic->width;
	int data;
	int UPSum=0;
	int DSum=0;
	float Avg;
	for(int i=100;i<height-100; i++)    //横坐标；
	{
		UPSum = 0;
		DSum = 0;
		int tempthre=0;//临时阈值
		int maxDataPos=0;
		bool flag=true;int up=0;int down=0;
		//自适应阈值的产生
		//tempthre=adaptThresholdVertical(pic,width,i, maxDataPos);

			for (int j = 200; j < width-200; j++)
			{
				data = (uchar)pic->imageData[i*pic->widthStep + j];
				if (data > 175)
				{
					if (flag) {
						up = j;
						flag = false;
					}
					UPSum = UPSum + data*(j + 1);
					DSum = DSum + data;
					down = j;
				}
			}
				Avg = (float)UPSum / DSum;
				if (up > 0) {
					allPoints.push_back(cvPoint2D32f(up, i));
				}

		
		/*
		for(int j=0;j<width; j++)	  //处理一张图片；
		{
			data=(uchar)pic->imageData[i*pic->widthStep+j];

			if(data>tempthre)
			{
				if(flag){

					up=j;
					flag=false;
				}
				UPSum = UPSum+data*(j+1);
				DSum = DSum+data;
				down=j;	
			}				
		}
		//printf("%d  %d\n",down,up);
		flag=true;
		if((DSum>0)&&((down-up)<30))//线条宽度不大于10个像素
		{
			//Avg = (int)UPSum/DSum;	
			//show->imageData[(int)Avg*gray->widthStep+j]=255;
			Avg = (float)UPSum / DSum;
			allPoints.push_back(cvPoint2D32f(Avg,i));
			//allPoints.push_back(cvPoint2D32f((float)UPSum / DSum,j));
		}
		*/
	} 
	
	//DrawPoint(pic,allPoints);
	//cvShowImage("pic",pic); 
	//cvReleaseImage(&gray);
	return allPoints;
}
// 图像差值
void AdeptThreshold::ImageInterpolation(IplImage* image, IplImage  *background,IplImage* imageInter)
{
	//IplImage  *image = cvLoadImage(imageName,1); 
	//IplImage  *background = cvLoadImage(backgroundName,1);
	if(image->imageSize!=background->imageSize){
		printf("输入图像有误\n");
		return;
	}
	//IplImage  *imageGray=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,1);
	//IplImage  *backgroundGray=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,1);
	//IplImage* imageInter=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);//差值图像
	//IplImage* imageCon=cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,3);//差值图像

	//cvCvtColor(image,imageGray,CV_BGR2GRAY);
	//cvCvtColor(background,backgroundGray,CV_BGR2GRAY);
	CvMat* imageMat = cvCreateMat(image->height, image->width, CV_32FC3);  
	CvMat* backgroundMat = cvCreateMat(image->height, image->width, CV_32FC3); 
	CvMat* imageInterMat = cvCreateMat(image->height, image->width, CV_32FC3);
	CvMat* imageConMat = cvCreateMat(image->height, image->width, CV_32FC3);
	cvConvert(image, imageMat);  
	cvConvert(background, backgroundMat);  
	cvAbsDiff( imageMat,backgroundMat,imageInterMat); 
	cvConvert(imageInterMat, imageInter);  
	////反色
	//int width=imageInter->width;
	//int height=imageInter->height;
	// int  data    = (uchar) imageInter->imageData; 
	// int step    = imageInter->widthStep;  
	//for (int  i=0;i<width;i++)  
	//{  
	//	for (int  j=0;j<height;j++)  
	//	{  
	//		for (int k=0;k<3;k++)  
	//		{  
	//			  imageInter->imageData[j*imageInter->widthStep+i*3+k]=255- imageInter->imageData[j*imageInter->widthStep+i*3+k];
	//		}  
	//	}  
	//}  

	//cvZero(imageInter);
	//int width=image->width;
	//int height=image->height;
	//int data1=0;int data2=0;int dataInter=0;
	//for(int i=0;i<width;i++){
	//	for(int j=0;j<height;j++){
	//			data1=(uchar)image->imageData[j*image->widthStep+i];
	//			data2=(uchar)background->imageData[j*background->widthStep+i];
	//			dataInter=abs(data1-data2);//取绝对值
	//			if(dataInter>50){
	//		       imageInter->imageData[j*imageInter->widthStep+i]=255;//dataInter;
	//			}
	//			data1=0;data2=0;dataInter=0;
	//
	//	}
	//}
	//cvShowImage("IMAGE",image);
	//cvShowImage("background",background);
	cvReleaseMat(&imageMat);
	cvReleaseMat(&backgroundMat);
	cvReleaseMat(&imageInterMat);
	cvReleaseMat(&imageConMat);
	//cvShowImage("inter",imageInter);
	//cvReleaseImage(&imageInter);
}
//自适应阈值法（输入为灰度图）
vector<CvPoint2D32f> AdeptThreshold::advancedAdeThreWeightGray(IplImage *pic,IplImage *gray)
{
	vector<CvPoint2D32f> allPoints;
	int height=pic->height;
	int width=pic->width;
	int data;
	int UPSum=0;
	int DSum=0;
	float Avg;
	for(int j=0;j<width; j++)    //横坐标；
	{
		UPSum = 0;
		DSum = 0;
		int tempthre=0;//临时阈值
		bool flag=true;int up=0;int down=0;
		//自适应阈值的产生
		tempthre=adaptThreshold(gray,height,j);
		for(int i=0;i<height; i++)	  //处理一张图片；
		{
			data=(uchar)gray->imageData[i*gray->widthStep+j];
			if(data>tempthre)//
			{
				if(flag){
					up=i;
					flag=false;
				}
				UPSum = UPSum+data*(i+1);
				DSum = DSum+data;
				down=i;	
			}				
		}
		//printf("%d  %d\n",down,up);
		flag=true;
		if((DSum>0)&&((down-up)<10))//线条宽度不大于10个像素
		{
			Avg = (float)UPSum/DSum;	
			//show->imageData[(int)Avg*gray->widthStep+j]=255;
			allPoints.push_back(cvPoint2D32f(j,Avg));
		}
	} 
	DrawPoint(pic,allPoints);
	cvShowImage("pic",pic); 
	return allPoints;
}
// 高亮度法
vector<CvPoint2D32f> AdeptThreshold::HighLight(IplImage  *pic)
{
	vector<CvPoint2D32f> allPoints;
	//IplImage  *pic = cvLoadImage(imagename,1); 
	IplImage  *picHSV = cvCreateImage(cvGetSize(pic),IPL_DEPTH_8U,3);
	IplImage  *hHSV = cvCreateImage(cvGetSize(pic),IPL_DEPTH_8U,1);
	IplImage  *sHSV = cvCreateImage(cvGetSize(pic),IPL_DEPTH_8U,1);
	IplImage  *vHSV = cvCreateImage(cvGetSize(pic),IPL_DEPTH_8U,1);
	cvSmooth(picHSV, picHSV, CV_MEDIAN,5); 
	cvCvtColor(pic,picHSV,CV_BGR2HSV);
	//cvShowImage("picHSV",picHSV);
	cvSplit(picHSV,hHSV,sHSV,vHSV,0);//123分别对应的事HSV通道
	cvShowImage("vHSV",vHSV);
	allPoints=advancedAdeThreWeightGray(pic,vHSV);
	return allPoints;
}
