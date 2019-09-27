#pragma once
#include "hinh.h"
class hcn :
	public hinh
{
private:
	int x1, x2, y1, y2;
public:
	hcn(CPoint p1, CPoint p2);
	hcn(int x1, int y1, int x2, int y2);
	void thietlap(int x1, int y1, int x2, int y2);
	CPoint getA();
	CPoint getC();
	void draw(CClientDC * pdc);
	int kttronghinh(CPoint p1);
	void dichuyen(int dx, int dy);
	float dientich();
	float chuvi();
	hcn(void);
	~hcn(void);
};

