#pragma once
#include "hinh.h"
class tron :
	public hinh
{
private: 
	int x,y;
	int S,P;
	int r;
public:
	tron(CPoint p1, CPoint p2);
	//float chuvi();
	//float dientich();
	void draw(CClientDC *pdc);
	tron(void);
	~tron(void);
};

