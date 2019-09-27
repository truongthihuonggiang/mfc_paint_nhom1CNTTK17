#include "stdafx.h"
#include "tamgiac.h"
#include"math.h"


tamgiac::tamgiac(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	x1 =  (p1.x + p2.x)/2;
	y1 = p1.y;
	x2 = p1.x;
	y2 = p2.y;
	x3 = p2.x;
	y3 = p2.y;
	
}
tamgiac::tamgiac(int mx1, int my1, int mx2, int my2, int mx3, int my3)
{
	x1 = mx1;
	x2 = mx2;
	x3 = mx3;
	y1 = my1;
	y2 = my2;
	y3 = my3;
}
void tamgiac::thietlap(int mx1, int my1, int mx2, int my2, int mx3, int my3)
{
	x1 = mx1;
	x2 = mx2;
	x3 = mx3;
	y1 = my1;
	y2 = my2;
	y3 = my3;
}
CPoint tamgiac::getA()
{
	return CPoint(x1, y1);
}
CPoint tamgiac::getB()
{
	return CPoint(x2, y2);
}
CPoint tamgiac::getC()
{
	return CPoint(x3, y3);
}
void tamgiac::draw(CClientDC *pdc)
{
	pdc->MoveTo(x1, y1);

	CString ta,tb,tc,td;
	ta.Format(_T("(%d,%d)"), x1, y1);
	tb.Format(_T("(%d,%d)"), x2, y2);
	tc.Format(_T("(%d,%d)"), x3, y3);


	pdc->LineTo(x2, y2);
	pdc->LineTo(x3, y3);
	pdc->LineTo(x1, y1);
	tc.Format(_T("  Dien tich tam giac la : %f"), dientich());
	td.Format(_T("  Chu vi tam giac la : %f"), chuvi());
	pdc->TextOutW(x3, y3, tc);
	pdc->TextOutW(x3, y3+20, td);
}
float tamgiac::dientich()
{
	float s = 0;
	
	s = (float)((0.5 )* abs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)));
	return s;
}
float tamgiac::chuvi()
{
	float p = 0;
	float d1,d2,d3;
	d1=sqrt((float)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	d2=sqrt((float)((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)));
	d3=sqrt((float)((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)));
	p=d1+d2+d3;
	return p;
}
int tamgiac::kttronghinh(CPoint p1)
{
	tamgiac tg1, tg2, tg3;
	tg1.thietlap(x1, y1, x2, y2, p1.x, p1.y);
	tg2.thietlap(x2, y2, x3, y3, p1.x, p1.y);
	tg3.thietlap(x3, y3, x1, y1, p1.x, p1.y);
	int kq = -1;
	if ((tg1.dientich() + tg2.dientich() + tg3.dientich()) == dientich())
		kq = 1;
	return kq;
}

tamgiac tamgiac::doixung()
{
	int mx1 = x3 + x3 - x1;
	int my1 = y1;
	int mx2 = x3;
	int my2 = y3;
	int mx3 = x2 + 2 * (x3 - x2);
	int my3 = y2;
	tamgiac kq;
	kq.thietlap(mx1, my1, mx2, my2, mx3, my3);
	return kq;
}
tamgiac::tamgiac(void)
{
}


tamgiac::~tamgiac(void)
{
}
