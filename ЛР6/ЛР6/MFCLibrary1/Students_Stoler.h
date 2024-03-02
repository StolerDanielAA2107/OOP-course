#pragma once
#include "Student_Stoler.h"
#include "Starosta_Stoler.h"
#include "pch.h"
using namespace std;

class Students_Stoler
{
public:
	static int MaxId;
	vector<shared_ptr<Student_Stoler>> students;

	Students_Stoler();
	virtual ~Students_Stoler();

	void clear();
	void addStudent();
	void addCaptain();
	size_t getSize();
	int getType(int n);


	void setName(int n, char *str);
	string getName(int n);
	void setGroup(int n, char* str);
	string getGroup(int n);
	void setAge(int n, int age);
	int getAge(int n);
	void setRating(int n, int r);
	int getRating(int n);
	void setPhone(int n, int num);
	int getPhone(int n);
	void save(const char *fileName);
	void load(const char *fileName);
};

