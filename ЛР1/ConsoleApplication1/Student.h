#include <vector>
#include <sstream>
#include <fstream>

#include "Utils.h"

class Student
{
public:
	int id, age;
	std:: string name, group;
	Student();
	~Student();
	virtual void InputFromConsole(int id);
	virtual void PrintToConsole();
	virtual void SaveToFile(std::ofstream& fout);
	virtual void LoadFromFile(std::ifstream& fin);
};
