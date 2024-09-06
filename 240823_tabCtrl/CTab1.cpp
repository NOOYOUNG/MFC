// CTab1.cpp: 구현 파일
//

#include "pch.h"
#include "240823_tabCtrl.h"
#include "afxdialogex.h"
#include "CTab1.h"


// CTab1 대화 상자

IMPLEMENT_DYNAMIC(CTab1, CDialogEx)

CTab1::CTab1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CTab1::~CTab1()
{
}

void CTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_T1_edit);
	DDX_Control(pDX, IDC_LIST1, m_T1_list);
}


BEGIN_MESSAGE_MAP(CTab1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTab1 메시지 처리기


void CTab1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString str = _T("");

	m_T1_edit.GetWindowTextW(str);

	m_T1_list.AddString(str);
}
