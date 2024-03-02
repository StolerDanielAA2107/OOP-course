#pragma once
#include <string>

class d1;
class d2;

class Student_Stoler: public CObject
{
public:
	CString name, group;
	int id, age;

	DECLARE_SERIAL(Student_Stoler)
	
	Student_Stoler();
	virtual ~Student_Stoler();
	virtual void Serialize(CArchive& ar);
	virtual void StrLen(int* aLen, CDC* pDC);
	virtual void CDCDrow(CDC* pDC, int* aLeft, int& top, int lineHeight);
	virtual void listb(d1* dlg);
	void addst(d2* d);
	void change(d2* dlg);
	void update(d2* dlg);
};

