#include "pch.h"
#include "Students_Stoler.h"
#include <algorithm>

using namespace std;

Students_Stoler::Students_Stoler() {}

Students_Stoler::~Students_Stoler() {}

void Students_Stoler::fout(CArchive& ar)
{
	ar << students.size();
	for (auto& student : students) {
		ar << student.get();
	}
}

void Students_Stoler::fin(CArchive& ar)
{
	size_t size;
	ar >> size;
	for (int i = 0; i < size; i++)
	{
		Student_Stoler* st;
		ar >> st;
		students.push_back(shared_ptr<Student_Stoler> (st));
	}
}

void Students_Stoler::clear()
{
	students.clear();
}

CSize Students_Stoler::drow(CDC* pDC)
{
	POINT sizeAll{};
	sizeAll.x = 0;
	sizeAll.y = 0;

	// Отсутпы Горизонтальные отсупы между словами Высота линий
	const int wordSpacing = 5;
	const int horizontalPadding = 15;
	const int lineHeight = 30;
	
	// Шапка
	CString aHead[6];
	aHead[0] = "Id";
	aHead[1] = "Возраст";
	aHead[2] = "Имя";
	aHead[3] = "Группа";
	aHead[4] = "Рейтинг ";
	aHead[5] = "Номер телефона";
	
	// Формируем массив максимальных длинн текста в px, за основу берётся шапка
	int aLen[6]{};
	for (int i = 0; i < 6; ++i)
		aLen[i] = pDC->GetTextExtent(aHead[i]).cx;

	if (students.size() != 0)
	{
		// расширяеем массив, вычисляя длины элементов
		for (auto& student : students)
		{
			int memLen[6];
			student->StrLen(memLen, pDC);
			for (int i = 0; i < 6; ++i)
				if (memLen[i] > aLen[i])
					aLen[i] = memLen[i];
		}

		// Превращаем массив длинн в массив координат
		aLen[0] += wordSpacing;
		for (int i = 1; i < 6; ++i)
		{
			aLen[i - 1] += horizontalPadding;
			aLen[i] += aLen[i - 1];
		}

		int aLeft[6]{};
		aLeft[0] = wordSpacing;
		for (int i = 1; i < 6; ++i)
			aLeft[i] = aLen[i - 1];

		// Выводим шапку
		int top = wordSpacing;
		for (int i = 0; i < 6; ++i)
		{
			pDC->TextOutW(aLeft[i], top, aHead[i]);
		}
		top += lineHeight;

		for_each(students.begin(), students.end(), bind(&Student_Stoler::CDCDrow, placeholders::_1, pDC, aLeft, ref(top), lineHeight));

		sizeAll.x = aLen[5] + wordSpacing;
		sizeAll.y = top;

		// Разделительные линии
		pDC->MoveTo(0, 0);
		pDC->LineTo(sizeAll.x, 0);
		pDC->LineTo(sizeAll);
		pDC->LineTo(0, sizeAll.y);
		pDC->LineTo(0, 0);
		
		for (int i = 1; i < 6; ++i)
		{
			pDC->MoveTo(aLeft[i] - horizontalPadding / 2, 0);
			pDC->LineTo(aLeft[i] - horizontalPadding / 2, sizeAll.y);
		}
		pDC->MoveTo(0, wordSpacing + lineHeight * 0.8);
		pDC->LineTo(sizeAll.x, wordSpacing + lineHeight * 0.8);
	}

	return sizeAll;
}

