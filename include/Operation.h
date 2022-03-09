#pragma once

#include <iostream>
#include "Set.h"

 
class Operation
{
public:
	Operation() = default;
	~Operation();

	virtual Set calculate(std::vector<Set> sets) = 0;

};