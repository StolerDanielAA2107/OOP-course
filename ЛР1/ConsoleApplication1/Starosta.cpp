#include "Starosta.h"

void Starosta::InputFromConsole(int id)
{
	Student* st = this;
	st->InputFromConsole(id);
	cout << "������� ����� ��������: " << endl;
	phone_number = InputCheck(0, INT_MAX);
	cout << "������� ������� ��������: " << endl;
	rating = InputCheck(0.0, DBL_MAX);	
}

void Starosta::PrintToConsole()
{
	Student* st = this;
	st->PrintToConsole();
	cout << "����� ��������: " << phone_number << endl;
	cout << "�������: " << rating << endl;
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


