#include "Plane.h"

Plane::Plane(void)
{

}

Plane::~Plane(void)
{

}

//平面点法式方程
Plane::Plane(double A, double B, double C, CvPoint3D64f point)
{
	this->A = A;
	this->B = B;
	this->C = C;
	this->point = point;
}

//平面一般式方程
Plane::Plane(double A, double B, double C, double D)
{
	this->AA = AA;
	this->BB = BB;
	this->CC = CC;
	this->DD = DD;
}

