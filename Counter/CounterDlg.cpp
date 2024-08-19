
// CounterDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Counter.h"
#include "CounterDlg.h"
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


// CCounterDlg 대화 상자



CCounterDlg::CCounterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COUNTER_DIALOG, pParent)
	, m_display(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_op1 = 0;
	m_op2 = 0;
	m_operator = 0;
	m_result = 0;
	m_opDone = false;
}

void CCounterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_display);
	DDX_Text(pDX, IDC_EDIT1, m_display);
}

BEGIN_MESSAGE_MAP(CCounterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CCounterDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CCounterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCounterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCounterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCounterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCounterDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCounterDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCounterDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCounterDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCounterDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCounterDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &CCounterDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &CCounterDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CCounterDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCounterDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CCounterDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CCounterDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON18, &CCounterDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCounterDlg::OnBnClickedButton19)
END_MESSAGE_MAP()


// CCounterDlg 메시지 처리기

BOOL CCounterDlg::OnInitDialog()
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

void CCounterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCounterDlg::OnPaint()
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
HCURSOR CCounterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCounterDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(L"계산기 프로그램을 종료합니다.", L"종료");
	CDialogEx::OnCancel();
}


void CCounterDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'1';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'2';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'3';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'4';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'5';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'6';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'7';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'8';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'9';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display = m_display + L'0';
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_display.Insert(0, '-');
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	if (m_operator == 1) {
		int a = 0;
		a = m_display.Find('+');
		m_op1 = _ttoi(m_display.Left(a)); // '+' 전에 있는 문자열을 얻을 수 있다.
		m_op2 = _ttoi(m_display.Mid(a + 1)); //'+' 뒤에 있는 문자열을 얻을 수 있다.

		m_result = m_op1 + m_op2;
		m_display.Format(L"%d", m_result);
	}
	else if (m_operator == 2) {
		int a = 0;
		a = m_display.Find('-');
		m_op1 = _ttoi(m_display.Left(a));
		m_op2 = _ttoi(m_display.Mid(a + 1));

		m_result = m_op1 - m_op2;
		m_display.Format(L"%d", m_result);
	}
	else if (m_operator == 3) {
		int a = 0;
		a = m_display.Find('*');
		m_op1 = _ttoi(m_display.Left(a));
		m_op2 = _ttoi(m_display.Mid(a + 1));

		m_result = m_op1 * m_op2;
		m_display.Format(L"%d", m_result);
	}
	else if (m_operator == 4) {
		int a = 0;
		a = m_display.Find('/');
		m_op1 = _ttoi(m_display.Left(a));
		m_op2 = _ttoi(m_display.Mid(a + 1));

		if (m_op2 == 0) {
			m_result = 0;
		}
		else {
			m_result = m_op1 / m_op2;
		}
		m_display.Format(L"%d", m_result);
	}
	else if (m_operator == 0) {
		int a = 0;
		a = m_display.Find('=');
		m_op1 = _ttoi(m_display.Left(a));
		m_display.Format(L"%d", m_op1);
	}

	m_opDone = true;
	UpdateData(FALSE);
}

void CCounterDlg::OnBnClickedButton13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_operator = 1;
	m_display = m_display + L"+";
	m_opDone = false;
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_operator = 2;
	m_display = m_display + L"-";
	m_opDone = false;
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_operator = 3;
	m_display = m_display + L"*";
	m_opDone = false;
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_operator = 4;
	m_display = m_display + L"/";
	m_opDone = false;
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_display = "";
	m_op1 = 0;
	m_op2 = 0;
	m_operator = 0;
	m_opDone = false;
	UpdateData(FALSE);
}


void CCounterDlg::OnBnClickedButton19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_display == "0") {
		return;
	}
	else {
		m_display.Truncate(m_display.GetLength() - 1);
	}
	UpdateData(FALSE);
}
