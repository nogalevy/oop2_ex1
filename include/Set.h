#pragma once
#include <iostream>
//#include <stdlib.h>
#include <vector>
//#include <ranges>
#include <algorithm>
#include<iterator>
#include<functional>
#include <array>
#include <ranges>
#include <memory>


class Set
{
public:
	//Set() = default; //Tali : need a default constructor (for other classes) want to know if we should have default m_setValues = {0} or something
	Set(std::vector<int> val);
	void makeSet();
	std::vector<int> getSet()const;
	void printSet()const;

private:
	std::vector<int> m_setValues;

	void sort();
	void unique();
};