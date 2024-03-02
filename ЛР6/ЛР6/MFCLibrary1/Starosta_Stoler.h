#pragma once
#include "Student_Stoler.h"
class Starosta_Stoler :
	public Student_Stoler
{
public:
	DECLARE_SERIAL(Starosta_Stoler)
	double rating;
	int phone_number;

	Starosta_Stoler();
	virtual ~Starosta_Stoler();
	void Serialize(CArchive& ar);
};

