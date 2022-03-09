#pragma once

#include "CompOperation.h"


class Union : public CompOperation
{
public:
	Union(std::shared_ptr<Operation> first, std::shared_ptr<Operation> second);
	~Union();

	Set calculate(std::vector<Set> &sets);

private:
	
};