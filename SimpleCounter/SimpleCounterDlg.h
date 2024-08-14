
// SimpleCounterDlg.h: 헤더 파일
//

#pragma once


// CSimpleCounterDlg 대화 상자
class CSimpleCounterDlg : public CDialogEx
{
// 생성입니다.
public:
	CSimpleCounterDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIMPLECOUNTER_DIALOG };
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
//	CEdit m_edit1;
//	CEdit m_edit2;
//	CEdit m_edit3;
//	CEdit m_edit4;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton1();
	CEdit m_op1;
	CEdit m_operator;
	CEdit m_op2;
	CEdit m_answer;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit1();
};
