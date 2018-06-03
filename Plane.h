//平点法
#pragma once
//#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;
class Plane
{

private:
	//平面点法式方程A*(x-x0)+B*(y-y0)+C*(z-z0)=0;
	//法向量为n=(A,B,C)
	double A;
	double B;
	double C;
	CvPoint3D32f point;//(x0,y0,z0)
	//平面的一般式方程A*x+B*y+C*z+D=0;
	double AA;
	double BB;
	double CC;
	double DD;
public:
	//平面点法式方程
	Plane(double A,double B,double C,CvPoint3D32f point);
	//平面一般式方程
	Plane(double AA,double BB,double CC,double DD);
	Plane(void);
	~Plane(void);
	void setA(double A){
		this->A=A;
	}
	void setB(double B){
		this->B=B;
	}
	void setC(double C){
		this->C=C;
	}
	void setPoint(CvPoint3D32f point){
		this->point=point;
	}
	double getA(){
		return this->A;
	}
	double getB(){
		return this->B;
	}
	double getC(){
		return this->C;
	}
	CvPoint3D32f getPoint(){
		return this->point;
	}
	//一般式方程
	void setAA(double AA){
		this->AA=AA;
	}
	void setBB(double BB){
		this->BB=BB;
	}
	void setCC(double CC){
		this->CC=CC;
	}
	void setDD(double DD){
		this->DD=DD;
	}
	double getAA(){
		return this->AA;
	}
	double getBB(){
		return this->BB;
	}
	double getCC(){
		return this->CC;
	}
	double getDD(){
		return this->DD;
	}
};

