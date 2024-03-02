#pragma once
#include "Student.h"

class Starosta :public Student
{
	double rating;
	int phone_number;
	virtual void InputFromConsole(int id);
	virtual void PrintToConsole();
	virtual void SaveToFile(std::ofstream& fout);
	virtual void LoadFromFile(std::ifstream& fin);
};

