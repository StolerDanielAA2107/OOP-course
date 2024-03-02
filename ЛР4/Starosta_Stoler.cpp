#include "pch.h"
#include "Student_Stoler.h"
#include "Starosta_Stoler.h"
#include "Students_Stoler.h"
#include "d1.h"
#include "d2.h"

using namespace std;

IMPLEMENT_SERIAL(Starosta_Stoler, Student_Stoler, 1 | VERSIONABLE_SCHEMA)

Starosta_Stoler::Starosta_Stoler(): rating(), phone_number(){}

Starosta_Stoler::~Starosta_Stoler() {}

void Starosta_Stoler::Serialize(CArchive& ar)
{
	Student_Stoler::Serialize(ar);
	if (ar.IsStoring()) {
		ar << rating;
		ar << phone_number;
	}
	else {
		ar >> rating;
		ar >> phone_number;
	}
}

void Starosta_Stoler::StrLen(int* aLen, CDC* pDC)
{
	Student_Stoler::StrLen(aLen, pDC);
	aLen[4] = pDC->GetTextExtent((CString)to_string(rating).c_str()).cx;
	aLen[5] = pDC->GetTextExtent((CString)to_string(phone_number).c_str()).cx;
}

void Starosta_Stoler::CDCDrow(CDC* pDC, int* aLeft, int& top, int lineHeight)
{
	pDC->TextOut(aLeft[4], top, (CString)to_string(rating).c_str());
	pDC->TextOut(aLeft[5], top, (CString)to_string(phone_number).c_str());
	Student_Stoler::CDCDrow(pDC, aLeft, top, lineHeight);
}

void Starosta_Stoler::listb(d1* dlg)
{
	dlg->t1 = name;
	dlg->t2 = (CString)to_string(age).c_str();
	dlg->t3 = group;
	dlg->t4 = (CString)to_string(rating).c_str();
	dlg->t5 = (CString)to_string(phone_number).c_str();
	dlg->e4.ShowWindow(true);
	dlg->e5.ShowWindow(true);
}

void Starosta_Stoler::addcap(d2* dlg)
{
	id = Students_Stoler::MaxId + 1;
	Starosta_Stoler::update1(dlg);
	++Students_Stoler::MaxId;
}

void Starosta_Stoler::change1(d2* dlg)
{
	dlg->t11 = name;
	dlg->t22 = (CString)to_string(age).c_str();
	dlg->t33 = group;
	dlg->t44 = (CString)to_string(rating).c_str();;
	dlg->t55 = (CString)to_string(phone_number).c_str();;
	dlg->e44.ShowWindow(true);
	dlg->e55.ShowWindow(true);
}

void Starosta_Stoler::update1(d2* dlg)
{
	name = dlg->t11;
	age = _ttoi(dlg->t22);
	group = dlg->t33;
	rating = _ttoi(dlg->t44);
	phone_number = _ttoi(dlg->t55);
	dlg->e44.ShowWindow(true);
	dlg->e44.EnableWindow(true);
	dlg->e55.ShowWindow(true);
	dlg->e55.EnableWindow(true);
}
