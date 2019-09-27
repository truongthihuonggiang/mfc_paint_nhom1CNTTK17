
// vehinhView.h : interface of the CvehinhView class
//

#pragma once
#include "nutbam.h"
#include "hinh.h"
#include "hcn.h"
#include "tron.h"
#include "tamgiac.h"

class CvehinhView : public CView
{
protected: // create from serialization only
	CvehinhView();
	DECLARE_DYNCREATE(CvehinhView)

// Attributes
public:
	CvehinhDoc* GetDocument() const;
	nutbam b1, b2, b3,b4,c1,c2,c3,c4;
	CClientDC *pDC;
	CPoint p1, p2;
	int control;
	int color;
	hinh *ph[20];
	int n;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CvehinhView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in vehinhView.cpp
inline CvehinhDoc* CvehinhView::GetDocument() const
   { return reinterpret_cast<CvehinhDoc*>(m_pDocument); }
#endif

