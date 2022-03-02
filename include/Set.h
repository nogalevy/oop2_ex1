#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>

class Set
{
public:
	Set(std::vector<int> val);

private:
	std::vector<int> m_setValues;

	void sort();
	void unique();
};