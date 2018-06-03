#include "RoamingScenceManager.h"
#include"MathAPIKernel/Vector3D.h"
#include"MathAPIKernel/Position3D.h"
#include"MathAPIKernel/Matrix4D.h"

GLfloat g_scale = 0.3;//初始化缩放参数
VERTEX_3D *g_ver;//Pointer to store vertices
int g_nPointsNumber;//Number of all triangle faces
RoamingScenceManager::RoamingScenceManager()
{
    OldMouse=new Position3D();
    Mouse=new Position3D();

    NewEye=new Vector3D(100,0,0);
    NewUp=new Vector3D(0,0,1);
    NewView=new Vector3D(0,0,0);

    AuxY =new Vector3D(0,1,0);
    AuxZ=new Vector3D();
    *AuxZ= (Vector3D)*NewEye - (Vector3D)*NewView;
    AuxX=new Vector3D();
    *AuxX=Vector3D::crossProduct(*AuxY,*AuxZ);
    AuxX->normalize();

    TempTranslateVec=new Vector3D(0,0,0);
    TempscaleFactor=1;
}

RoamingScenceManager::~RoamingScenceManager()
{
    delete OldMouse;
    delete Mouse;
    delete NewEye;
    delete NewUp;
    delete NewView;
    delete AuxX;
    delete AuxY;
    delete AuxZ;
    delete TempTranslateVec;
}

void RoamingScenceManager::init()
{
   init_CoordinaryDisplayList();
   glShadeModel(GL_SMOOTH);
   glClearColor(0.156   ,   0.156  ,    0.168 ,     0.0);
   glClearDepth(1.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1000/2,1000/2,-1000/2,1000/2,-1000/2,1000/2);
 //  loadPointCloudPLY("testfile.txt");
}

void RoamingScenceManager::render()
{
	glClearColor(0.156, 0.156, 0.168, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	*NewView = *NewEye*-1;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(TempTranslateVec->X(), TempTranslateVec->Y(), TempTranslateVec->Z());
	glScalef(TempscaleFactor, TempscaleFactor, TempscaleFactor);
	gluLookAt(NewEye->X(), NewEye->Y(), NewEye->Z(),
		NewView->X(), NewView->Y(), NewView->Z(),
		NewUp->X(), NewUp->Y(), NewUp->Z());


	glDisable(GL_LIGHTING);
	glBegin(GL_POINTS);
	for (int i = 0; i<g_nPointsNumber; i++) {
		glColor3d(1, 1, 1);
		glVertex3d(g_ver[i].x, g_ver[i].y, g_ver[i].z);
	}
	glEnd();
	glFlush();
	//glCallList(ID_COORDINATY);
}
void  RoamingScenceManager::loadPointCloudPLY(char *filename)
{
	int i;
	double x, y, z, c, g;
	VERTEX3D vMin, vMax;
	VERTEX3D vMean;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("ERROR: unable to open point cloud [%s]!\n", filename);
		exit(0);
	}
	// Read the number of points
	g_nPointsNumber = 0;
	while (fscanf(fp, "%lf", &x) && !feof(fp))
		g_nPointsNumber++;

	g_nPointsNumber = g_nPointsNumber / 3;

	printf("Number of points: %d\n", g_nPointsNumber);
	fseek(fp, 0L, SEEK_SET);
	//Allocate the points array
	g_ver = new VERTEX3D[g_nPointsNumber];
	//Read in the points
	for (i = 0; i<g_nPointsNumber; i++)
	{
		fscanf(fp, "%lf %lf %lf", &x, &y, &z);
		g_ver[i].x = x;
		g_ver[i].y = y;
		g_ver[i].z = z;
		if (i == 0)
		{
			vMin.x = vMax.x = g_ver[i].x;
			vMin.y = vMax.y = g_ver[i].y;
			vMin.z = vMax.z = g_ver[i].z;
		}
		else
			getMinMax(vMin, vMax, g_ver[i]);

		vMean.x += g_ver[i].x;
		vMean.y += g_ver[i].y;
		vMean.z += g_ver[i].z;
	}
	vMean.x = vMean.x / g_nPointsNumber;
	vMean.y = vMean.y / g_nPointsNumber;
	vMean.z = vMean.z / g_nPointsNumber;
	for (i = 0; i<g_nPointsNumber; i++)
	{
		//formatGeometry(g_ver[i], vMin, vMax, g_scale);
		g_ver[i].x = g_ver[i].x - vMean.x;
		g_ver[i].y = g_ver[i].y - vMean.y;
		g_ver[i].z = g_ver[i].z - vMean.z;
	}

	fclose(fp);
}
void RoamingScenceManager::getMinMax(VERTEX3D &vMin, VERTEX3D &vMax, VERTEX3D v)
{
	if (v.x < vMin.x) vMin.x = v.x;
	if (v.y < vMin.y) vMin.y = v.y;
	if (v.z < vMin.z) vMin.z = v.z;
	if (v.x > vMax.x) vMax.x = v.x;
	if (v.y > vMax.y) vMax.y = v.y;
	if (v.z > vMax.z) vMax.z = v.z;
}
void RoamingScenceManager::formatGeometry(VERTEX3D &v, VERTEX3D vMin, VERTEX3D vMax, double scale)
{
	v.x = scale*(v.x - 0.5*(vMin.x + vMax.x));
	v.y = scale*(v.y - 0.5*(vMin.y + vMax.y));
	v.z = scale*(v.z - 0.5*(vMin.z + vMax.z));
}


void RoamingScenceManager::executeRotateOperation(int x, int y)
{
    Mouse->setX(x);
    Mouse->setY(y);

    Vector3D MouseTrace=*AuxY*(OldMouse->Y()-Mouse->Y())+*AuxX*(Mouse->X()-OldMouse->X());
    Vector3D RotateAsix=Vector3D::crossProduct(MouseTrace,*AuxZ);
    RotateAsix.normalize();

    float angle=MouseTrace.length();
    Matrix4D rotatMatrix=Matrix4D::getRotateMatrix(angle,RotateAsix);

    *NewEye=rotatMatrix*(*NewEye);
    *NewUp=rotatMatrix*(*NewUp);

    NewUp->normalize();
    *AuxY=*NewUp;
    * AuxZ= (Vector3D)*NewEye- (Vector3D)*NewView;
    *AuxX=Vector3D::crossProduct(*AuxY,*AuxZ);
    AuxX->normalize();
    *OldMouse=*Mouse;
}

void RoamingScenceManager::executeScaleOperation(float factor)
{
      if(TempscaleFactor<=0)
      {
          TempscaleFactor=0.1;
      }else
      {
          TempscaleFactor+=factor;
      }
}

void RoamingScenceManager::executeTranslateOperation(int x, int y)
{
    Mouse->setX(x);
    Mouse->setY(y);
    Vector3D vec(-OldMouse->X()+Mouse->X(),-Mouse->Y()+OldMouse->Y(),0);
    *TempTranslateVec=*TempTranslateVec+vec;
    *OldMouse=*Mouse;
}

void RoamingScenceManager::getInitPos(int x, int y)
{
    Mouse->setX(x);
    Mouse->setY(y);
    *OldMouse=*Mouse;
}

void RoamingScenceManager::init_CoordinaryDisplayList()
{
    ID_COORDINATY=glGenLists(1);
    glNewList(ID_COORDINATY,GL_COMPILE);
    int length=500;
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(length,0.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,length,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,length);
    glEnd();

    glLineWidth(1);
    glEnd();
    glEndList();
}