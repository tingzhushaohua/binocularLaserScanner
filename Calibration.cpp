#include"Calibration.h"

Calibration::Calibration()
{
	times = 0;
	H = 150;
	points.clear();
}

Calibration::~Calibration()
{

}

void Calibration::cal_M()
{

	double m[3][4];

	m[2][3] = H;
	m[0][3] = points[0].x*H;
	m[1][3] = points[0].y*H;
	m[2][2] = ((points[0].x - points[1].x)*(points[2].y - points[3].y) - (points[2].x - points[3].x)*(points[0].y - points[1].y)) /
		((points[1].x - points[3].x)*(points[2].y - points[3].y) - (points[2].x - points[3].x)*(points[1].y - points[3].y));
	m[2][1] = ((points[0].x - points[2].x)*(points[1].y - points[3].y) - (points[1].x - points[3].x)*(points[0].y - points[2].y)) /
		((points[2].x - points[3].x)*(points[1].y - points[3].y) - (points[1].x - points[3].x)*(points[2].y - points[3].y));
	m[0][2] = ((points[0].x*points[2].x*(points[1].y - points[3].y) + points[0].x*points[3].x*(points[2].y - points[1].y)) +
		points[1].x*points[2].x*(points[3].y - points[0].y) + points[1].x*points[3].x*(points[0].y - points[2].y)) /
		((points[1].x - points[3].x)*(points[2].y - points[3].y) - (points[2].x - points[3].x)*(points[1].y - points[3].y));
	m[0][1] = ((points[0].x*points[1].x*(points[2].y - points[3].y) + points[0].x*points[3].x*(points[1].y - points[2].y)) +
		points[1].x*points[2].x*(points[3].y - points[0].y) + points[2].x*points[3].x*(points[0].y - points[1].y)) /
		((points[2].x - points[3].x)*(points[1].y - points[3].y) - (points[1].x - points[3].x)*(points[2].y - points[3].y));
	m[1][2] = ((points[0].x*points[1].y - points[1].x*points[0].y)*(points[2].y - points[3].y) +
		(points[3].x*points[2].y - points[2].x*points[3].y)*(points[0].y - points[1].y)) /
		((points[1].x - points[3].x)*(points[2].y - points[3].y) - (points[2].x - points[3].x)*(points[1].y - points[3].y));
	m[1][1] = ((points[0].x*points[2].y - points[2].x*points[0].y)*(points[1].y - points[3].y) +
		(points[3].x*points[1].y - points[1].x*points[3].y)*(points[0].y - points[2].y)) /
		((points[2].x - points[3].x)*(points[1].y - points[3].y) - (points[1].x - points[3].x)*(points[2].y - points[3].y));
	m[2][0] = (points[0].y - points[1].y - points[4].y + points[5].y - (points[1].y - points[5].y)*m[2][2]) /
		(points[4].y - points[5].y);

	m[0][0] = points[4].x - points[0].x + points[4].x*m[2][0];
	m[1][0] = points[4].y - points[0].y + points[4].y*m[2][0];

	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<4; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}

	//计算参数
	double mhe2 = 1 / (m[2][0] * m[2][0] + m[2][1] * m[2][1] + m[2][2] * m[2][2]);
	double mh = sqrt(mhe2);
	double r3[3];
	for (int i = 0; i<3; i++)
		r3[i] = mh*m[2][i];
	u = mhe2*(m[0][0] * m[2][0] + m[0][1] * m[2][1] + m[0][2] * m[2][2]);
	v = mhe2*(m[1][0] * m[2][0] + m[1][1] * m[2][1] + m[1][2] * m[2][2]);
	double ax[3];
	ax[0] = m[0][1] * m[2][2] - m[0][2] * m[2][1];
	ax[1] = m[0][2] * m[2][0] - m[0][0] * m[2][2];
	ax[2] = m[0][0] * m[2][1] - m[0][1] * m[2][0];
	fx = mhe2*sqrt(ax[0] * ax[0] + ax[1] * ax[1] + ax[2] * ax[2]);
	double ay[3];
	ay[0] = m[1][1] * m[2][2] - m[1][2] * m[2][1];
	ay[1] = m[1][2] * m[2][0] - m[1][0] * m[2][2];
	ay[2] = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	fy = mhe2*sqrt(ay[0] * ay[0] + ay[1] * ay[1] + ay[2] * ay[2]);
	double r1[3];
	for (int i = 0; i<3; i++)
		r1[i] = mh*(m[0][i] - u*m[2][i]) / fx;
	double r2[3];
	for (int i = 0; i<3; i++)
		r2[i] = mh*(m[1][i] - v*m[2][i]) / fy;
	tz = mh*H;
	tx = mh*(m[0][3] - u*H) / fx;
	ty = mh*(m[1][3] - v*H) / fy;
	T = (Mat_<double>(3, 1) << tx, ty, tz);
	R = (Mat_<double>(3, 3) <<
		r1[0], r1[1], r1[2],
		r2[0], r2[1], r2[2],
		r3[0], r3[1], r3[2]);
	for (int i = 0; i<3; i++)
	{
		cout << r1[i] << " " << r2[i] << " " << r3[i] << endl;
	}
	cout << tx << " " << ty << " " << tz << endl; //平移向量的三分量
	cout << fx << " " << fy << endl;
	cout << u << " " << v << endl;
}
void Calibration::putPoint(double x, double y)
{
	points.push_back(cvPoint2D32f(x, y));
}