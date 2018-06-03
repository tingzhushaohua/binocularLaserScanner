//公式类
#pragma once
//#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include<fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Plane.h"
#include "Line.h"
//#include "BackgroudEquations.h"
using namespace cv;
using namespace std;

class Equations
{
public:
	Equations();//int width,int height,double f,double M
	~Equations(void);
	int width;//图片宽度
	int height;//图片长度
	//double M;//
	//标定结果
	CvPoint3D32f leftcenter;
	CvPoint3D32f rightcenter;

	
	//存储图像提取的二维点坐标
	vector<CvPoint2D32f> allPointsleft;//左图所有激光点	
	vector<CvPoint2D32f> allPointsright;//右图所有激光点
	vector<CvPoint2D32f> matchPoints;//右图中的匹配点
	//vector<CvPoint2D32f> allCalRightPoints;//存储计算得到的右图对应点坐标
	//CvPoint2D32f *allCalRightPoints;

	//存储光条的的三维点坐标
	vector<CvPoint3D32f> allPoints3d;
	//double Tx;
	//double cx;
	//double cy;
	//BackgroudEquations backgroundEquation;//提取背景板计算结果
	double R[3][3];
	double T[3];
	float f;    //焦距(像素)
	float fL;    //焦距(像素)左
	float fR;    //焦距(像素)右
	float M;   //Tx(mm)
	float dx, dy; //分别代表x,y轴方向一个像素的宽度(mm/像素)
	CvMat *RotationMat;//旋转矩阵
	CvMat *TransationMat;//平移矩阵

	// 根据实际空间中的3个点  计算平面 point1,point2,point3 为输入的三个非共线的点； 
	Plane CreatePlaneEquation(CvPoint3D32f point1,CvPoint3D32f point2,CvPoint3D32f point3);
	//求平面一般式方程 
	Plane CreatePlaneEquationGeneral(double A,double B,double C,double D);
	//空间中的2点计算直线
	Line CreatLineEquation(CvPoint3D32f point1, CvPoint3D32f point2);
	//两个相交平面的交线
	Line CrossPlaneLine(Plane plane1,Plane plane2);
	//两条相交线交点；
	CvPoint3D32f CrossLinePoint(Line line1,Line line2);
	//线面相交求交点
	CvPoint3D32f Equations::PlaneAndLine(Plane plane,Line line);
	//计算三维点到原点的距离；
	double Equations::Point3D_O(CvPoint3D32f point);
	//计算右图中的点 使用allLeftPoints计算allCalRightPoints
	void CalculateRightPoint(Plane rightPlane);//CvPoint3D32f leftPoint,CvPoint3D32f &rightPoint
	//计算右图像平面方程
	Plane CalRightPicEquation();
	// 图像上二维点转三维点
	void Point2DTo3D(CvPoint2D32f point,double f,CvPoint3D32f &point3d);
	//求空间中两个点之间的距离；
	float Point3D_Point3D(CvPoint3D32f point1,CvPoint3D32f point2);
	//右坐标系下的点转到左坐标系下
	CvPoint3D32f RightAxisToLeft(CvPoint3D32f point);
	//左坐标系下的点转到右坐标系下
	CvPoint3D32f Equations::LeftAxisToRight(CvPoint3D32f point);
	// 用匹配点计算点三维坐标
	void CalRightPointDifY2(int dif);
	void XIANGSHIPoint2();
	void Cal3dPoints();
	//写入文件
	fstream fst;
	void SimpleFileWrite(int ne,int fa,double scale);
	//相同y值计算右点
	void CalRightPointY(void);
	//直线间最小距离
	CvPoint3D32f MinLineDis(Line line1, Line line2);
	//公垂线
	CvPoint3D32f CalCrossLine(Line line1, Line line2);
	CvPoint3D32f CalCrossLine2(Line line1, Line line2);
	//Y值差值求匹配点
	void CalRightPointDifY(int dif);
	//旋转平移矩阵求匹配点
	void CalRightPoint();
	//两点求三维点,输入为两个对应点，及对应摄像机的焦距，输出为三维点
	CvPoint3D32f Cal3DpointsBy2Points(CvPoint2D32f point1,CvPoint2D32f point2,float f1,float f2);
	void XIANGSHIPoint();
	Mat disp; //视差图
	void InitMat();
};


