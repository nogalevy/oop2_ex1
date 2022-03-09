#include "Operation.h"

Operation::~Operation()
{
}

void Operation::setNumOfSets(const int num)
{
	m_numOfSets = num;
}

int Operation::getNumOfSets() const
{
	return m_numOfSets;
}
