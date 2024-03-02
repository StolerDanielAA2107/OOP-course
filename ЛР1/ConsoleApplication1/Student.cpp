#include "Student.h"

using namespace std;


Student::Student() {
	id = { 0 };
	name = { " " };
	age = { 0 };
	group = { " " };
}

Student::~Student() {}

void Student::InputFromConsole(int id)
{
	this->id = id;
	cout << "������� ��� ��������: " << endl;
	cin.ignore(1000, '\n');
	cin.clear();
	getline(cin, name);
	cout << "������� ������� ��������: " << endl;
	age = InputCheck(0, INT_MAX);
	cout << "������� ������ ��������: " << endl;
	cin.ignore(1000, '\n');
	cin.clear();
	getline(cin, group);
}

void Student::PrintToConsole()
{
	cout << "id ��������: " << id << endl;
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "������: " << group << endl;
	cout << "\n";
}

void Student::SaveToFile(ofstream& fout)
{
	fout << "Student" << endl;
	fout << id << "\n" << name << "\n" << age << "\n" << group << endl;
}

void Student::LoadFromFile(std::ifstream& fin)
{
	fin >> id; fin.ignore(); getline(fin, name); fin >> age; fin.ignore(); getline(fin, group);
}
