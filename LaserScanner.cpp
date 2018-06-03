#include "LaserScanner.h"
#include <math.h>

LaserScanner::LaserScanner(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	OnInitialize();
	connect(ui.btn_openCam, &QPushButton::clicked, this, &LaserScanner::OpenCamera);
	//connect(ui.btn_capture, &QPushButton::clicked, this, &LaserScanner::Test);

	connect(ui.btn_loadParameter, &QPushButton::clicked, this, &LaserScanner::LoadParameter);
	connect(ui.btn_scan, &QPushButton::clicked, this, &LaserScanner::StartScan);
	connect(ui.btnSaveImage, &QPushButton::clicked, this, &LaserScanner::SaveImage);
	connect(ui.btn_calibrationL, &QPushButton::clicked, this, &LaserScanner::StartCalibrationL);
	connect(ui.btn_calibrationR, &QPushButton::clicked, this, &LaserScanner::StartCalibrationR);
	connect(ui.btn_swapRL, &QPushButton::clicked, this, &LaserScanner::SwapLR);
	connect(ui.btn_correction, &QPushButton::clicked, this, &LaserScanner::Correction);
    connect(ui.btn_showCloud, &QPushButton::clicked, this, &LaserScanner::ViewPoints);
	// 滑动条连接信号槽（相互改变）
	connect(ui.spinBox_light, SIGNAL(valueChanged(int)), ui.lightSlider, SLOT(setValue(int)));
	connect(ui.lightSlider, SIGNAL(valueChanged(int)), ui.spinBox_light, SLOT(setValue(int)));
	connect(&theTimer, &QTimer::timeout, this, &LaserScanner::OnTimer);

}
void LaserScanner::OnInitialize()
{

	//获取校正参数
	isSwap = 0;
	isStartScan = 0;
	bConnected = 0;
	isCorrection = 0;
	isLoadParameter = 0;
	saveTimes = 0;
	isCalibratedL = 0;
	isCalibratedR = 0;
	chooseL = 0;
	chooseR = 0;
	allEquation.width = MAX_WIDTH;
	allEquation.height = MAX_HEIGHT;
	tempthre = 100; //阈值
	xyzMinZ = 0;
	xyzMaxZ = 10000;
	xyzScale = 1;
	leftCapture->getIndex(0);
	rightCapture->getIndex(1);
	if (leftCapture->OnInitialize() && rightCapture->OnInitialize())
	{
		//若//leftCapture捕获到右摄像机的MAC地址，校正//leftCapture与rightCapture的id
		if (strcmp(leftCapture->lInfo.DevMAC, "00-11-1C-F1-47-81") == 0)
		{
			leftCapture->getIndex(1);
			rightCapture->getIndex(0);
			//重新初始化
			leftCapture->OnInitialize();
			rightCapture->OnInitialize();
		}
		//获取窗口句柄
		leftCapture->m_Hwnd = (HWND)ui.videoBox_left->winId();
		rightCapture->m_Hwnd = (HWND)ui.videoBox_right->winId();
		/////////
		allEquation.fL = (float)1199;
		allEquation.fR = (float)1186;
		allEquation.f = (float)1195;
		allEquation.M = (float)138.84;
		allEquation.dx = (float)0.0053;
		allEquation.dy = (float)0.0053;
		ui.infoEdit->append(u8"===设备" + QString::number(0) + "===\nIP:" + leftCapture->lInfo.DevIP + " \nMAC:" + leftCapture->lInfo.DevMAC);
		ui.infoEdit->append(u8"===设备" + QString::number(1) + "===\nIP:" + rightCapture->lInfo.DevIP + " \nMAC:" + rightCapture->lInfo.DevMAC);
		ui.infoEdit->append(u8"请点击‘启动设备-连接摄像机’以打开摄像机\n");
	}
	else
	{
		ui.infoEdit->append(u8"未检查到任何设备!");
	}
}
void LaserScanner::LoadParameter()
{
	isLoadParameter = true;
	ui.infoEdit->append(u8"读取参数成功!\n");
}
void LaserScanner::SwapLR()
{
	if (isSwap)
	{
		isSwap = false;
	}
	else {
		isSwap = true;
	}
	ui.infoEdit->append(u8"左右设备交换成功!\n");
}

void LaserScanner::Test()
{
	//测试
	allEquation.f = (float)1195;
	allEquation.M = (float)138.5611;
	allEquation.width = 1280;
	allEquation.height = 1024;
	sprintf(buffer_left, "ImageData\\Left%d.jpg",7);
	sprintf(buffer_right, "ImageData2\\Right%d.jpg", 7);
	leftMat = imread(buffer_left, CV_LOAD_IMAGE_UNCHANGED);
	rightMat = imread(buffer_right, CV_LOAD_IMAGE_UNCHANGED);
	trans->doRemap(leftMat, leftMat, mapLx, mapLy);
	trans->doRemap(rightMat, rightMat, mapRx, mapRy);
	trans->doThreshold(leftMat, dstL, tempthre);
	trans->doThreshold(rightMat, dstR, tempthre);
	lplImg_left = &IplImage(dstL);
	lplImg_right = &IplImage(dstR);
	imshow("111", dstL);
	imshow("222", dstR);
	allPointsleft.clear();
	allPointsright.clear();
	allPointsleft = getLaserCenter(leftMat, lplImg_left, 0);
	allPointsright = getLaserCenter(rightMat, lplImg_right, 1);
	//伪彩色显示
	Mat rgbleftMat, rgbrightMat;
	cvtColor(leftMat, rgbleftMat, CV_GRAY2BGR);  //伪彩色图
	cvtColor(rightMat, rgbrightMat, CV_GRAY2BGR);

	laserL.open("laserL.txt", ios::out);
	laserL.clear();

	for (int i = 0; i<allPointsleft.size(); i++) {
		laserL << (float)allPointsleft[i].x << " " << (float)allPointsleft[i].y << endl;
		circle(rgbleftMat, cvPoint((int)allPointsleft[i].x, allPointsleft[i].y), 1, Scalar(0, 0, 255));
	}
	laserL.close();

	laserR.open("laserR.txt", ios::out);
	laserR.clear();
	for (int i = 0; i<allPointsright.size(); i++) {
		laserR << (float)allPointsright[i].x << " " << (float)allPointsright[i].y << endl;
		circle(rgbrightMat, cvPoint((int)allPointsright[i].x, allPointsright[i].y), 1, Scalar(0, 0, 255));
	}
	laserR.close();
	imshow("left2", rgbleftMat);
	imshow("right2", rgbrightMat);

	allEquation.allPointsleft = allPointsleft;
	allEquation.allPointsright = allPointsright;
	//allEquation.XIANGSHIPoint();
	allEquation.CalRightPointDifY(0);
	testClouds.open("testClouds.txt", ios::out);
	testClouds.clear();
	for (int i = 0; i<allEquation.allPoints3d.size(); i++) {
		testClouds << (float)allEquation.allPoints3d[i].x << " " << (float)allEquation.allPoints3d[i].y << " " << (float)allEquation.allPoints3d[i].z << endl;
	}
	testClouds.close();
}

vector<CvPoint2D32f> LaserScanner::getLaserCenter(Mat src, IplImage* pic, int type)
{
	//灰度中心法求光条中心，src表示原始图像，transpic表示处理后的图像，type取0表示左相机，取1表示右相机
	IplImage* srcpic = &IplImage(src);
	vector<CvPoint2D32f> allPoints;
	int height = pic->height;
	int width = pic->width;
	int data;

	for (int i = 0; i<height; i++)
	{
		bool first = true;
		bool second = true;
		int a = 0;
		int b = 0;
		float c;
		int UPSum = 0;
		int DSum = 0;
		float Avg;
		if (type == 0)
		{
			for (int j = width-1; j >= 0; j--)	 
			{
				data = ((uchar *)(pic->imageData + i*pic->widthStep))[j];
				if (data == 255 && first)
				{
					//记录光条边界1
					a = j;
					first = false;
				}
				if (!first&&data == 0 && second)
				{
					//记录光条边界2
					b = j;
					second = false;
				}
			}
			if (a > 0 && b > 0 && (a - b)<20)
			{
				for (int k = b; k <= a; k++)
				{
					data = ((uchar *)(srcpic->imageData + i*srcpic->widthStep))[k];
					UPSum = UPSum + data*k;
					DSum = DSum + data;
				}
				//求光条边界内像素的灰度中心
				Avg = (float)UPSum / DSum;
				allPoints.push_back(cvPoint2D32f(Avg, i));
			}
		}
		else if (type == 1)
		{
			for (int j = 0; j<width; j++)	  
			{
				data = ((uchar *)(pic->imageData + i*pic->widthStep))[j];
				if (data == 255 && first)
				{
					a = j;
					first = false;
				}
				if (!first&&data == 0 && second)
				{
					b = j;
					second = false;
				}
			}
			if (a > 0 && b > 0 && (b - a)<30)
			{
				for (int k = a; k <= b; k++)
				{
					data = ((uchar *)(srcpic->imageData + i*srcpic->widthStep))[k];
					UPSum = UPSum + data*k;
					DSum = DSum + data;

				}
				Avg = (float)UPSum / DSum;
				allPoints.push_back(cvPoint2D32f(Avg, i));
			}
		}
	}
	return allPoints;
}


void  LaserScanner::OpenCamera()
{
	if (!bConnected)
	{
		if (leftCapture->  Open() && rightCapture->Open())
		{
			if (leftCapture->Capture() && rightCapture->Capture())
			{
				if (leftCapture->m_iDevType == RS_A1300_GM60&&rightCapture->m_iDevType == RS_A1300_GM60)
				{
					ui.infoEdit->append(u8"设备0:打开RS_A1300_GM60成功!\n");
					ui.infoEdit->append(u8"设备1:打开RS_A1300_GM60成功!\n");
				}
				else
				{
					ui.infoEdit->append(u8"设备0:打开未知设备成功!\n");
					ui.infoEdit->append(u8"设备1:打开未知设备成功!\n");
				}
				//绑定窗口句柄
				createWindow("left", ui.videoBox_left);
				cvResizeWindow("left", ui.videoBox_left->width(), ui.videoBox_left->height());
			    createWindow("right", ui.videoBox_right);
				cvResizeWindow("right", ui.videoBox_right->width(), ui.videoBox_right->height());
				allEquation.width = rightCapture->m_iImgWidth;
				allEquation.height = rightCapture->m_iImgHeight;
				ui.btn_openCam->setText(u8"关闭摄像机");
				bConnected = true;
				theTimer.start(0);
			}
			else
			{
				ui.infoEdit->append(u8"设备捕获失败!\n");
			}
		}
		else
		{
			ui.infoEdit->append(u8"设备打开失败!请尝试从新连接\n");
		}

	}
	else
	{
		if (leftCapture->Close())
		{
			cvDestroyWindow("left"); //销毁窗口
			leftMat.release();
			ui.infoEdit->append(u8"摄像头1关闭成功!\n");
			if (rightCapture->Close())
			{
				ui.infoEdit->append(u8"摄像头2关闭成功!\n");
				cvDestroyWindow("right"); //销毁窗口
				theTimer.stop();
				rightMat.release();
				ui.btn_openCam->setText(u8"连接摄像机");
				bConnected = false;
			}
	
		}

	}
}

void  LaserScanner::StartScan()
{
	if (theTimer.isActive())
	{
		if (isStartScan)
		{

			isStartScan = false;
			ui.infoEdit->append(u8"关闭扫描!\n");
			ui.btn_scan->setText(u8"开始扫描");
			allEquation.fst.close();
			ui.infoEdit->append(u8"保存点云成功!\n");
		}
		else {
			ui.infoEdit->append(u8"开始扫描!\n");
			ui.btn_scan->setText(u8"完成扫描(保存点云)");
			allEquation.fst.open("testClouds.txt", ios::out);
			if (allEquation.fst)
			{
				ui.infoEdit->append(u8"文件打开成功!\n");
			}
			else {
				ui.infoEdit->append(u8"文件打开失败!\n");
			}
			allEquation.fst.clear();
			isStartScan = true;
		}
	}
	else
	{
		ui.infoEdit->append(u8"扫描失败，请检测摄像头连接!\n");
	}
}
void LaserScanner::SaveImage()
{
	if (bConnected)
	{
		saveTimes++;
		sprintf(buffer_left, "ImageDataL\\Left%d.jpg", saveTimes);
		sprintf(buffer_right, "ImageDataR\\Right%d.jpg", saveTimes);
		cv::imwrite(buffer_left, leftMat);
		cv::imwrite(buffer_right, rightMat);
		ui.infoEdit->append(u8"图像截取成功!\n");
	}
	else
	{
		ui.infoEdit->append(u8"图像截取失败!\n");
	}
}
void LaserScanner::OnTimer()
{
	time_Start = (double)clock();
	leftCapture->m_bMatSaveOnce = TRUE;
	rightCapture->m_bMatSaveOnce = TRUE;
	while (leftCapture->m_bMatSaveOnce == TRUE || rightCapture->m_bMatSaveOnce == TRUE)
	{
		//ui.infoEdit->append(u8"wait!\n");
	}
	//转换Mat成功，捕获读取到的Mat数据
	if (!isSwap)
	{
		leftMat = leftCapture->imgMat;
		rightMat = rightCapture->imgMat;
	}
	else {
		rightMat = leftCapture->imgMat;
		leftMat = rightCapture->imgMat;
	}

	if (isCorrection)
	{
		//校正
		trans->doRemap(leftMat, rectifyImageL, mapLx, mapLy);
		trans->doRemap(rightMat, rectifyImageR, mapRx, mapRy);
		cvtColor(rectifyImageL, rgbRectifyImageL, CV_GRAY2BGR);  //伪彩色图
		cvtColor(rectifyImageR, rgbRectifyImageR, CV_GRAY2BGR);
		if (isStartScan)
		{
			Handle(rectifyImageL, rectifyImageR);
		}
	}
	else
	{
		cvtColor(leftMat, rgbRectifyImageL, CV_GRAY2BGR);  //伪彩色图
		cvtColor(rightMat, rgbRectifyImageR, CV_GRAY2BGR);
		if (isStartScan)
		{
			Handle(leftMat, rightMat);
		}
	}
	imshow("left", rgbRectifyImageL);
	imshow("right", rgbRectifyImageR);
	time_End = (double)clock();
	ui.infoEdit->append(u8"time:" + QString::number((time_End - time_Start) / 1000.0) + "s"); //计时
}
void LaserScanner::createWindow(char* src, QWidget * picSize)
{
	cvNamedWindow(src, 0);
	HWND hWnd = (HWND)cvGetWindowHandle(src);
	cvResizeWindow(src, 0, 0);
	HWND hParent = GetParent(hWnd);//窗口父对象为hWnd
	ShowWindow(hParent, SW_HIDE); //隐藏原父对象
	HWND new_hParent = (HWND)picSize->winId(); //获取qt窗口句柄
	SetParent(hWnd, new_hParent); //父对象设置

}
void LaserScanner::resizeEvent(QResizeEvent *event)
{
	if (theTimer.isActive())
	{
		cvResizeWindow("left", ui.videoBox_left->width(), ui.videoBox_left->height());
		cvResizeWindow("right", ui.videoBox_right->width(), ui.videoBox_right->height());
	}
}

void LaserScanner::paintEvent(QPaintEvent *event)
{
	if (tempthre != ui.spinBox_light->text().toInt())
	{
		tempthre = ui.spinBox_light->text().toInt();
		ui.infoEdit->append(u8"更改阈值成功!\n");
	}
	if (xyzMinZ != ui.xyzMinZ->text().toInt())
	{
		xyzMinZ = ui.xyzMinZ->text().toInt();
		ui.infoEdit->append(u8"更改点云最小Z值成功!\n");
	}
	if (xyzMaxZ != ui.xyzMaxZ->text().toInt())
	{
		xyzMaxZ = ui.xyzMaxZ->text().toInt();
		ui.infoEdit->append(u8"更改点云最大Z值成功!\n");
	}
	if (xyzScale != ui.xyzScale->text().toInt())
	{
		xyzScale = ui.xyzScale->text().toInt();
		ui.infoEdit->append(u8"更改点云最大Z值成功!\n");
	}
}
void LaserScanner::Handle(Mat picL, Mat picR)
{
	trans->doThreshold(picL, dstL, tempthre);
	trans->doThreshold(picR, dstR, tempthre);
	lplImg_left = &IplImage(dstL);
	lplImg_right = &IplImage(dstR);
	allPointsleft.clear();
	allPointsright.clear();
	allPointsleft = getLaserCenter(picL, lplImg_left, 0);
	allPointsright = getLaserCenter(picR, lplImg_right, 1);
	allEquation.allPointsleft = allPointsleft;
	allEquation.allPointsright = allPointsright;
	//allEquation.XIANGSHIPoint();
	allEquation.CalRightPointDifY(0);
	for (int i = 0; i<allEquation.allPointsleft.size(); i++) {
		//绘制圆圈函数 .图片,图片中亮点的坐标位置,半径，颜色，线条的粗细
		circle(rgbRectifyImageL, cvPoint((int)allEquation.allPointsleft[i].x, allEquation.allPointsleft[i].y), 1, Scalar(0, 0, 255));
	}
	for (int i = 0; i<allEquation.allPointsright.size(); i++) {
		//绘制圆圈函数 .图片,图片中亮点的坐标位置,半径，颜色，线条的粗细
		circle(rgbRectifyImageR, cvPoint((int)allPointsright[i].x, allEquation.allPointsright[i].y), 1, Scalar(0, 0, 255));
	}
	if (!allEquation.allPoints3d.empty())
	{
		ui.infoEdit->append(u8"save!\n");
		allEquation.SimpleFileWrite(xyzMinZ, xyzMaxZ, xyzScale);
	}
}

void LaserScanner::ViewPoints()
{
	//this->hide();

	QString filename = QFileDialog::getOpenFileName(
		this,
		"Open Document",
		QDir::currentPath(),
		"Document files (*.txt);;All files(*.*)");



	if (!filename.isNull()) { //用户选择了文件
							  // 处理文件
		glWidget->setTxtName(filename);
		glWidget = new GLMainWidget();
		glWidget->resize(800, 600);
		glWidget->show();
		//ui.infoEdit->append(c_str);
		ui.infoEdit->append(u8"显示点云: 使用中键旋转，ctrl+中键平移，滑轮缩放");
	}
	else // 用户取消选择
		ui.infoEdit->append(u8"取消选择成功!");

}

void LaserScanner::StartCalibrationL()
{
	leftCalibration.setTimes(0);
	chooseL = true;
	//int times = 0;
	ui.infoEdit->append(u8"请选择左图角点\n");
	ui.infoEdit->append(u8"请按中下-中上-左下-左上-右下-右上的顺序双击找到6个角点,并按任意键结束\n");
	//leftCalibration.setSrc(cvLoadImage("ImageDataL\\Left1.jpg", 1)) ;
	calImage = cvLoadImage("ImageDataL\\Left1.jpg", 1);
	cvNamedWindow("Calibration", 1);
	setMouseCallback("Calibration", LaserScanner::onMouse, this);
	cvShowImage("Calibration", calImage);
	cvWaitKey(0);
	cvDestroyAllWindows();
	cvReleaseImage(&calImage);
	if (leftCalibration.getTimes() == 6)
	{
		ui.infoEdit->append(u8"左图像角点选择成功!");
		isCalibratedL = true;
		StereoCalibration();
	}
	chooseL = false;
}
void LaserScanner::StartCalibrationR()
{
	rightCalibration.setTimes(0);
	chooseR = true;
	ui.infoEdit->append(u8"请选择右图角点\n");
	ui.infoEdit->append(u8"请按中下-中上-左下-左上-右下-右上的顺序双击找到6个角点,并按任意键结束\n");
	//rightCalibration.setSrc(cvLoadImage("ImageDataR\\Right1.jpg", 1));
	calImage = cvLoadImage("ImageDataR\\Right1.jpg", 1);
	cvNamedWindow("Calibration", 1);
	setMouseCallback("Calibration", LaserScanner::onMouse, this);
	cvShowImage("Calibration", calImage);
	cvWaitKey(0);
	cvDestroyAllWindows();
	cvReleaseImage(&calImage);
	if (rightCalibration.getTimes() == 6)
	{
		ui.infoEdit->append(u8"右图像角点选择成功!");
		isCalibratedR = true;
		StereoCalibration();
	}
	chooseR = false;
}
void LaserScanner::StereoCalibration()
{
	if (isCalibratedL&&isCalibratedR)
	{
		ui.infoEdit->append(u8"开始标定!");
		FileStorage fs("RandT.yml", FileStorage::WRITE);
		leftCalibration.cal_M();
		fs << "TL" << leftCalibration.getT();
		fs << "RL" << leftCalibration.getR();

		rightCalibration.cal_M();
		fs << "TR" << rightCalibration.getT();
		fs << "RR" << rightCalibration.getR();

		Mat R, T;
		Mat meinv = leftCalibration.getR().inv();
		R = rightCalibration.getR()*meinv;
		T = rightCalibration.getT() - R*leftCalibration.getT();
		fs << "T" << T;
		fs << "R" << R;
		fs.release();

		cameraMatrixL = (Mat_<double>(3, 3) <<
			leftCalibration.fx, 0, leftCalibration.u,
			0, leftCalibration.fy, leftCalibration.v,
			0, 0, 1);
		cameraMatrixR = (Mat_<double>(3, 3) <<
			rightCalibration.fx, 0, rightCalibration.u,
			0, rightCalibration.fy, rightCalibration.v,
			0, 0, 1);
		distCoeffL = (Mat_<double>(5, 1) << 0, 0, 0, 0, 0);
		distCoeffR = (Mat_<double>(5, 1) << 0, 0, 0, 0, 0);
		FileStorage fs2("Parameter.yml", FileStorage::WRITE);
		fs2 << "cameraMatrixL" << cameraMatrixL << "cameraMatrixR" << cameraMatrixR;
		fs2 << "distCoeffL" << distCoeffL << "distCoeffR" << distCoeffR;
		fs2 << "T" << T << "R" << R;
		fs2.release();
		ui.infoEdit->append(u8"标定成功!");
		isLoadParameter = true;
	}
}
void LaserScanner::Correction()
{
	if (!isCorrection)
	{
		if (isLoadParameter)
		{
			/////////////////////////////read/////////////////////////////////////////
			FileStorage fs("Parameter.yml", FileStorage::READ);
			fs["cameraMatrixL"] >> cameraMatrixL;
			fs["cameraMatrixR"] >> cameraMatrixR;
			fs["distCoeffL"] >> distCoeffL;
			fs["distCoeffR"] >> distCoeffR;
			fs["T"] >> T;
			fs["R"] >> R;
			fs.release();
			/////////////////////////////////////////////////////////////////////////////////
			allEquation.f = (float)(cameraMatrixL.at<double>(0, 0) + cameraMatrixR.at<double>(0, 0)) / 2;
			allEquation.M = (float)T.at<double>(0, 0);

		}
		//Rodrigues(rec, R); //Rodrigues变换
		stereoRectify(cameraMatrixL, distCoeffL, cameraMatrixR, distCoeffR, imageSize, R, T, Rl, Rr, Pl, Pr, Q, CALIB_ZERO_DISPARITY,
			0, imageSize, &validROIL, &validROIR);
		initUndistortRectifyMap(cameraMatrixL, distCoeffL, Rl, Pl, imageSize, CV_32FC1, mapLx, mapLy);
		initUndistortRectifyMap(cameraMatrixR, distCoeffR, Rr, Pr, imageSize, CV_32FC1, mapRx, mapRy);
		isCorrection = true;
		ui.infoEdit->append(u8"校正成功!");
	}
	else
	{
		isCorrection = false;
	}
	
}
void LaserScanner::onMouse(int event, int x, int y, int, void* userdata)
{
	// Check for null pointer in userdata and handle the error  
	LaserScanner* temp = reinterpret_cast<LaserScanner*>(userdata);
	temp->on_Mouse(event, x, y);
}

void LaserScanner::on_Mouse(int event, int x, int y)
{
	static CvPoint pre_pt = { -1,-1 };
	static CvPoint cur_pt = { -1,-1 };
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1, CV_AA);
	char temp[16];
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		//your code here  
		break;
	case CV_EVENT_MOUSEMOVE:
		//your code here  
		break;
	case CV_EVENT_LBUTTONUP:
		//your code here  
		break;
	case CV_EVENT_LBUTTONDBLCLK:
		sprintf(temp, "(%d,%d)", x, y);
		pre_pt = cvPoint(x, y);
		if (chooseL&&leftCalibration.getTimes()< 6)
		{
			leftCalibration.grabPoint(); //times++
			leftCalibration.putPoint(x, y);
			cvPutText(calImage, temp, pre_pt, &font, cvScalar(0, 0, 255, 255));
			cvCircle(calImage, pre_pt, 3, cvScalar(255, 255, 255, 0), CV_FILLED, CV_AA, 0);
		}
		if (chooseR && rightCalibration.getTimes()< 6)
		{
			rightCalibration.grabPoint(); //times++
			rightCalibration.putPoint(x, y);
			cvPutText(calImage, temp, pre_pt, &font, cvScalar(0, 0, 255, 255));
			cvCircle(calImage, pre_pt, 3, cvScalar(255, 255, 255, 0), CV_FILLED, CV_AA, 0);
		}
		cvShowImage("Calibration", calImage);
		break;
	}
}