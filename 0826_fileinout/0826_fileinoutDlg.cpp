
// 0826_fileinoutDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "0826_fileinout.h"
#include "0826_fileinoutDlg.h"
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


// CMy0826fileinoutDlg 대화 상자



CMy0826fileinoutDlg::CMy0826fileinoutDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY0826_FILEINOUT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy0826fileinoutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TEXT, m_edit_text);
	DDX_Control(pDX, IDC_EDIT_READ, m_edit_read);
}

BEGIN_MESSAGE_MAP(CMy0826fileinoutDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy0826fileinoutDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy0826fileinoutDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy0826fileinoutDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy0826fileinoutDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMy0826fileinoutDlg 메시지 처리기

BOOL CMy0826fileinoutDlg::OnInitDialog()
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

void CMy0826fileinoutDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy0826fileinoutDlg::OnPaint()
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
HCURSOR CMy0826fileinoutDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy0826fileinoutDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString path; // 파일 저장 경로
	CFileDialog dlg(false); // CFileDialog 생성 - false=저장대화상자
	if (dlg.DoModal() == IDOK) { // 값이 선택되면
		path = dlg.GetPathName(); // path값이 저장됨
	}
	else {
		return;
	}

	CFile file;
	CArchive ar(&file, CArchive::store);
	file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL);

	/*int a, b, c;
	CString str;
	str.Format(_T("MFC File Read Write TEST!"));

	a = 1;
	b = 2;
	c = 3;
	
	ar << a << b << str << c;*/

	CString strText=_T("");
	m_edit_text.GetWindowTextW(strText);
	ar << strText;

	ar.Flush();

	ar.Close();
	file.Close();

}


void CMy0826fileinoutDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString path;
	CFileDialog dlg(true);
	if (dlg.DoModal() == IDOK) {
		path = dlg.GetPathName();
	}
	else {
		return;
	}

	SetDlgItemText(IDC_EDIT_PATH, path);

	CFile file;
	CArchive ar(&file, CArchive::load);
	file.Open(path, CFile::modeRead);

	//int a, b, c;
	//CString str;

	//ar >> a >> b >> str >> c;

	CString strText;
	ar >> strText;

	m_edit_read.SetWindowTextW(strText);
	MessageBox(strText);

	ar.Close();
	file.Close();

	//TCHAR output[255];
	////wsprintf(output, _T("%d %d %s %d"), a, b, str, c); // wsprintf 분리
	//wsprintf(output, _T("%s", str));
	//MessageBox(output);
}


void CMy0826fileinoutDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_checkfontup == false) {
		CFont m_font;
		m_font.CreatePointFont(180, _T("굴림"));
		m_edit_text.SetFont(&m_font, TRUE);
		m_checkfontup = true;

		if (m_checkfontdown == true) {
			m_checkfontdown = false;
		}
	}
}


void CMy0826fileinoutDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_checkfontdown == false) {
		CFont m_font;
		m_font.CreatePointFont(100, _T("굴림"));
		m_edit_text.SetFont(&m_font, TRUE);
		m_checkfontdown = true;

		if (m_checkfontup == true) {
			m_checkfontup = false;
		}
	}
}
