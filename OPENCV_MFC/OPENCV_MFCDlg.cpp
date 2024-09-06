
// OPENCV_MFCDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "OPENCV_MFC.h"
#include "OPENCV_MFCDlg.h"
#include "afxdialogex.h"

#include "global_header.h"

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
//	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// COPENCVMFCDlg 대화 상자



COPENCVMFCDlg::COPENCVMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPENCV_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_cstrImgPath = _T("");
	m_colorMat = 0;
	m_ratioMat = 0;
}

void COPENCVMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_EDIT, m_Slider);
	DDX_Control(pDX, IDC_SLIDER1, m_Slider2);
	DDX_Control(pDX, IDC_EDIT1, m_angle);
}

BEGIN_MESSAGE_MAP(COPENCVMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &COPENCVMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &COPENCVMFCDlg::OnBnClickedButton2)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON3, &COPENCVMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &COPENCVMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &COPENCVMFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &COPENCVMFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &COPENCVMFCDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &COPENCVMFCDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON7, &COPENCVMFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &COPENCVMFCDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON11, &COPENCVMFCDlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// COPENCVMFCDlg 메시지 처리기

BOOL COPENCVMFCDlg::OnInitDialog()
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

	m_Slider.SetRange(0, 255); //brightness
	m_Slider2.SetRange(0, 100); //ratio

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void COPENCVMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COPENCVMFCDlg::OnPaint()
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
		DisplayImage(IDC_PIC, m_srcMat);
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COPENCVMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void COPENCVMFCDlg::DisplayImage(int IDC_PICTURE_TARGET, Mat targetMat)
{
	////픽쳐컨트롤 DC 및 RECT 정의
	//CWnd* pWnd_pictureCtrl = GetDlgItem(IDC_PICTURE_TARGET);
	//CClientDC dcImageTarget(pWnd_pictureCtrl);
	//RECT rcPicCtrl;
	//pWnd_pictureCtrl->GetClientRect(&rcPicCtrl);

	////영상 비율 계산
	//float fImageRatio = float(targetMat.cols) / float(targetMat.rows);
	//float fRectRatio = float(rcPicCtrl.right) / float(rcPicCtrl.bottom);
	//float fScaleFactor;
	//if (fImageRatio < fRectRatio) { //이미지 비율이 픽쳐컨트롤보다 작을 때
	//	fScaleFactor = float(rcPicCtrl.bottom) / float(targetMat.rows);
	//	int rightWithRatio = targetMat.cols * fScaleFactor;
	//	float halfOfDif = ((float)rcPicCtrl.right - (float)rightWithRatio) / (float)2;
	//	rcPicCtrl.left = halfOfDif;
	//	rcPicCtrl.bottom = rightWithRatio;
	//}
	//else {
	//	fScaleFactor = float(rcPicCtrl.right) / float(targetMat.cols);
	//	int bottomWithRatio = targetMat.rows * fScaleFactor;
	//	float halfOfDif = ((float)rcPicCtrl.bottom - (float)bottomWithRatio) / (float)2;
	//	rcPicCtrl.top = halfOfDif;
	//	rcPicCtrl.bottom = bottomWithRatio;
	//}

	////비트맵 선언
	//BITMAPINFO bitmapinfo;
	//memset(&bitmapinfo, 0, sizeof(bitmapinfo));
	//bitmapinfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	//bitmapinfo.bmiHeader.biPlanes = 1;
	//bitmapinfo.bmiHeader.biCompression = BI_RGB;
	//bitmapinfo.bmiHeader.biWidth = targetMat.cols;
	//bitmapinfo.bmiHeader.biHeight = -(targetMat.rows);
	//bitmapinfo.bmiHeader.biBitCount = 24;
	//dcImageTarget.SetStretchBltMode(COLORONCOLOR);
	//::StretchDIBits(dcImageTarget.GetSafeHdc(),
	//	rcPicCtrl.left, rcPicCtrl.top, rcPicCtrl.right, rcPicCtrl.bottom,
	//	0, 0, targetMat.cols, targetMat.rows, targetMat.data,
	//	&bitmapinfo, DIB_RGB_COLORS, SRCCOPY);


	// IDC 픽쳐 컨트롤 DC 및 RECT 정의
	CWnd* pWnd_pictureControl = GetDlgItem(IDC_PICTURE_TARGET);
	CClientDC dcImageTraget(pWnd_pictureControl);
	RECT rcPicControl; // right->width, bottom->height
	pWnd_pictureControl->GetClientRect(&rcPicControl);

	// 영상 비율 계산 및 반영
	float fImageRatio = float(targetMat.cols) / float(targetMat.rows);
	float fRectRatio = float(rcPicControl.right) / float(rcPicControl.bottom);
	float fScaleFactor;
	if (fImageRatio < fRectRatio) {  //이미지의 비율이 사각형 보다 작을때

		fScaleFactor = float(rcPicControl.bottom) / float(targetMat.rows); //TRACE("%f",fScaleFactor);
		int rightWithRatio = targetMat.cols * fScaleFactor;
		float halfOfDif = ((float)rcPicControl.right - (float)rightWithRatio) / (float)2;
		rcPicControl.left = halfOfDif;
		rcPicControl.right = rightWithRatio;
	}
	else {
		fScaleFactor = float(rcPicControl.right) / float(targetMat.cols); //TRACE("%f",fScaleFactor);
		int bottomWithRatio = targetMat.rows * fScaleFactor;
		float halfOfDif = ((float)rcPicControl.bottom - (float)bottomWithRatio) / (float)2;
		rcPicControl.top = halfOfDif;
		rcPicControl.bottom = bottomWithRatio;
	}

	// 비트맵 선언 및 정의
	BITMAPINFO bitmapInfo;
	memset(&bitmapInfo, 0, sizeof(bitmapInfo));
	bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfo.bmiHeader.biPlanes = 1;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;
	bitmapInfo.bmiHeader.biWidth = targetMat.cols;
	bitmapInfo.bmiHeader.biHeight = -(targetMat.rows);
	bitmapInfo.bmiHeader.biBitCount = 24;
	dcImageTraget.SetStretchBltMode(COLORONCOLOR);
	::StretchDIBits(dcImageTraget.GetSafeHdc(),
		rcPicControl.left, rcPicControl.top, rcPicControl.right, rcPicControl.bottom,
		0, 0, targetMat.cols, targetMat.rows, targetMat.data,
		&bitmapInfo, DIB_RGB_COLORS, SRCCOPY);
}


void COPENCVMFCDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK) {
		CString path = fileDlg.GetPathName();

		CT2CA pszString(path);
		string strPath(pszString);

		m_srcMat = imread(strPath, IMREAD_UNCHANGED);

		m_colorMat = 0;
		Invalidate(true);
	}
}


void COPENCVMFCDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	cvtColor(m_srcMat, m_grayMat, COLOR_BGR2GRAY);

	imshow("Gray", m_grayMat);
}


//void CAboutDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
//{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

//	int bright;
//	bright = m_Slider.getPos();
//
//
//	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
//}


void COPENCVMFCDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_colorMat = m_Slider.GetPos();
	m_ratioMat = m_Slider2.GetPos();

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void COPENCVMFCDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//m_brightMat = m_srcMat + m_colorMat;

	m_brightMat = Mat::zeros(m_srcMat.size(), m_srcMat.type()); // m_srcMat과 크기와 유형이 동일하고 0으로 초기화된 m_brightMat 생성

	if (m_srcMat.type() == CV_8UC1) // 회색 이미지 밝기 조정
	{
		for (int i = 0; i < m_srcMat.rows; i++) { // 이미지 각 픽셀 반복
			for (int j = 0; j < m_srcMat.cols; j++) { // 이미지 각 픽셀 반복
				m_brightMat.at<uchar>(i, j) = saturate_cast<uchar>(m_srcMat.at<uchar>(i, j) + m_colorMat);
			}
		}
	}
	else if (m_srcMat.type() == CV_8UC3) // 컬러 이미지 밝기 조절
	{
		for (int i = 0; i < m_srcMat.rows; i++) {
			for (int j = 0; j < m_srcMat.cols; j++) {
				//Vec3b: 3채널 RGB 이미지에서 각 채널을 나타내는 데이터 타입
				Vec3b& pixel = m_brightMat.at<Vec3b>(i, j); // m_brightMat의 RGB 픽셀 값 참조
				Vec3b srcPixel = m_srcMat.at<Vec3b>(i, j); // m_srcMat (i, j) 위치에서 가져온 픽셀 값 저장
				for (int c = 0; c < 3; c++) {  // RGB의 각 채널에 대한 밝기 조절 수행
					pixel[c] = saturate_cast<uchar>(srcPixel[c] + m_colorMat);
				}
			}
		}
	}

	imshow("Bright", m_brightMat);

	while (true) {
		int key = waitKey(0);

		if (key == 27) {  // ESC key
			break;
		}
		else if (key == 's') {  // 's' key
			saveImage(m_brightMat);
			break;
		}
	}

	Invalidate(true);
}


void COPENCVMFCDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Point2f cp(m_srcMat.cols / 2.f, m_srcMat.rows / 2.f); // 이미지 중심점 계산

	CString textAngle=_T("");
	m_angle.GetWindowTextW(textAngle);
	int angle = _ttoi(textAngle);

	Mat M = getRotationMatrix2D(cp, angle, 1); // 회전 행렬 생성

	Rect bbox = RotatedRect(cp, m_srcMat.size(), angle).boundingRect(); // 회전된 이미지의 바운딩 박스 계산

	// 회전된 이미지가 새로운 바운딩 박스의 중앙에 오도록 회전 행렬을 조정
	M.at<double>(0, 2) += bbox.width / 2.0 - cp.x;
	M.at<double>(1, 2) += bbox.height / 2.0 - cp.y;
	// (300 x 200 이미지의 경우) 이미지의 원래 중심 = (150, 100)
	// 새 경계 상자 크기 : bbox.width = 200, bbox.height = 300
	// 새로운 X: (200 / 2.0 - 150 = 100 - 150 = -50)
	// 새로운 Y: (300 / 2.0 - 100 = 150 - 100 = 50)
	// at(0, 2) += -50 >> 150-50=100
	// at(1, 2) += 50 >> 100+50=150 
	// 새로운 중심점 (100, 150)

	warpAffine(m_srcMat, m_rotateMat, M, bbox.size());

	imshow("Quarter Rotation Image", m_rotateMat);

	while (true) {
		int key = waitKey(0);

		if (key == 27) {  // ESC key
			break;
		}
		else if (key == 's') {  // 's' key
			saveImage(m_rotateMat);
			break;
		}
	}
	//Invalidate(true);
}


void COPENCVMFCDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	flip(m_srcMat, m_flipMat, 0); // 0이면 상하 대칭
	imshow("U&D_FLIP", m_flipMat);

	while (true) {
		int key = waitKey(0);

		if (key == 27) {  // ESC key
			break;
		}
		else if (key == 's') {  // 's' key
			saveImage(m_flipMat);
			break;
		}
	}

	Invalidate(true);
}


void COPENCVMFCDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	flip(m_srcMat, m_flipMat, 1);
	imshow("R&L_FLIP", m_flipMat);

	while (true) {
		int key = waitKey(0);

		if (key == 27) {  // ESC key
			break;
		}
		else if (key == 's') {  // 's' key
			saveImage(m_flipMat);
			break;
		}
	}

	Invalidate(true);
}


void COPENCVMFCDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	float data[] = { -1,-1,0,-1,0,1,0,1,1 };
	Mat emboss(3, 3, CV_32FC1, data);

	filter2D(m_srcMat, m_filterMat, -1, emboss, Point(-1, -1), 128);

	imshow("Embossing Filter", m_filterMat);

	while (true) {
		int key = waitKey(0);

		if (key == 27) {  // ESC key
			break;  
		}
		else if (key == 's') {  // 's' key
			saveImage(m_filterMat);
			break;
		}
	}
	
	Invalidate(true);
}


void COPENCVMFCDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GaussianBlur(m_srcMat, m_filterMat, Size(), 1);

	imshow("Gaussian Blur", m_filterMat);

	while (true) {
		int key = waitKey(0);

		if (key == 27) {  // ESC key
			break;
		}
		else if (key == 's') {  // 's' key
			saveImage(m_filterMat);
			break;
		}
	}

	Invalidate(true);
}


//void COPENCVMFCDlg::detectAndDraw(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale, bool tryflip)
//{
//	double t = 0;
//	vector<Rect> faces, faces2;
//	const static Scalar colors[] =
//	{
//		Scalar(255,0,0),
//		Scalar(255,128,0),
//		Scalar(255,255,0),
//		Scalar(0,255,0),
//		Scalar(0,128,255),
//		Scalar(0,255,255),
//		Scalar(0,0,255),
//		Scalar(255,0,255)
//	};
//	Mat gray, smallImg;
//
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	double fx = 1 / scale;
//	resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);
//	equalizeHist(smallImg, smallImg);
//
//	t = (double)getTickCount();
//	cascade.detectMultiScale(smallImg, faces,
//		1.1, 2, 0
//		//|CASCADE_FIND_BIGGEST_OBJECT
//		//|CASCADE_DO_ROUGH_SEARCH
//		| CASCADE_SCALE_IMAGE,
//		Size(30, 30));
//	if (tryflip)
//	{
//		flip(smallImg, smallImg, 1);
//		cascade.detectMultiScale(smallImg, faces2,
//			1.1, 2, 0
//			//|CASCADE_FIND_BIGGEST_OBJECT
//			//|CASCADE_DO_ROUGH_SEARCH
//			| CASCADE_SCALE_IMAGE,
//			Size(30, 30));
//		for (vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); ++r)
//		{
//			faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
//		}
//	}
//	t = (double)getTickCount() - t;
//	printf("detection time = %g ms\n", t * 1000 / getTickFrequency());
//	for (size_t i = 0; i < faces.size(); i++)
//	{
//		Rect r = faces[i];
//		Mat smallImgROI;
//		vector<Rect> nestedObjects;
//		Point center;
//		Scalar color = colors[i % 8];
//		int radius;
//
//		double aspect_ratio = (double)r.width / r.height;
//		if (0.75 < aspect_ratio && aspect_ratio < 1.3)
//		{
//			center.x = cvRound((r.x + r.width * 0.5) * scale);
//			center.y = cvRound((r.y + r.height * 0.5) * scale);
//			radius = cvRound((r.width + r.height) * 0.25 * scale);
//			circle(img, center, radius, color, 3, 8, 0);
//		}
//		else
//			rectangle(img, Point(cvRound(r.x * scale), cvRound(r.y * scale)),
//				Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)),
//				color, 3, 8, 0);
//		if (nestedCascade.empty())
//			continue;
//		smallImgROI = smallImg(r);
//		nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
//			1.1, 2, 0
//			//|CASCADE_FIND_BIGGEST_OBJECT
//			//|CASCADE_DO_ROUGH_SEARCH
//			//|CASCADE_DO_CANNY_PRUNING
//			| CASCADE_SCALE_IMAGE,
//			Size(30, 30));
//		for (size_t j = 0; j < nestedObjects.size(); j++)
//		{
//			Rect nr = nestedObjects[j];
//			center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
//			center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
//			radius = cvRound((nr.width + nr.height) * 0.25 * scale);
//			circle(img, center, radius, color, 3, 8, 0);
//		}
//	}
//	imshow("result", img);
//}


void COPENCVMFCDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//Mat frame, image;
	//string inputName;
	//bool tryflip = false;
	//CascadeClassifier cascade, nestedCascade;
	//double scale;

	//static TCHAR BASED_CODE szFilter[] = _T("이미지 파일(*.BMP, *.GIF, *.JPG, *.PNG) | *.BMP;*.GIF;*.JPG;*.PNG;*.bmp;*.jpg;*.gif;*.png | 모든파일(*.*) | *.* || ");

	//CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);

	//if (fileDlg.DoModal() == IDOK) {
	//	CString path = fileDlg.GetPathName();

	//	CT2CA pszString(path);
	//	inputName = string(pszString);
	//}

	//cascadeName = "haarcascade_frontalface_alt.xml";
	//nestedCascadeName = "haarcascade_eye_tree_eyeglasses.xml";
	//scale = 1;

	////inputName = "lena.jpg";

	//if (!nestedCascade.load(nestedCascadeName))
	//	cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;
	//if (!cascade.load(cascadeName))
	//{
	//	cerr << "ERROR: Could not load classifier cascade" << endl;
	//}
	//if (!inputName.empty())
	//{
	//	image = imread(inputName, IMREAD_COLOR);
	//	if (image.empty())
	//	{
	//		cout << "Couldn't read Image" << endl;
	//	}
	//}

	//cout << "Detecting face(s) in " << inputName << endl;
	//if (!image.empty())
	//{
	//	detectAndDraw(image, cascade, nestedCascade, scale, tryflip);
	//	waitKey(0);
	//}

	facedetect_image();
}


void COPENCVMFCDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	facedetect_video(1);
}


void COPENCVMFCDlg::saveImage(Mat img)
{
	/*CFileDialog fileDlg(FALSE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));

	if (fileDlg.DoModal() == IDOK) {
		CString path = fileDlg.GetPathName();

		CT2CA pszString(path);
		string strPath(pszString);

		imwrite(strPath, img);
	}*/

	CFileDialog fileDlg(FALSE, _T("jpg"), NULL, OFN_OVERWRITEPROMPT, _T("Image Files (*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files (*.*)|*.*||"));

	if (fileDlg.DoModal() == IDOK) {
		CString path = fileDlg.GetPathName();
		
		CT2CA pszString(path);
		std::string strPath(pszString);

		if (!imwrite(strPath, img)) {
			AfxMessageBox(_T("Error saving image."));
		}
	}
}


void COPENCVMFCDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	resize(m_srcMat, m_resizeMat, Size(), ((float)m_ratioMat / 100), ((float)m_ratioMat / 100));
	
	imshow("Resize", m_resizeMat);
}
