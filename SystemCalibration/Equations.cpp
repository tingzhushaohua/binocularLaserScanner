#include "Equations.h"


Equations::Equations()
{

}

Equations::~Equations(void)
{

}

Plane Equations::CreatePlaneEquationGeneral(double A, double B, double C, double D)
{
	Plane plane;
	plane.setAA(A);
	plane.setBB(B);
	plane.setCC(C);
	plane.setDD(D);
	return plane;
}

Line Equations::CreateLineEquation(CvPoint3D64f point1, CvPoint3D64f point2)
{
	Line line;
	line.setA(point1.x - point2.y);
	line.setB(point1.z - point2.z);
	line.setC(point1.z - point2.z);
	line.setPoint(point1);
	return line;
}

/*
找到这个平面的法向量。
设一条直线为直线a，另一条为b
步骤：
第一步、在直线a上取一点A，b上取一点B，得到向量AB
第二步、通过直线a（或者b）的方程得到a的方向向量，向量t
第三步、计算向量t与向量AB的叉乘，得到平面法向量n。
由A点（或B点）坐标和法向量n得到平面的点法式表达式。

点法式举例：
设A坐标 (x0,y0,z0)，法向量 n=(r,s,t)，
则 点法式为 r(x-x0)+s(y-y0)+t(z-z0)=0
*/
Plane CreateLaserPlaneEquation(Line Line1, CvPoint3D64f Line2)
{
	Plane plane;
	return plane;
}


Plane Equations::CreatePlaneEquation(CvPoint3D64f point1, CvPoint3D64f point2, CvPoint3D64f point3)
{
	Plane plane;
	double A, B, C;
	double sum;

	A = (point2.y - point1.y)*(point3.z - point1.z) - (point3.y - point1.y)*(point2.z - point1.z);
	B = (point2.z - point1.z)*(point3.x - point1.x) - (point3.z - point1.z)*(point2.x - point1.x);
	C = (point2.x - point1.x)*(point3.y - point1.y) - (point3.x - point1.x)*(point2.y - point1.y);

	//Vec3f normalLine = getPlaneNormal(point1, point2, point3);
	//A = normalLine[1];
	//B = normalLine[2];
	//C = normalLine[3];

	sum = A*A + B*B + C*C;
	sum = sqrtf(sum);

	plane.setA(A / sum);
	plane.setB(B / sum);
	plane.setC(C / sum);

	plane.setPoint(point2);
	return plane;
}

Line Equations::CrossPlaneLine(Plane plane1, Plane plane2)
{
	Line line;
	CvPoint3D64f point;
	double A1, A2, B1, B2, C1, C2, D1, D2, x1, x2, y1, y2, z1, z2;
	A1 = plane1.getA();
	A2 = plane2.getA();
	B1 = plane1.getB();
	B2 = plane2.getB();
	C1 = plane1.getC();
	C2 = plane2.getC();
	x1 = plane1.getPoint().x;  //两个点带入点斜式
	x2 = plane2.getPoint().x;
	y1 = plane1.getPoint().y;
	y2 = plane2.getPoint().y;
	z1 = plane1.getPoint().z;
	z2 = plane2.getPoint().z;

	double  M = A1*x1 + B1*y1 + C1*z1 - A1;
	double  N = A2*x2 + B2*y2 + C2*z2 - A2;
	
	point.x = 1;
	point.z = (B2*M - B1*N) / (B2*C1 - B1*C2);
	point.y = (M - C1*point.z) / B1;

	line.setA(B1*C2 - B2*C1);  //叉乘求得相交直线的法向
	line.setB(A1*C2 - A2*C1);
	line.setC(A1*B2 - A2*B1);
	line.setPoint(point);

	return line;
}

Vec3f Equations::getPlaneNormal(CvPoint3D64f p1, CvPoint3D64f p2, CvPoint3D64f p3)
{
	double A, B, C;
	A = ((p2.y - p1.y)*(p3.z - p1.z) - (p2.z - p1.z)*(p3.y - p1.y));
	B = ((p2.z - p1.z)*(p3.x - p1.x) - (p2.x - p1.x)*(p3.z - p1.z));
	C = ((p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x));

	return Vec3f(A, B, C);
}
