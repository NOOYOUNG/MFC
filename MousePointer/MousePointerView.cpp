
// MousePointerView.cpp: CMousePointerView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MousePointer.h"
#endif

#include "MousePointerDoc.h"
#include "MousePointerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMousePointerView

IMPLEMENT_DYNCREATE(CMousePointerView, CView)

BEGIN_MESSAGE_MAP(CMousePointerView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMousePointerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMousePointerView 생성/소멸

CMousePointerView::CMousePointerView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMousePointerView::~CMousePointerView()
{
}

BOOL CMousePointerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMousePointerView 그리기

void CMousePointerView::OnDraw(CDC* /*pDC*/)
{
	CMousePointerDoc* pDoc = GetDocument(); // 현재 문서 객체를 가져옵니다.
	ASSERT_VALID(pDoc);  // pDoc 포인터가 유효한지 확인, ASSERT_VALID은 디버그 모드에서만 작동
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CClientDC dc(this); // 화면에 그리기 위한 클라이언트 DC(Device Context) 생성
	CString strPoint; // 문자열 저장할 CString 객체 선언
	strPoint.Format(_T("마우스 좌표(%4d, %4d)"), m_Pos.x, m_Pos.y); // 마우스의 현재 좌표 저장
	dc.TextOutW(0, 0, strPoint); // 형식화된 문자열을 (0, 0) 위치에 텍스트로 출력
}


// CMousePointerView 인쇄


void CMousePointerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMousePointerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMousePointerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMousePointerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMousePointerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMousePointerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMousePointerView 진단

#ifdef _DEBUG
void CMousePointerView::AssertValid() const
{
	CView::AssertValid();
}

void CMousePointerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMousePointerDoc* CMousePointerView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMousePointerDoc)));
	return (CMousePointerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMousePointerView 메시지 처리기


void CMousePointerView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_Pos = point; // m_Pos를 현재 마우스 포인터의 위치로 업데이트
	Invalidate(); // Invalidate()를 호출하여 뷰를 무효화하고, 화면을 다시 그리도록 요청

	CView::OnMouseMove(nFlags, point);
}
