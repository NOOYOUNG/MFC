
// 240820_prac1Dlg.h: 헤더 파일
//

#pragma once


// CMy240820prac1Dlg 대화 상자
class CMy240820prac1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy240820prac1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY240820_PRAC1_DIALOG };
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
	CProgressCtrl m_progress;
	afx_msg void OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl m_slider;
	int m_radio;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CEdit m_edit1;
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
};
