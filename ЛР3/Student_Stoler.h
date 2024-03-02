#pragma once
#include <string>

class Student_Stoler: public CObject
{
protected:
	CString name, group;
	int id, age;
public:
	DECLARE_SERIAL(Student_Stoler)
	Student_Stoler();
	virtual ~Student_Stoler();
	virtual void Serialize(CArchive& ar);
	virtual void StrLen(int* aLen, CDC* pDC);
	virtual void CDCDrow(CDC* pDC, int* aLeft, int& top, int lineHeight);
};

