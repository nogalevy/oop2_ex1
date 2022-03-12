#pragma once

#include "CompOperation.h"


class Intersection : public CompOperation
{
public:
	Intersection( std::shared_ptr<Operation> first,  std::shared_ptr<Operation> second);
	//TODO: if all constructors are the same, just use Aba's

	Set calculate(std::vector<Set> &sets);
	virtual void print(int& offset);
private:
};