// CTab2.cpp: 구현 파일
//

#include "pch.h"
#include "240823_tabCtrl.h"
#include "afxdialogex.h"
#include "CTab2.h"


// CTab2 대화 상자

IMPLEMENT_DYNAMIC(CTab2, CDialogEx)

CTab2::CTab2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CTab2::~CTab2()
{
}

void CTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_T2_slider1);
	DDX_Control(pDX, IDC_SLIDER2, m_T2_slider2);
	DDX_Control(pDX, IDC_SLIDER3, m_T2_slider3);
}


BEGIN_MESSAGE_MAP(CTab2, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CTab2::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CTab2::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CTab2::OnNMCustomdrawSlider3)
	ON_WM_HSCROLL()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTab2 메시지 처리기


void CTab2::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	*pResult = 0;
}


void CTab2::OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CTab2::OnNMCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


BOOL CTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_T2_slider1.SetRange(0, 255);
	m_T2_slider2.SetRange(0, 255);
	m_T2_slider3.SetRange(0, 255);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTab2::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	int pos1 = m_T2_slider1.GetPos();
	int pos2 = m_T2_slider2.GetPos();
	int pos3 = m_T2_slider3.GetPos();

	CRect rect;
	GetDlgItem(IDC_STATIC_rgb)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	m_cRGB = RGB(pos1, pos2, pos3);
	UpdateData(FALSE);
	InvalidateRect(&rect);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CTab2::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	CRect rect;
	CClientDC rgbdc(GetDlgItem(IDC_STATIC_rgb));
	CStatic* pSRGB = (CStatic*)GetDlgItem(IDC_STATIC_rgb);
	pSRGB->GetClientRect(rect);
	rgbdc.FillSolidRect(rect, m_cRGB);
	pSRGB->ValidateRect(rect);
}
