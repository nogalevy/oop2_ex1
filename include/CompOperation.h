#pragma once

#include "Operation.h"


class CompOperation :Operation
{
public:
	//Intersection();
	CompOperation();
	~CompOperation();


	//Access Functions
	//Set getUnion()const;
private:
	std::shared_ptr<Operation> m_first;
	std::shared_ptr<Operation> m_second;
};