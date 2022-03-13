#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include<iterator>

class Set
{
public:
	Set(const std::vector<int> val);

	std::vector<int> getSet()const;
	void printSet()const;

private:
	std::vector<int> m_setValues;

	void makeSet();
	void sort();
	void unique();
};