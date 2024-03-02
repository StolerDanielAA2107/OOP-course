#include "pch.h"
#include "StarostaStoler.h"

IMPLEMENT_SERIAL(Starosta_Stoler, Student_Stoler, 1 | VERSIONABLE_SCHEMA)

Starosta_Stoler::Starosta_Stoler(){}

Starosta_Stoler::~Starosta_Stoler(){}

void Starosta_Stoler::InputFromConsole(int id)
{
	Student_Stoler::InputFromConsole(id);
	cout << "Введите номер телефона: " << endl;
	phone_number = InputCheck(0, INT_MAX);
	cout << "Введите рейтинг старосты: " << endl;
	rating = InputCheck(0.0, DBL_MAX);
}

void Starosta_Stoler::PrintToConsole()
{
	Student_Stoler::PrintToConsole();
	cout << "Номер телефона: " << phone_number << endl;
	cout << "Рейтинг: " << rating << endl;
	cout << "\n";
}

void Starosta_Stoler::Serialize(CArchive& ar)
{
	Student_Stoler::Serialize(ar);
	if (ar.IsStoring()) {
		ar << rating;
		ar << phone_number;
	} else {
		ar >> rating;
		ar >> phone_number;
	}
}