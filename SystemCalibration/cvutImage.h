#ifndef CVUT_IMAGE_H
#define CVUT_IMAGE_H

#include "cv.h"
#include "highgui.h"
#include <iostream>
#include <string>

using namespace std;

namespace cvutImage {
	/************************************************************************
		class Image
	*************************************************************************/
	template <typename T>
	class Image {
	public:
		IplImage* cvimage;
		int height;
		int width;
		int channels;
		bool is_show;
		char* window_name;	
	public:
		/***********************************************************************
		                        constructor
		***********************************************************************/
		Image(int width,int height, int depth, int channels )  {//长、宽、高和通道数构造
			cvimage = cvCreateImage(cvSize(width,height),depth,channels);
			if (cvimage == NULL) {
				cerr<<"fail to create image!\n";
				exit(1);
			}
			this->width = width;
			this->height = height;
			this->channels = channels;
			is_show=false;
			window_name="";
		};
		Image(CvSize size, int depth, int channels ) {//尺寸、高度和通道数
			cvimage = cvCreateImage(size,depth,channels);
			if (cvimage == NULL) {
				cerr<<"fail to create image!\n";
				exit(1);
			}
			width = cvimage->width;
			height = cvimage->height;
			this->channels = channels;
			is_show=false;
			window_name="";
		};
		Image(Image<T>& src) {//用一幅图像构造
			cvimage = cvCloneImage(src.cvimage);
			if (cvimage == NULL) {
				cerr<<"fail to clone image!\n";
				exit(1);
			}
			width = cvimage->width;
			height = cvimage->height;
			channels = src.channels;
			is_show=false;
			window_name="";
		};
		Image(const char* name) {//char型图像名称
			cvimage = cvLoadImage( name, 1);
			if (cvimage == NULL) {
				cerr<<"fail to load image!\n";
				exit(1);
			}
			if (cvimage->widthStep/cvimage->width/cvimage->nChannels != sizeof(T))
			{
				cerr<<"image type unmatch!\n";
				exit(1);
			}
			width =cvimage->width;
			height = cvimage->height;
			channels = cvimage->nChannels;
			is_show = false;
			window_name="";
		};
		Image(const string name) {
			cvimage = cvLoadImage( name.c_str(), 1);
			if (cvimage == NULL) {
				cerr<<"fail to load image!\n";
				exit(1);
			}
			if (cvimage->widthStep/cvimage->width/cvimage->nChannels != sizeof(T))
			{
				cerr<<"image type unmatch!\n";
				exit(1);
			}
			width = cvimage->width;
			height =cvimage->height;
			channels = cvimage->nChannels;
			is_show = false;
			window_name="";
		};

		/***********************************************************************
		                        deconstructor
		***********************************************************************/
		~Image() {
			if (is_show) {
				close();
			}
			window_name=NULL;
			cvReleaseImage(&cvimage);
		};
		

		/***********************************************************************
		                        overload =
		***********************************************************************/
		Image& operator = (Image<T>& src) {
			cvReleaseImage(&cvimage);
			cvimage = cvCloneImage(src.cvimage);
			is_show = false;
			width = src.width;
			height = src.height;
			channels = src.channels;
			return *this;
		};

		/***********************************************************************
		                        access pixel
		***********************************************************************/
		T& operator () (int row,int col,int channel=0) {
			if (channel<0 || channel>=cvimage->nChannels ||
				row<0 || row>=height ||
				col<0 || col>=width) 
			{
				cerr<<"image out of range!\n";
				exit(1);
			}
			return ((T*)(cvimage->imageData + cvimage->widthStep*row))[col*cvimage->nChannels+channel];
		};

		/***********************************************************************
		                        show image in window
		***********************************************************************/
		void show(char* window="",int x=0,int y=0) {
			if (!is_show) {
				window_name=window;
				cvNamedWindow(window_name);
				cvMoveWindow(window_name,x,y);
			    cvimage=scaling(cvimage,0.3);
				cvShowImage(window_name,cvimage);
				is_show = true;
			}
		};
		IplImage* scaling(IplImage *src,double scale)
		{
			CvSize dst_cvsize;
		    dst_cvsize.width=(int)(src->width*scale);
			dst_cvsize.height=(int)(src->height*scale);
			IplImage *dst=cvCreateImage(dst_cvsize,src->depth,src->nChannels);
			cvResize(src,dst,CV_INTER_NN);//

				//             CV_INTER_NN - 最近邻插值,

				//             CV_INTER_LINEAR - 双线性插值 (缺省使用)

				//             CV_INTER_AREA - 使用象素关系重采样。当图像缩小时候，该方法可以避免波纹出现。

				/*当图像放大时，类似于 CV_INTER_NN 方法..*/

				//             CV_INTER_CUBIC - 立方插值.
			cvReleaseImage(&src);
			return dst;
		}
		/***********************************************************************
		                        close image window
		***********************************************************************/
		void close() {
			if (is_show) {
				cvDestroyWindow(window_name);
				window_name="";
				is_show = false;
			}
		};
		CvSize size(){
			return cvSize(width,height);
		};

	};/* class Image */

	/************************************************************************
	       image tool function
	*************************************************************************/

	/***********************************************************************
	                        turn rgb image to gray
	***********************************************************************/
	template <typename T>
	void rgb2gray (Image<T>& rgb,Image<T>& gray){
		cvCvtColor(rgb.cvimage,gray.cvimage,CV_RGB2GRAY);
	};
	
}/* namespace cvutImage */

#endif /* CVUT_IMAGE_H */