#include "systemcalibration.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SystemCalibration w;
	w.show();
	return a.exec();
}
