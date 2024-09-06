﻿
// 0826_imageDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "0826_image.h"
#include "0826_imageDlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <string>

using namespace std;

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


// CMy0826imageDlg 대화 상자



CMy0826imageDlg::CMy0826imageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY0826_IMAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy0826imageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_picture);
}

BEGIN_MESSAGE_MAP(CMy0826imageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy0826imageDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy0826imageDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMy0826imageDlg 메시지 처리기

BOOL CMy0826imageDlg::OnInitDialog()
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

void CMy0826imageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy0826imageDlg::OnPaint()
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
HCURSOR CMy0826imageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy0826imageDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString path;
	CFileDialog dlg(false);
	
	 //CFileDialog dlg(true, _T("*.bmp"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("BMP Files(*.bmp)|*.bmp|"), NULL);
	// 파일 열기 옵션을 bmp 확장자만 가능하도록 설정

	if (dlg.DoModal() == IDOK) {
		path = dlg.GetPathName();
	}
	else {
		return;
	}
	
	CRect rect;
	m_picture.GetWindowRect(rect);

	CDC* dc;
	dc = m_picture.GetDC();

	CImage image;
	image.Load(path);

	image.StretchBlt(dc->m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);

	ReleaseDC(dc);
}


void CMy0826imageDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	VideoCapture capture(1, CAP_DSHOW);

	if (!capture.isOpened()) {
		MessageBox(_T("웹캠 열기 실패"));
		return;
	}

	Mat frame;
	CImage image;

	capture >> frame;
	if (frame.empty()) {
		MessageBox(_T("웹캠에서 프레이 캡처 실패"));
	}

	capture.set(CAP_PROP_FRAME_WIDTH, 1280);
	capture.set(CAP_PROP_FRAME_HEIGHT, 720);

	Mat frame;
	capture >> frame;  // 첫 번째 프레임 캡처

	// 프레임이 비어있는지 확인
	if (frame.empty()) {
		MessageBox(_T("웹캠에서 프레임 캡처 실패"));
		return;
	}

	// Convert cv::Mat to CImage
	int width = frame.cols;
	int height = frame.rows;

	// Create a CImage object with 24-bit RGB format
	CImage image;
	image.Create(width, height, 24, 0);

	// Copy data from Mat to CImage
	for (int y = 0; y < height; ++y) {
		uchar* pSrcRow = frame.ptr<uchar>(height - y - 1);  // OpenCV stores image from top-left, but CImage uses bottom-left
		uchar* pDestRow = image.GetBits() + y * image.GetPitch();
		memcpy(pDestRow, pSrcRow, width * 3);  // 3 bytes per pixel (RGB)
	}

	// Display the CImage in the CStatic control
	CRect rect;
	m_picture.GetWindowRect(rect);
	ScreenToClient(rect);  // Convert to client coordinates

	CDC* pDC = m_picture.GetDC();
	image.Draw(pDC->GetSafeHdc(), 0, 0, rect.Width(), rect.Height());

	m_picture.ReleaseDC(pDC);
}
