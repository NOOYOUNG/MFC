
// 240822_prac1Dlg.h: 헤더 파일
//

#pragma once


// CMy240822prac1Dlg 대화 상자
class CMy240822prac1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy240822prac1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY240822_PRAC1_DIALOG };
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
	CComboBox m_combo;
	afx_msg void OnSelchangeCombo1();
	CListBox m_list1;
	CListBox m_list2;
	afx_msg void OnSelchangeList4();
	CEdit m_edit1;
	afx_msg void OnBnClickedButton2();
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnDblclkList4();
	afx_msg void OnDblclkList5();
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox m_combo2;
	CComboBox m_combo3;
	CEdit m_edit_buy;
//	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
};
