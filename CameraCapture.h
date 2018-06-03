#pragma once
#include<Windows.h>
#include"MVCAPI.h"
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>  
#include<opencv2\imgproc\imgproc.hpp>  
#include<iostream>  
using namespace cv;
#define  CAMNO 4
class CameraCapture
{
public:
	virtual BOOL OnInitialize();  //初始化
	BOOL Open();
	BOOL Close();
	//开启连续捕获
	BOOL Capture();
	BOOL CaptureImage(MVCFRAMEINFO lFrameInfo, BOOL l_bRaw);
	void getIndex(DWORD num);
	//回调函数
	static UINT WINAPI MStreamProc(WORD iDevNo, MVCFRAMEINFO m_FrameInfo, PVOID pUserData); //采集回调函数
	static DWORD WINAPI Processfunc(LPVOID lpData); //处理函数
	void  ReInitDisp();

public:
	BOOL			m_bColor;		//彩色相机标志
	BOOL			m_bDevopen;		//设备开启标志
	BOOL			m_bCapture;		//采集开启标志
	BOOL          m_bMatSaveOnce;           //采集Mat标志
	DWORD		m_iDevIndex;	//设备序号
	DWORD			m_iDevType;		//设备型号
	MVCGE_DEVLIST lInfo;  //设备信息
	DWORD			g_iTotalCaped;	//采集总帧数
	DWORD			g_iCapNumber;	//采集帧数
	DWORD			g_iDspNumber;	//显示帧数
	int				m_iImgBit;		//采集位深
	int				m_iImgWidth;	//采集宽度
	int				m_iImgHeight;	//采集高度
	BOOL         	m_bJumbo;  //巨帧开启标志
	BOOL			m_bHookData;	//数据处理标识
	PBYTE			m_pRAWData;		//原始图像Buffer
	PBYTE			m_pRAWDataEx;	//原始图像Buffer
	PBYTE			m_pRGBData;		//转换彩色Buffer
	MVCFRAMEINFO	RAWFrameInfo;	//原始图像结构体
	MVCFRAMEINFO	CVTFrameInfo;	//转换图像结构体
	HANDLE			hProcessThread;	//处理函数句柄
	HANDLE			hEventBuf;		//图像预备信号
	HANDLE			hEventEnd;		//处理退出信号
	BOOL m_bHookDisp;  //图像显示标志
	BOOL m_bBayer3x3; //T:使用Bayer3x3转换显示,F:普通Bayer转换
	HWND			m_Hwnd;			//单窗口句柄
	RECT			m_RectEx;		//主窗口矩形
	Mat              imgMat;      
	int saveTimes;
	char buffer_name[50];
	char buffer_name2[50];
};