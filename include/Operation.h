#pragma once

#include <iostream>
#include "Set.h"

 
class Operation
{
public:
	Operation() = default;
	virtual ~Operation();

	void setNumOfSets(const int num);
	int getNumOfSets()const;

	virtual Set calculate(std::vector<Set> &sets) = 0;

	virtual void print(int& offset) = 0;
private:
	int m_numOfSets;
};