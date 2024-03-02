#include "pch.h"
#include "GroupStoler.h"
#include "Utils.h"

void GroupStoler::AddStudent(shared_ptr<Student_Stoler> st)
{
	students.push_back(st);
}

void GroupStoler::PrintAll()
{
	if (students.size() == 0) {
		cout << "Объекты не добавлены" << endl;
	}
	for (auto& i : students) {
		i->PrintToConsole();
	}
}

void GroupStoler::savetofile()
{
	CFile file(L"outputfile.dat", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	ar << students.size();
	for (auto& o : students) {
		ar << o.get();
	}
	cout << "Сохранение завершено" << endl;

}

void GroupStoler::loadfromfile()
{
	CFile File(L"outputfile.dat", CFile::modeRead);
	CArchive ar(&File, CArchive::load);
	size_t n;
	ar >> n;
	for (int i = 0; i < n; i++) {
		Student_Stoler* st;
		ar >> st;
		students.push_back(shared_ptr<Student_Stoler>(st));
	}
	cout << "Загрузка завершена" << endl;
}

int GroupStoler::sizevector() {
	int inpid = students.size();
	return inpid;
}

void GroupStoler::clearstudents()
{

	students.clear();
	cout << "Список очищен" << endl;
}
