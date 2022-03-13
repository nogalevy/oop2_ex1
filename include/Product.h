#pragma once

#include "CompOperation.h"

class Product : public CompOperation
{
public:
	Product(std::shared_ptr<Operation> first, std::shared_ptr<Operation> second);

	virtual Set calculate(std::vector<Set>& sets);
	virtual void print(int& offset);
private:
	Set calcProduct(std::vector<int> set1, std::vector<int> set2);
};