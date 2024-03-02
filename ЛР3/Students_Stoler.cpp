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

	// ������� �������������� ������ ����� ������� ������ �����
	const int wordSpacing = 5;
	const int horizontalPadding = 15;
	const int lineHeight = 30;
	
	// �����
	CString aHead[6];
	aHead[0] = "Id";
	aHead[1] = "�������";
	aHead[2] = "���";
	aHead[3] = "������";
	aHead[4] = "������� ";
	aHead[5] = "����� ��������";
	
	// ��������� ������ ������������ ����� ������ � px, �� ������ ������ �����
	int aLen[6]{};
	for (int i = 0; i < 6; ++i)
		aLen[i] = pDC->GetTextExtent(aHead[i]).cx;

	if (students.size() != 0)
	{
		// ���������� ������, �������� ����� ���������
		for (auto& student : students)
		{
			int memLen[6];
			student->StrLen(memLen, pDC);
			for (int i = 0; i < 6; ++i)
				if (memLen[i] > aLen[i])
					aLen[i] = memLen[i];
		}

		// ���������� ������ ����� � ������ ���������
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

		// ������� �����
		int top = wordSpacing;
		for (int i = 0; i < 6; ++i)
		{
			pDC->TextOutW(aLeft[i], top, aHead[i]);
		}
		top += lineHeight;

		for_each(students.begin(), students.end(), bind(&Student_Stoler::CDCDrow, placeholders::_1, pDC, aLeft, ref(top), lineHeight));

		sizeAll.x = aLen[5] + wordSpacing;
		sizeAll.y = top;

		// �������������� �����
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

