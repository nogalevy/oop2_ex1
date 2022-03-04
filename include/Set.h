#pragma once
#include <iostream>
//#include <stdlib.h>
#include <vector>
//#include <ranges>
#include <algorithm>


class Set
{
public:
	Set(std::vector<int> val);
	void makeSet();
	std::vector<int> getSet()const;
	void printSet()const;

private:
	std::vector<int> m_setValues;

	void sort();
	void unique();
};