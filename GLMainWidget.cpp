
#include"GLMainWidget.h"
#include"RoamingScenceManager.h"
#include<QMouseEvent>
#include<QWheelEvent>
#include<QDebug>
#include <QLabel.h>  
GLMainWidget::GLMainWidget(QWidget *parent) :
    QGLWidget(parent)
{
	this->setFocusPolicy(Qt::StrongFocus);
    manager=new RoamingScenceManager();
}

GLMainWidget::~GLMainWidget()
{
    delete manager;
}
void GLMainWidget::setTxtName(QString filename)
{
	QByteArray ba = filename.toLocal8Bit();
	char *c_str = ba.data();
	//char*  ch;

	//QByteArray ba = filename.toLatin1();

	//ch = ba.data();
	manager->loadPointCloudPLY(c_str);
}


void GLMainWidget::initializeGL()
{
    manager->init();
}

void GLMainWidget::resizeGL(int w, int h)
{
    glViewport(0,-(w-h)/2,w,w);
}
void GLMainWidget::paintGL()
{

    manager->render();

}

void GLMainWidget::mousePressEvent(QMouseEvent *e)
{
    manager->getInitPos(e->x(),e->y());
}

void GLMainWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons()&Qt::MiddleButton)
    {
        if(e->modifiers()==Qt::CTRL)
        {
            manager->executeTranslateOperation(e->x(),e->y());
        }
        else
        {
            manager->executeRotateOperation(e->x(),e->y());
        }
    }
    updateGL();
}

void GLMainWidget::wheelEvent(QWheelEvent *e)
{
    if(e->delta()>=0)
    {
        manager->executeScaleOperation(-0.1);
    }else
    {
        manager->executeScaleOperation(0.1);
    }
    updateGL();
}
