// CTab3.cpp: 구현 파일
//

#include "pch.h"
#include "240823_tabCtrl.h"
#include "afxdialogex.h"
#include "CTab3.h"


// CTab3 대화 상자

IMPLEMENT_DYNAMIC(CTab3, CDialogEx)

CTab3::CTab3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CTab3::~CTab3()
{
}

void CTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab3, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &CTab3::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CTab3::OnBnClickedCheck2)
END_MESSAGE_MAP()


// CTab3 메시지 처리기


void CTab3::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	MessageBox(_T("체크박스 1"));
}


void CTab3::OnBnClickedCheck2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	MessageBox(_T("체크박스 2"));
}
