#pragma once

#include "CompOperation.h"

class Difference : public CompOperation
{
public:
	Difference(std::shared_ptr<Operation> first, std::shared_ptr<Operation> second);

	Set calculate(std::vector<Set>& sets);
	virtual void print(int& offset);
};