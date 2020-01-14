﻿#pragma once

#include "CSocCom.h"
#include "afxdb.h"
// MatchGame 대화 상자

class MatchGame : public CDialogEx
{
	DECLARE_DYNAMIC(MatchGame)

public:
	MatchGame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MatchGame();
	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MATCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	afx_msg LRESULT OnReceive(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strTyping;
	CString m_strScore;
	CString m_strID;
	CSocCom m_socCom;
	CString m_strConnect;
	CDatabase m_db;
	CRecordset* m_pRs;
	CString m_word1;
	CString m_word10;
	CString m_word11;
	CString m_word12;
	CString m_word13;
	CString m_word14;
	CString m_word15;
	CString m_word2;
	CString m_word3;
	CString m_word4;
	CString m_word5;
	CString m_word6;
	CString m_word7;
	CString m_word8;
	CString m_word9;

	int m_myScore = 0;
	BOOL m_bConnect;
	int m_listSize;
	int endGameIndex;
	CString m_strList[15];
	CString score;

	afx_msg void OnBnClickedButtonConnect();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	BOOL IsGameEnd();
	void EraseCheck(int wordIndex, BOOL itsMe);
	void SetGameEnd();
	void SendGame(CString strTmp);
	int staticStringToIndex(CString str);
	void InitGame();
};
