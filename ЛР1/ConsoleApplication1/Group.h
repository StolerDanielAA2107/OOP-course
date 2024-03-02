#pragma once
#include <vector>
#include <fstream>
#include <sstream>

#include "Student.h"
#include "Starosta.h"

class Group
{
	vector <shared_ptr<Student>> students;

public:
	void AddStudent(shared_ptr<Student> st);
	void PrintAll();
	void savetofile();
	void loadfromfile();
	void clearstudents();
	int sizevector();
};

