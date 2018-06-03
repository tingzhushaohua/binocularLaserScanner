#ifndef CVUT_SEQ_H
#define CVUT_SEQ_H

#include "cv.h"
#include "highgui.h"
#include <string>
#include <iostream>

using namespace std;

namespace cvutSeq {
	/************************************************************************
		Seq
	*************************************************************************/
	template <typename T>
	class Seq {
		public:
			CvSeq* cvseq;
			CvMemStorage* storage;
			int is_sorted;
		public:
			/************************************************************************
			       constructor
			*************************************************************************/
			Seq(int seq_length = 0,int flag = 0) { 
				storage = cvCreateMemStorage(MAX(sizeof(T)*seq_length,1<<16));
				cvseq = cvCreateSeq(flag,sizeof(CvSeq),sizeof(T),storage);
				is_sorted=0;
			};
			Seq(Seq<T>& src) {
				cvReleaseMemStorage(&storage);
				cvseq = cvCloneSeq(src.cvseq,storage);
				is_sorted=0;
			};
			/************************************************************************
			       deconstructor
			*************************************************************************/
			~Seq(){
				cvReleaseMemStorage(&storage);
				cvseq = NULL;
			};
			/************************************************************************
			       access seq element
			*************************************************************************/
			T& operator [](int index){
				if (index<0 || index>=cvseq->total) {
					cout<<"seq access out of range!\n";
					exit(1);
				}
				return *(T*)cvGetSeqElem(cvseq,index);
			};
			/***********************************************************************
			       whether seq is empty
			***********************************************************************/
			bool empty() {
				return (cvseq->total == 0)?true:false;
			}
			/************************************************************************
			       get the length of the seq
			*************************************************************************/
			int length(){
				return cvseq->total;
			};
			/************************************************************************
			       remove all elements in the seq
			*************************************************************************/
			void clear(){
				cvClearSeq(cvseq);
			};
			/************************************************************************
			       add an element at rear
			*************************************************************************/
			void push_back(T elem){
				cvSeqPush(cvseq,(void*)&elem);
			};
			/************************************************************************
			       add some elements at rear
			*************************************************************************/
			void push_back(T* src = NULL,int num = 0) {
				if (src != NULL) {
					cvSeqPushMulti(cvseq,(void*)src,num);
				}
			};
			/************************************************************************
			       remove the last element in the seq
			*************************************************************************/
			bool pop_back(){
				if (cvseq->total <= 0) {
					cout<<"Seq is empty! fail to pop back!\n";
					return false;
				}
				cvSeqPop(cvseq);
				return true;
			};
			/************************************************************************
			       add an element at head
			*************************************************************************/
			void push_front(T elem) {
				cvSeqPushFront(cvseq,(void*)&elem);
			};
			/************************************************************************
			       remove an element at head
			*************************************************************************/
			bool pop_front() {
				if (cvseq->total <= 0) {
					cout<<"Seq is empty! fail to pop front!\n";
					return false;
				}
				cvSeqPopFront(cvseq,NULL);
				return true;
			};
			/************************************************************************
			       insert at any position in the seq
			*************************************************************************/
			bool insert(int index,T elem) {
				if (index<0 || index>=cvseq->total) {
					cout<<"out of range! fail to insert!\n";
					return false; 
				}
				cvSeqInsert(cvseq,index,(void*)&elem);
				return true;
			};
			/************************************************************************
			       remove an element at any position
			*************************************************************************/
			bool remove(int index) {
				if (cvseq->total < index+1) {
					cout<<"index out of range! fail to remove\n";
					return false;
				}
				cvSeqRemove(cvseq,index);
				return true;
			};
			/************************************************************************
			       invert the seq
			*************************************************************************/
			void reverse() {
				cvSeqInvert(cvseq);
			};
			/************************************************************************
				   sort seq
			*************************************************************************/
			static int cmp_func( const void* a, const void* b, void* userdata ) {
				return *(T*)a < *(T*)b ? -1 : *(T*)a > *(T*)b ? 1 : 0;
			};

			void sort() {
				cvSeqSort(cvseq,cmp_func);
				is_sorted=1;
			};
			/************************************************************************
			       search seq
			*************************************************************************/
			int find(T elem) {
				int index=-1;
				cvSeqSearch(cvseq,(void*)&elem,cmp_func,is_sorted,&index);
				return index;
			};
	}; /* class Seq */
	
	
	/************************************************************************
	       output seq
	*************************************************************************/
	template <typename T>
	ostream& operator << (ostream& out,Seq<T>& seq) {
		out<<'{';
		for (int i=0;i<seq.cvseq->total;i++) {
			out<<seq[i]<<' ';
		}
		out<<'}';
		return out;
	};
} /* namespace cvutSeq */

#endif /* CVUT_SEQ_H */