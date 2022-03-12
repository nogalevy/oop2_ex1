#pragma once

#include "Operation.h"
#include "utilities.h"

class Identity : public Operation
{
public:
	Identity();

	virtual Set calculate(std::vector<Set>& sets);
	virtual void print(int& offset);
};