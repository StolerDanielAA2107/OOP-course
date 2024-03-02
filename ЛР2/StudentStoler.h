#pragma once
#include <string>

#include "Utils.h"

class Student_Stoler :public CObject
{
public:
	DECLARE_SERIAL(Student_Stoler);
	int id, age;
	CStringA name, group;
	Student_Stoler();
	~Student_Stoler();
	virtual void InputFromConsole(int id);
	virtual void PrintToConsole();
	virtual void Serialize(CArchive& ar);
};

