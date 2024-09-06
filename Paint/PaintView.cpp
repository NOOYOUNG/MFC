
// PaintView.cpp: CPaintView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Paint.h"
#endif

#include "PaintDoc.h"
#include "PaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

BEGIN_MESSAGE_MAP(CPaintView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)

	ON_COMMAND_RANGE(ID_FREELINE, ID_ELLIPSE, OnChangTool)
	ON_UPDATE_COMMAND_UI_RANGE(ID_FREELINE, ID_ELLIPSE, OnUpdateChangeTool)
	ON_COMMAND(ID_LINECOLOR, &CPaintView::OnLinecolor)
	ON_COMMAND(ID_FILLCOLOR, &CPaintView::OnFillcolor)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CPaintView 생성/소멸

CPaintView::CPaintView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPaintView::~CPaintView()
{
}

BOOL CPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPaintView 그리기

void CPaintView::OnDraw(CDC* /*pDC*/)
{
	CPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPaintView 인쇄

BOOL CPaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPaintView 진단

#ifdef _DEBUG
void CPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintDoc* CPaintView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintDoc)));
	return (CPaintDoc*)m_pDocument;
}
#endif //_DEBUG


// CPaintView 메시지 처리기

void CPaintView::OnChangTool(UINT wParam)
{
	m_nType = GetCurrentMessage()->wParam;
}

void CPaintView::OnUpdateChangeTool(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nType == (int)pCmdUI->m_nID);
}

void CPaintView::OnLinecolor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_colLine = dlg.GetColor();
		m_colLineXor = (RGB(GetRValue(m_colLine) ^ 255, GetGValue(m_colLine) ^ 255, GetBValue(m_colLine) ^ 255));
	}
}


void CPaintView::OnFillcolor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_colFill = dlg.GetColor();
	}
}


void CPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	ReleaseCapture();

	CClientDC dc(this);

	CBrush brush, * poldBrush;
	if (m_nType == ID_RECTANGLE) {
		brush.CreateSolidBrush(m_colFill);

		poldBrush = (CBrush*)dc.SelectObject(brush);

		dc.Rectangle(m_pntOld.x, m_pntOld.y, point.x, point.y);
	}
	else if (m_nType == ID_ELLIPSE) {
		brush.CreateSolidBrush(m_colFill);
		poldBrush = (CBrush*)dc.SelectObject(brush);
		dc.Ellipse(m_pntOld.x, m_pntOld.y, point.x, point.y);
	}

	CView::OnLButtonUp(nFlags, point);
}


void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pntOld = point;
	m_pntCur = point;
	SetCapture();

	CView::OnLButtonDown(nFlags, point);
}


void CPaintView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON) {
		CClientDC dc(this);

		//펜과 브러쉬 속성 변경
		CPen pen, * pOldPen;
		CBrush brush, * pOldBrush;

		if (m_nType == ID_FREELINE) { // 자유곡선
			pen.CreatePen(PS_SOLID, 1, m_colLine); // 선택한 색으로 펜 생성

			pOldPen = (CPen*)dc.SelectObject(&pen); // 생성한 펜 선택

			dc.MoveTo(m_pntOld.x, m_pntOld.y); // 직전 좌표에서 현재 좌표까지 선 그림
			dc.LineTo(point.x, point.y);

			m_pntOld = point; // 현재 좌표 저장
			dc.SelectObject(pOldPen);
		}
		else if (m_nType == ID_LINE) { // 직선
			pen.CreatePen(PS_SOLID, 1, m_colLineXor); // xor된 색으로 펜 생성

			dc.SelectObject(GetStockObject(NULL_BRUSH)); // NULL 브러쉬(투명브러쉬) 선택

			dc.SetROP2(R2_XORPEN); // 그리기 모드를 XOR 모드로 변경

			pOldPen = (CPen*)dc.SelectObject(&pen); // 선색으로 펜 생성

			// 이전 그림 지우기
			dc.MoveTo(m_pntOld.x, m_pntOld.y);
			dc.LineTo(m_pntCur.x, m_pntCur.y);

			// 새 그림 그리기
			dc.MoveTo(m_pntOld.x, m_pntOld.y);
			dc.LineTo(point.x, point.y);

			dc.SelectObject(pOldPen);
		}
		else if (m_nType == ID_RECTANGLE) { // 사각형
			pen.CreatePen(PS_SOLID, 1, m_colLineXor);

			dc.SelectObject(GetStockObject(NULL_BRUSH));

			dc.SetROP2(R2_XORPEN);

			pOldPen = (CPen*)dc.SelectObject(&pen);

			dc.Rectangle(m_pntOld.x, m_pntOld.y, m_pntCur.x, m_pntCur.y);

			dc.Rectangle(m_pntOld.x, m_pntOld.y, point.x, point.y);
			
			dc.SelectObject(pOldPen);
		}
		else if (m_nType = ID_ELLIPSE) { // 원
			pen.CreatePen(PS_SOLID, 1, m_colLineXor);

			dc.SelectObject(GetStockObject(NULL_BRUSH));

			dc.SetROP2(R2_XORPEN);

			pOldPen = (CPen*)dc.SelectObject(&pen);

			dc.Ellipse(m_pntOld.x, m_pntOld.y, m_pntCur.x, m_pntCur.y);

			dc.Ellipse(m_pntOld.x, m_pntOld.y, point.x, point.y);

			dc.SelectObject(pOldPen);
		}
		m_pntCur = point;
	}


	CView::OnMouseMove(nFlags, point);
}
