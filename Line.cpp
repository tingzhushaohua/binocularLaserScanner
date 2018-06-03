//#include "stdafx.h"
#include "Line.h"
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;

Line::Line(void)
{
}
//全参构造
Line::Line(double A,double B,double C,CvPoint3D32f point){
	this->A=A;
	this->B=B;
	this->C=C;
	this->point=point;
}

Line::~Line(void)
{
}
