#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QTimer>  
#include <time.h> 
#include "ui_BinocularScanner.h"
#include "CameraCapture.h"
#include "Equations.h"
#include "AdeptThreshold.h"
#include "Calibration.h"
#include "Transforms.h"
#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include"GLMainWidget.h"
#include <QFileDialog>
using namespace std;
namespace Ui {
	class BinocularScannerClass;
}
class LaserScanner : public QMainWindow
{
	Q_OBJECT
private:

	/* constants */
	static const int OBJECT_THRESH = 100;
	static const int LASER_THRESH = 250;
	static const int MAX_WIDTH = 1280;
	static const int MAX_HEIGHT = 1024;
public:
	LaserScanner(QWidget *parent = Q_NULLPTR);
	void OnTimer();

protected:
	void OnInitialize();  //初始化
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent * event);
	void Correction(); //立体校正
	void createWindow(char* src, QWidget * picSize);  //显示cv::Mat的方法
	vector<CvPoint2D32f> getLaserCenter(Mat src,IplImage* transpic,int type);
	void view3d(vector<CvPoint3D32f> allPoints3d);
	void Handle(Mat picL, Mat picR);
	void StereoCalibration();
public slots:

	void OpenCamera();
	void Test();
	void StartScan();
	void SaveImage();
	void StartCalibrationL();
	void StartCalibrationR();
	void SwapLR();
	void ViewPoints();
	void LoadParameter();
private:
	Ui::BinocularScannerClass ui;
	void on_Mouse(int event, int x, int y);
	static void onMouse(int event, int x, int y, int, void* userdata);
	static const int HOUGH_THRESH = 70;			//100
	static const int HOUGH_PARAM1 = 1;			//700
	static const int HOUGH_PARAM2 = 600;		//600
	static const int CANNY_LOWTHRESH = 80;
	static const int CANNY_HIGHTHRESH = 160;
	int tempthre ; //阈值
	bool bConnected; //连接按钮标志
	bool isStartScan; //是否开始扫描
	bool isSwap; //是否左右交换
	bool isCorrection;//是否校正
	bool isLoadParameter; //是否加载参数
	bool chooseL; //标定左
	bool chooseR; //标定右
	bool isCalibratedL;
	bool isCalibratedR;
	GLMainWidget*glWidget;
	QTimer theTimer; //计时器
	CameraCapture*  leftCapture = new CameraCapture;
	CameraCapture*  rightCapture = new CameraCapture;
	Calibration  leftCalibration;
	Calibration  rightCalibration;
	Mat leftMat, rightMat;
	Mat dstL, dstR;
	IplImage *calImage;
	//伪彩色显示
	Mat rgbleftMat, rgbrightMat;
	IplImage * lplImg_left;  // opencv里的图片类型指针
	IplImage * lplImg_right;  // opencv里的图片类型指针
	IplImage * lplImg_disp;  // opencv里的图片类型指针
	Equations allEquation;
	Transforms *trans= new Transforms();     //图像处理
	AdeptThreshold adeptThreshold;//自适应阈值法提取光条中心
	vector<CvPoint2D32f> allPointsleft;//左图像所有激光中心点
	vector<CvPoint2D32f> allPointsright;//右图像所有激光中心点
	vector<CvPoint2D32f> allPointsleft2;//左图像所有激光中心点
	vector<CvPoint2D32f> allPointsright2;//右图像所有激光中心点
	vector<CvPoint2D32f> allPointsleft3;//左图像所有激光中心点
	vector<CvPoint2D32f> allPointsright3;//右图像所有激光中心点
	vector<CvPoint2D32f> matchPoints;
	vector<CvPoint3D32f> allPointsdisp;


	//写入文件
	fstream laserL;
	fstream laserR;
	fstream testClouds;
	fstream laserMatchDIS;
	fstream disp;
	double time_Start, time_End;
	int saveTimes ;
	int xyzMinZ, xyzMaxZ, xyzScale;
	char buffer_left[50];
	char buffer_right[50];
	Size imageSize = Size(MAX_WIDTH, MAX_HEIGHT);
	//Mat rgbImageL, grayImageL;
	//Mat rgbImageR, grayImageR;
	Mat rectifyImageL, rectifyImageR;
	Mat rgbRectifyImageL, rgbRectifyImageR;
	Rect validROIL;//图像校正之后，会对图像进行裁剪，这里的validROI就是指裁剪之后的区域  
	Rect validROIR;
	Mat mapLx, mapLy, mapRx, mapRy;     //映射表  
	Mat Rl, Rr, Pl, Pr, Q;              //校正旋转矩阵R，投影矩阵P 重投影矩阵Q
	Mat xyz;              //三维坐标
						  /*
						  事先标定好的相机的参数
						  fx 0 cx
						  0 fy cy
						  0 0  1
						  */
	Mat cameraMatrixL = (Mat_<double>(3, 3) << 
		1198.2               ,  0                  , 632.1480,
		0                        , 1194.5         , 487.8904,
		0                        , 0                  , 1                 );


	Mat cameraMatrixR = (Mat_<double>(3, 3) << 
		1196.2, 0                         , 649.8460,
		0                      , 1192.5   , 486.7133,
		0                      , 0                      , 1                  );
	Mat distCoeffL = (Mat_<double>(5, 1) << -0.1853, -0.1255, -0.0027, -0.0015, 0.7990);
	Mat distCoeffR = (Mat_<double>(5, 1) << -0.1731, -0.2295, -0.0012, -0.0018, 1.6306);

	Mat T = (Mat_<double>(3, 1) << -138.5611, -0.4780, 2.1508);//T平移向量
	Mat rec = (Mat_<double>(3, 1) << -0.01001,0.04790,-0.00219);//rec旋转向量
	Mat R = (Mat_<double>(3, 3) <<
		0.9998, 0.0015, 0.0216,
		-0.0017, 0.9999, 0.0100,
		-0.0216, -0.0100, 0.9997);
};
