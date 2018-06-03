
#include "Equations.h"
//#define width 640
//#define height 480
using namespace cv;
using namespace std;

Equations::Equations()
{	
	this->leftcenter.x=0;
	this->leftcenter.y=0;
	this->leftcenter.z=0;
	RotationMat=cvCreateMat(3,3,CV_64FC1);
	TransationMat=cvCreateMat(3,1,CV_64FC1);
	this->M=0;
	this->f=0;
}

Equations::~Equations(void)
{
	fst.close();
	cvReleaseMat(&RotationMat);
	cvReleaseMat(&TransationMat);
}
//空间中的2点计算直线
Line Equations::CreatLineEquation(CvPoint3D32f point1, CvPoint3D32f point2)
{
	Line line;
	line.setA(point1.x-point2.x);
	line.setB(point1.y-point2.y);
	line.setC(point1.z-point2.z);
	line.setPoint(point1);
	return line;
}
//空间中的3点计算平面
Plane Equations::CreatePlaneEquation(CvPoint3D32f point1,CvPoint3D32f point2,CvPoint3D32f point3){
	Plane plane;
	CvPoint3D32f m1,m2;
	//point1 - point2;
	m1.x= (point1.x-point2.x);
	m1.y= (point1.y-point2.y);
	m1.z= (point1.z-point2.z);
	//point2 - point3;
	m2.x= (point1.x-point3.x);
	m2.y= (point1.y-point3.y);
	m2.z= (point1.z-point3.z);

	float A,B,C;
	float sum;

	A = m1.y*m2.z-m2.y*m1.z;
	B = -(m1.x*m2.z-m2.x*m1.z);  ////////////////////
	C = m1.x*m2.y-m2.x*m1.y;

	sum = A*A + B*B + C*C;
	sum = sqrtf(sum);

	plane.setA (A/sum) ;
	plane.setB (B/sum) ;
	plane.setC(C/sum) ;

	plane.setPoint(point2) ;
	return plane;
}
// 求平面一般式方程
Plane CreatePlaneEquationGeneral(double A,double B,double C,double D){
	Plane plane;
	plane.setAA(A);
	plane.setBB(B);
	plane.setCC(C);
	plane.setDD(D);
	return plane;
}
//两个相交平面的交线
Line Equations::CrossPlaneLine(Plane plane1,Plane plane2)
{
	Line line;
	CvPoint3D32f point;
	float A1,A2,B1,B2,C1,C2,D1,D2,x1,x2,y1,y2,z1,z2;
	A1=plane1.getA();
	A2=plane2.getA();
	B1=plane1.getB();
	B2=plane2.getB();
	C1=plane1.getC();
	C2=plane2.getC();
	x1=plane1.getPoint().x;
	x2=plane2.getPoint().x;
	y1=plane1.getPoint().y;
	y2=plane2.getPoint().y;
	z1=plane1.getPoint().z;
	z2=plane2.getPoint().z;

	double  M=A1*x1+B1*y1+C1*z1-A1;
	double  N=A2*x2+B2*y2+C2*z2-A2;
	//D1=-(A1*plane1.getPoint().x+B1*plane1.getPoint().y+C1*plane1.getPoint().z);
	//D2=-(A2*plane2.getPoint().x+B2*plane2.getPoint().y+C1*plane2.getPoint().z);

	point.x=1;
	//point.y=C1*D2-C2*D1+A2*C1-A1*C2;
	//point.y=point.y/(B1*C2-B2*C1);
	//point.z=B1*D2-B2*D1+A2*B1-A1*B2;
	//point.z=point.z/(B2*C1-B1*C2);
	point.z=(B2*M-B1*N)/(B2*C1-B1*C2);
	point.y=(M-C1*point.z)/B1;

	line.setA(B1*C2-B2*C1);
	line.setB(A1*C2-A2*C1);
	line.setC(A1*B2-A2*B1);
	line.setPoint(point);

	return line;
}
//两条相交线交点；
CvPoint3D32f Equations::CrossLinePoint(Line line1,Line line2)
{
	CvPoint3D32f point;
	float A0,B0,C0,x0,y0,z0;
	float A1,B1,C1,x1,y1,z1;
	float t0,t1;

	A0=line1.getA();
	B0=line1.getB();
	C0=line1.getC();
	x0=line1.getPoint().x;
	y0=line1.getPoint().y;
	z0=line1.getPoint().z;

	A1=line2.getA();
	B1=line2.getB();
	C1=line2.getC();
	x1=line2.getPoint().x;
	y1=line2.getPoint().y;
	z1=line2.getPoint().z;

	if(fabs(A1*B0-A0*B1)>0&&fabs(A0*B1-A1*B0)>0)
	{
		t1=(x0*B0-A0*y0+A0*y1-B0*x1)/(A1*B0-A0*B1);
		t0=(x1*B1-A1*y1+A1*y0-B1*x0)/(A0*B1-A1*B0);

		point.x=t0*A0+x0;
		point.y=t0*B0+y0;
		point.z=t0*C0+z0;
	}
	else
	{
		point.x=0;
		point.y=0;
		point.z=0;
	}
	/*double down=A0*B1-B0*A1+B0*T[0];
	double t=B1*T[0]/down;
	if(down!=0){
	point.x=t*A0;
	point.y=t*B0;
	point.z=t*C0;
	}else{
	point.x=0;
	point.y=0;
	point.z=0;
	}*/
	return point;

}
//线面相交求交点
CvPoint3D32f Equations::PlaneAndLine(Plane plane,Line line)
{
	CvPoint3D32f point;
	double A,B,C,LA,LB,LC,t;
	double x0,y0,z0,x1,y1,z1;
	A=plane.getA();
	B=plane.getB();
	C=plane.getC();
	LA=line.getA();
	LB=line.getB();
	LC=line.getC();
	x0=plane.getPoint().x;
	y0=plane.getPoint().y;
	z0=plane.getPoint().z;
	x1=line.getPoint().x;
	y1=line.getPoint().y;
	z1=line.getPoint().z;

	t=A*(x0-x1)+B*(x0-x1)+C*(x0-x1);
	t=t/(A*LA+B*LB+C*LC);

	point.x=t*LA+x1;
	point.y=t*LB+y1;
	point.z=t*LC+z1;

	return point;
}
//计算三维点到原点的距离；
double Equations::Point3D_O(CvPoint3D32f point)
{
	double temp;
	temp=point.x*point.x+point.y*point.y+point.z*point.z;
	temp=sqrtf(temp);
	return temp;
}
//求空间中两个点之间的距离；
float Equations::Point3D_Point3D(CvPoint3D32f point1,CvPoint3D32f point2)
{
	float tempx;
	float tempy;
	float tempz;
	float sum;
	tempx=point1.x-point2.x;
	tempy=point1.y-point2.y;
	tempz=point1.z-point2.z;
	sum=tempx*tempx+tempy*tempy+tempz*tempz;
	sum=sqrtf(sum);
	return sum;
}
//直线间最小距离
CvPoint3D32f  Equations::MinLineDis(Line line1, Line line2)
{
	float A1,A2,B1,B2,C1,C2;
	CvPoint3D32f point1,point2,N,temp;
	double disN,disline1,disline2;
	double x1,x2,y1,y2,z1,z2;
	double yl1,yl2,x,y,z;
	A1=line1.getA();
	A2=line2.getA();
	B1=line1.getB();
	B2=line2.getB();
	C1=line1.getC();
	C2=line2.getC();
	//归一化
	disline1=sqrt(A1*A1+B1*B1+C1*C1);
	disline2=sqrt(A2*A2+B2*B2+C2*C2);
	A1=(double)A1/disline1;
	B1=(double)B1/disline1;
	C1=(double)C1/disline1;
	A2=(double)A2/disline2;
	B2=(double)B2/disline2;
	C2=(double)C2/disline2;
	point1=line1.getPoint();
	x1=point1.x;
	y1=point1.y;
	z1=point1.z;
	point2=line2.getPoint();
	x2=point2.x;
	y2=point2.y;
	z2=point2.z;

	N.x=B1*C2-B2*C1;
	N.y=A1*C2-A2*C1;
	N.z=A1*B2-A2*B1;

	Line  verticalLine;
	disN=sqrt(N.x*N.x+N.y*N.y+N.z*N.z);
	verticalLine.setA(N.x/disN);
	verticalLine.setB(N.y/disN);
	verticalLine.setC(N.z/disN);

	//point1->point2
	temp.x=point2.x-point1.x;
	temp.y=point2.y-point1.y;
	temp.z=point2.z-point1.z;
	//dis=abs(temp.x*N.x+temp.y*N.y+temp.z*N.z)/disN;
	//x，z相等的时候，y的值
	float t=A2*z1-A2*z2+C2*x2-C2*x1;
	t=t/(A1*C2-A2*C1);
	x=A1*t+x1;
	yl1=B1*t+y1;
	z=C1*t+z1;
	yl2=(double)(B2*x-B2*x2+A2*y2)/A2;
	y=(double)(yl1+yl2)/2;
	////求两条直线的公垂线
	//CvPoint3D32f NL1,NL2;//两条直线与公垂线形成的平面
	//Plane plane1,plane2;
	//double disNL1,disNL2,disLine;//
	//
	//NL1.x=B1*N.z-N.y*C1;
	//NL1.y=A1*N.z-N.x*C1;
	//NL1.z=A1*N.y-N.x*B1;
	//disNL1=sqrt(NL1.x*NL1.x+NL1.y*NL1.y+NL1.z*NL1.z);
	//plane1.setA(NL1.x/disNL1);
	//plane1.setB(NL1.y/disNL1);
	//plane1.setC(NL1.z/disNL1);
	//plane1.setPoint(point1);

	//NL2.x=B2*N.z-N.y*C2;
	//NL2.y=A2*N.z-N.x*C2;
	//NL2.z=A2*N.y-N.x*B2;
	//disNL2=sqrt(NL2.x*NL2.x+NL2.y*NL2.y+NL2.z*NL2.z);
	//plane2.setA(NL2.x/disNL2);
	//plane2.setB(NL2.y/disNL2);
	//plane2.setC(NL2.z/disNL2);
	//plane2.setPoint(point2);

	//Line line=CrossPlaneLine(plane1,plane2);
	//disLine=sqrt(line.getA()*line.getA()+line.getB()*line.getB()+line.getC()*line.getC());
	//line.setA(line.getA()/disLine);
	//line.setB(line.getB()/disLine);
	//line.setC(line.getC()/disLine);
	//CvPoint3D32f pointLine1=CrossLinePoint(line1,line);
	//CvPoint3D32f pointLine2=CrossLinePoint(line2,line);

	CvPoint3D32f cen;
	cen.x=x;
	cen.y=y;
	cen.z=z;
	return cen;
}
//公垂线中点
CvPoint3D32f Equations::CalCrossLine(Line line1, Line line2){
	CvPoint3D32f p1;//设为line1上的点
	CvPoint3D32f p2;//设为line2上的点
	CvPoint3D32f p;//公垂线中点

	float A,B,C,A0,B0,C0,x,y,z;//待求公垂线的法向量
	float A1,B1,C1,x1,y1,z1;
	float A2,B2,C2,x2,y2,z2;
	float T,t0,t;

	double disN,disline1,disline2;

	//变量初始化
	A1=line1.getA();
	B1=line1.getB();
	C1=line1.getC();

	x1=line1.getPoint().x;
	y1=line1.getPoint().y;
	z1=line1.getPoint().z;

	A2=line2.getA();
	B2=line2.getB();
	C2=line2.getC();

	x2=line2.getPoint().x;
	y2=line2.getPoint().y;
	z2=line2.getPoint().z;

	//归一化
	disline1=sqrt(A1*A1+B1*B1+C1*C1);
	disline2=sqrt(A2*A2+B2*B2+C2*C2);
	A1=A1/disline1;
	B1=B1/disline1;
	C1=C1/disline1;
	A2=A2/disline2;
	B2=B2/disline2;
	C2=C2/disline2;
	//差乘求向量
	//A=(B1*C2-B2*C1);
	//B=(A1*C2-A2*C1);
	//C=(A1*B2-A2*B1);

	//求T值

	A0=(B1*C2-B2*C1);
	B0=(A1*C2-A2*C1);
	C0=(A1*B2-A2*B1);
	T=-A1*A2*z2*A2*B1+A1*A2*z2*A1*B2+A1*A2*z1*A2*B1-A1*A2*z1*A1*B2+A2*B1*A1*C2*x2-A1*C2*x2*A1*B2-A2*C1*x1*A2*B1+A1*B2*A2*C1*x1
		+A2*B1*x1*A2*C1-A2*B1*x1*C2*A1-A1*B2*x2*A2*C1+A1*B2*x2*A1*C2+A1*A2*y2*A2*C1-A1*A2*y2*A1*C2-A1*A2*y1*A2*C1+A1*A2*y1*A1*C2;
	t0=A1*A2*C0*A2*B1-A1*A2*C0*A1*B2-A2*B1*A0*A2*C1+A1*B2*A2*C1*A2*A0-A1*A2*B0*A2*C1+A1*A2*B0*A1*C2+A2*B1*A0*A2*C1-A2*B1*A0*A1*C2;
	t=T/t0;
	A=t*A0;
	B=t*B0;
	C=t*C0;

	disN=sqrt(A*A+B*B+C*C);
	A=A/disN;
	B=B/disN;
	C=C/disN;
	if((A2*B1-A1*B2!=0)&&(A1!=0)&&(A2!=0)){
		p2.x=(A2*B1*x1-A1*B2*x2+A1*A2*B+A1*A2*y2-A1*A2*y1)/(A2*B1-A1*B2);

		p1.x=p2.x+A;
		p1.y=((B1*p1.x-B1*x1)/A1)+y1;
		p1.z=((C1*p1.x-C1*x1)/A1)+z1;
		p2.y=((B2*p2.x-B2*x2)/A2)+y2;
		p2.z=((C2*p2.x-C2*x2)/A2)+z2;

		p.x=(p1.x+p2.x)/2;
		p.y=(p1.y+p2.y)/2;
		p.z=(p1.z+p2.z)/2;
	}
	return p;
}
//公垂线中点方法2
CvPoint3D32f Equations::CalCrossLine2(Line line1, Line line2){
	float a,b,c,d,e,f,det,invdet,epsilon;
	epsilon=10e-3;
	CvPoint3D32f u,q,q1,q2,p1,p2;
	float distance;
	p1=line1.getPoint();
	p2=line2.getPoint();
	u.x=p1.x-p2.x;
	u.y=p1.y-p2.y;
	u.z=p1.z-p2.z;
	a=line1.A*line1.A+line1.B*line1.B+line1.C*line1.C;
	b=line1.A*line2.A+line1.B*line2.B+line1.C*line2.C;
	c=line2.A*line2.A+line2.B*line2.B+line2.C*line2.C;
	d=line1.A*u.x+line1.B*u.y+line1.C*u.z;
	e=line2.A*u.x+line2.B*u.y+line2.C*u.z;
	f=u.x*u.x+u.y*u.y+u.z*u.z;
	det=a*c-b*b;
	float s,t;
	if(det<epsilon){
		s=0;
		if(b>c){
			t=d/b;
		}else{
			t=e/c;
		}
		distance= d*s+f;
	}else{
		invdet=1/det;
		s=(b*e-c*d)*invdet;
		t=(a*e-b*d)*invdet;
		distance=s*(a*s+b*t+2*d)+t*(b*s+c*t+2*e)+f;
	}
	q1.x=p1.x+s*line1.getA();
	q1.y=p1.y+s*line1.getB();
	q1.z=p1.z+s*line1.getC();
	q2.x=p2.x+s*line2.getA();
	q2.y=p2.y+s*line2.getB();
	q2.z=p2.z+s*line2.getC();
	q.x=-(q1.x+q2.x)/2;
	q.y=(q1.y+q2.y)/2;
	q.z=(q1.z+q2.z)/2;
	return q;
}
//计算右图像平面方程
Plane Equations::CalRightPicEquation(){
	//F:得到系统标定得到的旋转平移矩阵
//	backgroundEquation.getRTMatrix(this->R,this->T);
	for(int i = 0; i <3; i++)
	{
		for(int j=0;j<3;j++){
			cvmSet(RotationMat,i,j,R[i][j]);//
		}
		cvmSet(TransationMat,i,0,T[i]);
	}
	double RightPicCenter[3]={0,0,f};//右图的图像中心 右图的平面法向量
	double RightPicCenterT[3]={0};//转化到左摄像机的右图的图像中心
	double pointRightCenter[3]={0};//右摄像机的坐标原点
	double pointRightCenterT[3]={0};//转化到左摄像机的右摄像机坐标原点
	double NRightArr[3]={0,0,f};//右图法向量，相对于右图中心
	double NRightArrT[3]={0};//右图法向量相对于左图，相对于右图中心
	CvMat *RotationMatINV=cvCreateMat(3,3,CV_64FC1);//R的逆矩阵
	CvMat *RightPicCenterMat=cvCreateMat(3,1,CV_64FC1);
	CvMat *pointRightCenterMat=cvCreateMat(3,1,CV_64FC1);
	CvMat *NRightMat=cvCreateMat(3,1,CV_64FC1);
	Plane rightPlane;
	//A=R逆*(B-T)
	cvInvert(RotationMat,RotationMatINV);//A矩阵的逆
	for(int i=0;i<3;i++){
		RightPicCenter[i]=RightPicCenter[i]-T[i];//法向量不参与平移
		pointRightCenter[i]=pointRightCenter[i]-T[i];
		cvmSet(RightPicCenterMat,i,0,RightPicCenter[i]);
		cvmSet(pointRightCenterMat,i,0,pointRightCenter[i]);
		cvmSet(NRightMat,i,0,NRightArr[i]);
	}
	cvMatMul(RotationMatINV,RightPicCenterMat,RightPicCenterMat);
	cvMatMul(RotationMatINV,pointRightCenterMat,pointRightCenterMat);
	cvMatMul(RotationMatINV,NRightMat,NRightMat);
	for(int i=0;i<3;i++){
		RightPicCenterT[i]=cvmGet(RightPicCenterMat,i,0);//图像中点
		pointRightCenterT[i]=cvmGet(pointRightCenterMat,i,0);//右摄像机的原点相对于左摄像机的坐标
		NRightArrT[i]=cvmGet(NRightMat,i,0);//法向量
	}	
	CvPoint3D32f point;
	point.x=RightPicCenterT[0];
	point.y=RightPicCenterT[1];
	point.z=RightPicCenterT[2];
	double sum=NRightArrT[0]+NRightArrT[1]+NRightArrT[2];
	rightPlane.setA((double)NRightArrT[0]/sum);
	rightPlane.setB((double)NRightArrT[1]/sum);
	rightPlane.setC((double)NRightArrT[2]/sum);
	rightPlane.setPoint(point);

	this->rightcenter.x=pointRightCenterT[0];
	this->rightcenter.y=pointRightCenterT[1];
	this->rightcenter.z=pointRightCenterT[2];

	cvReleaseMat(&RotationMatINV);
	cvReleaseMat(&RightPicCenterMat);
	cvReleaseMat(&pointRightCenterMat);
	cvReleaseMat(&NRightMat);
	return rightPlane;
}
//计算右图中对应的像点坐标
void Equations::CalculateRightPoint(Plane rightPlane)
{
	matchPoints.clear();
	allPoints3d.clear();

	CvPoint2D32f leftPoint;
	CvPoint3D32f leftPoint3dT;//通过变换后的左点
	CvPoint3D32f leftPoint3d;

	double leftPointArr[3]={0};
	for(int i=0;i<allPointsleft.size();i++){
		leftPoint=allPointsleft[i];
		leftPoint3d.x=leftPoint.x-(double)width/2;
		leftPoint3d.y=(double)height/2-leftPoint.y;
		leftPoint3d.z=f;
		//if(leftPoint3d.y<240-abs(T[1])){
		//计算过图像上一点平面方程
		Plane picPlane=CreatePlaneEquation(this->leftcenter,this->rightcenter,leftPoint3d);
		//cout<<"picPlane:"<<picPlane.getA()<<","<<picPlane.getB()<<","<<picPlane.getC()<<endl;
		//cout<<"picPlanePoint:"<<picPlane.getPoint().x<<","<<picPlane.getPoint().y<<","<<picPlane.getPoint().z<<endl;
		//计算方程与右平面的相交线
		Line crossLine=CrossPlaneLine(picPlane,rightPlane);
		//cout<<"crossLine:"<<crossLine.getA()<<","<<crossLine.getB()<<","<<crossLine.getC()<<endl;
		//cout<<"crossLinePoint:"<<crossLine.getPoint().x<<","<<crossLine.getPoint().y<<","<<crossLine.getPoint().z<<endl;
		CvPoint3D32f crossPoint=crossLine.getPoint();
		//方向向量v(v1,v2,v3)
		double v1=crossLine.getA();
		double v2=crossLine.getB();
		double v3=crossLine.getC();
		double m1=crossPoint.x;
		double m2=crossPoint.y;
		double m3=crossPoint.z;

		//遍历右图中心线
		CvPoint2D32f pointRight;
		CvPoint3D32f pointRight3D;
		CvPoint2D32f tempRightPoint;
		CvPoint3D32f tempRightPoint3d;
		double mindis=10000;
		double temp=0;

		double AX,AY,AZ,D,t,qx,qy,qz;
		for(int j=0;j<allPointsright.size();j++){
			pointRight=allPointsright[j];
			pointRight3D.x=pointRight.x-(double)width/2;
			pointRight3D.y=(double)height/2-pointRight.y;
			pointRight3D.z=f;
			//(pointRight3D.x<(leftPoint3d.x+100+abs(T[0])))&&(pointRight3D.x>(leftPoint3d.x-100-abs(T[0])))&&
			if((pointRight3D.y<(leftPoint3d.y+10))&&(pointRight3D.y>(leftPoint3d.y-10))){
				pointRight3D=RightAxisToLeft(pointRight3D);//abs(T[1])abs(T[1])	
				AX=pointRight3D.x;
				AY=pointRight3D.y;
				AZ=pointRight3D.z;
				D=AX*v1+AY*v2+AZ*v3;
				t=((m1*v1+m2*v2+m3*v3)-D)/(v1*v1+v2*v2+v3*v3);
				qx=m1+t*v1;
				qy=m2+t*v2;
				qz=m3+t*v3;
				temp=sqrt((AX-qx)*(AX-qx)+(AY-qy)*(AY-qy)+(AZ-qz)*(AZ-qz));
				if(mindis>abs(temp)){
					mindis=abs(temp);
					tempRightPoint.x=pointRight.x;
					tempRightPoint.y=pointRight.y;
					tempRightPoint3d.x=AX;
					tempRightPoint3d.y=AY;
					tempRightPoint3d.z=AZ;
				}
			}
		}
		//计算三维点
		//左摄像机中心到左摄像机激光点的直线
		Line leftLine=CreatLineEquation(leftPoint3d,leftcenter);
		//cout<<"leftLine:"<<leftLine.getA()<<","<<leftLine.getB()<<","<<leftLine.getC()<<endl;
		//cout<<"leftLine.getPoint:"<<leftLine.getPoint().x<<","<<leftLine.getPoint().y<<","<<leftLine.getPoint().z<<endl;
		//右摄像机中心到右图像匹配点的直线
		Line rightLine=CreatLineEquation(tempRightPoint3d,rightcenter);
		//cout<<"rightLine:"<<rightLine.getA()<<","<<rightLine.getB()<<","<<rightLine.getC()<<endl;
		//cout<<"rightLine.Point:"<<rightLine.getPoint().x<<","<<rightLine.getPoint().y<<","<<rightLine.getPoint().z<<endl;
		CvPoint3D32f point3d=MinLineDis(leftLine,rightLine);
		matchPoints.push_back(tempRightPoint);
		allPoints3d.push_back(point3d);
		mindis=10000;
		//}	
	}
}
// 图像上二维点转三维点
void Equations::Point2DTo3D(CvPoint2D32f point,double f,CvPoint3D32f &point3d)
{
	point3d.x=point.x;
	point3d.y=point.y;
	point3d.z=(float)f;
}
//右坐标系下的点转到左坐标系下
CvPoint3D32f Equations::RightAxisToLeft(CvPoint3D32f point)
{
	for(int i = 0; i <3; i++)
	{
		for(int j=0;j<3;j++){
			cvmSet(RotationMat,i,j,R[i][j]);//
		}
		cvmSet(TransationMat,i,0,T[i]);
	}
	CvPoint3D32f pointT;
	CvMat *pointMat=cvCreateMat(3,1,CV_64FC1);
	CvMat *RotationMatINV=cvCreateMat(3,3,CV_64FC1);//R的逆矩阵
	double pointArr[3]={point.x,point.y,point.z};
	//A=R逆*(B-T)
	cvInvert(RotationMat,RotationMatINV);//A矩阵的逆
	for(int i=0;i<3;i++){
		pointArr[i]=pointArr[i]-T[i];
		cvmSet(pointMat,i,0,pointArr[i]);
	}
	cvMatMul(RotationMatINV,pointMat,pointMat);
	pointT.x=cvmGet(pointMat,0,0);
	pointT.y=cvmGet(pointMat,1,0);
	pointT.z=cvmGet(pointMat,2,0);
	cvReleaseMat(&RotationMatINV);
	cvReleaseMat(&pointMat);
	return pointT;
}
//右坐标系下的点转到左坐标系下
CvPoint3D32f Equations::LeftAxisToRight(CvPoint3D32f point){
	CvPoint3D32f temp;
	double leftPointArr[3]={0};
	leftPointArr[0]=point.x;
	leftPointArr[1]=point.y;
	leftPointArr[2]=point.z;
	for(int i = 0;i < 3;i++)
	{
		double ab = 0;
		for(int j = 0;j < 3;j++)
		{
			ab+= R[i][j]*leftPointArr[j];
		}
		ab += T[i] ;
		leftPointArr[i]=ab;
	}
	temp.x=leftPointArr[0];
	temp.y=leftPointArr[1];
	temp.z=leftPointArr[2];
	return temp;
}
void Equations::SimpleFileWrite(int ne,int fa,double scale)
{
	for(int i=0; i<allPoints3d.size(); i++){

		if((allPoints3d[i].z<fa)&&(allPoints3d[i].z>ne)){
			fst<<(float)allPoints3d[i].x/scale<<" "<<(float)allPoints3d[i].y/scale<<" "<<(float)allPoints3d[i].z/scale<<endl;  
		}
	}		
}
//Y值对应法求匹配点
void Equations::CalRightPointY()
{
	allPoints3d.clear();
	matchPoints.clear();
	CvPoint2D32f leftPoint;
	CvPoint2D32f rightPoint;
	CvPoint3D32f leftPoint3d;
	CvPoint3D32f rightPoint3d;

	for(int i=0;i<allPointsleft.size();i++){
		leftPoint=allPointsleft[i];
		leftPoint3d.x=leftPoint.x-320;
		leftPoint3d.y=240-leftPoint.y;
		leftPoint3d.z=f;
		//左摄像机中心到做摄像机激光点的直线
		Line leftLine=CreatLineEquation(leftPoint3d,leftcenter);
		for(int j=0;j<allPointsright.size();j++){
			rightPoint=allPointsright[j];
			if(rightPoint.y==leftPoint.y){
				rightPoint3d.x=rightPoint.x-320+600;
				rightPoint3d.y=240-rightPoint.y;
				rightPoint3d.z=f;

				rightcenter.x=600;
				rightcenter.y=0;
				rightcenter.z=0;
				//右摄像机中心到右图像匹配点的直线距离
				Line rightLine=CreatLineEquation(rightPoint3d,rightcenter);
				CvPoint3D32f point3d=CalCrossLine2(leftLine,rightLine);//CrossLinePoint(leftLine,rightLine);//MinLineDis(leftLine,rightLine);//
				allPoints3d.push_back(point3d);
				matchPoints.push_back(rightPoint);
			}
		}
	}
}
//Y值对应法求匹配点
void Equations::CalRightPointDifY(int dif)
{
	allPoints3d.clear();
	matchPoints.clear();
	CvPoint2D32f leftPoint;
	CvPoint2D32f rightPoint;
	CvPoint3D32f leftPoint3d;
	CvPoint3D32f rightPoint3d;
	for(int i=0;i<allPointsleft.size();i++){
		leftPoint=allPointsleft[i];
		leftPoint3d.x= leftPoint.x - width/2;
		leftPoint3d.y= height/2 - leftPoint.y;
		leftPoint3d.z=f;
		Line leftLine=CreatLineEquation(leftPoint3d,leftcenter);
		for (int j = 0; j < allPointsright.size(); j++) {
			rightPoint = allPointsright[j];
			if (rightPoint.y == leftPoint.y)
			{
				//转换到左摄像机坐标系上
				rightPoint3d.x = rightPoint.x - width/2+ abs(M);
				rightPoint3d.y = height/2- rightPoint.y ;
				rightPoint3d.z = f;
				//右光心转换到左坐标系
				rightcenter.x = abs(M);
				rightcenter.y = 0;
				rightcenter.z = 0;
				Line rightLine = CreatLineEquation(rightPoint3d, rightcenter);
				//求两条直线的公垂线中心
				CvPoint3D32f point3d = CalCrossLine2(leftLine, rightLine);
				matchPoints.push_back(rightPoint);
				allPoints3d.push_back(point3d);
			}
		}
	}
}
void Equations::CalRightPointDifY2(int dif)
{
	allPoints3d.clear();
	matchPoints.clear();
	CvPoint2D32f leftPoint;
	CvPoint2D32f rightPoint;
	CvPoint3D32f leftPoint3d;
	CvPoint3D32f rightPoint3d;
	//F:图像坐标转摄像机坐标
	for (int i = 0; i<allPointsleft.size(); i++) {
		leftPoint = allPointsleft[i];
		leftPoint3d.x = leftPoint.x - 640;
		leftPoint3d.y =512- leftPoint.y;
		leftPoint3d.z = f;
		//左摄像机中心到做摄像机激光点的直线(F:leftcenter=(0,0,0);)
		Line leftLine = CreatLineEquation(leftPoint3d, leftcenter);
		//遍历右光条中心点
		for (int j = 0; j<allPointsright.size(); j++) {
			rightPoint = allPointsright[j];
			//若该右光点与左光点的差值为y方向的偏移值dif
			if (rightPoint.y + dif == leftPoint.y) {
				//转换到左摄像机坐标系上
				rightPoint3d.x = rightPoint.x - 640+ abs(M);
				rightPoint3d.y = 512 - rightPoint.y - dif;
				rightPoint3d.z = f;
				//右光心转换到左坐标系
				rightcenter.x = abs(M);
				rightcenter.y = -dif;
				rightcenter.z = 0;
				//右摄像机中心到右图像匹配点的直线距离
				Line rightLine = CreatLineEquation(rightPoint3d, rightcenter);
				//求两条直线的公垂线中心
				CvPoint3D32f point3d = CalCrossLine2(leftLine, rightLine);//MinLineDis(leftLine,rightLine);//CrossLinePoint(leftLine,rightLine);//
				allPoints3d.push_back(point3d);
				matchPoints.push_back(rightPoint);
			}
		}
	}
}
//旋转平移矩阵求匹配点
void Equations::CalRightPoint()
{
	allPoints3d.clear();
	matchPoints.clear();

	CvPoint2D32f leftPoint;
	CvPoint2D32f rightPoint;
	CvPoint3D32f leftPoint3d;
	CvPoint3D32f rightPoint3d;

	for(int i=0;i<allPointsleft.size();i++){
		leftPoint=allPointsleft[i];
		leftPoint3d.x=leftPoint.x-320;
		leftPoint3d.y=240-leftPoint.y;
		leftPoint3d.z=f;
		//左摄像机中心到做摄像机激光点的直线
		Line leftLine=CreatLineEquation(leftPoint3d,leftcenter);
		for(int j=0;j<allPointsright.size();j++){
			rightPoint=allPointsright[j];
			if(rightPoint.y+(int)T[1]==leftPoint.y){//
				rightPoint3d.x=rightPoint.x-320+abs(T[0]);
				rightPoint3d.y=240-rightPoint.y-(int)T[1];
				rightPoint3d.z=f+T[2];

				rightcenter.x=abs(T[0]);
				rightcenter.y=-(int)T[1];
				rightcenter.z=T[2];
				//右摄像机中心到右图像匹配点的直线距离
				Line rightLine=CreatLineEquation(rightPoint3d,rightcenter);
				CvPoint3D32f point3d=CalCrossLine(leftLine,rightLine);//MinLineDis(leftLine,rightLine);////CrossLinePoint(leftLine,rightLine);////
				allPoints3d.push_back(point3d);
				matchPoints.push_back(rightPoint);
			}
		}
	}
}
//两点求三维点,输入为两个对应点，及对应摄像机的焦距，输出为三维点
CvPoint3D32f Equations::Cal3DpointsBy2Points(CvPoint2D32f point1,CvPoint2D32f point2,float f1,float f2){
	allPoints3d.clear();
	matchPoints.clear();
	CvPoint3D32f leftPoint3d;
	CvPoint3D32f rightPoint3d;
	float dif=point1.y-point2.y;
	//CvPoint3D32f point3d;
	leftPoint3d.x=point1.x-320;
	leftPoint3d.y=240-point1.y;
	leftPoint3d.z=f1;
	rightcenter.x=abs(M);
	rightcenter.y=-dif;
	rightcenter.z=0;
	rightPoint3d.x=point2.x-320;
	rightPoint3d.y=240-point2.y-dif;//;
	rightPoint3d.z=f2;
	//左摄像机中心到做摄像机激光点的直线
	Line leftLine=CreatLineEquation(leftPoint3d,leftcenter);
	//右摄像机中心到右图像匹配点的直线距离
	Line rightLine=CreatLineEquation(rightPoint3d,rightcenter);
	CvPoint3D32f point3d=CrossLinePoint(leftLine,rightLine);//MinLineDis(leftLine,rightLine);//
	allPoints3d.push_back(point3d);
	//matchPoints.push_back(point2);
	return point3d;
}
void Equations::XIANGSHIPoint()
{
	allPoints3d.clear();
	matchPoints.clear();
	float pp = 0;
	CvPoint2D32f leftPoint;
	CvPoint2D32f rightPoint;
	CvPoint2D32f match;
	for (int i = 0; i<allPointsleft.size(); i++) {
		leftPoint = allPointsleft[i];
		for (int j = 0; j<allPointsright.size(); j++) {
			rightPoint = allPointsright[j];
			if (rightPoint.y == leftPoint.y) {
				CvPoint3D32f point3d;

				pp = rightPoint.x - leftPoint.x;
				
				point3d.z = f+M*f / pp;
				point3d.x = (point3d.z-f)*(width / 2 - leftPoint.x) / f;
				point3d.y = -(point3d.z-f)*(height / 2 - leftPoint.y) / f;
				allPoints3d.push_back(point3d);
				match.x = pp;
				match.y = rightPoint.y;
				matchPoints.push_back(rightPoint);
//				disp.at<float>(leftPoint.y, leftPoint.x) = abs(pp);
			}
		}
	}
}
void Equations::XIANGSHIPoint2()
{

	matchPoints.clear();

	CvPoint2D32f leftPoint;
	CvPoint2D32f rightPoint;
	CvPoint2D32f match;
	for (int i = 0; i<allPointsleft.size(); i++) {
		leftPoint = allPointsleft[i];
		for (int j = 0; j<allPointsright.size(); j++) {
			rightPoint = allPointsright[j];
			if (rightPoint.y == leftPoint.y) {
				match.x = rightPoint.x - leftPoint.x;
				match.y = rightPoint.y;
				matchPoints.push_back(match);
			}
		}
	}
}

void Equations::InitMat()
{
	disp = Mat(1024, 1280, CV_32F);
	for (int i = 0; i<disp.rows; i++)
		for (int j = 0; j<disp.cols; j++)
			disp.at<float>(i, j) = 0;
}