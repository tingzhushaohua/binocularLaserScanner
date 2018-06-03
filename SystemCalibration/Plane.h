#pragma once

#include <iostream>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

class Plane
{
public:
	Plane(void);
	~Plane(void);
	//平面点法式方程
	Plane(double A, double B, double C, CvPoint3D64f point);
	//平面一般式方程
	Plane(double A, double B, double C, double D);

	void setA(double A)
	{
		this->A = A;
	}
	void setB(double B)
	{
		this->B = B;
	}
	void setC(double C)
	{
		this->C = C;
	}
	void setPoint(CvPoint3D64f point)
	{
		this->point = point;
	}
	CvPoint3D64f getPoint()
	{
		return this->point;
	}
	double getC()
	{
		return this->C;
	}
	double getB()
	{
		return this->B;
	}
	double getA()
	{
		return this->A;
	}

	void setAA(double AA)
	{
		this->AA = AA;
	}
	void setBB(double BB)
	{
		this->BB = BB;
	}
	void setCC(double CC)
	{
		this->CC = CC;
	}
	void setDD(double DD)
	{
		this->DD = DD;
	}
	double getAA()
	{
		return this->AA;
	}
	double getBB()
	{
		return this->BB;
	}
	double getCC()
	{
		return this->CC;
	}
	double getDD()
	{
		return this->DD;
	}
private:
	//平面点法式方程 A*(x - x0) + B* (y- y0) +C*(z - z0) = 0,法向量为n = (A,B,C)
	double A;
	double B;
	double C;
	CvPoint3D64f point;
	//平面一般式方程 A*x + B*Y +C*z +D = 0;
	double AA;
	double BB;
	double CC;
	double DD;
};
