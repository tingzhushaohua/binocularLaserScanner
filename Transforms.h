#pragma once

#include <opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace cv;
using namespace std;
class Transforms
{
private:
	/* constants */
	static const int CANNY_LOWTHRESH = 80;
	static const int CANNY_HIGHTHRESH = 160;
	/* variables */
	\
public:
	
	Transforms();
	void doThreshold(Mat&src, Mat& dst, int tempthre);
	void doRemap(Mat&src, Mat& dst, Mat mapx, Mat mapy);
	void delete_jut(Mat& src, Mat& dst, int uthreshold, int vthreshold, int type);
	void imageblur(Mat& src, Mat& dst, Size size, int threshold);
	void setSrc(Mat src); //µº»Î‘¥ÕºœÒ
	void RemoveSmallRegion(Mat &Src, Mat &Dst, int AreaLimit, int CheckMode, int NeihborMode);
};
