#pragma once
class hinh
{
public:
	CPoint point1, point2;
	hinh();
	~hinh();
	virtual void draw(CClientDC *pDC);
	virtual float dientich();
	virtual float chuvi();
	virtual int kttronghinh(CPoint p1);
	
};

