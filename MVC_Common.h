/////////////////////////////////////////////////////////////////////////////////////////////
//
//    Copyright (C) 2009-2014 Microview Science & Technology Co.,Ltd. All Rights Reserved.
//
//    Module:    MVC_Common.H
//
//    Abstract:  Header file for MVCAPI.DLL
//
//    Ver:       1.1.1.1
//
//    Date:      2011.11.28
//
//    Build:     2016.11.07
//
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MVCCOMMON_H_
#define _MVCCOMMON_H_

#define CY_RESULT_OK                     (0)
#define CY_RESULT_ABORTED                (1)
#define CY_RESULT_ARGUMENT_TOO_LONG      (2)
#define CY_RESULT_BAD_ADDRESS            (3)
#define CY_RESULT_BUFFER_TOO_SMALL       (4)
#define CY_RESULT_CANNOT_CREATE_EVENT    (5)
#define CY_RESULT_CANNOT_OPEN_FILE       (6)
#define CY_RESULT_CANNOT_SET_EVENT       (7)
#define CY_RESULT_CONSTRUCTOR_FAILED     (8)
#define CY_RESULT_CORRUPTED_FILE         (9)
#define CY_RESULT_D3D_ERROR              (10)
#define CY_RESULT_DD_ERROR               (11)
#define CY_RESULT_DEVICE_ERROR           (12)
#define CY_RESULT_DEVICE_RESET           (13)
#define CY_RESULT_DRIVER_ERROR           (14)
#define CY_RESULT_EMPTY_SEQUENCE         (15)
#define CY_RESULT_FILE_ERROR             (16)
#define CY_RESULT_INTERNAL_ERROR         (17)
#define CY_RESULT_INVALID_ARGUMENT       (18)
#define CY_RESULT_NETWORK_ERROR          (19)
#define CY_RESULT_NO_AVAILABLE_DATA      (20)
#define CY_RESULT_NO_MORE_ITEM           (21)
#define CY_RESULT_NO_SELECTED_ITEM       (22)
#define CY_RESULT_NOT_CONNECTED          (23)
#define CY_RESULT_NOT_ENOUGH_MEMORY      (24)
#define CY_RESULT_NOT_FOUND              (25)
#define CY_RESULT_NOT_SUPPORTED          (26)
#define CY_RESULT_OVERFLOW               (27)
#define CY_RESULT_STATE_ERROR            (28)
#define CY_RESULT_THREAD_ERROR           (29)
#define CY_RESULT_TIMEOUT                (30)
#define CY_RESULT_UNDERFLOW              (31)
#define CY_RESULT_UNEXPECTED_ERROR       (32)
#define CY_RESULT_UNEXPECTED_EXCEPTION   (33)
#define CY_RESULT_UNKNOWN_ERROR          (34)
#define CY_RESULT_UNSUPPORTED_CONVERSION (35)
#define CY_RESULT_OPERATION_PENDING      (36)
#define CY_RESULT_IMAGE_ERROR            (37)
#define CY_RESULT_CORRUPTED_IMAGE        (38)
#define CY_RESULT_MISSING_PACKETS        (39)
#define CY_RESULT_NETWORK_LINK_DOWN      (40)
#define CY_RESULT_MAX                    (41)
#define CY_RESULT_DEVICE_OPEN_ERROR      (100)
#define CY_RESULT_DEVICE_NO_OPEN         (101)
#define CY_RESULT_DEVICE_LOST            (102)
#define CY_RESULT_DEVICE_OPENED          (103)
#define CY_RESULT_OTHER_ERROR            (200)

typedef struct  _MVCGE_DEVLIST_
{
    char DevName[255];
    char DevIP[255];
    char DevMAC[255];
    char AdapterMAC[255];
    BOOL DevEnable;
}MVCGE_DEVLIST, *PMVCGE_DEVLIST;

typedef struct  _MVCGE_DEVLISTEX_
{
    char DevName[255];
    char DevIP[255];
    char DevMAC[255];
    char DevSerialNum[255];
    char DevSubnetMask[255];
    char DevGateway[255];
    char DevManufacturerName[255];
    char DevGigEVersion[255];
    char DevMultiCastAddress[255];  
    char AdapterInfo[255];
    char AdapterMAC[255];
    char AdapterIP[255];
    char AdapterSubnetMask[255];
    char AdapterGateway[255];
    unsigned long mDeviceType;
    BOOL DevEnable;
}MVCGE_DEVLISTEX, *PMVCGE_DEVLISTEX;

typedef struct  _MVCGE_COMMUNICATION_
{
    unsigned long AnswerTimeout;
    unsigned long CommandRetryCount;
    unsigned long PacketSize;
    unsigned long FirstPacketTimeout;
    unsigned long PacketTimeout;
    unsigned long RequestTimeout;
    unsigned long HeartbeatInterval;
    unsigned long HeartbeatTimeOut;
    unsigned long mDeviceWorkRole;
}
MVCGE_COMMUNICATION,*PMVCGE_COMMUNICATION;

typedef struct  _MVCGE_ADAPTERLIST_
{
    char DevIP[255];
    char DevMAC[255];
    char SubnetMask[255];
}MVCGE_ADAPTERLIST, *PMVCGE_ADAPTERLIST;

typedef struct  _MVCFRAMEINFO_
{
    unsigned long FRAMEID;
    unsigned long lBufSize;
    unsigned long Width;
    unsigned long Height;
    unsigned long PixelID;
    unsigned char *lBufPtr;
}MVCFRAMEINFO, *PMVCFRAMEINFO;

typedef struct  _MVCDEVSTATE_
{
    double CAP_FPS;
    double CAP_AVE_FPS;
    double DISP_FPS;
    double DISP_AVE_FPS;
    unsigned long CAP_ImageCount;
}MVCDEVSTATE, *PMVCDEVSTATE;

typedef struct  _MVCGE_SERIALCONFIG_
{
    BYTE SerialPort;
    BYTE BitPerSecond;
    BYTE DataBits;
    BYTE Parity;
    BYTE StopBits;
}MVCGE_SERIALCONFIG, *PMVCGE_SERIALCONFIG;

//A pulse generator 
typedef struct  _MVCGE_PULSEGENPARAM_
{
    DWORD PULSE_WIDTH;
    DWORD PULSE_DELAY;
    DWORD PULSE_GRANULARITY;
    BOOL  PULSE_PERIODIC;
    DWORD PULSE_TRIGGER_MODE;
}MVCGE_PULSEGENPARAM, *PMVCGE_PULSEGENPARAM;

typedef struct  _MVCGE_GPIOLUTPARAM_
{
    BYTE LUT_INPUT_I0_CONFIG;
    BYTE LUT_INPUT_I1_CONFIG;
    BYTE LUT_INPUT_I2_CONFIG;
    BYTE LUT_INPUT_I3_CONFIG;
    BYTE LUT_INPUT_I4_CONFIG;
    BYTE LUT_INPUT_I5_CONFIG;
    BYTE LUT_INPUT_I6_CONFIG;
    BYTE LUT_INPUT_I7_CONFIG;
}MVCGE_GPIOLUTPARAM, *PMVCGE_GPIOLUTPARAM;

typedef struct  _MVCGE_COUNTERPARAM_
{
    BYTE COUNTER_INCMODE;
    BYTE COUNTER_DECMODE;
    BYTE COUNTER_CLRMODE;
    BYTE COUNTER_CLRSIGN;
    UINT COUNTER_CMPNUMB;
}MVCGE_COUNTERPARAM, *PMVCGE_COUNTERPARAM;

enum LINE_TRIGMODE
{
    LINE_TGMODE0    = 0x0,
    LINE_TGMODE1    = 0x1,
    LINE_TGMODE2    = 0x2,
    LINE_TGMODE3    = 0x3,
    LINE_TGMODE4    = 0x4,
};

typedef struct  _MVCGE_LINESCAN_PULSEGENPARAM_
{
    DWORD PULSE_DELAY0;
    DWORD PULSE_WIDTH;
    DWORD PULSE_DELAY;
    DWORD VIRTUAL_FRAME_HEIGHT;
    BOOL PULSE_ENABLE;
    LINE_TRIGMODE LINE_TRIGGER_MODE;
}MVCGE_LINESCAN_PULSEGENPARAM, *PMVCGE_LINESCAN_PULSEGENPARAM;

enum DEVICE_INFO
{
    DEVICE_IP        = 0,
    DEVICE_NAME      = 1
};

enum GRAPHMODE
{
    GRAPH_STRING    = 0,
    GRAPH_LINE      = 1,
    GRAPH_CIRCLE    = 2
};

enum FILE_FORMT
{
    FILE_BMP        = 0,
    FILE_RAW        = 1,
    FILE_JPG        = 2
};

enum MVC_TYPE
{
    //Old Series
    MVC300SAM_GE100        = 64,
    MVC300SAM_GE50         = 65,
    MVC300SAC_GE200        = 60,
    MVC300SAM_GE200        = 61,
    
    MVC360SAM_GE60         = 62,
    MVC360SAC_GE60         = 63,
    MVC360SAM_GE60_MINI    = 124,
    
    MVC1000SAC_GE30        = 20,
    MVC1000SAM_GE30        = 21,

    MVC1280SAC_GE30        = 10,
    MVC1280SAM_GE30        = 11,
    MVC1280SANR_GE30       = 12,
    
    MVC2000SAC_GE20        = 30,
    MVC3000SAC_GE12        = 40,
    MVC5000SAC_GE12        = 41,
    MVC5001SAC_GE14        = 52,
    MVC5001SAM_GE14        = 53,
    MVC6600SAC_GE5         = 50,
    MVC6600SAM_GE5         = 51,

    //CVT Series
    MVCL2GE_B              = 70,
    MVLV2GE_S              = 71,
    MVDIG2GE_S             = 72,

    //ST Series
    MVC360SAM_GE60ST       = 118,
    MVC360SAC_GE60ST       = 119,
    MVC360SAM_GE60ST3      = 121,
    MVC360SAC_GE60ST3      = 122,
    MVC360SAM_GE60ST4      = 127,
    MVC360SAC_GE60ST4      = 128,

    MVC1000SAC_GE30ST      = 112,
    MVC1000SAM_GE30ST      = 113,
    MVC1000SAM_GE30ST3     = 123,
    MVC1000SAM_GE30ST4     = 129,
    MVC1000SAC_GE30ST4     = 130,

    MVC2000SAC_GE20ST      = 114,
    MVC2000SAC_GE20ST4     = 131,

    MVC3000SAC_GE12ST      = 115,
    MVC3000SAC_GE12ST4     = 132,

    MVCSDV_GEST4           = 209,
    MVCCL_GEST4            = 213,
    MVCCL_GEST2_N          = 223,
    MVCPOCL_GEST2_N        = 226,
    MVCPOCL_GEST4_N        = 229,

    MVC360SAM_GE60ST2      = 133,
    MVC360SAC_GE60ST2      = 134,
    MVC360SAM_GE60ST2_N    = 216,
    MVC360SAC_GE60ST2_N    = 217,
    MVC360SAM_GE60ST4_N    = 211,
    MVC360SAC_GE60ST4_N    = 212,
    MVC360SAM_GE60ST8_N    = 241,
    MVC360SAM_GE60ST6_N    = 242,

    MVC1000SAM_GE30ST2     = 135,
    MVC1000SAM_GE30ST2_N   = 218,
    MVC1001SAM_GE30ST2_N   = 230,
    MVC1000SAC_GE30ST2_N   = 220,
    MVC1000SAM_GE20ST4_N   = 224,

    MVC3000SAC_GE8ST4_N    = 225,
    MVC3000SAC_GE12ST2_N   = 219,

    //Line Scan Series
    MVC512DLM_GE60         = 210,
    MVC512DLM_CL60         = 303,

    MVC1024DLM_GE35        = 205,
    MVC1024DLM_CL35        = 302,

    MVC2048DLM_GE15        = 90,
    MVC2048DLM_GE19        = 111,
    MVC2048DLM_CL19        = 301,

    MVC2113DLC_GE9         = 231,
    MVC2113DLC_CL9         = 304,
    MVC4096SLM_GE18        = 306,
    MVC4000SLM_GE29        = 307,
    MVC2049SLM_GE32        = 308,
    MVC2000SLM_GE55        = 309,
    MVC8000SLM_GE12        = 310,

    //CCD Series
    MVC380DAM_GE60         = 208,
    MVC380DAC_GE60         = 207,

    MVC600DAM_GE60         = 102,
    MVC600DAC_GE60         = 117,
    MVC600DAS_GE60         = 126,

    MVC610DAM_GE110        = 92,
    MVC610DAC_GE110        = 91,
    MVC610DAS_GE110        = 136,

    MVC680DAM_GE60         = 110,
    MVC680DAM_GE60_12      = 96,
    MVC680DAC_GE60         = 85,
    MVC680DAS_GE60         = 125,

    MVC685DAM_GE110        = 94,
    MVC685DAC_GE110        = 79,
    MVC685DAS_GE110        = 106,

    MVC800DAM_GE45         = 83,
    MVC800DAM_GE25         = 137,
    MVC800DAC_GE45         = 104,

    MVC900DAM_GE15         = 84,
    MVC900DAM_GE30         = 101,
    MVC900DAC_GE15         = 81,
    MVC900DAC_GE30         = 97,
    MVC900DAS_GE15         = 116,

    MVC930DAM_GE25         = 78,
    MVC930DAM_GE30         = 80,
    MVC930DAC_GE30         = 105,
    MVC930DAM_GE30_12      = 89,

    MVC1000DAM_GE1000      = 109,

    MVC1450DAM_GE15        = 201,
    MVC1450DAC_GE15        = 200,

    MVC1800DAM_GE15        = 87,
    MVC1800DAM_GE30        = 108,
    MVC1800DAC_GE15        = 82,
    MVC1800DAC_GE30        = 99,
    MVC1800DAS_GE15        = 107,

    MVC1830DAM_GE30        = 103,
    MVC1830DAM_GE30_12     = 86,
    MVC1830DAC_GE30        = 98,
    MVC1830DAC_GE30_12     = 120,
    MVC1830DAS_GE30        = 100,
    MVC1830DAS_GE30_12     = 88,
    
    MVC2000DAC_GE16        = 93,
    MVC2000DAM_GE16        = 95,
    
    MVC2010DAM_GE12        = 206,
    MVC2010DAC_GE12        = 204,
    MVC2010DAC_GE6         = 215,

    MVC2011DAM_GE15_N      = 227,
    MVC2011DAC_GE15_N      = 228,

    MVC2900DAC_GE15        = 202,
    MVC2900DAM_GE15        = 203,
    MVC2900DAC_GE8         = 214,
    MVC2903DAM_GE12        = 901,

    //CIS Series
    VCC_F60FV19_GE15       = 401,
    VCC_F60FU29_GE26       = 402,
    VCC_G60FV11_GE15       = 403,
    VCC_G60U21_GE30        = 404,

    //CMOS Series
    MVC361SAM_GE60_N       = 221,
    MVC361SAC_GE60_N       = 222,

    MVC500SAM_GE60_N       = 531,
    MVC500SAC_GE60_N       = 532,

    MVC660SAM_GE120_N      = 571,

    MVC1300SAM_GE60_N      = 501,
    MVC1300SAC_GE60_N      = 502,
    MVC1300SAM_GE30        = 503,
    MVC1300SAC_GE30        = 504,
    MVC1300SAC_GE60        = 515,
    MVC1301SAM_GE60_N      = 514,
    MVC1310SAM_GE60        = 510,
    MVC1320SAC_GE60        = 511,
    MVC1330SAM_GE60        = 507,
    MVC1330SAC_GE60        = 508,
    MVC1340SAM_GE60_N      = 512,
    MVC1340SAC_GE60_N      = 513,
    MVC1340SAM_GE60        = 506,
    MVC1370SAM_GE30        = 509,
    MVC1371SAM_GE30        = 505,
    MVC1300SAM_GE60        = 516,

    MVC1400SAM_GE60_N      = 541,
    MVC1400SAC_GE60_N      = 542,
    MVC1400SANR_GE60_N     = 552,
    MVC1400SAV_GE60_N      = 553,
    MVC1410SAM_GE60        = 543,
    MVC1440SAM_GE60        = 531,
    MVC1450SAM_GE60_N      = 582,
    MVC1450SAC_GE60_N      = 533,
    MVC1470SAM_GE30        = 550,
    MVC1471SAM_GE30        = 551,
    MVC1472SAM_GE60        = 305,
    MVC1480SAM_GE60_N      = 537,
    MVC1480SAC_GE60_N      = 538,

    MVC1500SAM_GE60_N      = 561,
    MVC1500SAC_GE60_N      = 562,
    MVC1500SANR_GE60_N     = 563,
    MVC1500SANR_GE6_N      = 564,
    MVC1500SAV_GE60_N      = 565,
    MVC1510SAM_GE60        = 568,
    MVC1531SAM_GE60        = 569,
    MVC1531SAC_GE60        = 570,
    MVC1550SAM_GE60_N      = 581,
    MVC1550SAC_GE60_N      = 572,
    MVC1570SAM_GE30        = 573,
    MVC1571SAM_GE30        = 574,
    MVC1580SAM_GE60_N      = 575,
    MVC1580SAC_GE60_N      = 576,

    MVC2300SAM_GE50_N      = 591,
    MVC2300SAC_GE50_N      = 592,
    MVC2300SAM_GE50        = 593,
    MVC2300SAC_GE50        = 594,

    MVC10KSAC_GE7_N        = 601,
    MVC10KSAM_GE7_N        = 602,
    MVC1200SAM_GE45_N      = 611,
    MVC1200SAC_GE45_N      = 612,
    MVC14KSAC_GE6_N        = 603,
    MVC14KSAM_GE6_N        = 604,

    //ROSA Series
    RS_A1300_GM60          = 701,
    RS_A1300_GC60          = 702,
    RS_A2300_GM50          = 703,
    RS_A2300_GC50          = 704,
    RS_A5001_GM14          = 705,
    RS_A5001_GC14          = 706,
    RS_A1400_GM60          = 707,
    RS_A1400_GC60          = 708,
    RS_A2001_GM60          = 709,
    RS_A1500_GM60          = 710,
    RS_A1000_GM30          = 711,
    RS_A3000_GC12          = 712,
    RS_A361_GM60           = 713,
    RS_A361_GC60           = 714,
    RS_A10K_GM7            = 715,
    RS_A10K_GC7            = 716,
    RS_A14K_GC8            = 717,
    RS_A1200_GM45          = 718,
    RS_A1200_GC45          = 719,
    RS_A2300_GM60          = 720,
    RS_A2300_GC60          = 721,
    RS_A361_GM100          = 722,
    RS_A361_GC100          = 723,
    RS_A363_GM150          = 724,
    RS_A363_GC150          = 725,
    RS_A1003_GM50          = 726,
    RS_A1003_GC50          = 727,
    RS_A370_GM55           = 728,
    RS_A12K_GM8            = 729,
    RS_A12K_GC8            = 730,

    //HAWK Series
    HK_A5100_GM17          = 801,
    HK_A5100_GC17          = 802,
    HK_A2101_GM50          = 803,
    HK_A2101_GC50          = 804,
    HK_A2400_GM30          = 810,
    HK_A2400_GC30          = 811,

	//CHAMELEON Series
    CM_A1003_GM50          = 921,
    CM_A1003_GC50          = 922,
};

enum DUALTAPOUTPUTMODE_TYPE
{
    TAP2_INTERLEAVED               = 0,
    TAP2_SEGMENTED                 = 1,
    TAP2_SEGMENTED_RIGHTINVERTED   = 2,
    TAP2_SEGMENTED_LEFTINVERTED    = 3,
    TAP2_SEGMENTED_INVERTED        = 4
};

enum BYAERCOLOR_TYPE
{
    GBRG                        = 0,
    GRBG                        = 1,
    RGGB                        = 2,
    BGGR                        = 3,
    MONO                        = 4
};

enum DISPCOLORFMT
{
    DISP_Y8                     = 0,
    DISP_RGB15                  = 1,
    DISP_RGB16                  = 2,
    DISP_RGB24                  = 3,
    DISP_RGB32                  = 4,
    DISP_YUYV                   = 5,
    DISP_UYVY                   = 6,
    DISP_YV12                   = 7
};

enum DISPMethod 
{
    DISP_OFFSCREEN              = 0,
    DISP_OVERLAY                = 1,
    DISP_GDIFUNCTION            = 2,
    DISP_AUTO                   = 3
};

enum PIXEL_BITMODE 
{
    PIXEL_BIT10                 = 0,
    PIXEL_BIT10_H8              = 1,
    PIXEL_BIT8                  = 2,
    PIXEL_BIT12                 = 3,
    PIXEL_BIT12_H10             = 4,
    PIXEL_BIT12_H8              = 5,
    PIXEL_BIT14                 = 6,
    PIXEL_BIT14_H12             = 7,
    PIXEL_BIT14_H10             = 8,
    PIXEL_BIT14_H8              = 9,
    PIXEL_BIT16                 = 10,
    PIXEL_BIT16_H14             = 11,
    PIXEL_BIT16_H12             = 12,
    PIXEL_BIT16_H10             = 13,
};

enum COLOR_MODE
{
    OTHERMODE                   = 0,
    RGB24                       = 1,
    BGR24                       = 2
};

enum LUT_MODE
{
    LUT_Bit8To8                 = 1,
    LUT_Bit10To8                = 2,
    LUT_Bit12To8                = 3,
    LUT_Bit14To8                = 4,
};

enum LF_TRIGGER_IN_LUT
{
    TTL_IN0                     = 0x0001,
    TTL_IN1                     = 0x0002,
    LVDS_IN0                    = 0x0004,
    LVDS_IN1                    = 0x0008,
    OPTO_IN0                    = 0x0010,
    OPTO_IN1                    = 0x0020,
    RS422_IN0                   = 0x0040,
    RS422_IN1                   = 0x0080,
    RS422_IN2                   = 0x0100,
    RS422_IN3                   = 0x0200,
    FRAME_VALID                 = 0x0400,
    LINE_VALID                  = 0x0800,
    DATA_VALID                  = 0x1000,
    SW_VBOUT2                   = 0x2000,
    REVERSE_FLAG                = 0x8000,
};

enum PG_WORKMODE
{
    PG_MODE0                    = 0x0,
    PG_MODE1                    = 0x1,
    PG_MODE2                    = 0x2,
    PG_MODE3                    = 0x3,
    PG_MODE4                    = 0x4,
    PG_MODE5                    = 0x5,
};

typedef struct  _MVCGE_QUAD_PULSEGENPARAM_
{
    DWORD PULSE_DELAY0;
    DWORD PULSE_WIDTH;
    DWORD PULSE_DELAY;
    DWORD VIRTUAL_FRAME_HEIGHT;
    BOOL PULSE_ENABLE;
    PG_WORKMODE PULSE_WORK_MODE;
    LINE_TRIGMODE LINE_TRIGGER_MODE;
    LF_TRIGGER_IN_LUT LINE_TRIGGER_LUT_IN;
    LF_TRIGGER_IN_LUT FRAME_TRIGGER_LUT_IN;
}MVCGE_QUAD_PULSEGENPARAM, *PMVCGE_QUAD_PULSEGENPARAM;

enum TRIGGER_OUT_LUT
{
    CHANNELA_TTL_IN0            = 0x00000001,
    CHANNELA_TTL_IN1            = 0x00000002,
    CHANNELA_LVDS_IN0           = 0x00000004,
    CHANNELA_LVDS_IN1           = 0x00000008,
    CHANNELA_OPTO_IN0           = 0x00000010,
    CHANNELA_OPTO_IN1           = 0x00000020,
    CHANNELA_422_IN0            = 0x00000040,
    CHANNELA_422_IN1            = 0x00000080,
    CHANNELA_422_IN2            = 0x00000100,
    CHANNELA_422_IN3            = 0x00000200,
    CHANNELA_PG0                = 0x00000400,
    CHANNELA_PG1                = 0x00000800,
    CHANNELA_PG2                = 0x00001000,
    CHANNELA_PG3                = 0x00002000,
    CHANNELB_CC1                = 0x00004000,
    CHANNELB_CC2                = 0x00008000,
    CHANNELC_CC1                = 0x00010000,
    CHANNELC_CC2                = 0x00020000,
    CHANNELD_CC1                = 0x00040000,
    CHANNELD_CC2                = 0x00080000,
    CHANNELSW_VBOUT2            = 0x00100000,
    CHREVERSE_FLAG              = 0x80000000,
};

typedef struct  _MVCGE_QUAD_LUTOUT_
{
    TRIGGER_OUT_LUT CHANNELA_CC1;
    TRIGGER_OUT_LUT CHANNELA_CC2;
    TRIGGER_OUT_LUT CHANNELA_CC3;
    TRIGGER_OUT_LUT CHANNELA_CC4;
    TRIGGER_OUT_LUT TTL_OUT0;
    TRIGGER_OUT_LUT TTL_OUT1;
    TRIGGER_OUT_LUT LVDS_OUT0;
    TRIGGER_OUT_LUT LVDS_OUT1;
    TRIGGER_OUT_LUT OPTO_OUT0;
    TRIGGER_OUT_LUT OPTO_OUT1;
    TRIGGER_OUT_LUT SW_VBIN3;
}MVCGE_QUAD_LUTOUT, *PMVCGE_QUAD_LUTOUT;

enum MVC_PARAMTER
{ 
    //Image Grabber Param
    MVCADJ_WIDTH                 = 0,
    MVCADJ_HEIGHT                = 1,
    MVCADJ_XOFFSET               = 2,
    MVCADJ_YOFFSET               = 3,
    MVCADJ_BITMODE               = 14,
    MVCADJ_UNDEFINED_WIDTH       = 8,
    MVCADJ_UNDEFINED_HEIGHT      = 9,
    MVCADJ_COLORMODE             = 100,
    MVCADJ_PIXELCONVERT          = 101,
    MVCADJ_RGBMODE               = 102,
    MVCADJ_PIXFORMAT             = 110,
    MVCADJ_PIXPACKED             = 111,
    
    //Camera Param 
    MVCADJ_XBINNING              = 4,
    MVCADJ_YBINNING              = 5,
    MVCADJ_SHUTTERTYPE           = 6,
    MVCADJ_SNAPSHUTTER           = 7,
    MVCADJ_GAMMA                 = 10,
    MVCADJ_DACGAIN               = 11,
    MVCADJ_OUTGAIN               = 12,
    MVCADJ_INTTIME               = 13,
    MVCADJ_INTNUM                = 15,
    MVCADJ_REDGAIN               = 16,
    MVCADJ_GREENGAIN             = 17,
    MVCADJ_BLUEGAIN              = 18,
    MVCADJ_REDOFFSET             = 77,
    MVCADJ_GREENOFFSET           = 78,
    MVCADJ_BLUEOFFSET            = 79,
    MVCADJ_OFFSET                = 19,
    MVCADJ_MASTER                = 20,
    MVCADJ_MIRROR                = 30,
    MVCADJ_COLFLIP               = 34,
    MVCADJ_AUTOAGC               = 35,
    MVCADJ_AUTOAEC               = 36,
    MVCADJ_DATAPORT              = 37,
    MVCADJ_BITLUT                = 38,

    //Trigger Flash Param
    MVCADJ_TRIGPICNUM            = 21,
    MVCADJ_TRIGGERDELAY          = 22,
    MVCADJ_PULSEWIDTH            = 23,
    MVCADJ_FLASHDELAY            = 24,
    MVCADJ_FLASHWIDTH            = 25,
    MVCADJ_SOFTTRIGGER           = 26,
    MVCADJ_STROBEOUT             = 27,
    MVCADJ_TRIGGER_DELAY         = 28,
    MVCADJ_TRIGGER_PLUSEWIDTH    = 29,
    MVCADJ_FLASH_POLARITY        = 608,
    MVCADJ_TRIGGER_POLARITY      = 609,
    MVCADJ_TRIGGER_SOURCE        = 610,
    MVCADJ_FLASH_SOURCE          = 611,
    MVCL_QUAD_DEBOUNCER          = 700,

    //Device Special Param
    MVCADJ_FRAMERATEMODE         = 606,
    MVCADJ_AUOTIRIS1             = 612,
    MVCADJ_AUOTIRIS2             = 613,
    MVCADJ_RPTRIGERDELAY         = 615,
    MVCADJ_SPECIFICFLASH         = 616,
    MVCADJ_BOARDPASS             = 600,
    MVCDEV_CONNECTSTATE          = 607,
    MVCDEV_BUSYSTATE             = 630,
    MVCGET_FIRMWAREVER           = 701,
    MVCGET_ISCAPTURE             = 702,
    MVCGET_ISHOOKCAP             = 703,
    MVCADJ_AUTOINTERNALRETRIGGER = 731,
    MVCADJ_INTERPACKETDELAY      = 509,
    MVCADJ_SHOWCONFIGDIALOG      = 510,
    MVCADJ_SHOWSERIALDIALOG      = 900,
	MVCADJ_MESSAGEHWND           = 555,

    //Long Time Integration Param
    MVCADJ_LT_INT_DELAY          = 31,
    MVCADJ_LT_INT_MODE           = 32,
    MVCADJ_LT_INT_TIME           = 33,

    //MVC1450/2900/2010 Special Param
    MVCADJ_CCD_CLAMPLEVEL        = 41,
    MVCADJ_CCD_CDSGAIN           = 42,

    //Param Save Load
    MVCADJ_LOADDEFAULT           = 50,
    MVCADJ_SAVEDEFAULT           = 51,
    MVCADJ_POWERON_LOAD          = 53,

    //MVC2048 Camera Special Param
    MVCADJ_LINETIME              = 52,
    MVCADJ_LINETRIGGER_DIVIDER   = 54,
    MVCADJ_FFC_STATUS            = 55,
    MVCADJ_FFC_PARAM_SAVE        = 56,
    MVCADJ_FFC_PARAM_LOAD        = 57,

    //MVC2113DLC Camera Special Param
    MVCADJ_SPATIAL_CORRECTION_R  = 80,
    MVCADJ_SPATIAL_CORRECTION_G  = 81,
    MVCADJ_SPATIAL_CORRECTION_B  = 82,
    MVCADJ_SPATIAL_CORRECTION_EN = 83,
    MVCADJ_COLOR_CORRECTION_R1   = 84,
    MVCADJ_COLOR_CORRECTION_R2   = 85,
    MVCADJ_COLOR_CORRECTION_R3   = 86,
    MVCADJ_COLOR_CORRECTION_G1   = 87,
    MVCADJ_COLOR_CORRECTION_G2   = 88,
    MVCADJ_COLOR_CORRECTION_G3   = 89,
    MVCADJ_COLOR_CORRECTION_B1   = 90,
    MVCADJ_COLOR_CORRECTION_B2   = 91,
    MVCADJ_COLOR_CORRECTION_B3   = 92,
    MVCADJ_COLOR_CORRECTION_RP   = 950,
    MVCADJ_COLOR_CORRECTION_GP   = 951,
    MVCADJ_COLOR_CORRECTION_BP   = 952,
    MVCADJ_COLOR_CORRECTION_EN   = 93,
    MVCADJ_AWB_RATIOR            = 94,
    MVCADJ_AWB_RATIOG            = 95,
    MVCADJ_AWB_RATIOB            = 96,
    MVCADJ_AWB_DONE              = 97,

    //WatchDog
    MVCADJ_WATCHDOGENABLE        = 60,
    MVCADJ_WATCHDOGDISABLE       = 61,

    //Sensor Width/Height/Offset
    MVCADJ_SENSORWIDTH           = 70,
    MVCADJ_SENSORHEIGHT          = 71,
    MVCADJ_SENSORXOFFSET         = 72,
    MVCADJ_SENSORYOFFSET         = 73,
    MVCADJ_SENSORRESET           = 74,

    //Motor
    MVCADJ_IRISPOSITIONENABLE    = 240,
	MVCADJ_IRISPOSITION          = 241,
    MVCADJ_FOCUSPOSITIONENABLE   = 242,
    MVCADJ_FOCUSPOSITION         = 243,

    //Inner Display Param
    MVCDISP_POSX                 = 201,
    MVCDISP_POSY                 = 202,
    MVCDISP_WIDTH                = 203,
    MVCDISP_HEIGHT               = 204,
    MVCDISP_ISDISP               = 205,
    MVCDISP_HWND                 = 206,
    MVCDISP_RGBMODE              = 207,
    MVCDISP_MEMMODE              = 208,
    MVCDISP_VSYNC                = 209,

    //Capture Param
    MVCCAP_BUFQUEUESIZE          = 300,
    MVCCAP_RGBMODE               = 301,
    MVCCAP_FRAMESKIP             = 306,
    MVCCAP_PIPECOUNT             = 307,
    MVCCAP_DECIMATION_X          = 320,
    MVCCAP_DECIMATION_Y          = 321,
    MVCCAP_DECIMATION_BLOCK_X    = 322,
    MVCCAP_DECIMATION_BLOCK_Y    = 323,
    MVCCAP_BANDWIDTH             = 327,
    MVCCAP_LOSTPACKET            = 328,
    MVCCAP_RESEND                = 329,
    MVCCAP_IMGOUTMODE            = 330,
    MVCCAP_GRABMODE              = 932,
    MVCCAP_AUTORESET             = 945,
    MVCCAP_TIMEOUTLIMIT          = 946,
    MVCCAP_RESETBUFFER           = 947,
    MVCCAP_FORCEMISSING          = 948,

    //Soft White Balance Param
    MVCCAP_REDGAIN               = 303,
    MVCCAP_GREENGAIN             = 304,
    MVCCAP_BLUEGAIN              = 305,
    MVCCAP_REDOFFSET             = 333,
    MVCCAP_GREENOFFSET           = 334,
    MVCCAP_BLUEOFFSET            = 335,

    //Soft Bright/Contrast Param
    MVCCAP_SBRIGHTNESS           = 310,
    MVCCAP_SCONTRAST             = 311,

    //Traffic Control
    MVCCAP_ENSPEED               = 400,
    MVCCAP_EMSPEEDMIN            = 401,
    MVCCAP_EMSPEEDMAX            = 402,
    MVCCAP_EMSPEEDDIST           = 403,
    MVCCAP_ENTEMP                = 411,
    MVCCAP_ENLIGHT               = 412,
    MVCCAP_ENFRAMENO             = 413,
    MVCCAP_ENBRIGHT              = 414,
    MVCCAP_ENAREA                = 420,
    MVCCAP_EMAREAHSTART          = 421,
    MVCCAP_EMAREAHEND            = 422,
    MVCCAP_EMAREAVSTART          = 423,
    MVCCAP_EMAREAVEND            = 424,
    MVCCAP_WISHBRIGHTMIN         = 430,
    MVCCAP_WISHBRIGHTMAX         = 431,
    MVCCAP_AECMIN                = 432,
    MVCCAP_AECMAX                = 433,
    MVCCAP_AGCMIN                = 434,
    MVCCAP_AGCMAX                = 435,

    //CameraLink Param
    MVCL_CAMTYPE                 = 500,
    MVCL_DATAVALID_ENABLE        = 501,
    MVCL_DATAVALID_POLARITY      = 502,
    MVCL_LINEVALID_POLARITY      = 503,
    MVCL_FRAMEVALID_POLARITY     = 504,
    MVCL_LINEVALID_EDGE          = 505,
    MVCL_FRAMEVALID_EDGE         = 506,
    MVCL_FRAMEVALID_SELECT       = 507,
    MVCL_LINEVALID_SELECT        = 508,
    MVCL_CLOCKPRESENT            = 511,
    MVCL_TAP_QUANTITY            = 512,
    MVCL_FVAL_FUNCTION_SELECT    = 513,
    MVCL_LVAL_FUNCTION_SELECT    = 514,
    MVCL_TAP_OUTPUTMODE          = 515,
    MVCL_SERIAL_INTERVAL         = 516,
    MVCL_SERIAL_TIMEOUT          = 517,
    MVCL_SERIAL_RETRYCOUNT       = 518,

    //MVC360 HDR Param
    MVCADJ_EN_HIGH_DY_RANGE      = 601,
    MVCADJ_HIGH_DY_RANGEV1       = 602,
    MVCADJ_HIGH_DY_RANGEV2       = 603,
    MVCADJ_HIGH_DY_RANGEV3       = 604,
    MVCADJ_HIGH_DY_RANGEV4       = 605,

    //Line Scan Camera Param
    MVCADJ_VIRTUALFRAMEHEIGHT    = 617,
    MVCADJ_EXPOSUREMODE          = 618,
    MVCADJ_FRAMETRIGGER_POLARITY = 619,
    MVCADJ_DTPIXELDISCREPANCY    = 620,
    MVCADJ_DTIMAGEBKMEAN         = 621,
    MVCADJ_DTTHRESHOLD           = 622,
    MVCADJ_DTSKIPHEIGHT          = 623,
    MVCADJ_LEDCONTROL            = 624,
    
    //Multi Converter Internal Signal
    MVCADJ_CONCAMNUM             = 39,
    MVCADJ_SELECTCAM             = 40,
    MVCADJ_CAMERASYNC            = 614,
    MVCADJ_HWIDTHMEM             = 308,
    MVCADJ_VHEIGHTMEM            = 309,
    MVCADJ_HOFFSETMEM            = 802,
    MVCADJ_VOFFSETMEM            = 803,
    MVCADJ_TRIGPICFPS            = 901,
    MVCADJ_INTERPULSEFREQ        = 902,
    MVCADJ_FRAMEINTERVAL         = 800,
    MVCADJ_TRIGGER_MODESELECT    = 801,
    MVCCON_TIMESTAMPCLEAR        = 324,
    MVCCON_TIMESTAMPMODE         = 325,
    MVCCON_TIMESTAMPPARAM        = 326,

    //MVC1300 Param
    MVCADJ_HDR                   = 903,
    MVCADJ_BLACKLEVEL            = 904,
    MVCADJ_FPSMAX                = 906,
    MVCADJ_XSUBSAMPLING          = 907,
    MVCADJ_YSUBSAMPLING          = 908,
    MVCADJ_SHUTTERMODE           = 909,
    MVCADJ_BLACKOFFSET           = 910,
    MVCADJ_MODESELECT            = 911,
    MVCADJ_FPSMAXENABLE          = 912,
    MVCADJ_LINEBLANK             = 913,

    //MVC1200/10K/14K Param
    MVCADJ_NOISEREMOVE           = 905,

    //ROSA Param
    MVCCAP_TEMPERATURE           = 921,
    MVCCAP_SHARPNESS             = 922,
    MVCCAP_DENOISING             = 923,
    MVCCAP_ENHANCEENABLE         = 938,
    MVCCAP_HUEENHANCE            = 939,
    MVCCAP_COLORENHANCE          = 924,
    MVCCAP_AWBPOSSTARTX          = 925,
    MVCCAP_AWBPOSSTARTY          = 926,
    MVCCAP_AWBPOSENDX            = 927,
    MVCCAP_AWBPOSENDY            = 928,
    MVCCAP_AWBONCE               = 929,
    MVCCAP_AWBRESET              = 937,
    MVCCAP_AWBRATIOBG            = 942,
    MVCCAP_AWBRATIORG            = 943,
    MVCCAP_AWBMODE               = 977,
    MVCCAP_IMAGEDATA             = 930,
    MVCCAP_BAYERMODE             = 931,
    MVCCAP_IOUNIT                = 933,
    MVCCAP_USEROUTSELECT         = 934,
    MVCCAP_USEROUTENABLE         = 935,
    MVCCAP_USEROUTINVERT         = 936,
    MVCCAP_GAMMAENABLE           = 940,
    MVCCAP_GAMMARAW              = 941,
    MVCCAP_EXPOSURETIME          = 944,
    MVCCAP_TESTPATTERN           = 945,
    MVCCAP_CCMENABLE             = 949,
    MVCCAP_CCMG00                = 950,
    MVCCAP_CCMG01                = 951,
    MVCCAP_CCMG02                = 952,
    MVCCAP_CCMG10                = 953,
    MVCCAP_CCMG11                = 954,
    MVCCAP_CCMG12                = 955,
    MVCCAP_CCMG20                = 956,
    MVCCAP_CCMG21                = 957,
    MVCCAP_CCMG22                = 958,
    MVCCAP_CCMRPLUS              = 959,
    MVCCAP_CCMGPLUS              = 960,
    MVCCAP_CCMBPLUS              = 961,
    MVCCAP_LUTENABLE             = 962,
    MVCCAP_LUTSELECT             = 963,
    MVCCAP_LUTLOAD               = 964,
    MVCCAP_LUTSAVE               = 965,
    MVCCAP_LUTRESET              = 966,
    MVCCAP_LUTINDEX              = 967,
    MVCCAP_LUTVALUE              = 968,
    MVCCAP_ADLIMITENABLE         = 969,
    MVCCAP_ADLIMITHIGH           = 970,
    MVCCAP_ADLIMITLOW            = 971,
    MVCCAP_ADKNEEPOINT           = 972,
    MVCCAP_AEENABLE              = 980,
    MVCCAP_AEONCE                = 981,
    MVCCAP_AESKIPNUM             = 982,

    //HAWK Param
    MVCADJ_PIXSOURCE             = 983,
    MVCADJ_OUTPUTMODE            = 984,
    MVCADJ_FRAMEBLANK            = 985,
    MVCADJ_DSNUENABLE            = 986,
    MVCADJ_PRNUENABLE            = 987,
    MVCADJ_DSNUONCE              = 988,
    MVCADJ_PRNUONCE              = 989,
    MVCADJ_DEFECTONCE            = 990,
    MVCCAP_AGENABLE              = 991,
    MVCCAP_AGONCE                = 992,
    MVCCAP_AEAGAREA              = 993,
    MVCADJ_CORRECTTIONINDEX      = 994,
    MVCADJ_CORRECTIONLOAD        = 995,
    MVCADJ_CORRECTIONSAVE        = 996,
    MVCADJ_CHANNELENABLE         = 997,
    MVCADJ_CAMERASTATUS          = 998,
    MVCADJ_DATACOMBINE           = 999,
    MVCCAP_ADLIMITAUTOVALUE      = 973,
    MVCCAP_ADLIMITAUTOCOUNT      = 974,
    MVCCAP_ADCOMPRESS            = 975,
};

typedef UINT (WINAPI *StreamProc)(WORD wHWCardNo,MVCFRAMEINFO m_FrameInfo,PVOID pUserData);
typedef UINT (WINAPI *GPIOProc)(WORD wHWCardNo,DWORD ID ,DWORD GPIOInputs,PVOID pUserData);
typedef UINT (WINAPI *DevLostProc)(WORD wHWCardNo,DWORD DevStat,PVOID pUserData); 

#endif