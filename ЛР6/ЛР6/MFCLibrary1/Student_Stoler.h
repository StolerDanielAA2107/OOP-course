#pragma once
#include "pch.h"
using namespace std;

class Student_Stoler :
	public CObject
{
public:
	DECLARE_SERIAL(Student_Stoler)
	string  name, group;
	int age, id;

	Student_Stoler();
	virtual ~Student_Stoler();
	virtual void Serialize(CArchive& ar);
};

