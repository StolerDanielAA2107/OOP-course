#include "pch.h"
#include "Student_Stoler.h"
#include "Starosta_Stoler.h"
#include "d1.h"
#include "Students_Stoler.h"

using namespace std;

IMPLEMENT_SERIAL(Student_Stoler, CObject, 1 | VERSIONABLE_SCHEMA)

Student_Stoler::Student_Stoler(): id(), age(), name(), group() {}

Student_Stoler::~Student_Stoler() {}

void Student_Stoler::Serialize(CArchive& ar)
{
	if (ar.IsStoring()) {
		ar << id << age << name << group;
	}
	else {
		ar >> id >> age >> name >> group;
	}
}

void Student_Stoler::StrLen(int* aLen, CDC* pDC)
{
	aLen[0] = pDC->GetTextExtent((CString)to_string(id).c_str()).cx;
	aLen[1] = pDC->GetTextExtent((CString)to_string(age).c_str()).cx;
	aLen[2] = pDC->GetTextExtent(name).cx;
	aLen[3] = pDC->GetTextExtent(group).cx;
}

void Student_Stoler::CDCDrow(CDC* pDC, int* aLeft, int& top, int lineHeight)
{
	pDC->TextOut(aLeft[0], top, (CString)to_string(id).c_str());
	pDC->TextOut(aLeft[1], top, (CString)to_string(age).c_str());
	pDC->TextOut(aLeft[2], top, name);
	pDC->TextOut(aLeft[3], top, group);
	top += lineHeight;
}

void Student_Stoler::listb(d1* dlg)
{
	dlg->t1 = name;
	dlg->t2 = (CString)to_string(age).c_str();
	dlg->t3 = group;
	dlg->e4.ShowWindow(false);
	dlg->e5.ShowWindow(false);
}

void Student_Stoler::addst(d2* dlg)
{
	id = Students_Stoler::MaxId + 1;
	Student_Stoler::update(dlg);
	++Students_Stoler::MaxId;
}

void Student_Stoler::change(d2* dlg)
{
	dlg->t11 = name;
	dlg->t22 = (CString)to_string(age).c_str();
	dlg->t33 = group;
	dlg->e44.ShowWindow(false);
	dlg->e55.ShowWindow(false);
}

void Student_Stoler::update(d2* dlg)
{
	name = dlg->t11;
	age = _ttoi(dlg->t22);
	group = dlg->t33;
	dlg->e44.ShowWindow(false);
	dlg->e55.ShowWindow(false);
}
