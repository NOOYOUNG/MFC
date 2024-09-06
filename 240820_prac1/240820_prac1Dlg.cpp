
// 240820_prac1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "240820_prac1.h"
#include "240820_prac1Dlg.h"
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


// CMy240820prac1Dlg 대화 상자



CMy240820prac1Dlg::CMy240820prac1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY240820_PRAC1_DIALOG, pParent)
	, m_radio(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy240820prac1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CMy240820prac1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CMy240820prac1Dlg::OnNMCustomdrawProgress1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy240820prac1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy240820prac1Dlg::OnBnClickedButton1)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON3, &CMy240820prac1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy240820prac1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_RADIO1, &CMy240820prac1Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMy240820prac1Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMy240820prac1Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMy240820prac1Dlg::OnBnClickedRadio4)
END_MESSAGE_MAP()


// CMy240820prac1Dlg 메시지 처리기

BOOL CMy240820prac1Dlg::OnInitDialog()
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

	m_progress.SetRange(0, 99); //프로그레스바 범위 지정
	m_progress.SetPos(10); // 프로그레스바 초기값 세팅

	CRect rt;
	m_ListCtrl.GetWindowRect(&rt);
	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_ListCtrl.InsertColumn(0, TEXT("순번"), LVCFMT_LEFT, rt.Width() * 0.5);
	m_ListCtrl.InsertColumn(1, TEXT("Radio"), LVCFMT_LEFT, rt.Width() * 0.5);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMy240820prac1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy240820prac1Dlg::OnPaint()
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
HCURSOR CMy240820prac1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy240820prac1Dlg::OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CMy240820prac1Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_progress.OffsetPos(-10);
	//OffsetPos 함수 안에 0아래로 내려가거나 100이상이 되는것 방지하는 기능 있음
}


void CMy240820prac1Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_progress.OffsetPos(10);
}


void CMy240820prac1Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	int pos = m_slider.GetPos();
	m_progress.SetPos(pos);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMy240820prac1Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(true); // 현재 화면상 누른 요소들을 멤버변수에 넣음

	switch (m_radio) {
	case 0: MessageBox(_T("radio1선택")); break;
	case 1: MessageBox(_T("radio2선택")); break;
	case 2: MessageBox(_T("radio3선택")); break;
	case 3: MessageBox(_T("radio4선택")); break;
	}
}


void CMy240820prac1Dlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str = _T("");
	m_edit1.GetWindowTextW(str);
	
	int radio=_ttoi(str)-1;
	m_radio = radio;
	UpdateData(false);

	int num = m_ListCtrl.GetItemCount();
	CString str1;
	str1.Format(_T("%d"), num);
	m_ListCtrl.InsertItem(num, str1);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, str, NULL, NULL, NULL, NULL);
}


void CMy240820prac1Dlg::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ListCtrl.GetItemCount();
	CString str;
	str.Format(_T("%d"), num);
	SetDlgItemText(IDC_EDIT1, _T("1"));
	m_ListCtrl.InsertItem(num, str);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, _T("1"), NULL, NULL, NULL, NULL);
}


void CMy240820prac1Dlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ListCtrl.GetItemCount();
	CString str;
	str.Format(_T("%d"), num);
	SetDlgItemText(IDC_EDIT1, _T("2"));
	m_ListCtrl.InsertItem(num, str);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, _T("2"), NULL, NULL, NULL, NULL);
}


void CMy240820prac1Dlg::OnBnClickedRadio3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ListCtrl.GetItemCount();
	CString str;
	str.Format(_T("%d"), num);
	SetDlgItemText(IDC_EDIT1, _T("3"));
	m_ListCtrl.InsertItem(num, str);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, _T("3"), NULL, NULL, NULL, NULL);
}


void CMy240820prac1Dlg::OnBnClickedRadio4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ListCtrl.GetItemCount();
	CString str;
	str.Format(_T("%d"), num);
	SetDlgItemText(IDC_EDIT1, _T("4"));
	m_ListCtrl.InsertItem(num, str);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, _T("4"), NULL, NULL, NULL, NULL);
}
