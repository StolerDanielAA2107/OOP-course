#include "pch.h"
#include "Starosta_Stoler.h"

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
