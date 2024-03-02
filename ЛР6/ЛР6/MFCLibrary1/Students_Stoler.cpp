#include "pch.h"
#include "Students_Stoler.h"

Students_Stoler::Students_Stoler() {}

Students_Stoler::~Students_Stoler() {}

int Students_Stoler::MaxId = 0;

void Students_Stoler::clear()
{
	students.clear();
}

void Students_Stoler::addStudent()
{
	students.push_back(make_shared<Student_Stoler>());
}

void Students_Stoler::addCaptain()
{
	students.push_back(make_shared<Starosta_Stoler>());
}

size_t Students_Stoler::getSize()
{
	return students.size();
}

int Students_Stoler::getType(int n)
{
	return students[n]->IsKindOf(RUNTIME_CLASS(Starosta_Stoler)) != 0;
}


void Students_Stoler::setName(int n, char* str)
{
	students[n]->name = str;
}

string Students_Stoler::getName(int n)
{
	return students[n]->name;
}

void Students_Stoler::setGroup(int n, char* str)
{
	students[n]->group = str;
}

string Students_Stoler::getGroup(int n)
{
	return students[n]->group;
}

void Students_Stoler::setAge(int n, int age)
{
	students[n]->age = age;
}

int Students_Stoler::getAge(int n)
{
	return students[n]->age;
}

void Students_Stoler::setRating(int n, int r)
{
	static_pointer_cast<Starosta_Stoler>(students[n])->rating = r;
}

void Students_Stoler::setPhone(int n, int num)
{
	static_pointer_cast<Starosta_Stoler>(students[n])->phone_number = num;
}

int Students_Stoler::getPhone(int n)
{
	return static_pointer_cast<Starosta_Stoler>(students[n])->phone_number;
}

int Students_Stoler::getRating(int n)
{
	return static_pointer_cast<Starosta_Stoler>(students[n])->rating;
}

void Students_Stoler::save(const char* fileName)
{
	CFile file(CString(fileName), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&file, CArchive::store);

	archive << getSize();

	for (int i = 0; i < getSize(); i++)
	{
		archive << students[i].get();
	}
}

void Students_Stoler::load(const char* fileName)
{
	clear();

	CFile file(CString(fileName), CFile::modeRead);
	CArchive archive(&file, CArchive::load);

	int size;
	archive >> size;

	for (int i = 0; i < size; i++)
	{
		Student_Stoler* student;
		archive >> student;
		students.push_back(shared_ptr<Student_Stoler>(student));
	}
	MaxId = students.size();

}

