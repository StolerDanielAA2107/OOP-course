#include "Group.h"
#include "Utils.h"

void Group::AddStudent(shared_ptr<Student> st)
{
	students.push_back(st);
}

void Group::PrintAll()
{
	if (students.size() == 0) {
		cout << "Объекты не добавлены" << endl;
	}
	for (auto& i : students) {
		//i->;
	}
}

void Group::savetofile()
{
	if (students.size() == 0) {
		cout << "Объекты не добавлены" << endl;
	}
	else {
		ofstream ofile;
		ofile.imbue(locale(".1251"));
		string name;
		cout << "Введите название файла для сохранения: " << endl;
		cin.ignore(1000, '\n');
		cin.clear();
		getline(cin, name);
		ofile.open(name, ios::out);
		if (ofile.is_open()) {
			ofile << students.size() << "\n";
			for (auto& i : students) {
				i->SaveToFile(ofile);
			}
			ofile.close();
			cout << "Сохранение выполнено." << endl;
		}
	}
}

void Group::loadfromfile()
{
	ifstream ifile;
	ifile.imbue(locale(".1251"));
	string name;
	cout << "Введите название файла из которого загрузить данные: " << endl;
	cin.ignore(1000, '\n');
	cin.clear();
	getline(cin, name);
	ifile.open(name, ios::in);
	if (ifile.is_open() == 0) {
		cout << "Ошибка открытия файла" << endl;
	}
	else if (ifile.peek() == EOF) {
		cout << "Ошибка чтения: нет данных в файле." << endl;
	}
	else {
		students.clear();
		int size;
		ifile >> size;
		students.reserve(size);
		for (int i = 0; i < size; ++i) {
			string str;
			ifile >> str;
			if (str.compare("Student") == 0){
				Student* st = new Student;
				st->LoadFromFile(ifile);
			}
			else {
				Starosta* st = new Starosta;
				st->LoadFromFile(ifile);
			}
			students.push_back(st);
		}
		ifile.close();
		cout << "Загрузка выполнена" << endl;
	}
}

int Group::sizevector() {
	int inpid = students.size();
	return inpid;
}

void Group::clearstudents()
{
	students.clear();
}



