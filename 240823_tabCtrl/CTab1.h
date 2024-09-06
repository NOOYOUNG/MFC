#pragma once
#include "afxdialogex.h"


// CTab1 대화 상자

class CTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_T1_edit;
	CListBox m_T1_list;
};
