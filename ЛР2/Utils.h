#pragma once
#include <iostream>

using namespace std;

template <typename T>

T InputCheck(T min, T max)
{
	T x{};
	while ((std::cin >> x).fail() || (x < min) || (x > max))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "���������� ��� ���" << std::endl;
	}
	return x;
}