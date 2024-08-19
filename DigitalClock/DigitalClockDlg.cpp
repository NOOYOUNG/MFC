
// DigitalClockDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "DigitalClock.h"
#include "DigitalClockDlg.h"
#include "afxdialogex.h"

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
public:
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_MBUTTONDOWN()
END_MESSAGE_MAP()


// CDigitalClockDlg 대화 상자



CDigitalClockDlg::CDigitalClockDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIGITALCLOCK_DIALOG, pParent)
	, m_Time(_T(""))
	, m_milli(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_msec = 0;
}

void CDigitalClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, mTIme);
	//  DDX_Text(pDX, IDC_EDIT1, m_TIme);
	DDX_Text(pDX, IDC_STATICTime, m_Time);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_STATICmilli, m_milli);
}

BEGIN_MESSAGE_MAP(CDigitalClockDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDigitalClockDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDigitalClockDlg::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON3, &CDigitalClockDlg::OnBnClickedButton3)
	ON_WM_MBUTTONUP()
END_MESSAGE_MAP()


// CDigitalClockDlg 메시지 처리기

BOOL CDigitalClockDlg::OnInitDialog()
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


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDigitalClockDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDigitalClockDlg::OnPaint()
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
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDigitalClockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDigitalClockDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(1, 100, NULL);
	m_msec = 0;
}


void CDigitalClockDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	KillTimer(1);
}


void CDigitalClockDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	switch (nIDEvent) {
	case 1:
		CTime cTime = CTime::GetCurrentTime();
		m_Time.Format(L"지금은 %04d년 %02d월 %02d일 %02d시 %02d분 %02d초", cTime.GetYear(), cTime.GetMonth(), cTime.GetDay(), cTime.GetHour(), cTime.GetMinute(), cTime.GetSecond());
		SetDlgItemText(IDC_STATICTime, m_Time);

		m_msec++;
		m_milli.Format(L"%02d:%02d.%d", m_msec / 10 / 60, m_msec / 10 % 60, m_msec % 10);
		SetDlgItemText(IDC_STATICmilli, m_milli);

		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CDigitalClockDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_list.AddString(m_Time);
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CDigitalClockDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_list.AddString(m_milli);
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CDigitalClockDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_msec = 0;
	SetDlgItemText(IDC_STATICmilli, 0);
}


//void CAboutDlg::OnMButtonDown(UINT nFlags, CPoint point)
//{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

//	CDialogEx::OnMButtonDown(nFlags, point);
//}


void CDigitalClockDlg::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (KillTimer(1) == 0) {
		int result = AfxMessageBox(L"디지털 시계를 동작시키겠습니까?", MB_YESNO | MB_ICONQUESTION);

		if (result == IDYES) {
			SetTimer(1, 100, NULL);
		}
		else if (result == IDNO) {

		}
	}
	else {
		int result = AfxMessageBox(L"정말로 디지털 시계 동작을 멈추겠습니까?", MB_YESNO | MB_ICONQUESTION);

		if (result == IDYES) {
			KillTimer(1);
		}
		else if (result == IDNO) {

		}
	}

	CDialogEx::OnMButtonUp(nFlags, point);
}
