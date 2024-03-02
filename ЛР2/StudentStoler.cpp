#include "pch.h"
#include "StudentStoler.h"

IMPLEMENT_SERIAL(Student_Stoler, CObject, 1 | VERSIONABLE_SCHEMA)

Student_Stoler::Student_Stoler() {}

Student_Stoler::~Student_Stoler() {}


void Student_Stoler::InputFromConsole(int id)
{
	this->id = id;
	string varStr;
	cout << "������� ��� ��������: " << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, varStr);
	name = varStr.c_str();
	cout << "������� ������� ��������: " << endl;
	age = InputCheck(0, INT_MAX);
	cout << "������� ������ ��������: " << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, varStr);
	group = varStr.c_str();
}

void Student_Stoler::PrintToConsole()
{
	cout << "\n";
	cout << "id ��������: " << id << endl;
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "������: " << group << endl;
}

void Student_Stoler::Serialize(CArchive& ar)
{
	if (ar.IsStoring()) {
		ar << id << age << name << group;
	} else {
		ar >> id >> age >> name >> group;
	}
}

