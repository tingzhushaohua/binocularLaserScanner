#pragma once
//#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "highgui.h"
#include<map>
#include <cv.h>
#include <cxcore.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>
using namespace cv;
using namespace std;
class WeightCenters
{
public:
	WeightCenters(void);
	~WeightCenters(void);
	//画点
	void DrawPoint(IplImage*image,vector<CvPoint2D32f> allPoints);
	//重心法
	int th;//阈值
	float his;//直方图均衡化阈值
	//重心法，提取光条中心
	void WeightCenterMethod(IplImage  *pic,vector<CvPoint2D32f> &allPoints);
	//图像增强
	int ImageStretchByHistogram(IplImage *src,IplImage *dst);
	//提取标定点
	//canny算子的高阈值和低阈值
	int lowthred;
	int highthred; 
	
	IplImage *image;//保存源图像
	IplImage *gray;//转化为灰度图像
	IplImage *cannyImage;//canny图像F：希望在提高对景物边缘的敏感性的同时，可以抑制噪声的方法才是好的边缘提取方法。
	map<float,CvPoint2D32f> leftCenters2dmap;  //存储提取到的点；
	map<float,CvPoint2D32f> rightCenters2dmap;  //存储提取到的点；
	vector<CvPoint2D32f> leftCenters2d;//保存左图像中找的二维点
	vector<CvPoint2D32f> rightCenters2d;//保存右图像中找的二维点
	int MaxV;    // 确定中心点的像素值阈值；
	double Minr;  //判断比值的确定范围，最小值；
	double Maxr;  //判断比值的范围，最大值；
	float Divr;    //半径偏移值；
	float centerx;//中心坐标
	float centery;
	
	void setImage(IplImage *simg);   //将图像转换成单通道图，并保存；
	//通过搜索图像中具有圆形轮廓的提取方式，来获取图像的中心点
	//直接从canny轮廓图中读取值；
	void FindSrcPoint(map<float,CvPoint2D32f> &sp);
	//canny运算
	void CannyContourDeal();
	//判断所取点是否为黑点；
	bool IsCircleCenterPixel(const CvPoint &p);
	//将这些点分开，得到点；
	bool SortFourPoints(map<float, CvPoint2D32f> pointsmap,vector<CvPoint2D32f>&points);
	//找图中的标定点2d
	bool findPoints(IplImage*left,IplImage*right);
	//找最大的光斑
	void findMaxPoints(IplImage*left,IplImage*right);
};

