//线结构光光条中心提取，自适应阈值法
#pragma once
//#include "stdafx.h"
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
class AdeptThreshold
{
public:
	AdeptThreshold(void);
	~AdeptThreshold(void);
	//画点
	void DrawPoint(IplImage*image,vector<CvPoint2D32f> allPoints);
	//尺寸调整
	IplImage* ResizeImage(IplImage* img); 
	//计算每一行的自适应阈值   
	int adaptThreshold(IplImage* pic,int height,int j);
	int AdeptThreshold::adaptThresholdVertical(IplImage* pic,int width,int j, int& maxDataPos);
	//去除假光条
	vector<CvPoint2D32f> NoiseRemove(IplImage* image,vector<CvPoint2D32f> allPoints,vector<CvPoint2D32f> allPoints2);
	//自适应阈值法改进重心法
	vector<CvPoint2D32f> advancedAdeThreWeight(IplImage  *pic);//横向
	vector<CvPoint2D32f> AdeptThreshold::advancedAdeThreWeightVertical(IplImage  *pic);//纵向
	// 图像差值
	void ImageInterpolation(IplImage* image, IplImage  *background,IplImage* imageInter);
	// 高亮度法
	vector<CvPoint2D32f> HighLight(IplImage  *pic);
	//自适应阈值法（输入为灰度图）
	vector<CvPoint2D32f> AdeptThreshold::advancedAdeThreWeightGray(IplImage *pic,IplImage *gray);
};

