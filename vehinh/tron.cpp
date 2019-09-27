#include "stdafx.h"
#include "tron.h"
#include"math.h"


tron::tron(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	
	x = (point1.x + point2.x) / 2;
	y = (point1.y + point2.y) / 2;
	r = (sqrt((float)((point1.x - point2.x)*(point1.x - point2.x) + (point1.y - point2.y)*(point1.y - point2.y))))/2;

	S=3.14*r*r;
	P=3.14 * r* 2;
}

/*

float tron::chuvi()
{
	float kq = 0;
	kq = 3.14 * r* 2;
	return (int)kq;
}


float tron::dientich()
{
	// TODO: Add your implementation code here.
	float kq=0;
	kq = 3.14 * r* r;
	return kq;
	
}*/


void tron::draw(CClientDC *pDC)
{
	// TODO: Add your implementation code here.
	pDC->Ellipse(point1.x, point1.y, point2.x, point2.y);
	CString Stron,Ptron;
	Stron.Format(_T("Dien tich hinh tron la : %d"),S);
	Ptron.Format(_T("Chu vi hinh tron la : %d"),P);
	pDC->TextOutW(point2.x, point2.y,Stron);
	pDC->TextOutW(point2.x, point2.y+20,Ptron);
}
tron::tron(void)
{
}


tron::~tron(void)
{
}
