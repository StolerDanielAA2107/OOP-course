#include "pch.h"
#include "d1.h"
#include "d2.h"
#include "LR3_Stoler.h"

IMPLEMENT_DYNAMIC(d1, CDialogEx)

d1::d1(CWnd* pParent) : CDialogEx(IDD_DIALOG1, pParent) {}

d1::~d1() {}

BOOL d1::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	DisableFields(TRUE);
	int n = l1.GetCurSel();

	for_each(pDoc->students.students.begin(), pDoc->students.students.end(), [&](shared_ptr<Student_Stoler> name)
		{
			CString s = name->name;
			l1.AddString(s);
		});

	if (n < 0)
	{
		b2.EnableWindow(false);
		b3.EnableWindow(false);
	}

	return TRUE;
}

void d1::OnBnClickedButton1() // добавить
{
	d2 dd2;
	dd2.n = -1;
	dd2.pDoc2 = pDoc;
	if (dd2.DoModal() == IDOK)
	{
		CString s = pDoc->students.students[pDoc->students.students.size() - 1]->name;
		l1.AddString(s);
	}
	l1.SetCurSel(pDoc->students.students.size() - 1);
	OnLbnSelchangeList1();
}

void d1::OnBnClickedButton2() // редактирование
{
	d2 dd2;
	dd2.pDoc2 = pDoc;
	dd2.n = l1.GetCurSel();
	int n = dd2.n;
	dd2.DoModal();
	auto p = pDoc->students.students[n];
	l1.DeleteString(n);
	l1.InsertString(n, p->name);
	l1.SetCurSel(n);
	OnLbnSelchangeList1();
	UpdateData(FALSE);
}

void d1::OnBnClickedButton3()
{
	d2 dd2;
	dd2.n = l1.GetCurSel();
	int n = dd2.n;
	if (dd2.n < 0)
	{
		b2.EnableWindow(false);
		b3.EnableWindow(false);
	}
	for (int i = n; i < pDoc->students.students.size() - 1; i++)
		pDoc->students.students[i] = pDoc->students.students[i + 1];
	pDoc->students.students.pop_back();
	l1.DeleteString(n);
	if (n < pDoc->students.students.size())
		l1.SetCurSel(n);
	else
		l1.SetCurSel(n - 1);
	if (l1.GetCurSel() == -1)
	{
		t1.Empty();
		t2.Empty();
		t3.Empty();
		t4.Empty();
		t5.Empty();
	}
	else
	{
		OnLbnSelchangeList1();
	}
	if (n <= 0)
	{
		b2.EnableWindow(false);
		b3.EnableWindow(false);
	}
	if (n > 0)
	{
		b2.EnableWindow(true);
		b3.EnableWindow(true);
	}
	UpdateData(false);
}

void d1::OnLbnSelchangeList1()
{
	int n = l1.GetCurSel();
	if (n < 0)
	{
		b2.EnableWindow(false);
		b3.EnableWindow(false);
		t1.Empty();
		e1.EnableWindow(false);
		t2.Empty();
		e2.EnableWindow(false);
		t3.Empty();
		e3.EnableWindow(false);
		t4.Empty();
		e4.EnableWindow(false);
		t5.Empty();
		e5.EnableWindow(false);
		UpdateData(FALSE);
		return;
	}
	if (n >= 0)
	{
		b2.EnableWindow(true);
		b3.EnableWindow(true);
		t5.Empty();
		e1.EnableWindow(true);
		e2.EnableWindow(true);
		e3.EnableWindow(true);
		e4.EnableWindow(true);
		e5.EnableWindow(true);

		auto p = pDoc->students.students[n];
		p->listb(this);

		UpdateData(FALSE);
	}
}

void d1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, e1);
	DDX_Control(pDX, IDC_EDIT2, e2);
	DDX_Control(pDX, IDC_EDIT3, e3);
	DDX_Control(pDX, IDC_EDIT4, e4);
	DDX_Control(pDX, IDC_EDIT5, e5);
	DDX_Control(pDX, IDC_BUTTON1, b1);
	DDX_Control(pDX, IDC_BUTTON2, b2);
	DDX_Control(pDX, IDC_BUTTON3, b3);
	DDX_Control(pDX, IDC_LIST1, l1);
	DDX_Text(pDX, IDC_EDIT1, t1);
	DDX_Text(pDX, IDC_EDIT2, t2);
	DDX_Text(pDX, IDC_EDIT3, t3);
	DDX_Text(pDX, IDC_EDIT4, t4);
	DDX_Text(pDX, IDC_EDIT5, t5);
}

BEGIN_MESSAGE_MAP(d1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &d1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &d1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &d1::OnBnClickedButton3)
	ON_LBN_SELCHANGE(IDC_LIST1, &d1::OnLbnSelchangeList1)
END_MESSAGE_MAP()

void d1::DisableFields(bool disabled)
{
	this->e1.EnableWindow(!disabled);
	this->e2.EnableWindow(!disabled);
	this->e3.EnableWindow(!disabled);
	this->e4.EnableWindow(!disabled);
	this->e5.EnableWindow(!disabled);
}
