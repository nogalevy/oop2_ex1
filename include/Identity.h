#pragma once

#include "Operation.h"

class Identity : public Operation
{
public:
	Identity();
	~Identity();

	virtual Set calculate(std::vector<Set>& sets);
	virtual void print(int& offset);
};