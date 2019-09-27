
// vehinhView.cpp : implementation of the CvehinhView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "vehinh.h"
#endif

#include "vehinhDoc.h"
#include "vehinhView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CvehinhView

IMPLEMENT_DYNCREATE(CvehinhView, CView)

BEGIN_MESSAGE_MAP(CvehinhView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CvehinhView construction/destruction

CvehinhView::CvehinhView()
{
	// TODO: add construction code here
	b1.thietlap(100, 10, 240,60);
	b1.text = CString("Hinh Chu Nhat");
	b2.thietlap(300, 10, 400, 60);
	b2.text = CString("Tam Giac");
	b3.thietlap(450, 10, 550, 60);
	b3.text = CString("Hinh Tron");
	b3.thietlap(450, 10, 550, 60);
	b4.thietlap(0,0,1400,75);
	c1.thietlap(700,20,730,50);
	c2.thietlap(740,20,770,50);
	c3.thietlap(780,20,810,50);
	c4.thietlap(820,20,850,50);
	control = 0;
	color=0;
	n = 0;
}

CvehinhView::~CvehinhView()
{
}

BOOL CvehinhView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CvehinhView drawing

void CvehinhView::OnDraw(CDC* /*pDC*/)
{
	CvehinhDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC = new CClientDC(this);
	
	
	CBrush *newbrush=new CBrush(RGB(186,200,240));
	CBrush *newbrush1=new CBrush(RGB(255,255,255));
	CBrush *newbrush2=new CBrush(RGB(255,0,0));
	CBrush *newbrush3=new CBrush(RGB(0,255,0));
	CBrush *newbrush4=new CBrush(RGB(0,0,255));
	CBrush *newbrush5=new CBrush(RGB(125,125,125));

	pDC->SelectObject(newbrush);
	b4.draw(pDC);

	pDC->SelectObject(newbrush1);
	b1.draw(pDC);
	b2.draw(pDC);
	b3.draw(pDC);
	pDC->SelectObject(newbrush2);
	c1.draw(pDC);
	pDC->SelectObject(newbrush3);
	c2.draw(pDC);
	pDC->SelectObject(newbrush4);
	c3.draw(pDC);
	pDC->SelectObject(newbrush5);
	c4.draw(pDC);
	pDC->SelectObject(newbrush1);
	// TODO: add draw code for native data here
}


// CvehinhView printing

BOOL CvehinhView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CvehinhView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CvehinhView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CvehinhView diagnostics

#ifdef _DEBUG
void CvehinhView::AssertValid() const
{
	CView::AssertValid();
}

void CvehinhView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CvehinhDoc* CvehinhView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CvehinhDoc)));
	return (CvehinhDoc*)m_pDocument;
}
#endif //_DEBUG


// CvehinhView message handlers


void CvehinhView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x = point.x;
	p1.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CvehinhView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p2.x = point.x;
	p2.y = point.y;
	if (b1.kttronghinh(point) == 1)
		control = 1;
	else if (b2.kttronghinh(point) == 1)
		control = 2;
	else if (b3.kttronghinh(point) == 1)
		control = 3;
	else if(c1.kttronghinh(point)==1)
		color=1;
	else if(c2.kttronghinh(point)==1)
		color=2;
	else if(c3.kttronghinh(point)==1)
		color=3;
	else if(c4.kttronghinh(point)==1)
		color=4;
	else if ( control ==1 && color ==1)//hcn
					{
						ph[n] = new hcn(p1, p2);
						CBrush *newbrush=new CBrush(RGB(255,0,0));

						pDC->SelectObject(newbrush);
						ph[n]->draw(pDC);
						n++;
					}
	else if ( control ==1 && color ==2)//hcn
					{
						ph[n] = new hcn(p1, p2);
						CBrush *newbrush=new CBrush(RGB(0,255,0));

						pDC->SelectObject(newbrush);
						ph[n]->draw(pDC);
						n++;
					}
	else if ( control ==1 && color ==3)//hcn
					{
						ph[n] = new hcn(p1, p2);
						CBrush *newbrush=new CBrush(RGB(0,0,255));

						pDC->SelectObject(newbrush);
						ph[n]->draw(pDC);
						n++;
					}
	else if ( control ==1 && color ==4)//hcn
					{
						ph[n] = new hcn(p1, p2);
						CBrush *newbrush=new CBrush(RGB(125,125,125));

						pDC->SelectObject(newbrush);
						ph[n]->draw(pDC);
						n++;
					}
	else if (control == 1 )//hcn
					{
						ph[n] = new hcn(p1, p2);
						ph[n]->draw(pDC);
						n++;
						
					}
	else if (control == 2)//tg
						{
							ph[n] = new tamgiac(p1, p2);
							ph[n]->draw(pDC);
							n++;
						}
	else if (  color==1&&control==3)//hinhtron
						{
							ph[n] = new tron(p1, p2);
							CBrush *newbrush=new CBrush(RGB(255,0,0));
							pDC->SelectObject(newbrush);
							ph[n]->draw(pDC);
							n++;
						}
	else if (  color==2&&control==3)//hinhtron
						{
							ph[n] = new tron(p1, p2);
							CBrush *newbrush=new CBrush(RGB(0,255,0));
							pDC->SelectObject(newbrush);
							ph[n]->draw(pDC);
							n++;
						}
	else if (  color==3&&control==3)//hinhtron
						{
							ph[n] = new tron(p1, p2);
							CBrush *newbrush=new CBrush(RGB(0,0,255));
							pDC->SelectObject(newbrush);
							ph[n]->draw(pDC);
							n++;
						}
	else if (  color==4&&control==3)//hinhtron
						{
							ph[n] = new tron(p1, p2);
							CBrush *newbrush=new CBrush(RGB(125,125,125));
							pDC->SelectObject(newbrush);
							ph[n]->draw(pDC);
							n++;
						}	
	else if (control == 3)//hinhtron
						{
							ph[n] = new tron(p1, p2);
							
							ph[n]->draw(pDC);
							n++;
						}
			

	CView::OnLButtonUp(nFlags, point);
}
