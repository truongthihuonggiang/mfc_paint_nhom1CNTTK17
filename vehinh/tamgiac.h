#pragma once
#include "hinh.h"
class tamgiac :
	public hinh
{
public:
	private:
	int x1, y1, x2, y2, x3, y3;
public:
	tamgiac(CPoint p1, CPoint p2);
	tamgiac(int mx1, int my1, int mx2, int my2, int mx3, int my3);
	void thietlap(int mx1, int my1, int mx2, int my2, int mx3, int my3);
	int kttronghinh(CPoint p1);
	CPoint getA();
	CPoint getB();
	CPoint getC();
	float dientich();
	float chuvi();
	void draw(CClientDC *pDC);
	tamgiac doixung();
	tamgiac(void);
	~tamgiac(void);
};

