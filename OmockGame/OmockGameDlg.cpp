﻿
// OmockGameDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "OmockGame.h"
#include "OmockGameDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COmockGameDlg 대화 상자



COmockGameDlg::COmockGameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OMOCKGAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COmockGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COmockGameDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// COmockGameDlg 메시지 처리기

BOOL COmockGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void COmockGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);

		for (int y = 1; y <= 15; y++) {
			for (int x = 1; x < 15; x++) {
				dc.Rectangle(x * 30, y * 30, x * 30 + 31, y * 30 + 31);
			}
		}

		CBrush black_brush(RGB(0, 0, 0)), * p_old_brush = 0;
		for (int y = 1; y <= 15; y++) {
			for (int x = 1; x < 15; x++) {
				if (m_dol[y - 1][x - 1] > 0) {
					if (m_dol[y - 1][x - 1] == 1) {
						p_old_brush = dc.SelectObject(&black_brush);
					}
					dc.Ellipse(x * 30 - 15, y * 30 - 15, x * 30 + 15, y * 30 + 15);
					if (m_dol[y - 1][x - 1] == 1) {
						dc.SelectObject(p_old_brush);
					}
				}
			}
		}

		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COmockGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COmockGameDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//CClientDC dc(this); // CClientDC: 'Client Area에 무언가를 그리겠다'에 대한 DC

	//CPen my_pen(PS_SOLID, 1, RGB(255, 0, 0));
	//CBrush my_brush(RGB(0, 0, 0));

	//CPen* p_old_pen = dc.SelectObject(&my_pen);
	//CBrush* p_old_brush = dc.SelectObject(&my_brush);

	//dc.Rectangle(point.x - 25, point.y - 25, point.x + 25, point.y + 25);

	//dc.SelectObject(p_old_pen);
	//dc.SelectObject(p_old_brush);

	CClientDC dc(this);
	CBrush black_brush(RGB(0, 0, 0)), * p_old_brush = 0;

	int x = (point.x+15) / 30, y = (point.y+15) / 30;

	if (x > 0 && y > 0 && x <= 16 && y <= 16 && m_dol[y-1][x-1]==0) {
		m_dol[y - 1][x - 1] = m_in_white + 1;
		x = x * 30;
		y = y * 30;

		if (m_in_white == 0) p_old_brush = dc.SelectObject(&black_brush);
		dc.Ellipse(x - 15, y - 15, x + 15, y + 15);
		if (m_in_white == 0) dc.SelectObject(p_old_brush);

		m_in_white = (m_in_white + 1) % 2;
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}
