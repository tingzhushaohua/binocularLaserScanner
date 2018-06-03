#include "Line.h"

Line::Line(void)
{

}

Line::Line(double A, double B, double C, CvPoint3D64f point)
{
	this->A = A;
	this->B = B;
	this->C = C;
	this->point = point;
}

Line::~Line(void)
{

}