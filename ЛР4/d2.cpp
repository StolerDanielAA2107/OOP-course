#include "pch.h"
#include "d2.h"
#include "LR3_Stoler.h"

IMPLEMENT_DYNAMIC(d2, CDialogEx)

d2::d2( CWnd* pParent /*=nullptr*/) : CDialogEx(IDD_DIALOG2, pParent) {}

d2::~d2() {}

void d2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, e11);
	DDX_Control(pDX, IDC_EDIT2, e22);
	DDX_Control(pDX, IDC_EDIT3, e33);
	DDX_Control(pDX, IDC_EDIT4, e44);
	DDX_Control(pDX, IDC_EDIT5, e55);
	DDX_Control(pDX, IDC_CHECK1, ch1);
	DDX_Control(pDX, IDC_BUTTON1, b1);
	DDX_Text(pDX, IDC_EDIT1, t11);
	DDX_Text(pDX, IDC_EDIT2, t22);
	DDX_Text(pDX, IDC_EDIT3, t33);
	DDX_Text(pDX, IDC_EDIT4, t44);
	DDX_Text(pDX, IDC_EDIT5, t55);
}

BEGIN_MESSAGE_MAP(d2, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &d2::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &d2::OnBnClickedButton1)
END_MESSAGE_MAP()

BOOL d2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (n == -1)
	{
		e44.EnableWindow(true);
		e44.ShowWindow(false);
		e55.EnableWindow(true);
		e55.ShowWindow(false);
		t11.Empty();
		t22.Empty();
		t33.Empty();
		t44.Empty(); 
		t55.Empty();
	}
	else
	{

		auto p = pDoc2->students.students[n];
		if (typeid(*p) == typeid(Student_Stoler)) {
			p->change(this);
			e44.EnableWindow(false);
			e55.EnableWindow(false);
		}
		else
			static_pointer_cast<Starosta_Stoler>(p)->change1(this);

	}
	UpdateData(false);
	return TRUE;
}

void d2::OnBnClickedCheck1()
{
	if (ch1.GetCheck()) {
		e44.ShowWindow(true);
		e55.ShowWindow(true);
	} else {
		e44.ShowWindow(false);
		e55.ShowWindow(false);
	}
}

void d2::OnBnClickedButton1()
{
	UpdateData(true);
	if (n == -1) {
		if (ch1.GetCheck())
		{
			shared_ptr<Starosta_Stoler> cap(new Starosta_Stoler);
			cap->addcap(this);
			pDoc2->students.students.push_back(cap);
		}
		else
		{
			shared_ptr<Student_Stoler>st(new Student_Stoler);
			st->addst(this);
			pDoc2->students.students.push_back(st);
		}
	}
	else {
		auto p = pDoc2->students.students[n];
		if (typeid(*p) == typeid(Student_Stoler))
			p->update(this);
		else
			static_pointer_cast<Starosta_Stoler>(p)->update1(this);
	}
	CDialogEx::OnOK();
}
