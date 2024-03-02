#include "pch.h"
#include "StudentStoler.h"

IMPLEMENT_SERIAL(Student_Stoler, CObject, 1 | VERSIONABLE_SCHEMA)

Student_Stoler::Student_Stoler() {}

Student_Stoler::~Student_Stoler() {}


void Student_Stoler::InputFromConsole(int id)
{
	this->id = id;
	string varStr;
	cout << "Введите имя студента: " << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, varStr);
	name = varStr.c_str();
	cout << "Введите возраст студента: " << endl;
	age = InputCheck(0, INT_MAX);
	cout << "Введите группу студента: " << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, varStr);
	group = varStr.c_str();
}

void Student_Stoler::PrintToConsole()
{
	cout << "\n";
	cout << "id студента: " << id << endl;
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Группа: " << group << endl;
}

void Student_Stoler::Serialize(CArchive& ar)
{
	if (ar.IsStoring()) {
		ar << id << age << name << group;
	} else {
		ar >> id >> age >> name >> group;
	}
}

