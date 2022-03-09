#pragma once

#include "Operation.h"


class CompOperation :Operation
{
public:
	CompOperation() ;
	~CompOperation();

private:
	std::shared_ptr<Operation> m_first;
	std::shared_ptr<Operation> m_second;
};