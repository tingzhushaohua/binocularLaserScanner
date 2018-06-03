
#include "Transforms.h"


Transforms::Transforms() {}





void Transforms::doRemap(Mat&src, Mat& dst,Mat mapx,Mat mapy)
{
	remap(src, dst, mapx, mapy, INTER_LINEAR);
}
void Transforms::doThreshold(Mat&src , Mat& dst,int tempthre)
{
	threshold(src, dst, tempthre, 255, CV_THRESH_BINARY);
	//adaptiveThreshold(remapMat, dstF,255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 13, -13);
}
void Transforms::delete_jut(Mat& src, Mat& dst, int uthreshold, int vthreshold, int type)
{
	//去除二值图像边缘的突出部  
	//uthreshold、vthreshold分别表示突出部的宽度阈值和高度阈值  
	//type代表突出部的颜色，0表示黑色，1代表白色   
	src.copyTo(dst);
	int height = dst.rows;
	int width = dst.cols;
	int k;  //用于循环计数传递到外部  
	for (int i = 0; i < height - 1; i++)
	{
		uchar* p = dst.ptr<uchar>(i);
		for (int j = 0; j < width - 1; j++)
		{
			if (type == 0)
			{
				//行消除  
				if (p[j] == 255 && p[j + 1] == 0)
				{
					if (j + uthreshold >= width)
					{
						for (int k = j + 1; k < width; k++)
							p[k] = 255;
					}
					else
					{
						for (k = j + 2; k <= j + uthreshold; k++)
						{
							if (p[k] == 255) break;
						}
						if (p[k] == 255)
						{
							for (int h = j + 1; h < k; h++)
								p[h] = 255;
						}
					}
				}
				//列消除  
				if (p[j] == 255 && p[j + width] == 0)
				{
					if (i + vthreshold >= height)
					{
						for (k = j + width; k < j + (height - i)*width; k += width)
							p[k] = 255;
					}
					else
					{
						for (k = j + 2 * width; k <= j + vthreshold*width; k += width)
						{
							if (p[k] == 255) break;
						}
						if (p[k] == 255)
						{
							for (int h = j + width; h < k; h += width)
								p[h] = 255;
						}
					}
				}
			}
			else  //type = 1  
			{
				//行消除  
				if (p[j] == 0 && p[j + 1] == 255)
				{
					if (j + uthreshold >= width)
					{
						for (int k = j + 1; k < width; k++)
							p[k] = 0;
					}
					else
					{
						for (k = j + 2; k <= j + uthreshold; k++)
						{
							if (p[k] == 0) break;
						}
						if (p[k] == 0)
						{
							for (int h = j + 1; h < k; h++)
								p[h] = 0;
						}
					}
				}
				//列消除  
				if (p[j] == 0 && p[j + width] == 255)
				{
					if (i + vthreshold >= height)
					{
						for (k = j + width; k < j + (height - i)*width; k += width)
							p[k] = 0;
					}
					else
					{
						for (k = j + 2 * width; k <= j + vthreshold*width; k += width)
						{
							if (p[k] == 0) break;
						}
						if (p[k] == 0)
						{
							for (int h = j + width; h < k; h += width)
								p[h] = 0;
						}
					}
				}
			}
		}
	}
}
void Transforms::imageblur(Mat& src, Mat& dst, Size size, int threshold)
{
	//图片边缘光滑处理  
	//size表示取均值的窗口大小，threshold表示对均值图像进行二值化的阈值  
	int height = src.rows;
	int width = src.cols;
	blur(src, dst, size);
	for (int i = 0; i < height; i++)
	{
		uchar* p = dst.ptr<uchar>(i);
		for (int j = 0; j < width; j++)
		{
			if (p[j] < threshold)
				p[j] = 0;
			else p[j] = 255;
		}
	}
	//imshow("Blur", dst);
}

void Transforms::RemoveSmallRegion(Mat &Src, Mat &Dst, int AreaLimit, int CheckMode, int NeihborMode)
{
	int RemoveCount = 0;
	Mat PointLabal = Mat::zeros(Src.size(), CV_8UC1);	//像素点状态，0位检查，1正检查，2不合格，3合格

	if (CheckMode == 1)
	{
		for (int i = 0; i < Src.rows; i++)
		{
			for (int j = 0; j<Src.cols; j++)
				if (Src.at<uchar>(i, j) < 10)
				{
					PointLabal.at<uchar>(i, j) = 3;
				}
		}
	}
	else
	{
		for (int i = 0; i < Src.rows; i++)
		{
			for (int j = 0; j<Src.cols; j++)
				if (Src.at<uchar>(i, j) > 10)
				{
					PointLabal.at<uchar>(i, j) = 3;
				}
		}
	}

	vector<Point2i>NeihborPos;  
	NeihborPos.push_back(Point2i(-1, 0));
	NeihborPos.push_back(Point2i(1, 0));
	NeihborPos.push_back(Point2i(0, -1));
	NeihborPos.push_back(Point2i(0, 1));
	if (NeihborMode == 1)
	{
	//	cout << "Neighbor Mode:8邻域." << endl;
		NeihborPos.push_back(Point2i(-1, -1));
		NeihborPos.push_back(Point2i(-1, 1));
		NeihborPos.push_back(Point2i(1, -1));
		NeihborPos.push_back(Point2i(1, 1));
	}
	else
	{
//		cout << "Neightor Mode:4邻域." << endl;
	}

	int Neihborcount = 4 + 4 * NeihborMode;
	int CurrX = 0, CurrY = 0;

	//检测
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			if (PointLabal.at<uchar>(i, j) == 0)
			{
				vector<Point2i>GrowBuffer;
				GrowBuffer.push_back(Point2i(j, i));
				PointLabal.at<uchar>(i, j) = 1;
				int CheckResult = 0;

				for (int z = 0; z < GrowBuffer.size(); z++)
				{
					for (int q = 0; q < Neihborcount; q++)
					{
						CurrX = GrowBuffer.at(z).x + NeihborPos.at(q).x;
						CurrY = GrowBuffer.at(z).y + NeihborPos.at(q).y;
						if (CurrX >= 0 && CurrX<Src.cols&&CurrY >= 0 && CurrY<Src.rows)
						{
							if (PointLabal.at<uchar>(CurrY, CurrX) == 0)
							{
								GrowBuffer.push_back(Point2i(CurrX, CurrY));
								PointLabal.at<uchar>(CurrY, CurrX) = 1;
							}
						}
					}
				}
				if (GrowBuffer.size() > AreaLimit)
				{
					CheckResult = 2;
				}
				else
				{
					CheckResult = 1;
					RemoveCount++;
				}

				for (int z = 0; z<GrowBuffer.size(); z++)
				{
					CurrX = GrowBuffer.at(z).x;
					CurrY = GrowBuffer.at(z).y;
					PointLabal.at<uchar>(CurrY, CurrX) += CheckResult;
				}

				//cout << "Check one point" << endl;

			}
		}
	}

	//cout << "Check Over." << endl;

	CheckMode = 255 * (1 - CheckMode);  //过小域反转
	Dst = Mat::zeros(Src.size(), CV_8UC1);
										//向目标写入
	for (int i = 0; i < Src.rows; i++)
	{
		for (int j = 0; j < Src.cols; j++)
		{
			if (PointLabal.at<uchar>(i, j) == 2)
			{
				Dst.at<uchar>(i, j) = CheckMode;
			}
			else if (PointLabal.at<uchar>(i, j) == 3)
			{
				Dst.at<uchar>(i, j) = Src.at<uchar>(i, j);
				//Dst2.at<uchar>(i, j) = 1;
			}
		}
	}

//	cout << RemoveCount << "objects removed." << endl;

}
