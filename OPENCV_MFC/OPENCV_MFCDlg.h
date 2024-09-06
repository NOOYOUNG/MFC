
// OPENCV_MFCDlg.h: 헤더 파일
//

#pragma once

#include "opencv2/opencv.hpp"
#include <opencv2/opencv.hpp>

#include <cstring>
#include <vector>

using namespace std;
using namespace cv;


// COPENCVMFCDlg 대화 상자
class COPENCVMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	COPENCVMFCDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENCV_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_cstrImgPath;
	Mat m_srcMat;
	Mat m_grayMat;
	int m_colorMat;
	void DisplayImage(int IDC_PICTURE_CONTROL, Mat srcMat);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CSliderCtrl m_Slider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	Mat m_brightMat;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	Mat m_rotateMat;
//	Mat M;
	afx_msg void OnBnClickedButton5();
//	Mat m_updownFlip;
	afx_msg void OnBnClickedButton6();
	Mat m_flipMat;
	afx_msg void OnBnClickedButton9();
	Mat m_filterMat;
	afx_msg void OnBnClickedButton10();
	//void detectAndDraw(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale, bool tryflip);
	//string cascadeName; // 얼굴 탐지용 Haar Cascade 파일의 이름을 저장할 문자열
	//string nestedCascadeName; // 눈 탐지용 Haar Cascade 파일의 이름을 저장할 문자열
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	void saveImage(Mat img);
	afx_msg void OnBnClickedButton11();
	CSliderCtrl m_Slider2;
	Mat m_resizeMat;
	int m_ratioMat;
	CEdit m_angle;
};
