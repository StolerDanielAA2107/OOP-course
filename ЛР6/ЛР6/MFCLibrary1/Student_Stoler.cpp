#include "pch.h"
#include "Student_Stoler.h"

IMPLEMENT_SERIAL(Student_Stoler, CObject, 1 | VERSIONABLE_SCHEMA)

Student_Stoler::Student_Stoler() :name(), group(), age() {}

Student_Stoler::~Student_Stoler() {}

void Student_Stoler::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << id;
		ar << age;
		ar << CString(name.c_str());
		ar << CString(group.c_str());
	}
	else
	{
		ar >> id;
		ar >> age;
		CString buffer;
		ar >> buffer;
		name = buffer;
		ar >> buffer;
		group = buffer;
	}
}