#pragma once
#include <afxdialogex.h>
#include "LR3_Stoler.h"
#include "LR3_StolerDoc.h"
#include "pch.h"
#include "d1.h"

class d1; 

class d2 : public CDialogEx
{
	DECLARE_DYNAMIC(d2)

public:
	d2(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~d2();
	int n;

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:

	CLR3StolerDoc* pDoc2;
	CEdit e11;
	CEdit e22;
	CEdit e33;
	CEdit e44;
	CEdit e55;

	CString t11;
	CString t22;
	CString t33;
	CString t44;
	CString t55;

	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedCheck1();
	CButton ch1;
	CButton b1;
	afx_msg void OnBnClickedButton1();
};

