#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include<iterator>

class Set
{
public:
	Set(std::vector<int> val);
	void makeSet(); //Tali: private?
	std::vector<int> getSet()const;
	void printSet()const;

private:
	std::vector<int> m_setValues;

	void sort();
	void unique();
};