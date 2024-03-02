#pragma once
#include <afxdialogex.h>
#include "LR3_Stoler.h"
#include "LR3_StolerDoc.h"
#include "pch.h"
#include "d2.h"

class d2;

class d1 : public CDialogEx
{
    DECLARE_DYNAMIC(d1)

public:
	d1(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~d1();

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	DECLARE_MESSAGE_MAP()
public:
	CLR3StolerDoc* pDoc;
	virtual BOOL OnInitDialog();

	CEdit e1;
	CEdit e2;
	CEdit e3;
	CEdit e4;
	CEdit e5;

	CString t1;
	CString t2;
	CString t3;
	CString t4;
	CString t5;

	CButton b1;
	afx_msg void OnBnClickedButton1();
	CButton b2;
	afx_msg void OnBnClickedButton2();
	CButton b3;
	afx_msg void OnBnClickedButton3();
	CListBox l1;
	afx_msg void OnLbnSelchangeList1();

	void DisableFields(bool disabled);

};

