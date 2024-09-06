
// PaintView.h: CPaintView 클래스의 인터페이스
//

#pragma once


class CPaintView : public CView
{
protected: // serialization에서만 만들어집니다.
	CPaintView() noexcept;
	DECLARE_DYNCREATE(CPaintView)

// 특성입니다.
public:
	CPaintDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

	afx_msg void OnChangTool(UINT wParam);
	afx_msg void OnUpdateChangeTool(CCmdUI* pCmdUI);

public:
	COLORREF m_colLine, m_colFill;
	COLORREF m_colLineXor;
	int m_nType;
	CPoint m_pntOld, m_pntCur;
	afx_msg void OnLinecolor();
	afx_msg void OnFillcolor();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // PaintView.cpp의 디버그 버전
inline CPaintDoc* CPaintView::GetDocument() const
   { return reinterpret_cast<CPaintDoc*>(m_pDocument); }
#endif

