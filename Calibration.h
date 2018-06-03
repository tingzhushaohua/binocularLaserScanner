#pragma once
//#include "stdafx.h"    
//用于特制6点标定板
#include <opencv2/opencv.hpp>    
#include <highgui.hpp>    
#include "cv.h"    
#include <cv.hpp>    
#include <iostream>    
using namespace std;
using namespace cv;
class Calibration
{
private:
	int times;
	double H; //标定板物理距离
	CvMat *M;

	Mat T;
	Mat R;
	vector<CvPoint2D32f> points;  //用以储存标定所需的坐标

public:
	double fx;
	double fy;
	double tz;
	double tx;
	double ty;
	double u;
	double v;
	 Calibration(void);
	 ~Calibration(void);
	 void cal_M();
	 void setTimes(int num) { times = num; };
	 int getTimes() { return times; };
	 vector<CvPoint2D32f> getPoints() { return points; };
	 Mat getT() { return T; };
	 Mat getR() { return R; };
	 void grabPoint() { times++; };
	 void putPoint(double x, double y);
};