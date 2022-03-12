#pragma once

#include "CompOperation.h"


class Union : public CompOperation
{
public:
	Union(std::shared_ptr<Operation> first, std::shared_ptr<Operation> second);

	Set calculate(std::vector<Set> &sets);

	virtual void print(int& offset);
private:
};