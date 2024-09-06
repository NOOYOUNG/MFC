
// 0826_fileinoutDlg.h: 헤더 파일
//

#pragma once


// CMy0826fileinoutDlg 대화 상자
class CMy0826fileinoutDlg : public CDialogEx
{
// 생성입니다.
public:
	CMy0826fileinoutDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY0826_FILEINOUT_DIALOG };
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
	afx_msg void OnBnClickedButton2();
	CEdit m_edit_text;
	CEdit m_edit_read;
	afx_msg void OnBnClickedButton4();
//	CFont m_font;
	bool m_checkfontup=false;
	afx_msg void OnBnClickedButton3();
	bool m_checkfontdown=false;
};
