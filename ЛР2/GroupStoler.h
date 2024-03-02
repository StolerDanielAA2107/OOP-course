#pragma once
#include <vector>
#include <fstream>
#include <sstream>

#include "StudentStoler.h"
#include "StarostaStoler.h"

using namespace std;

class GroupStoler
{
	vector <shared_ptr<Student_Stoler>> students;

public:
	void AddStudent(shared_ptr<Student_Stoler> st);
	void PrintAll();
	void savetofile();
	void loadfromfile();
	void clearstudents();
	int sizevector();
};


