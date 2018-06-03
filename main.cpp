#include "LaserScanner.h"
#include <QtWidgets/QApplication>
//#include "PointCloudViewer.h"
int main(int argc, char *argv[])
{
	/*
	QApplication a(argc, argv);
	PCLVisualizer w;
	w.show();
	return a.exec();
	*/

	QApplication a(argc, argv);
	//Widget w;
	LaserScanner w;
	w.show();
	return a.exec();
	
}
