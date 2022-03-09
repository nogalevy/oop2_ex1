#include "CompOperation.h"

CompOperation::CompOperation(std::shared_ptr<Operation> first,std::shared_ptr<Operation> second)
	: m_firstOp(first), m_secondOp(second)
{
}

CompOperation::~CompOperation()
{
}

std::shared_ptr<Operation> CompOperation::getFirstOp() const
{
	return m_firstOp;
}

std::shared_ptr<Operation> CompOperation::getSecondOp() const
{
	return m_secondOp;
}
