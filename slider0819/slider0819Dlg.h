
// slider0819Dlg.h: 헤더 파일
//

#pragma once


// Cslider0819Dlg 대화 상자
class Cslider0819Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cslider0819Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SLIDER0819_DIALOG };
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
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	CSliderCtrl m_slider1;
	CSliderCtrl m_slider2;
	CSliderCtrl m_slider3;
	afx_msg void OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult);
	COLORREF m_cRGB;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedListctrlAdd();
	afx_msg void OnBnClickedListctrlDel();
//	afx_msg void OnNMClickListctrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnNMClickListctrl(NMHDR* pNMHDR, LRESULT* pResult);
	COLORREF m_cRGB2;
	afx_msg void OnStnClickedStaticrgb1();
	CButton m_chk1;
	CButton m_chk2;
};
