
// slider0819Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "slider0819.h"
#include "slider0819Dlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cslider0819Dlg 대화 상자



Cslider0819Dlg::Cslider0819Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SLIDER0819_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cslider0819Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_slider1);
	DDX_Control(pDX, IDC_SLIDER2, m_slider2);
	DDX_Control(pDX, IDC_SLIDER3, m_slider3);
	DDX_Control(pDX, IDC_LISTCTRL, m_ListCtrl);
	DDX_Control(pDX, IDC_CHECK1, m_chk1);
	DDX_Control(pDX, IDC_CHECK2, m_chk2);
}

BEGIN_MESSAGE_MAP(Cslider0819Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Cslider0819Dlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &Cslider0819Dlg::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &Cslider0819Dlg::OnNMCustomdrawSlider3)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_LISTCTRL_ADD, &Cslider0819Dlg::OnBnClickedListctrlAdd)
	ON_BN_CLICKED(IDC_LISTCTRL_DEL, &Cslider0819Dlg::OnBnClickedListctrlDel)
	//ON_NOTIFY(NM_CLICK, IDC_LISTCTRL, &Cslider0819Dlg::OnNMClickListctrl)
	ON_EN_CHANGE(IDC_EDIT1, &Cslider0819Dlg::OnEnChangeEdit1)
	ON_NOTIFY(NM_CLICK, IDC_LISTCTRL, &Cslider0819Dlg::OnNMClickListctrl)
	ON_STN_CLICKED(IDC_STATIC_rgb1, &Cslider0819Dlg::OnStnClickedStaticrgb1)
END_MESSAGE_MAP()


// Cslider0819Dlg 메시지 처리기

BOOL Cslider0819Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.


	//슬라이더 범위 지정
	m_slider1.SetRange(0, 255);
	m_slider2.SetRange(0, 255);
	m_slider3.SetRange(0, 255);


	//List Control 초기화
	
	// 순번, 항목, 내용
	//CRect rt;
	//m_ListCtrl.GetWindowRect(&rt);
	//m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//m_ListCtrl.InsertColumn(0, TEXT("순번"), LVCFMT_LEFT, rt.Width() * 0.25);
	//m_ListCtrl.InsertColumn(1, TEXT("항목"), LVCFMT_CENTER, rt.Width() * 0.25);
	//m_ListCtrl.InsertColumn(2, TEXT("내용"), LVCFMT_CENTER, rt.Width() * 0.25);

	CRect rt;
	m_ListCtrl.GetWindowRect(&rt);
	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	m_ListCtrl.InsertColumn(0, TEXT("순번"), LVCFMT_LEFT, rt.Width() * 0.15);
	m_ListCtrl.InsertColumn(1, TEXT("RED"), LVCFMT_CENTER, rt.Width() * 0.15);
	m_ListCtrl.InsertColumn(2, TEXT("GREEN"), LVCFMT_CENTER, rt.Width() * 0.15);
	m_ListCtrl.InsertColumn(3, TEXT("BLUE"), LVCFMT_CENTER, rt.Width() * 0.15);
	m_ListCtrl.InsertColumn(4, TEXT("chk1"), LVCFMT_CENTER, rt.Width() * 0.15);
	m_ListCtrl.InsertColumn(5, TEXT("chk2"), LVCFMT_CENTER, rt.Width() * 0.15);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cslider0819Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cslider0819Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		CRect rect;
		CClientDC rgbdc(GetDlgItem(IDC_STATIC_rgb1));
		CStatic* pSRGB = (CStatic*)GetDlgItem(IDC_STATIC_rgb1);
		pSRGB->GetClientRect(rect);
		rgbdc.FillSolidRect(rect, m_cRGB);
		pSRGB->ValidateRect(rect);

		CRect rect2;
		CClientDC rgbdc2(GetDlgItem(IDC_STATIC_rgb2));
		CStatic* pSRGB2 = (CStatic*)GetDlgItem(IDC_STATIC_rgb2);
		pSRGB2->GetClientRect(rect2);
		rgbdc2.FillSolidRect(rect2, m_cRGB2);
		pSRGB2->ValidateRect(rect2);
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cslider0819Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cslider0819Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//int position;
	//position = m_slider1.GetPos();
	//SetDlgItemInt(IDC_EDIT1, position);

	int position1 = m_slider1.GetPos();
	int position2 = m_slider2.GetPos();
	int position3 = m_slider3.GetPos();

	CString str;
	str.Format(_T("(%d, %d, %d)"), position1, position2, position3);

	SetDlgItemText(IDC_EDIT1, str);
	SetDlgItemInt(IDC_EDIT2, position1);

	*pResult = 0;
}


void Cslider0819Dlg::OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int position1 = m_slider1.GetPos();
	int position2 = m_slider2.GetPos();
	int position3 = m_slider3.GetPos();

	CString str;
	str.Format(_T("(%d, %d, %d)"), position1, position2, position3);

	SetDlgItemText(IDC_EDIT1, str);
	SetDlgItemInt(IDC_EDIT3, position2);

	*pResult = 0;
}


void Cslider0819Dlg::OnNMCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int position1 = m_slider1.GetPos();
	int position2 = m_slider2.GetPos();
	int position3 = m_slider3.GetPos();

	CString str;
	str.Format(_T("(%d, %d, %d)"), position1, position2, position3);

	SetDlgItemText(IDC_EDIT1, str);
	SetDlgItemInt(IDC_EDIT4, position3);

	*pResult = 0;
}


void Cslider0819Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	int position1 = m_slider1.GetPos();
	int position2 = m_slider2.GetPos();
	int position3 = m_slider3.GetPos();

	CString str;
	str.Format(_T("(%d, %d, %d)"), position1, position2, position3);

	SetDlgItemText(IDC_EDIT1, str);
	SetDlgItemInt(IDC_EDIT2, position1);
	SetDlgItemInt(IDC_EDIT3, position2);
	SetDlgItemInt(IDC_EDIT4, position3);

	int clickidx = m_ListCtrl.GetSelectionMark();
	
	if (clickidx != -1) { //선택된 항이 있는 경우
		CString pos1, pos2, pos3;
		pos1.Format(_T("%d"), position1);
		pos2.Format(_T("%d"), position2);
		pos3.Format(_T("%d"), position3);

		m_ListCtrl.SetItem(clickidx, 1, LVIF_TEXT, pos1, NULL, NULL, NULL, NULL);
		m_ListCtrl.SetItem(clickidx, 2, LVIF_TEXT, pos2, NULL, NULL, NULL, NULL);
		m_ListCtrl.SetItem(clickidx, 3, LVIF_TEXT, pos3, NULL, NULL, NULL, NULL);
	}
		
	CRect rect;
	GetDlgItem(IDC_STATIC_rgb1)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	m_cRGB = RGB(position1, position2, position3);
	UpdateData(FALSE);
	InvalidateRect(&rect);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void Cslider0819Dlg::OnBnClickedListctrlAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 순번, 항목, 내용
	/*int num = m_ListCtrl.GetItemCount();

	CString str;
	str.Format(_T("%d"), num);
	m_ListCtrl.InsertItem(num, str);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, TEXT("test"), NULL, NULL, NULL, NULL);

	CString str2;
	GetDlgItemTextW(IDC_LISTCTRL_EDIT, str2);

	m_ListCtrl.SetItem(num, 2, LVIF_TEXT, str2, NULL, NULL, NULL, NULL);*/

	int position1 = m_slider1.GetPos();
	int position2 = m_slider2.GetPos();
	int position3 = m_slider3.GetPos();

	CString pos1, pos2, pos3;
	pos1.Format(_T("%d"), position1);
	pos2.Format(_T("%d"), position2);
	pos3.Format(_T("%d"), position3);

	int num = m_ListCtrl.GetItemCount();
	CString str;
	str.Format(_T("%d"), num);
	m_ListCtrl.InsertItem(num, str);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, pos1, NULL, NULL, NULL, NULL);
	m_ListCtrl.SetItem(num, 2, LVIF_TEXT, pos2, NULL, NULL, NULL, NULL);
	m_ListCtrl.SetItem(num, 3, LVIF_TEXT, pos3, NULL, NULL, NULL, NULL);

	bool chk1 = 0, chk2 = 0;
	
	chk1 = m_chk1.GetCheck();
	chk2 = m_chk2.GetCheck();
	CString y = _T("Y"), n = _T("N");

	if (chk1 == 1) {
		m_ListCtrl.SetItem(num, 4, LVIF_TEXT, y, NULL, NULL, NULL, NULL);
	}
	else {
		m_ListCtrl.SetItem(num, 4, LVIF_TEXT, n, NULL, NULL, NULL, NULL);
	}

	if (chk2 == 1) {
		m_ListCtrl.SetItem(num, 5, LVIF_TEXT, y, NULL, NULL, NULL, NULL);
	}
	else {
		m_ListCtrl.SetItem(num, 5, LVIF_TEXT, n, NULL, NULL, NULL, NULL);
	}

}


void Cslider0819Dlg::OnBnClickedListctrlDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 순번, 항목, 내용
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	int idx = m_ListCtrl.GetNextSelectedItem(pos);
	m_ListCtrl.DeleteItem(idx);

}


//void Cslider0819Dlg::OnNMClickListctrl(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//int clickidx = m_ListCtrl.GetSelectionMark();

	//int position1 = m_slider1.GetPos();
	//int position2 = m_slider2.GetPos();
	//int position3 = m_slider3.GetPos();

	//CString pos1, pos2, pos3;
	//pos1.Format(_T("%d"), position1);
	//pos2.Format(_T("%d"), position2);
	//pos3.Format(_T("%d"), position3);

	//m_ListCtrl.InsertItem(clickidx, pos1);
	//m_ListCtrl.SetItem(clickidx, 1, LVIF_TEXT, pos2, NULL, NULL, NULL, NULL);
	//m_ListCtrl.SetItem(clickidx, 2, LVIF_TEXT, pos3, NULL, NULL, NULL, NULL);

	

//	*pResult = 0;
//}


void Cslider0819Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cslider0819Dlg::OnNMClickListctrl(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int clickidx = m_ListCtrl.GetSelectionMark();
	
	if (clickidx == -1) {
		*pResult = 0;
	}

	CString R=m_ListCtrl.GetItemText(clickidx, 1);
	CString G = m_ListCtrl.GetItemText(clickidx, 2);
	CString B = m_ListCtrl.GetItemText(clickidx, 3);

	int Red = _ttoi(R);
	int Green = _ttoi(G);
	int Blue = _ttoi(B);

	CRect rect;
	GetDlgItem(IDC_STATIC_rgb2)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	m_cRGB2 = RGB(Red, Green, Blue);
	UpdateData(FALSE);
	InvalidateRect(&rect);

	*pResult = 0;
}


void Cslider0819Dlg::OnStnClickedStaticrgb1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
