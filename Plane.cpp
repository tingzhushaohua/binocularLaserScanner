//#include "stdafx.h"
#include "Plane.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;
//点法式方程的构造
Plane::Plane(double A,double B,double C,CvPoint3D32f point)
{
	this->A=A;
	this->B=B;
	this->C=C;
	this->point=point;
}
//一般式方程的构造
Plane::Plane(double AA,double BB,double CC,double DD)
{
	this->AA=AA;
	this->BB=BB;
	this->CC=CC;
	this->DD=DD;
}
Plane::Plane(void){

}

Plane::~Plane(void)
{
}
