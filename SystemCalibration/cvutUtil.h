#ifndef CVUT_UTIL_H
#define CVUT_UTIL_H

#include "cvutMatrix.h"
#include "cvutImage.h"
#include "cvaux.h"
#include <iostream>

using namespace std;
using namespace cvutMatrix;
using namespace cvutImage;

namespace cvutUtil {
	/************************************************************************
		image rectification
	*************************************************************************/
	template <typename T>
	void do_morphing(Image<T>& RightImage, Image<T>& LeftImage,CvMatrix3* F_Matrix) {
		CvSize ImgSize;
		ImgSize.width=RightImage.width*3;
		ImgSize.height=RightImage.height*3;
		int line_count;
		cvMakeScanlines(0,ImgSize,0,0,0,0,&line_count);
		line_count=2400;
		int* scanlines1;
		int* scanlines2;
		int* scanlinesA;
		scanlines1=(int*)(calloc( line_count * 2, sizeof(int) * 4));
		scanlines2=(int*)(calloc( line_count * 2, sizeof(int) * 4));
		scanlinesA=(int*)(calloc( line_count * 2, sizeof(int) * 4));
		int* lenghts1;
		int* lenghts2;
		int* lenghts;
		lenghts1=(int*)(calloc( line_count * 2, sizeof(int)*4));
		lenghts2=(int*)(calloc( line_count * 2, sizeof(int)*4));
		lenghts=(int*)(calloc( line_count * 2, sizeof(int)*4));
		//	IplImage* dst1 = cvCreateImage(cvSize(ImgSize.width,ImgSize.height),8,3);
		//	IplImage* dst2 = cvCreateImage(cvSize(ImgSize.width,ImgSize.height),8,3);
		//	IplImage* dst3 = cvCreateImage(cvSize(ImgSize.width,ImgSize.height),8,3);
		uchar* dst1;
		dst1=(uchar*)(malloc(ImgSize.width * (ImgSize.height+1) * 3 * sizeof(uchar)));
		uchar* dst2;
		dst2=(uchar*)(malloc(ImgSize.width * (ImgSize.height+1) * 3 * sizeof(uchar)));
		uchar* dst_pix;
		dst_pix=(uchar*)(calloc(ImgSize.width * (ImgSize.height+1), 3 * sizeof(uchar)));
		int* runs1;
		int* runs2;
		runs1=(int*)(calloc(ImgSize.width * ImgSize.height * 2, 2 * sizeof(int)));
		runs2=(int*)(calloc(ImgSize.width * ImgSize.height * 2, 2 * sizeof(int)));
		int* first_corr;
		int* second_corr;
		first_corr=(int*)(calloc(ImgSize.width * ImgSize.height * 2, 2 * sizeof(int)));
		second_corr=(int*)(calloc(ImgSize.width * ImgSize.height * 2, 2 * sizeof(int)));
		int* num_runs1;
		int* num_runs2;
		num_runs1=(int*)(calloc(ImgSize.width * ImgSize.height * 2, 2 * sizeof(int)));
		num_runs2=(int*)(calloc(ImgSize.width * ImgSize.height * 2, 2 * sizeof(int)));
		
		ImgSize.width=RightImage.width;
		ImgSize.height=RightImage.height;
		
		cvMakeScanlines(F_Matrix,ImgSize,0,0,0,0,&line_count);
		
		cvMakeScanlines(F_Matrix,ImgSize,scanlines1,scanlines2,lenghts1,lenghts2,&line_count);
		
		// 	IplImage* image1=cvCreateImage(RightImage.size(),8,3);
		// 	image1=cvCloneImage(RightImage.cvimage);
		
		//	cvPreWarpImage(line_count,image1,dst1,lenghts1,scanlines1);
		cvPreWarpImage(line_count,RightImage.cvimage,dst1,lenghts1,scanlines1);	
		// 	IplImage* image2=cvCreateImage(LeftImage.size(),8,3);
		// 	image2=cvCloneImage(LeftImage.cvimage);
		
		//	cvPreWarpImage(line_count,image2,dst2,lenghts2,scanlines2);		
		cvPreWarpImage(line_count,LeftImage.cvimage,dst2,lenghts2,scanlines2);
		if (scanlines1 != 0) free (scanlines1);
		if (scanlines2 != 0) free (scanlines2);
		if (scanlinesA != 0) free (scanlinesA);
		if (lenghts1 != 0) free (lenghts1);
		if (lenghts2 != 0) free (lenghts2);
		if (lenghts != 0) free (lenghts);
		if (dst1 != 0) free (dst1);
		if (dst2 != 0) free (dst2);
		if (dst_pix != 0) free (dst_pix);
		if (runs1 != 0) free (runs1);
		if (runs2 != 0) free (runs2);
		if (first_corr != 0) free (first_corr);
		if (second_corr != 0) free (second_corr);
		if (num_runs1 != 0) free (num_runs1);
		if (num_runs2 != 0) free (num_runs2);
		scanlines1 = 0;
		scanlines2 = 0;
		scanlinesA = 0;
		lenghts1 = 0;
		lenghts2 = 0;
		lenghts = 0;
		runs1 = 0;
		runs2 = 0;
		dst1 = 0;
		dst2 = 0;
		dst_pix = 0;
		num_runs1 = 0;
		num_runs2 = 0;
		first_corr = 0;
		second_corr = 0;
};
	/************************************************************************
		calculate the skew symmetric matrix of a vector
	*************************************************************************/
	template <typename T>
		Matrix<T> skew_sym(Matrix<T>& vec) {
		if (!(vec.channels == 1 && 
			(vec.rows == 3 && vec.cols == 1 || vec.rows == 1 && vec.cols == 3)))
		{
			cerr<<"wrong type of matrix!\n";
			exit(1);
		}
		Matrix<T> skew(3,3,1);
		skew(0,1) = -vec.data[2];
		skew(0,2) = vec.data[1];
		skew(1,0) = vec.data[2];
		skew(1,2) = -vec.data[0];
		skew(2,0) = -vec.data[1];
		skew(2,1) = vec.data[0];
		return skew;
	};

	/************************************************************************
		calculate fundamental matrix using two projective matrixes
	*************************************************************************/
	template <typename T>
	Matrix<T> calc_fundamental(Matrix<T>& mat1, Matrix<T>& mat2) {
		if (mat1.rows != 3 || mat1.cols != 4 || mat1.channels != 1
			|| mat2.rows != 3 || mat2.cols != 4 || mat2.channels != 1) 
		{
			cerr<<"wrong type of matrix!\n";
			exit(1);
		}
		return skew_sym(mat2.get_col(3)-mat2.get_cols(0,2)*invert(mat1.get_cols(0,2))*mat1.get_col(3))*mat2.get_cols(0,2)*invert(mat1.get_cols(0,2));
	};

	/***********************************************************************
		histgram equalization
	***********************************************************************/
	template <typename T>
		void hist_equalize(Image<T>& src) {
		if (src.channels > 1) {
			cerr<<"fail to equalize histgram!\n";
			exit(1);
		}	
		int hdim = 256;    // bin of HIST, default = 256
		
		CvHistogram *hist = 0;
		
		int n = hdim;     
		double* nn = new double[hdim];
		uchar* T = new uchar[hdim];
		
		int sum = 0; // sum of pixels of the source image 图像中象素点的总和
		double val = 0;
		
		
		// calculate histgram 计算直方图
		hist = cvCreateHist( 1, &n, CV_HIST_ARRAY, 0, 1 );  
		cvCalcHist( &src.cvimage, hist, 0, 0 ); 
		
		// Create Accumulative Distribute Function of histgram
		int i;
		for (i = 0; i < n; i++)
		{
			val = val + cvGetReal1D (hist->bins, i);
			nn[i] = val;
		}
		
		// Compute intensity transformation 计算变换函数的离散形式
		sum = src.height * src.width;
		for(i = 0; i < n; i++ )
		{
			T[i] = (uchar) (255 * nn[i] / sum); // range is [0,255]
		}
		Matrix<uchar> T_mat(1,256,1,T);
		cvLUT( src.cvimage, src.cvimage, T_mat.cvmat ); 
		
	};
	
} /* namespace cvutUtil */

#endif