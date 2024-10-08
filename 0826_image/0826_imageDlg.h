﻿
// 0826_imageDlg.h: 헤더 파일
//

#pragma once
#include "opencv2/opencv.hpp"
#include <opencv2/dnn.hpp>
using namespace cv;

// CMy0826imageDlg 대화 상자
class CMy0826imageDlg : public CDialogEx
{
// 생성입니다.
public:
	CMy0826imageDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY0826_IMAGE_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	CStatic m_picture;
	afx_msg void OnBnClickedButton2();
	CString m_cstrImgPath;
	Mat m_srcMat;
};
