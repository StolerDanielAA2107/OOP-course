#include "Starosta.h"

void Starosta::InputFromConsole(int id)
{
	Student* st = this;
	st->InputFromConsole(id);
	cout << "Введите номер телефона: " << endl;
	phone_number = InputCheck(0, INT_MAX);
	cout << "Введите рейтинг старосты: " << endl;
	rating = InputCheck(0.0, DBL_MAX);	
}

void Starosta::PrintToConsole()
{
	Student* st = this;
	st->PrintToConsole();
	cout << "Номер телефона: " << phone_number << endl;
	cout << "Рейтинг: " << rating << endl;
}

void Starosta::SaveToFile(std::ofstream& fout)
{
	fout << "Starosta" << endl;
	fout << id << "\n" << name << "\n" << age << "\n" << group <<  rating << "\n" << phone_number << "\n";
}

void Starosta::LoadFromFile(std::ifstream& fin)
{
	Student* st = this;
	st->LoadFromFile(fin);
	fin >> rating; fin >> phone_number;
}


