
// 240822_prac1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "240822_prac1.h"
#include "240822_prac1Dlg.h"
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


// CMy240822prac1Dlg 대화 상자



CMy240822prac1Dlg::CMy240822prac1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY240822_PRAC1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy240822prac1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_LIST4, m_list1);
	DDX_Control(pDX, IDC_LIST5, m_list2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Control(pDX, IDC_EDIT2, m_edit_buy);
}

BEGIN_MESSAGE_MAP(CMy240822prac1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMy240822prac1Dlg::OnSelchangeCombo1)
	ON_LBN_SELCHANGE(IDC_LIST4, &CMy240822prac1Dlg::OnSelchangeList4)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy240822prac1Dlg::OnBnClickedButton2)
//	ON_BN_CLICKED(IDC_BUTTON1, &CMy240822prac1Dlg::OnBnClickedButton1)
	ON_LBN_DBLCLK(IDC_LIST4, &CMy240822prac1Dlg::OnDblclkList4)
	ON_LBN_DBLCLK(IDC_LIST5, &CMy240822prac1Dlg::OnDblclkList5)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMy240822prac1Dlg::OnCbnSelchangeCombo2)
//	ON_EN_CHANGE(IDC_EDIT2, &CMy240822prac1Dlg::OnEnChangeEdit2)
ON_BN_CLICKED(IDC_BUTTON1, &CMy240822prac1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy240822prac1Dlg 메시지 처리기

BOOL CMy240822prac1Dlg::OnInitDialog()
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
	//m_combo.AddString(_T("첫째항목"));
	//m_combo.AddString(_T("둘째항목"));
	//m_combo.AddString(_T("셋째항목"));
	//m_combo.AddString(_T("넷째항목"));
	//m_combo.AddString(_T("다섯째항목"));

	m_combo.AddString(_T("장바구니 담기"));
	m_combo.AddString(_T("장바구니 빼기"));

	m_list1.AddString(_T("복숭아"));
	m_list1.AddString(_T("딸기"));
	m_list1.AddString(_T("사과"));
	m_list1.AddString(_T("바나나"));
	m_list1.AddString(_T("수박"));
	m_list1.AddString(_T("삼겹살"));
	m_list1.AddString(_T("참기름"));
	m_list1.AddString(_T("양파"));
	m_list1.AddString(_T("계란"));
	m_list1.AddString(_T("감자"));

	m_combo2.AddString(_T("복숭아"));
	m_combo2.AddString(_T("딸기"));
	m_combo2.AddString(_T("사과"));
	m_combo2.AddString(_T("바나나"));
	m_combo2.AddString(_T("수박"));
	m_combo2.AddString(_T("삼겹살"));
	m_combo2.AddString(_T("삼겹살"));
	m_combo2.AddString(_T("참기름"));
	m_combo2.AddString(_T("양파"));
	m_combo2.AddString(_T("계란"));
	m_combo2.AddString(_T("감자"));



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMy240822prac1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy240822prac1Dlg::OnPaint()
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
HCURSOR CMy240822prac1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy240822prac1Dlg::OnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CString str;
	//str.Format(_T("%d번 콤보 선택"), m_combo.GetCurSel()+1);

	//MessageBox(str);

	int combo = m_combo.GetCurSel();
	if (combo == 0) {
		CString str;
		int idx = m_list1.GetCurSel();

		m_list1.GetText(idx, str);
		m_list1.DeleteString(idx);
		m_list2.InsertString(-1, str); // 마지막 줄에 str 추가
	}
	else if (combo == 1) {
		CString str;
		int idx = m_list2.GetCurSel();

		m_list2.GetText(idx, str);
		m_list2.DeleteString(idx);
		m_list1.InsertString(-1, str);
	}
}


void CMy240822prac1Dlg::OnSelchangeList4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CString str;
	//int idx = m_list1.GetCurSel();
	//m_list1.GetText(idx, str);

	//MessageBox(str+"을 선택하셨습니다.");
}


void CMy240822prac1Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString str = _T("");
	m_edit1.GetWindowTextW(str);

	m_list1.AddString(str);
}


void CMy240822prac1Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str=_T("");
	CString str2 = _T("");

	int idxs = m_list2.GetCount();

	for (int i = 0; i < idxs; i++) {
		m_list2.GetText(i, str);
		str2 +=str;
		str2 += "\r\n";
	}

	SetDlgItemText(IDC_EDIT2, str2); //for문 안에 넣으면 맨 마지막 줄만 출력됨 >> 문장을 전체 합쳐서 출력해야한다.
}


void CMy240822prac1Dlg::OnDblclkList4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	int index = m_list1.GetCurSel();
	m_list1.GetText(index, str);
	m_list1.DeleteString(index);
	m_list2.InsertString(-1, str);
}


void CMy240822prac1Dlg::OnDblclkList5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	int index = m_list2.GetCurSel();
	m_list2.GetText(index, str);
	m_list2.DeleteString(index);
	m_list1.InsertString(-1, str);
}


void CMy240822prac1Dlg::OnCbnSelchangeCombo2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	int index = m_combo2.GetCurSel();
	m_combo2.GetLBText(index, str);
	m_combo2.DeleteString(index);
	m_combo3.InsertString(-1, str);
}


//void CMy240822prac1Dlg::OnEnChangeEdit2()
//{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}
