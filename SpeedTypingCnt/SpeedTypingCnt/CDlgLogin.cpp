﻿// CDlgLogin.cpp: 구현 파일
//

#include "pch.h"
#include "SpeedTypingCnt.h"
#include "CDlgLogin.h"
#include "afxdialogex.h"
#include "SpeedTypingCntDlg.h";



// CDlgLogin 대화 상자

IMPLEMENT_DYNAMIC(CDlgLogin, CDialogEx)

CDlgLogin::CDlgLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, m_strID(_T(""))
	, m_strPW(_T(""))
{

}

CDlgLogin::~CDlgLogin()
{
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_PW, m_strPW);
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDlgLogin::OnClickedButtonAdd)
END_MESSAGE_MAP()


// CDlgLogin 메시지 처리기


void CDlgLogin::OnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	try
	{
		BOOL bOpen = m_db.OpenEx(_T("DRIVER={MYSQL ODBC 8.0 Unicode Driver};SERVER=127.0.0.1;PORT=3306;USER=root;PASSWORD=123123;DATABASE=typing;OPTION=3;"), CDatabase::noOdbcDialog);
		if (bOpen)
			m_pRs = new CRecordset(&m_db);
	}
	catch (CException * e)
	{
		e->ReportError();

	}

	m_db.BeginTrans();
	try
	{
		UpdateData(TRUE);
		m_db.ExecuteSQL(_T("INSERT INTO user(username,password) VALUES('"+m_strID+"','"+m_strPW+"')"));


	}
	catch (CException * e)
	{
		e->ReportError();
	}
	m_db.CommitTrans();



	::SendMessage(this->m_hWnd, WM_CLOSE, NULL,NULL);
}
