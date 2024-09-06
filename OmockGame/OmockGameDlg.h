
// OmockGameDlg.h: 헤더 파일
//

#pragma once


// COmockGameDlg 대화 상자
class COmockGameDlg : public CDialogEx
{
// 생성입니다.
public:
	COmockGameDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OMOCKGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
	char m_in_white = 0;
	char m_dol[16][16] = { {0,} };
};
