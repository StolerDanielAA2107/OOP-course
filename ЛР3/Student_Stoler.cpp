#include "pch.h"
#include "Student_Stoler.h"


using namespace std;

IMPLEMENT_SERIAL(Student_Stoler, CObject, 1 | VERSIONABLE_SCHEMA)

Student_Stoler::Student_Stoler(): id(), age(), name(), group(){}

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
	CString buf;
	pDC->TextOut(aLeft[0], top, (CString)to_string(id).c_str());
	pDC->TextOut(aLeft[1], top, (CString)to_string(age).c_str());
	pDC->TextOut(aLeft[2], top, name);
	pDC->TextOut(aLeft[3], top, group);
	top += lineHeight;
}