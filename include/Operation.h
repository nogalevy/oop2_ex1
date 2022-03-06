#pragma once

#include "Set.h"

class Operation
{
public:
	Operation() = default;
	~Operation();

	virtual Set calculate(const Set&, const Set&) = 0;
};