#pragma once
#include "StudentStoler.h"

class Starosta_Stoler :public Student_Stoler
{
public:
	DECLARE_SERIAL(Starosta_Stoler)
	double rating;
	int phone_number;
	Starosta_Stoler();
	~Starosta_Stoler();
	virtual void InputFromConsole(int id);
	virtual void PrintToConsole();
	virtual void Serialize(CArchive& ar);
};

