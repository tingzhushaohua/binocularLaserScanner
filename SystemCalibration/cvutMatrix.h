/************************************************************************
没有考虑不同数据类型但相同矩阵形式之间的各种操作
*************************************************************************/

#ifndef CVUT_MATRIX_H
#define CVUT_MATRIX_H

#include "cv.h"
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std;

//#pragma comment(lib,"cxcore.lib")

namespace cvutMatrix {
	/************************************************************************
	Class Matrix
	*************************************************************************/
	template <typename T>
	class Matrix {
	public:
		T* data;
		int rows;
		int cols;
		int channels;
		CvMat* cvmat;

	public:
		/************************************************************************
		constructor
		*************************************************************************/
		Matrix(int rows,int cols,int channels=1,const T* arr=NULL) {
			int type=0;
			if (0 == strcmp(typeid(*data).name(),"unsigned char")) {
				type = 0;
			} else if (0 == strcmp(typeid(*data).name(),"char")) {
				type = 1;
			} else if (0 == strcmp(typeid(*data).name(),"short")) {
				type = 2;
			} else if (0 == strcmp(typeid(*data).name(),"unsigned short")) {
				type = 3;
			} else if (0 == strcmp(typeid(*data).name(),"int")) {
				type = 4;
			} else if (0 == strcmp(typeid(*data).name(),"float")) {
				type = 5;
			} else if (0 == strcmp(typeid(*data).name(),"double")) {
				type = 6;
			} else {
				cerr<<"unsupported matrix type!\n";
				exit(1);
			}
			cvmat = cvCreateMat(rows,cols,type+8*(channels-1));
			data = (T*)cvmat->data.ptr;
			this->rows = rows;
			this->cols = cols;
			this->channels=channels;
			bool user_data=false;
			if (arr !=NULL) 
				user_data=true;
			for (int i=0;i<rows;i++) {
				for (int j=0;j<cols;j++) {
					for (int k=0;k<channels;k++) {
						if (user_data)
							data[i*cols*channels+j*channels+k]=arr[i*cols*channels+j*channels+k];
						else
							data[i*cols*channels+j*channels+k]=0;
					}
				}
			}
		};

		Matrix(CvMat* src) {
			cvmat = cvCloneMat(src);
			data = (T*)src->data.ptr;
			rows = src->rows;
			cols = src->cols;
			channels=cvmat->step/cols/sizeof(T);
		};

		Matrix(Matrix<T>& src) {
			cvmat=cvCloneMat(src.cvmat);
			data = (T*)(src.cvmat->data.ptr);
			rows = src.rows;
			cols = src.cols;
			channels=src.channels;
		};

		/************************************************************************
		deconstructor
		*************************************************************************/
		~Matrix() {
			cvReleaseMat(&cvmat);
			data=NULL;
		};

		/************************************************************************
		access matrix element
		*************************************************************************/
		T& operator () (int i_row,int i_col,int i_channel=0) {
			if (i_row>=0 && i_row<rows && i_col>=0 && i_col<cols && i_channel>=0 && i_channel<channels)
				return data[i_row*cols+i_col*channels+i_channel];
			else {
				cerr<<"matrix access out of range"<<endl;
				exit(1);
			}
		};

		/************************************************************************
		overload = (Matrix = Matrix)
		*************************************************************************/
		Matrix<T>& operator =(Matrix<T>& src) {
			if (!mat_type_cmp(*this,src)) {
				cerr<<"matrix type unmatch!\n";
				exit(1);
			}
			for (int i=0;i<rows;i++) {
				for (int j=0;j<cols;j++) {
					for (int k=0;k<channels;k++) {
						data[i*cols*channels+j*channels+k]=src.data[i*cols*channels+j*channels+k];
					}
				}
			}
			return *this;
		};

		/************************************************************************
		overload + (matrix + matrix)
		*************************************************************************/
		Matrix<T> operator + (Matrix<T>& src) {
			if (!mat_type_cmp(*this,src)) {
				cerr<<"matrix type unmatch!\n";
				exit(1);
			}
			Matrix<T> temp(*this);
			cvAdd(cvmat,src.cvmat,temp.cvmat);
			return temp;
		};

		/************************************************************************
		overload += (matrix += matrix)
		*************************************************************************/
		Matrix<T>& operator +=(Matrix<T>& src) {
			if (!mat_type_cmp(*this,src)) {
				cerr<<"matrix type unmatch!\n";
				exit(1);
			}
			cvAdd(cvmat,src.cvmat,cvmat);
			return *this;
		};

		/************************************************************************
		overload + (matrix + number)
		*************************************************************************/
		Matrix<T> operator + (double num) {
			Matrix<T> temp(*this);
			for (int i=0;i<rows;i++) {
				for (int j=0;j<cols;j++) {
					for (int k=0;k<channels;k++) {
						temp.data[i*cols*channels+j*channels+k]+=num;
					}
				}
			}
			return temp;
		};

		/************************************************************************
		overload += (matrix += number)
		*************************************************************************/
		Matrix<T>& operator +=(double num) {
			for (int i=0;i<rows;i++) {
				for (int j=0;j<cols;j++) {
					for (int k=0;k<channels;k++) {
						data[i*cols*channels+j*channels+k]+=num;
					}
				}
			}
			return *this;
		};

		/************************************************************************
		overload - (matrix - matrix)
		*************************************************************************/
		Matrix<T> operator - (Matrix<T>& src) {
			if (!mat_type_cmp(*this,src)) {
				cerr<<"matrix type unmatch!\n";
				exit(1);
			}
			Matrix<T> temp(*this);
			cvSub(cvmat,src.cvmat,temp.cvmat);
			return temp;
		};

		/************************************************************************
		overload -= (matrix -= matrix)
		*************************************************************************/
		Matrix<T>& operator -=(Matrix<T>& src) {
			if (!mat_type_cmp(*this,src)) {
				cerr<<"matrix type unmatch!\n";
				exit(1);
			}
			cvSub(cvmat,src.cvmat,cvmat);
			return *this;
		};

		/************************************************************************
		overload - (matrix - number)
		*************************************************************************/
		Matrix<T> operator - (double num) {
			Matrix<T> temp(*this);
			return temp+=(-num);;
		};

		/************************************************************************
		overload -= (matrix -= number)
		*************************************************************************/
		Matrix<T>& operator -=(double num) {
			return *this+=(-num);
		};

		/************************************************************************
		overload * (matrix * matrix)
		*************************************************************************/
		Matrix<T> operator * (Matrix<T>& src) {
			if (!can_mult(*this,src)) {
				cerr<<"matrix multiply fail!\n";
				exit(1);
			}
			Matrix<T> temp(rows,src.cols,channels);
			cvMatMul(cvmat,src.cvmat,temp.cvmat);
			return temp;
		};

		/************************************************************************
		overload * (matrix * number)
		*************************************************************************/
		Matrix<T> operator * (double num) {
			Matrix<T> temp(*this);
			for (int i=0;i<rows;i++) {
				for (int j=0;j<cols;j++) {
					for (int k=0;k<channels;k++) {
						temp.data[i*cols*channels+j*channels+k] *= num;
					}
				}
			}
			return temp;
		};

		/************************************************************************
		overload *= (matrix *= number)
		*************************************************************************/
		Matrix<T>& operator *=(double num) {
			for (int i=0;i<rows;i++) {
				for (int j=0;j<cols;j++) {
					for (int k=0;k<channels;k++) {
						data[i*cols*channels+j*channels+k]*=num;
					}
				}
			}
			return *this;
		};

		/************************************************************************
		compare two matrixes (matrix == matrix)
		regardless of element type
		*************************************************************************/
		bool operator == (const Matrix<T>& src) {
			if (!mat_type_cmp(*this,src))
				return false;
			for (int i=0;i<src.rows;i++) {
				for (int j=0;j<src.cols;j++) {
					for (int k=0;k<src.channels;k++) {
						if (src.data[i*src.cols*src.channels+j*src.channels+k] !=
							data[i*src.cols*src.channels+j*src.channels+k]) 
						{
							return false;	
						}
					}
				}
			}
			return true;
		};

		/************************************************************************
		set matrix identity
		*************************************************************************/
		void identity() {
			if (cols != rows) {
				cerr<<"identity fail! non-spuare!\n";
				exit(1);
			}
			for (int i=0;i<cols;i++) {
				for (int j=0;j<rows;j++) {
					for (int k=0;k<channels;k++)
						data[i*cols*channels+j*channels+k]=(i == j)?1.0:0.0;
				}
			}
		};

		/************************************************************************
		get row
		*************************************************************************/
		Matrix<T> get_row(int index) {
			if (index<0 || index>=rows) {
				cerr<<"out of range!\n";
				exit(1);
			}
			Matrix<T> temp(1,cols,channels);
			for (int i=0;i<cols;i++) {
				for (int j=0;j<channels;j++) {
					temp(0,i,j) = data[index*cols*channels+i*channels+j];
				}
			}
			return temp;
		};

		/************************************************************************
		get rows
		*************************************************************************/
		Matrix<T> get_rows(int first,int last) {
			if (first<0 || first>=rows || last<0 || last>=rows || first>last) {
				cerr<<"out of range!\n";
				exit(1);
			}
			Matrix<T> temp(last-first+1,cols,channels);
			for (int t=0;t<last-first+1;t++) {
				for (int i=0;i<cols;i++) {
					for (int j=0;j<channels;j++) {
						temp(t,i,j) = data[(t+first)*cols*channels+i*channels+j];
					}
				}
			}
			return temp;
		};

		/************************************************************************
		get column
		*************************************************************************/
		Matrix<T> get_col(int index) {
			if (index<0 || index>=cols) {
				cerr<<"out of range!\n";
				exit(1);
			}
			Matrix<T> temp(rows,1,channels);
			for (int i=0;i<rows;i++) {
				for (int j=0;j<channels;j++) {
					temp(i,0,j) = data[i*cols*channels+index*channels+j];
				}
			}
			return temp;
		};

		/************************************************************************
		get columns
		*************************************************************************/
		Matrix<T> get_cols(int first,int last) {
			if (first<0 || first>=cols || last<0 || last>=cols || first>last) {
				cerr<<"out of range!\n";
				exit(1);
			}
			Matrix<T> temp(rows,last-first+1,channels);
			for (int t=0;t<rows;t++) {
				for (int i=0;i<last-first+1;i++) {
					for (int j=0;j<channels;j++) {
						temp(t,i,j) = data[t*cols*channels+(i+first)*channels+j];
					}
				}
			}
			return temp;
		};

		/************************************************************************
		get sub-matrix
		*************************************************************************/
		Matrix<T> submat(int first_row,int last_row,int first_col,int last_col,int first_channel,int last_channel) {
			if (first_row<0 || first_row>=rows ||
				last_row<0 || last_row>=rows || first_row>last_row ||
				first_col<0 || first_col>=cols ||
				last_col<0 || last_col>=cols || first_col>last_col ||
				first_channel<0 || first_channel>=channels ||
				last_channel<0 || last_channel>=channels || first_channel>last_channel) 
			{
				cerr<<"out of range!\n";
				exit(1);
			}
			Matrix<T> temp(last_row-first_row+1,last_col-first_col+1,last_channel-first_channel+1);
			for (int i=0;i<last_row-first_row+1;i++) {
				for (int j=0;j<last_col-first_col+1;j++) {
					for (int t=0;t<last_channel-first_channel+1;t++) {
						temp(i,j,t) = data[(i+first_row)*cols*channels+(j+first_col)*channels+t];
					}
				}
			}
			return temp;
		};

		/************************************************************************
		get struct information of matrix
		*************************************************************************/
		string info() {
			stringstream stream;
			string rows,cols,cha;
			stream<<rows;
			stream>>rows;
			stream.clear();
			stream<<cols;
			stream>>cols;
			stream.clear();
			stream<<channels;
			stream>>cha;
			stream.clear();
			string s = "elem type : ";
			s+=typeid(*data).name();
			s+="\nrows : ";
			s+=rows;
			s+="\ncols : ";
			s+=cols;
			s+="\nchannels : ";
			s+=cha;
			s+='\n';
			return s;
		};
	}; /* class Matrix */

	/************************************************************************
	Matrix tool function
	*************************************************************************/ 
	/************************************************************************
	whether matrix is square
	*************************************************************************/
	template <typename T>
	bool is_square (const Matrix<T>& src) {
		if (src.rows == src.cols)
			return true;
		else
			return false;
	};

	/************************************************************************
	whether matrix can mult
	*************************************************************************/
	template <typename T>
	bool can_mult(const Matrix<T>& mat1,const Matrix<T>& mat2) {
		if ((mat1.cols == mat2.rows) && (mat1.channels == mat2.channels))
			return true;
		else
			return false;
	};

	/************************************************************************
	whether two matrix are same
	regardless of element type
	*************************************************************************/
	template <typename T>
	bool mat_type_cmp (const Matrix<T>& mat1,const Matrix<T>& mat2) {
		if (mat1.channels != mat2.channels)
			return false;
		if (mat1.rows != mat2.rows)
			return false;
		if (mat1.cols != mat2.cols)
			return false;
		return true;
	};

	/************************************************************************
	whether the element types of two matrix are same
	*************************************************************************/
	template <typename T,typename P>
	bool mat_data_type_cmp (const Matrix<T>& mat1,const Matrix<P>& mat2) {
		if (typeid(*mat1.data) == typeid(*mat2.data))
			return true;
		return false;
	};

	/************************************************************************
	matrix transpose
	*************************************************************************/
	template <typename T>
	Matrix<T> transpose(Matrix<T>& src) {
		Matrix<T> temp(src.cols,src.rows,src.channels);
		cvTranspose(src.cvmat,temp.cvmat);
		return temp;
	};

	/************************************************************************
	invert matrix
	*************************************************************************/
	template <typename T>
	Matrix<T> invert(Matrix<T>& src,int method=CV_SVD) {
		if (!is_square(src)) {
			cerr<<"can not invert a non-squre matrix!\n";
			exit(1);
		}
		Matrix<T> temp(src);
		cvInvert(src.cvmat,temp.cvmat,method);
		return temp;
	};

	/************************************************************************
	matrix's det
	*************************************************************************/
	template <typename T>
	double det(Matrix<T>& src) {
		if (!is_square(src)) {
			cerr<<"con not get det from non-square matrix!\n";
			exit(1);
		}
		return cvDet(src.cvmat);
	};

	template <typename T>
	ostream& operator << (ostream& out,Matrix<T>& src) {
		stringstream stream;
		string data = "";
		for (int i=0; i < src.rows; i++) {
			out << "\t{";
			for (int j=0; j < src.cols; j++) {
				if (src.channels != 1)
					out << '{';
				for (int k=0;k < src.channels; k++) {
					stream.clear();
					stream << src.data[i * src.cols * src.channels+j * src.channels + k];
					stream >> data;
					out << data;
					if (k < src.channels - 1)
						out << ", ";
				}
				if (src.channels != 1)
					out << '}';
				if (j < src.cols - 1)
					out << ", ";
			}
			out << '}' << "\r\n";
		}
		return out;
	};

	template <typename T>
	void convertTo1DMatrix(Matrix<T>& src, vector<string>& matrix) {
		stringstream stream;
		string data = "";
		int index = 0;
		for (int i=0; i < src.rows; i++)
			for (int j=0; j < src.cols; j++) 
				for (int k=0;k < src.channels; k++) {
					stream.clear();
					stream << src.data[i * src.cols * src.channels+j * src.channels + k];
					stream >> data;
					matrix[index++] = data;
				}
	}

} /* namespace cvutMatrix */

#endif /* CVUT_MATRIX_H */