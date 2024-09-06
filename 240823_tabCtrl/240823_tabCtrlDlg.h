
// 240823_tabCtrlDlg.h: 헤더 파일
//

#pragma once

class CTab1;
class CTab2;
class CTab3;


// CMy240823tabCtrlDlg 대화 상자
class CMy240823tabCtrlDlg : public CDialogEx
{
// 생성입니다.
public:
	CMy240823tabCtrlDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CTab1* pDlg1;
	CTab2* pDlg2;
	CTab3* pDlg3;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY240823_TABCTRL_DIALOG };
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
	CTabCtrl m_Tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedCancel();
};
