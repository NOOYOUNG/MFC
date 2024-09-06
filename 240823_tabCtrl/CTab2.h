#pragma once
#include "afxdialogex.h"


// CTab2 대화 상자

class CTab2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab2)

public:
	CTab2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl m_T2_slider1;
	CSliderCtrl m_T2_slider2;
	CSliderCtrl m_T2_slider3;
	afx_msg void OnPaint();
	COLORREF m_cRGB;
};
