#pragma once

#include "Operation.h"

class CompOperation : public Operation
{
public:
	CompOperation(std::shared_ptr<Operation> first,std::shared_ptr<Operation> second);

	int initNumOfSets();

	std::shared_ptr<Operation> getFirstOp()const;
	std::shared_ptr<Operation> getSecondOp()const;
	
private:
	std::shared_ptr<Operation> m_firstOp;
	std::shared_ptr<Operation> m_secondOp;
};