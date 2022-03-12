#include "CompOperation.h"

CompOperation::CompOperation(std::shared_ptr<Operation> first,std::shared_ptr<Operation> second)
	: m_firstOp(first), m_secondOp(second)
{
}

int CompOperation::initNumOfSets()
{
	int count1 = getFirstOp().get()->getNumOfSets();
	int count2 = getSecondOp().get()->getNumOfSets();

	return (count1 + count2);
}

std::shared_ptr<Operation> CompOperation::getFirstOp() const
{
	return m_firstOp;
}

std::shared_ptr<Operation> CompOperation::getSecondOp() const
{
	return m_secondOp;
}
