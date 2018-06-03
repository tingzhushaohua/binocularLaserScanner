/********************************************************************************
** Form generated from reading UI file 'systemcalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMCALIBRATION_H
#define UI_SYSTEMCALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemCalibrationClass
{
public:
    QAction *action_OpenCalibrationPicture;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_showImage;
    QPushButton *pushButton_LoadPicture;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_PrePicture;
    QPushButton *pushButton_NextPicture;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_;
    QLineEdit *lineEdit_GridSizeRow;
    QLabel *label_3;
    QLineEdit *lineEdit_GridSizeCol;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *lineEdit_GridColNum;
    QLabel *label_5;
    QLineEdit *lineEdit_GridRowNum;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_BeginCalibration;
    QPushButton *pushButton_BeginCalibration_2;
    QPushButton *pushButton_CalibrationResult;
    QPushButton *pushButton_BackToHome;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QLabel *label_TranslationMatrix;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_RotationMatrix;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_laserCenter1;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_scrollArea_featurePoint;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_B;
    QLabel *label_9;
    QLineEdit *lineEdit_D;
    QLabel *label_7;
    QLabel *label_10;
    QLineEdit *lineEdit_A;
    QLabel *label_8;
    QLineEdit *lineEdit_C;
    QPushButton *pushButton_coefficient1;
    QGroupBox *groupBox_13;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_coefficient2;
    QLabel *label_20;
    QLineEdit *lineEdit_AA;
    QLabel *label_23;
    QLineEdit *lineEdit_14;
    QLabel *label_22;
    QLineEdit *lineEdit_CC;
    QLabel *label_21;
    QLineEdit *lineEdit_DD;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_internalMatrix;
    QLabel *label_internalMatrix_2;
    QGridLayout *gridLayout_5;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_distortionMatrix;
    QLabel *label_distortionMatrix_2;
    QLabel *label_11;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_scrollArea;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *SystemCalibrationClass)
    {
        if (SystemCalibrationClass->objectName().isEmpty())
            SystemCalibrationClass->setObjectName(QStringLiteral("SystemCalibrationClass"));
        SystemCalibrationClass->resize(952, 649);
        action_OpenCalibrationPicture = new QAction(SystemCalibrationClass);
        action_OpenCalibrationPicture->setObjectName(QStringLiteral("action_OpenCalibrationPicture"));
        centralWidget = new QWidget(SystemCalibrationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_showImage = new QLabel(groupBox);
        label_showImage->setObjectName(QStringLiteral("label_showImage"));
        label_showImage->setMinimumSize(QSize(400, 365));
        label_showImage->setMaximumSize(QSize(400, 365));
        label_showImage->setTextFormat(Qt::PlainText);
        label_showImage->setWordWrap(false);
        label_showImage->setMargin(15);

        gridLayout_3->addWidget(label_showImage, 0, 0, 1, 3);

        pushButton_LoadPicture = new QPushButton(groupBox);
        pushButton_LoadPicture->setObjectName(QStringLiteral("pushButton_LoadPicture"));
        pushButton_LoadPicture->setMinimumSize(QSize(50, 20));
        pushButton_LoadPicture->setMaximumSize(QSize(65, 16777215));
        pushButton_LoadPicture->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_3->addWidget(pushButton_LoadPicture, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_PrePicture = new QPushButton(groupBox);
        pushButton_PrePicture->setObjectName(QStringLiteral("pushButton_PrePicture"));
        pushButton_PrePicture->setMinimumSize(QSize(65, 20));
        pushButton_PrePicture->setMaximumSize(QSize(65, 20));
        pushButton_PrePicture->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_PrePicture->setMouseTracking(false);

        verticalLayout->addWidget(pushButton_PrePicture);

        pushButton_NextPicture = new QPushButton(groupBox);
        pushButton_NextPicture->setObjectName(QStringLiteral("pushButton_NextPicture"));
        pushButton_NextPicture->setMinimumSize(QSize(65, 20));
        pushButton_NextPicture->setMaximumSize(QSize(65, 20));

        verticalLayout->addWidget(pushButton_NextPicture);


        gridLayout_3->addLayout(verticalLayout, 1, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_ = new QLabel(groupBox_2);
        label_->setObjectName(QStringLiteral("label_"));

        gridLayout->addWidget(label_, 0, 0, 1, 1);

        lineEdit_GridSizeRow = new QLineEdit(groupBox_2);
        lineEdit_GridSizeRow->setObjectName(QStringLiteral("lineEdit_GridSizeRow"));

        gridLayout->addWidget(lineEdit_GridSizeRow, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        lineEdit_GridSizeCol = new QLineEdit(groupBox_2);
        lineEdit_GridSizeCol->setObjectName(QStringLiteral("lineEdit_GridSizeCol"));

        gridLayout->addWidget(lineEdit_GridSizeCol, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 4, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lineEdit_GridColNum = new QLineEdit(groupBox_2);
        lineEdit_GridColNum->setObjectName(QStringLiteral("lineEdit_GridColNum"));

        gridLayout->addWidget(lineEdit_GridColNum, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        lineEdit_GridRowNum = new QLineEdit(groupBox_2);
        lineEdit_GridRowNum->setObjectName(QStringLiteral("lineEdit_GridRowNum"));

        gridLayout->addWidget(lineEdit_GridRowNum, 1, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_BeginCalibration = new QPushButton(groupBox_2);
        pushButton_BeginCalibration->setObjectName(QStringLiteral("pushButton_BeginCalibration"));
        pushButton_BeginCalibration->setMinimumSize(QSize(66, 0));
        pushButton_BeginCalibration->setMaximumSize(QSize(66, 16777215));

        horizontalLayout_4->addWidget(pushButton_BeginCalibration);

        pushButton_BeginCalibration_2 = new QPushButton(groupBox_2);
        pushButton_BeginCalibration_2->setObjectName(QStringLiteral("pushButton_BeginCalibration_2"));
        pushButton_BeginCalibration_2->setMinimumSize(QSize(66, 0));
        pushButton_BeginCalibration_2->setMaximumSize(QSize(66, 16777215));

        horizontalLayout_4->addWidget(pushButton_BeginCalibration_2);


        gridLayout->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        pushButton_CalibrationResult = new QPushButton(groupBox_2);
        pushButton_CalibrationResult->setObjectName(QStringLiteral("pushButton_CalibrationResult"));

        gridLayout->addWidget(pushButton_CalibrationResult, 2, 3, 1, 1);

        pushButton_BackToHome = new QPushButton(groupBox_2);
        pushButton_BackToHome->setObjectName(QStringLiteral("pushButton_BackToHome"));

        gridLayout->addWidget(pushButton_BackToHome, 2, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_5 = new QHBoxLayout(page);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 20, 449, 131));
        label_TranslationMatrix = new QLabel(groupBox_4);
        label_TranslationMatrix->setObjectName(QStringLiteral("label_TranslationMatrix"));
        label_TranslationMatrix->setGeometry(QRect(120, 30, 301, 21));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 61, 16));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 70, 61, 20));
        label_RotationMatrix = new QLabel(groupBox_4);
        label_RotationMatrix->setObjectName(QStringLiteral("label_RotationMatrix"));
        label_RotationMatrix->setGeometry(QRect(120, 58, 301, 51));
        label_RotationMatrix->setMinimumSize(QSize(0, 0));
        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(11, 161, 451, 396));
        gridLayout_7 = new QGridLayout(groupBox_5);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_8 = new QGroupBox(groupBox_5);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        verticalLayout_5 = new QVBoxLayout(groupBox_8);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_laserCenter1 = new QPushButton(groupBox_8);
        pushButton_laserCenter1->setObjectName(QStringLiteral("pushButton_laserCenter1"));
        pushButton_laserCenter1->setCursor(QCursor(Qt::OpenHandCursor));

        verticalLayout_5->addWidget(pushButton_laserCenter1);

        scrollArea_2 = new QScrollArea(groupBox_8);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 191, 313));
        horizontalLayout_6 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_scrollArea_featurePoint = new QLabel(scrollAreaWidgetContents_2);
        label_scrollArea_featurePoint->setObjectName(QStringLiteral("label_scrollArea_featurePoint"));

        horizontalLayout_6->addWidget(label_scrollArea_featurePoint);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_5->addWidget(scrollArea_2);


        gridLayout_7->addWidget(groupBox_8, 0, 0, 2, 1);

        groupBox_9 = new QGroupBox(groupBox_5);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_9);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        groupBox_7 = new QGroupBox(groupBox_9);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_4 = new QGridLayout(groupBox_7);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_B = new QLineEdit(groupBox_7);
        lineEdit_B->setObjectName(QStringLiteral("lineEdit_B"));
        lineEdit_B->setReadOnly(true);

        gridLayout_4->addWidget(lineEdit_B, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_4->addWidget(label_9, 3, 0, 1, 1);

        lineEdit_D = new QLineEdit(groupBox_7);
        lineEdit_D->setObjectName(QStringLiteral("lineEdit_D"));
        lineEdit_D->setReadOnly(true);

        gridLayout_4->addWidget(lineEdit_D, 4, 1, 1, 1);

        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 4, 0, 1, 1);

        lineEdit_A = new QLineEdit(groupBox_7);
        lineEdit_A->setObjectName(QStringLiteral("lineEdit_A"));
        lineEdit_A->setReadOnly(true);

        gridLayout_4->addWidget(lineEdit_A, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_7);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_C = new QLineEdit(groupBox_7);
        lineEdit_C->setObjectName(QStringLiteral("lineEdit_C"));
        lineEdit_C->setReadOnly(true);

        gridLayout_4->addWidget(lineEdit_C, 3, 1, 1, 1);

        pushButton_coefficient1 = new QPushButton(groupBox_7);
        pushButton_coefficient1->setObjectName(QStringLiteral("pushButton_coefficient1"));
        pushButton_coefficient1->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_4->addWidget(pushButton_coefficient1, 0, 0, 1, 2);


        horizontalLayout_8->addWidget(groupBox_7);


        gridLayout_7->addWidget(groupBox_9, 0, 1, 1, 1);

        groupBox_13 = new QGroupBox(groupBox_5);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_13);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        groupBox_15 = new QGroupBox(groupBox_13);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        gridLayout_6 = new QGridLayout(groupBox_15);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton_coefficient2 = new QPushButton(groupBox_15);
        pushButton_coefficient2->setObjectName(QStringLiteral("pushButton_coefficient2"));
        pushButton_coefficient2->setCursor(QCursor(Qt::OpenHandCursor));

        gridLayout_6->addWidget(pushButton_coefficient2, 0, 0, 1, 2);

        label_20 = new QLabel(groupBox_15);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_6->addWidget(label_20, 1, 0, 1, 1);

        lineEdit_AA = new QLineEdit(groupBox_15);
        lineEdit_AA->setObjectName(QStringLiteral("lineEdit_AA"));
        lineEdit_AA->setReadOnly(true);

        gridLayout_6->addWidget(lineEdit_AA, 1, 1, 1, 1);

        label_23 = new QLabel(groupBox_15);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_6->addWidget(label_23, 2, 0, 1, 1);

        lineEdit_14 = new QLineEdit(groupBox_15);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setReadOnly(true);

        gridLayout_6->addWidget(lineEdit_14, 2, 1, 1, 1);

        label_22 = new QLabel(groupBox_15);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_6->addWidget(label_22, 3, 0, 1, 1);

        lineEdit_CC = new QLineEdit(groupBox_15);
        lineEdit_CC->setObjectName(QStringLiteral("lineEdit_CC"));
        lineEdit_CC->setReadOnly(true);

        gridLayout_6->addWidget(lineEdit_CC, 3, 1, 1, 1);

        label_21 = new QLabel(groupBox_15);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_6->addWidget(label_21, 4, 0, 1, 1);

        lineEdit_DD = new QLineEdit(groupBox_15);
        lineEdit_DD->setObjectName(QStringLiteral("lineEdit_DD"));
        lineEdit_DD->setReadOnly(true);

        gridLayout_6->addWidget(lineEdit_DD, 4, 1, 1, 1);


        horizontalLayout_9->addWidget(groupBox_15);


        gridLayout_7->addWidget(groupBox_13, 1, 1, 1, 1);


        horizontalLayout_5->addWidget(groupBox_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout = new QHBoxLayout(page_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_6 = new QGroupBox(page_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_3 = new QVBoxLayout(groupBox_6);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 0, 0, 1, 1);

        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 0, 1, 1, 1);

        label_internalMatrix = new QLabel(groupBox_6);
        label_internalMatrix->setObjectName(QStringLiteral("label_internalMatrix"));
        label_internalMatrix->setMinimumSize(QSize(230, 80));
        label_internalMatrix->setMaximumSize(QSize(230, 16777215));

        gridLayout_2->addWidget(label_internalMatrix, 1, 0, 1, 1);

        label_internalMatrix_2 = new QLabel(groupBox_6);
        label_internalMatrix_2->setObjectName(QStringLiteral("label_internalMatrix_2"));
        label_internalMatrix_2->setMinimumSize(QSize(230, 80));
        label_internalMatrix_2->setMaximumSize(QSize(230, 16777215));

        gridLayout_2->addWidget(label_internalMatrix_2, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_5->addWidget(label_13, 0, 0, 1, 1);

        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 0, 1, 1, 1);

        label_distortionMatrix = new QLabel(groupBox_6);
        label_distortionMatrix->setObjectName(QStringLiteral("label_distortionMatrix"));
        label_distortionMatrix->setMinimumSize(QSize(230, 45));
        label_distortionMatrix->setMaximumSize(QSize(230, 16777215));

        gridLayout_5->addWidget(label_distortionMatrix, 1, 0, 1, 1);

        label_distortionMatrix_2 = new QLabel(groupBox_6);
        label_distortionMatrix_2->setObjectName(QStringLiteral("label_distortionMatrix_2"));
        label_distortionMatrix_2->setMinimumSize(QSize(230, 45));
        label_distortionMatrix_2->setMaximumSize(QSize(230, 16777215));

        gridLayout_5->addWidget(label_distortionMatrix_2, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_5);

        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_3->addWidget(label_11);

        scrollArea = new QScrollArea(groupBox_6);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 466, 327));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_scrollArea = new QLabel(scrollAreaWidgetContents);
        label_scrollArea->setObjectName(QStringLiteral("label_scrollArea"));

        horizontalLayout_2->addWidget(label_scrollArea);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        horizontalLayout->addWidget(groupBox_6);

        stackedWidget->addWidget(page_2);

        horizontalLayout_3->addWidget(stackedWidget);

        SystemCalibrationClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(SystemCalibrationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SystemCalibrationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SystemCalibrationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SystemCalibrationClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(SystemCalibrationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 952, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        SystemCalibrationClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_OpenCalibrationPicture);

        retranslateUi(SystemCalibrationClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SystemCalibrationClass);
    } // setupUi

    void retranslateUi(QMainWindow *SystemCalibrationClass)
    {
        SystemCalibrationClass->setWindowTitle(QApplication::translate("SystemCalibrationClass", "\345\217\214\347\233\256\350\247\206\350\247\211\347\263\273\347\273\237\346\240\207\345\256\232\350\275\257\344\273\266", Q_NULLPTR));
        action_OpenCalibrationPicture->setText(QApplication::translate("SystemCalibrationClass", "\346\211\223\345\274\200\346\240\207\345\256\232\345\233\276\347\211\207", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SystemCalibrationClass", "\345\212\240\350\275\275\345\233\276\347\211\207", Q_NULLPTR));
        label_showImage->setText(QApplication::translate("SystemCalibrationClass", "                          \346\240\207\345\256\232\345\233\276\347\211\207\346\230\276\347\244\272", Q_NULLPTR));
        pushButton_LoadPicture->setText(QApplication::translate("SystemCalibrationClass", "\350\275\275\345\205\245\345\233\276\347\211\207", Q_NULLPTR));
        pushButton_PrePicture->setText(QApplication::translate("SystemCalibrationClass", "\344\270\212\344\270\200\345\274\240", Q_NULLPTR));
        pushButton_NextPicture->setText(QApplication::translate("SystemCalibrationClass", "\344\270\213\344\270\200\345\274\240", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SystemCalibrationClass", "\347\233\270\346\234\272\346\240\207\345\256\232", Q_NULLPTR));
        label_->setText(QApplication::translate("SystemCalibrationClass", "\346\243\213\347\233\230\346\257\217\346\240\274\345\244\247\345\260\217", Q_NULLPTR));
        lineEdit_GridSizeRow->setText(QApplication::translate("SystemCalibrationClass", "20", Q_NULLPTR));
        label_3->setText(QApplication::translate("SystemCalibrationClass", "\303\227", Q_NULLPTR));
        lineEdit_GridSizeCol->setText(QApplication::translate("SystemCalibrationClass", "20", Q_NULLPTR));
        label_6->setText(QApplication::translate("SystemCalibrationClass", "mm", Q_NULLPTR));
        label_4->setText(QApplication::translate("SystemCalibrationClass", "\346\243\213\347\233\230\346\240\274\350\241\214\345\210\227\346\225\260", Q_NULLPTR));
        lineEdit_GridColNum->setText(QApplication::translate("SystemCalibrationClass", "7", Q_NULLPTR));
        label_5->setText(QApplication::translate("SystemCalibrationClass", "\303\227", Q_NULLPTR));
        lineEdit_GridRowNum->setText(QApplication::translate("SystemCalibrationClass", "10", Q_NULLPTR));
        pushButton_BeginCalibration->setText(QApplication::translate("SystemCalibrationClass", "\346\240\207\345\256\232\347\233\270\346\234\2721", Q_NULLPTR));
        pushButton_BeginCalibration_2->setText(QApplication::translate("SystemCalibrationClass", "\346\240\207\345\256\232\347\233\270\346\234\2722", Q_NULLPTR));
        pushButton_CalibrationResult->setText(QApplication::translate("SystemCalibrationClass", "\347\263\273\347\273\237\346\240\207\345\256\232", Q_NULLPTR));
        pushButton_BackToHome->setText(QApplication::translate("SystemCalibrationClass", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("SystemCalibrationClass", "\347\263\273\347\273\237\346\240\207\345\256\232\347\273\223\346\236\234", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("SystemCalibrationClass", "1.\344\270\244\347\233\270\346\234\272\351\227\264\345\271\263\347\247\273\346\227\213\350\275\254\347\237\251\351\230\265", Q_NULLPTR));
        label_TranslationMatrix->setText(QString());
        label->setText(QApplication::translate("SystemCalibrationClass", "\345\271\263\347\247\273\347\237\251\351\230\265\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("SystemCalibrationClass", "\346\227\213\350\275\254\347\237\251\351\230\265\357\274\232", Q_NULLPTR));
        label_RotationMatrix->setText(QString());
        groupBox_5->setTitle(QApplication::translate("SystemCalibrationClass", "2.\346\227\213\350\275\254\350\275\264\346\240\207\345\256\232", Q_NULLPTR));
        groupBox_8->setTitle(QString());
        pushButton_laserCenter1->setText(QApplication::translate("SystemCalibrationClass", "1\357\274\211\346\277\200\345\205\211\346\235\241\344\270\255\345\277\203\346\217\220\345\217\226\357\274\232\347\211\271\345\276\201\347\202\271", Q_NULLPTR));
        label_scrollArea_featurePoint->setText(QString());
        groupBox_9->setTitle(QApplication::translate("SystemCalibrationClass", "         \346\263\2251\357\274\232\347\211\271\345\276\201\347\202\271\346\263\225", Q_NULLPTR));
        groupBox_7->setTitle(QString());
        label_9->setText(QApplication::translate("SystemCalibrationClass", "C", Q_NULLPTR));
        label_7->setText(QApplication::translate("SystemCalibrationClass", "A", Q_NULLPTR));
        label_10->setText(QApplication::translate("SystemCalibrationClass", "P", Q_NULLPTR));
        label_8->setText(QApplication::translate("SystemCalibrationClass", "B", Q_NULLPTR));
        pushButton_coefficient1->setText(QApplication::translate("SystemCalibrationClass", "2\357\274\211\346\261\202\345\217\226\346\277\200\345\205\211\345\271\263\351\235\242\346\226\271\347\250\213", Q_NULLPTR));
        groupBox_13->setTitle(QApplication::translate("SystemCalibrationClass", "       \346\263\2252\357\274\232\345\205\211\345\271\263\351\235\242\346\213\237\345\220\210\346\263\225", Q_NULLPTR));
        groupBox_15->setTitle(QString());
        pushButton_coefficient2->setText(QApplication::translate("SystemCalibrationClass", "2\357\274\211\346\261\202\345\217\226\346\277\200\345\205\211\345\271\263\351\235\242\346\226\271\347\250\213", Q_NULLPTR));
        label_20->setText(QApplication::translate("SystemCalibrationClass", "A", Q_NULLPTR));
        label_23->setText(QApplication::translate("SystemCalibrationClass", "B", Q_NULLPTR));
        label_22->setText(QApplication::translate("SystemCalibrationClass", "C", Q_NULLPTR));
        label_21->setText(QApplication::translate("SystemCalibrationClass", "D", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("SystemCalibrationClass", "\345\217\214\347\233\256\347\233\270\346\234\272\346\240\207\345\256\232\347\273\223\346\236\234", Q_NULLPTR));
        label_12->setText(QApplication::translate("SystemCalibrationClass", "\347\233\270\346\234\2721\345\206\205\345\217\202\346\225\260\347\237\251\351\230\265", Q_NULLPTR));
        label_14->setText(QApplication::translate("SystemCalibrationClass", "\347\233\270\346\234\2722\345\206\205\345\217\202\346\225\260\347\237\251\351\230\265", Q_NULLPTR));
        label_internalMatrix->setText(QString());
        label_internalMatrix_2->setText(QString());
        label_13->setText(QApplication::translate("SystemCalibrationClass", "\347\233\270\346\234\2721\347\225\270\345\217\230\347\263\273\346\225\260", Q_NULLPTR));
        label_15->setText(QApplication::translate("SystemCalibrationClass", "\347\233\270\346\234\2722\347\225\270\345\217\230\347\263\273\346\225\260", Q_NULLPTR));
        label_distortionMatrix->setText(QString());
        label_distortionMatrix_2->setText(QString());
        label_11->setText(QApplication::translate("SystemCalibrationClass", "\345\220\204\346\243\213\347\233\230\346\240\274\345\233\276\345\203\217\347\233\270\346\234\272\345\244\226\345\217\202\357\274\210\346\227\213\350\275\254\345\271\263\347\247\273\357\274\211\345\217\212\346\240\207\345\256\232\350\257\257\345\267\256\357\274\232", Q_NULLPTR));
        label_scrollArea->setText(QString());
        menu->setTitle(QApplication::translate("SystemCalibrationClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("SystemCalibrationClass", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SystemCalibrationClass: public Ui_SystemCalibrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMCALIBRATION_H
