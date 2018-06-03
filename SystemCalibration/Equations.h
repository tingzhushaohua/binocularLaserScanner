#pragma once
#include "Line.h"
#include "Plane.h"

/*
	基本思路1：
	1.拍摄激光投射的标定图像；
	2.将需要确定线段的点转换到相机坐标系
	3.通过两点确定一条直线分别得到两错位线段的方程
	4.两错位线段所在直线方程求得激光平面
	5.多组激光平面相交求出激光器旋转轴线的方程
*/


/*
	基本思路2：找到这个平面的法向量。
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

class Equations
{
public:
	Equations();
	~Equations(void);

	//求平面一般式方程 
	Plane CreatePlaneEquationGeneral(double A, double B, double C, double D);

	//空间中的2点计算直线
	Line CreateLineEquation(CvPoint3D64f point1, CvPoint3D64f point2);
	//空间中的2线计算激光平面
	//Plane CreateLaserPlaneEquation(Line Line1, CvPoint3D32f Line2);	
	//2. 两个相交平面的交线
	Line CrossPlaneLine(Plane plane1, Plane plane2);

	//已知空间中的3个点计算法向
	Vec3f getPlaneNormal(CvPoint3D64f p1, CvPoint3D64f p2, CvPoint3D64f p3);
	//1. 已知空间中的3个点计算平面 point1,point2,point3 为输入的三个非共线的点； 
	Plane CreatePlaneEquation(CvPoint3D64f point1, CvPoint3D64f point2, CvPoint3D64f point3);
};