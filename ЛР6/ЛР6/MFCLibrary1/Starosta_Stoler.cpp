#include "pch.h"
#include "Starosta_Stoler.h"
using namespace std;

IMPLEMENT_SERIAL(Starosta_Stoler, Student_Stoler, 1 | VERSIONABLE_SCHEMA)

Starosta_Stoler::Starosta_Stoler() :rating(), phone_number() {}

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