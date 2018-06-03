#ifndef SYSTEMCALIBRATION_H
#define SYSTEMCALIBRATION_H
# pragma warning (disable:4819)

#include <QtWidgets/QMainWindow>
#include <iostream>
#include "qstring.h"
#include "qvector.h"
#include "qimage.h"

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\calib3d.hpp>
#include "cvut.h"
#include "ui_systemcalibration.h"

#include"Equations.h"

using namespace std;
using namespace cv;
using namespace cvut;

class SystemCalibration : public QMainWindow
{
	Q_OBJECT

public:
	SystemCalibration(QWidget *parent = 0);
	~SystemCalibration();

	void	 OnBnClickedButtonNext();
	void	 OnBnClickedButtonPre();
	void	 OpenCalibrationPicture();
	void	 BeginCalibration();
	void	 BeginCalibration2();
	void	 BeginSystemCalib();
	void	 BackToHome();
	void	 GetFeaturePoint();
	void	 GetEquationCoeff1();
	void	 GetEquationCoeff2();

	void completeAndEvaluateAndSave(int & chessRow, int& chessColumn);
	
	void loadAndShowImage           (int index, const QString &cfileFullName);												  //加载显示图片
	void readChessboardPara         (float& cellHeight, float &cellWidth, int &chessRow, int &chessColumn);
	
	bool connerDetection			(CvSize& image_size, const CvSize&board_size, cvut::Seq<CvPoint2D32f>& image_points_seq);  //角点检测
	void cameraCalibration			(CvSize& image_size, const CvSize& board_size,											   //相机标定
									 cvut::Seq<CvPoint2D32f>& image_points_seq, Matrix<double>& intrinsic_matrix,
									 Matrix<double>& distortion_coeffs,        Matrix<double>& rotation_vectors,
									 Matrix<double>& translation_vectors,      Matrix<int>& point_counts,
									 Matrix<double>& image_points,     Matrix<double>& object_points);
	void evaluateCalibResult        (Matrix<int>& point_counts,        Matrix<double>& objects_points,
									 Matrix<double>& rotation_vectors, Matrix<double>& translation_vectors,
									 Matrix<double>& intrinsic_matrix, Matrix<double>& distortion_coeffs,
									 Matrix<double>& image_points);															//评价标定结果
	void saveCalibrationResult	    (Matrix<double>& rotation_vectors, Matrix<double>& translation_vectors, 
									 Matrix<double>& intrinsic_matrix, Matrix<double>& distortion_coeffs);
	void saveCalibrationResult2		(Matrix<double>& rotation_vectors, Matrix<double>& translation_vectors,
									 Matrix<double>& intrinsic_matrix, Matrix<double>& distortion_coeffs);
	void showInternalAndDistortion  (Matrix<double>& intrinsic_matrix, Matrix<double>& distortion_coeffs,
								     QLabel* distortionLabelShow,      QLabel*internalLabelShow);						    //显示结果
	void showRotationAndTranslation (Matrix<double>& intrinsic_matrix, Matrix<double>& distortion_coeffs,
								     QLabel* translationLabelShow, QLabel*rotationLabelShow);

	vector<CvPoint2D32f>	advancedThreWeight(IplImage *imageView);
	int  adaptThreshold		(IplImage *pic, int width, int j);
	void drawPoint			(IplImage* image, vector<CvPoint2D32f> allpoints);
	//void greyCenter(IplImage* image, vector<CvPoint2D32f>& allPoints);
	void getLaserPlane		(Plane& plane);
	void getLaserFitPlane	(Plane& plane);
	void showLine			(Line &line);
	void showLine2			(Line &line);
	void cvFitPlane			(const CvMat* points, double *plane);

	QImage cIplImgToQImg(IplImage* cvimage);			 //IplImage转QImage
	void   testShow33   (Matrix<double>& steroR, Matrix<double>& steroT, QLabel* translationLabelShow, QLabel*rotationLabelShow);
	void   testShow31   (Matrix<double>& steroR, Matrix<double>& steroT, QLabel* translationLabelShow, QLabel*rotationLabelShow);
private:
	Ui::SystemCalibrationClass ui;

	CvSize      image_size;           //图像大小
	QStringList filePathList;		  //文件路径列表
	QStringList cornerFilePathList;   //角点路径列表
	QStringList imageNameList;        //所有图像名字
	string cornerDir;			      //角点保存目录
	int    imageNum;				  //加载图片数量
	int    picIndex;	              //当前显示的是第几个图像
	bool   isCorner;                    //当前显示的图像是否为角点图像
	bool   isBeginCalibration2;
	bool   isBeginCalibration;          //是否开始标定相机1
	bool   isBeginSystemCalib;          //是否系统标定
	bool   isClibrationCamer1;          //相机1标定成功
	bool   isClibrationCamer2;          //相机2标定成功

	float  cellHeight;
	float  cellWidth;
	int    chessRow;
	int    chessColumn;

	Matrix<double> *intrinsic_matrix2 ;			  //摄像机内参数矩阵
	Matrix<double> *intrinsic_matrix ; 

	vector<CvPoint2D32f> allFeaturePoints;
	Equations eqations;   
	int featurePointNum = 1;					 //特征点个数
	int  isPlaneOk = 0;
	int  isPlaneOk1 = 0;
	bool flag1 = true;
	bool flag2 = true;

	stringstream ss;
	vector<string> vecErr;
	string data = "";
};


#endif // SYSTEMCALIBRATION_H
