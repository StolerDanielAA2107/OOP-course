#pragma once
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
#include "Student_Stoler.h"
#include "Starosta_Stoler.h"
using namespace std;

class Students_Stoler
{
public:
	vector<shared_ptr<Student_Stoler>> students;
	Students_Stoler();
	virtual ~Students_Stoler();
	void fout(CArchive& ar);
	void fin(CArchive& ar);
	void clear();
	CSize drow(CDC* pDC);
};

