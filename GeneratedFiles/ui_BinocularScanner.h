/********************************************************************************
** Form generated from reading UI file 'BinocularScanner.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINOCULARSCANNER_H
#define UI_BINOCULARSCANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BinocularScannerClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_left;
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *cameraBoot;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_15;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *btn_openCam;
    QGroupBox *groupBox_16;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *btn_swapRL;
    QSpacerItem *verticalSpacer_5;
    QWidget *focusCalibration;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_10;
    QPushButton *btnSaveImage;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_10;
    QToolButton *btn_calibrationL;
    QToolButton *btn_calibrationR;
    QGroupBox *groupBox_21;
    QVBoxLayout *verticalLayout_7;
    QPushButton *btn_loadParameter;
    QPushButton *btn_correction;
    QSpacerItem *verticalSpacer_3;
    QWidget *lightScans;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QSpinBox *xyzMinZ;
    QLabel *label_5;
    QSpinBox *xyzMaxZ;
    QLabel *label_6;
    QSpinBox *xyzScale;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QPushButton *btn_scan;
    QGroupBox *groupBox_19;
    QGridLayout *gridLayout_7;
    QPushButton *btn_showCloud;
    QGroupBox *groupBox_17;
    QVBoxLayout *verticalLayout_4;
    QSlider *lightSlider;
    QSpinBox *spinBox_light;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_center;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *videoBox_left;
    QWidget *videoBox_right;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QWidget *widget_cloud;
    QWidget *widget_3;
    QWidget *widget_right;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_11;
    QTextEdit *infoEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BinocularScannerClass)
    {
        if (BinocularScannerClass->objectName().isEmpty())
            BinocularScannerClass->setObjectName(QStringLiteral("BinocularScannerClass"));
        BinocularScannerClass->resize(1280, 720);
        BinocularScannerClass->setMinimumSize(QSize(1280, 720));
        BinocularScannerClass->setStyleSheet(QStringLiteral("background-color: rgb(58, 58, 58);"));
        centralWidget = new QWidget(BinocularScannerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        widget_left = new QWidget(centralWidget);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        gridLayout = new QGridLayout(widget_left);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 3);
        toolBox = new QToolBox(widget_left);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        toolBox->setFont(font);
        toolBox->setMouseTracking(false);
        toolBox->setAutoFillBackground(false);
        toolBox->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
""));
        cameraBoot = new QWidget();
        cameraBoot->setObjectName(QStringLiteral("cameraBoot"));
        cameraBoot->setGeometry(QRect(0, 0, 208, 561));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(59, 59, 59, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        cameraBoot->setPalette(palette);
        cameraBoot->setStyleSheet(QLatin1String("\n"
"background-color: rgb(59, 59, 59);"));
        verticalLayout_5 = new QVBoxLayout(cameraBoot);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_15 = new QGroupBox(cameraBoot);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        groupBox_15->setAlignment(Qt::AlignCenter);
        horizontalLayout_12 = new QHBoxLayout(groupBox_15);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        btn_openCam = new QPushButton(groupBox_15);
        btn_openCam->setObjectName(QStringLiteral("btn_openCam"));
        sizePolicy.setHeightForWidth(btn_openCam->sizePolicy().hasHeightForWidth());
        btn_openCam->setSizePolicy(sizePolicy);
        btn_openCam->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\346\226\260\345\211\215\347\274\200/Resources/Start.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_openCam->setIcon(icon);

        horizontalLayout_12->addWidget(btn_openCam);


        verticalLayout_5->addWidget(groupBox_15);

        groupBox_16 = new QGroupBox(cameraBoot);
        groupBox_16->setObjectName(QStringLiteral("groupBox_16"));
        groupBox_16->setAlignment(Qt::AlignCenter);
        horizontalLayout_13 = new QHBoxLayout(groupBox_16);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        btn_swapRL = new QPushButton(groupBox_16);
        btn_swapRL->setObjectName(QStringLiteral("btn_swapRL"));
        btn_swapRL->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));

        horizontalLayout_13->addWidget(btn_swapRL);


        verticalLayout_5->addWidget(groupBox_16);

        verticalSpacer_5 = new QSpacerItem(20, 222, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 3);
        toolBox->addItem(cameraBoot, QString::fromUtf8("\345\220\257\345\212\250\350\256\276\345\244\207"));
        focusCalibration = new QWidget();
        focusCalibration->setObjectName(QStringLiteral("focusCalibration"));
        focusCalibration->setGeometry(QRect(0, 0, 208, 561));
        focusCalibration->setStyleSheet(QStringLiteral("background-color: rgb(59, 59, 59);"));
        verticalLayout_6 = new QVBoxLayout(focusCalibration);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_9 = new QGroupBox(focusCalibration);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setAlignment(Qt::AlignCenter);
        verticalLayout_10 = new QVBoxLayout(groupBox_9);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        btnSaveImage = new QPushButton(groupBox_9);
        btnSaveImage->setObjectName(QStringLiteral("btnSaveImage"));
        btnSaveImage->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\346\226\260\345\211\215\347\274\200/Resources/FILE.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveImage->setIcon(icon1);

        verticalLayout_10->addWidget(btnSaveImage);

        verticalLayout_10->setStretch(0, 1);

        verticalLayout_6->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(focusCalibration);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setAlignment(Qt::AlignCenter);
        horizontalLayout_10 = new QHBoxLayout(groupBox_10);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        btn_calibrationL = new QToolButton(groupBox_10);
        btn_calibrationL->setObjectName(QStringLiteral("btn_calibrationL"));
        btn_calibrationL->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));

        horizontalLayout_10->addWidget(btn_calibrationL);

        btn_calibrationR = new QToolButton(groupBox_10);
        btn_calibrationR->setObjectName(QStringLiteral("btn_calibrationR"));
        btn_calibrationR->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));

        horizontalLayout_10->addWidget(btn_calibrationR);


        verticalLayout_6->addWidget(groupBox_10);

        groupBox_21 = new QGroupBox(focusCalibration);
        groupBox_21->setObjectName(QStringLiteral("groupBox_21"));
        groupBox_21->setAlignment(Qt::AlignCenter);
        verticalLayout_7 = new QVBoxLayout(groupBox_21);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        btn_loadParameter = new QPushButton(groupBox_21);
        btn_loadParameter->setObjectName(QStringLiteral("btn_loadParameter"));
        btn_loadParameter->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));

        verticalLayout_7->addWidget(btn_loadParameter);

        btn_correction = new QPushButton(groupBox_21);
        btn_correction->setObjectName(QStringLiteral("btn_correction"));
        btn_correction->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));

        verticalLayout_7->addWidget(btn_correction);


        verticalLayout_6->addWidget(groupBox_21);

        verticalSpacer_3 = new QSpacerItem(20, 223, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        toolBox->addItem(focusCalibration, QString::fromUtf8("\347\204\246\350\267\235\346\240\207\345\256\232"));
        lightScans = new QWidget();
        lightScans->setObjectName(QStringLiteral("lightScans"));
        lightScans->setGeometry(QRect(0, 0, 208, 561));
        lightScans->setStyleSheet(QStringLiteral("background-color: rgb(59, 59, 59);"));
        verticalLayout_13 = new QVBoxLayout(lightScans);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(3, 3, 3, 3);
        groupBox_3 = new QGroupBox(lightScans);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        xyzMinZ = new QSpinBox(groupBox_3);
        xyzMinZ->setObjectName(QStringLiteral("xyzMinZ"));
        xyzMinZ->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.2, x2:0, y2:0, stop:0 rgba(48, 15, 15, 255), stop:1 rgba(255, 255, 255, 255));"));

        gridLayout_3->addWidget(xyzMinZ, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        xyzMaxZ = new QSpinBox(groupBox_3);
        xyzMaxZ->setObjectName(QStringLiteral("xyzMaxZ"));
        xyzMaxZ->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.2, x2:0, y2:0, stop:0 rgba(48, 15, 15, 255), stop:1 rgba(255, 255, 255, 255));"));
        xyzMaxZ->setMaximum(99999);
        xyzMaxZ->setValue(10000);

        gridLayout_3->addWidget(xyzMaxZ, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        xyzScale = new QSpinBox(groupBox_3);
        xyzScale->setObjectName(QStringLiteral("xyzScale"));
        xyzScale->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.2, x2:0, y2:0, stop:0 rgba(48, 15, 15, 255), stop:1 rgba(255, 255, 255, 255));"));
        xyzScale->setMaximum(99999);
        xyzScale->setValue(1);

        gridLayout_3->addWidget(xyzScale, 2, 1, 1, 1);


        verticalLayout_13->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(lightScans);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        btn_scan = new QPushButton(groupBox_2);
        btn_scan->setObjectName(QStringLiteral("btn_scan"));
        sizePolicy.setHeightForWidth(btn_scan->sizePolicy().hasHeightForWidth());
        btn_scan->setSizePolicy(sizePolicy);
        btn_scan->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        btn_scan->setIcon(icon);

        gridLayout_4->addWidget(btn_scan, 0, 0, 1, 1);


        verticalLayout_13->addWidget(groupBox_2);

        groupBox_19 = new QGroupBox(lightScans);
        groupBox_19->setObjectName(QStringLiteral("groupBox_19"));
        groupBox_19->setAlignment(Qt::AlignCenter);
        gridLayout_7 = new QGridLayout(groupBox_19);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        btn_showCloud = new QPushButton(groupBox_19);
        btn_showCloud->setObjectName(QStringLiteral("btn_showCloud"));
        sizePolicy.setHeightForWidth(btn_showCloud->sizePolicy().hasHeightForWidth());
        btn_showCloud->setSizePolicy(sizePolicy);
        btn_showCloud->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/BinocularScanner/Resources/Start.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_showCloud->setIcon(icon2);

        gridLayout_7->addWidget(btn_showCloud, 0, 0, 1, 1);


        verticalLayout_13->addWidget(groupBox_19);

        groupBox_17 = new QGroupBox(lightScans);
        groupBox_17->setObjectName(QStringLiteral("groupBox_17"));
        groupBox_17->setAlignment(Qt::AlignCenter);
        verticalLayout_4 = new QVBoxLayout(groupBox_17);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lightSlider = new QSlider(groupBox_17);
        lightSlider->setObjectName(QStringLiteral("lightSlider"));
        lightSlider->setStyleSheet(QStringLiteral(""));
        lightSlider->setMaximum(255);
        lightSlider->setValue(100);
        lightSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(lightSlider);

        spinBox_light = new QSpinBox(groupBox_17);
        spinBox_light->setObjectName(QStringLiteral("spinBox_light"));
        spinBox_light->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.2, x2:0, y2:0, stop:0 rgba(48, 15, 15, 255), stop:1 rgba(255, 255, 255, 255));"));
        spinBox_light->setMaximum(255);
        spinBox_light->setValue(100);

        verticalLayout_4->addWidget(spinBox_light);


        verticalLayout_13->addWidget(groupBox_17);

        verticalSpacer_2 = new QSpacerItem(20, 338, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_2);

        toolBox->addItem(lightScans, QString::fromUtf8("\346\277\200\345\205\211\346\211\253\346\217\217"));

        gridLayout->addWidget(toolBox, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget_left);

        widget_center = new QWidget(centralWidget);
        widget_center->setObjectName(QStringLiteral("widget_center"));
        verticalLayout = new QVBoxLayout(widget_center);
        verticalLayout->setSpacing(7);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        widget = new QWidget(widget_center);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widget_center);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 0, 1, 1);
        tabWidget = new QTabWidget(widget_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(58, 58, 58, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush3(QColor(255, 64, 16, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        QBrush brush4(QColor(170, 255, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
        tabWidget->setPalette(palette1);
        tabWidget->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(59, 59, 59);\n"
""));
        widget_6 = new QWidget();
        widget_6->setObjectName(QStringLiteral("widget_6"));
        sizePolicy.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        videoBox_left = new QWidget(widget_6);
        videoBox_left->setObjectName(QStringLiteral("videoBox_left"));
        sizePolicy.setHeightForWidth(videoBox_left->sizePolicy().hasHeightForWidth());
        videoBox_left->setSizePolicy(sizePolicy);
        videoBox_left->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(videoBox_left);

        videoBox_right = new QWidget(widget_6);
        videoBox_right->setObjectName(QStringLiteral("videoBox_right"));
        sizePolicy.setHeightForWidth(videoBox_right->sizePolicy().hasHeightForWidth());
        videoBox_right->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(videoBox_right);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(17, 203, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_3->setStretch(0, 100);
        verticalLayout_3->setStretch(1, 59);
        tabWidget->addTab(widget_6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget_cloud = new QWidget(tab_2);
        widget_cloud->setObjectName(QStringLiteral("widget_cloud"));

        gridLayout_2->addWidget(widget_cloud, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget_center);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));

        verticalLayout->addWidget(widget_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 20);
        verticalLayout->setStretch(2, 1);

        horizontalLayout->addWidget(widget_center);

        widget_right = new QWidget(centralWidget);
        widget_right->setObjectName(QStringLiteral("widget_right"));
        widget_right->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(widget_right);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 2);
        groupBox_14 = new QGroupBox(widget_right);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        groupBox_14->setAlignment(Qt::AlignCenter);
        verticalLayout_11 = new QVBoxLayout(groupBox_14);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(1, 0, 1, 1);
        infoEdit = new QTextEdit(groupBox_14);
        infoEdit->setObjectName(QStringLiteral("infoEdit"));
        infoEdit->setFocusPolicy(Qt::NoFocus);
        infoEdit->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout_11->addWidget(infoEdit);


        verticalLayout_2->addWidget(groupBox_14);

        verticalLayout_2->setStretch(0, 9);

        horizontalLayout->addWidget(widget_right);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(2, 1);
        BinocularScannerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BinocularScannerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        BinocularScannerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BinocularScannerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BinocularScannerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BinocularScannerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BinocularScannerClass->setStatusBar(statusBar);

        retranslateUi(BinocularScannerClass);

        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BinocularScannerClass);
    } // setupUi

    void retranslateUi(QMainWindow *BinocularScannerClass)
    {
        BinocularScannerClass->setWindowTitle(QApplication::translate("BinocularScannerClass", "BinocularScanner", Q_NULLPTR));
        groupBox_15->setTitle(QString());
        btn_openCam->setText(QApplication::translate("BinocularScannerClass", "\346\211\223\345\274\200\346\221\204\345\203\217\346\234\272", Q_NULLPTR));
        groupBox_16->setTitle(QApplication::translate("BinocularScannerClass", "\344\272\244\346\215\242\350\247\206\351\242\221\345\267\246\345\217\263\344\275\215\347\275\256", Q_NULLPTR));
        btn_swapRL->setText(QApplication::translate("BinocularScannerClass", "\344\272\244\346\215\242\344\275\215\347\275\256", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(cameraBoot), QApplication::translate("BinocularScannerClass", "\345\220\257\345\212\250\350\256\276\345\244\207", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("BinocularScannerClass", "\346\213\215\346\221\204\346\240\207\345\256\232\345\233\276:", Q_NULLPTR));
        btnSaveImage->setText(QApplication::translate("BinocularScannerClass", "\344\277\235\345\255\230\345\233\276\345\203\217", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("BinocularScannerClass", "\351\200\211\346\213\251\346\240\207\345\256\232\345\233\276:", Q_NULLPTR));
        btn_calibrationL->setText(QApplication::translate("BinocularScannerClass", "\345\267\246", Q_NULLPTR));
        btn_calibrationR->setText(QApplication::translate("BinocularScannerClass", "\345\217\263", Q_NULLPTR));
        groupBox_21->setTitle(QApplication::translate("BinocularScannerClass", "\347\253\213\344\275\223\346\240\241\346\255\243", Q_NULLPTR));
        btn_loadParameter->setText(QApplication::translate("BinocularScannerClass", "\350\257\273\345\217\226\345\217\202\346\225\260", Q_NULLPTR));
        btn_correction->setText(QApplication::translate("BinocularScannerClass", "\346\240\241\346\255\243", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(focusCalibration), QApplication::translate("BinocularScannerClass", "\347\204\246\350\267\235\346\240\207\345\256\232", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("BinocularScannerClass", "\345\217\202\346\225\260:", Q_NULLPTR));
        label_4->setText(QApplication::translate("BinocularScannerClass", "\346\234\200\345\260\217Z\345\200\274", Q_NULLPTR));
        label_5->setText(QApplication::translate("BinocularScannerClass", "\346\234\200\345\244\247Z\345\200\274", Q_NULLPTR));
        label_6->setText(QApplication::translate("BinocularScannerClass", "\347\274\251\346\224\276\346\257\224\344\276\213", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("BinocularScannerClass", "\345\274\200\345\247\213\346\211\253\346\217\217:", Q_NULLPTR));
        btn_scan->setText(QApplication::translate("BinocularScannerClass", "\345\274\200\345\247\213\346\211\253\346\217\217", Q_NULLPTR));
        groupBox_19->setTitle(QApplication::translate("BinocularScannerClass", "\346\230\276\347\244\272\347\202\271\344\272\221:", Q_NULLPTR));
        btn_showCloud->setText(QApplication::translate("BinocularScannerClass", "\346\230\276\347\244\272\347\202\271\344\272\221", Q_NULLPTR));
        groupBox_17->setTitle(QApplication::translate("BinocularScannerClass", "\345\205\211\346\235\241\351\230\210\345\200\274:", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(lightScans), QApplication::translate("BinocularScannerClass", "\346\277\200\345\205\211\346\211\253\346\217\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(widget_6), QApplication::translate("BinocularScannerClass", "\350\247\206\351\242\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("BinocularScannerClass", "\347\202\271\344\272\221", Q_NULLPTR));
        groupBox_14->setTitle(QApplication::translate("BinocularScannerClass", "\347\212\266\346\200\201\346\240\217:", Q_NULLPTR));
        infoEdit->setHtml(QApplication::translate("BinocularScannerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:9pt; font-weight:72; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-weight:400;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BinocularScannerClass: public Ui_BinocularScannerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINOCULARSCANNER_H
