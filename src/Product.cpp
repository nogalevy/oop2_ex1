#include "Product.h"

Product::Product(std::shared_ptr<Operation> first, std::shared_ptr<Operation> second)
	:CompOperation(first, second)
{
}

Product::~Product()
{
}

Set Product::calculate(std::vector<Set>& sets)
{
	Set firstSide = getFirstOp().get()->calculate(sets);
	Set secondSide = getSecondOp().get()->calculate(sets);

	auto res = std::vector<int>();

	return calcProduct(firstSide.getSet(), secondSide.getSet());;
}

void Product::print(int& offset)
{
	std::cout << " ( ";
	getFirstOp().get()->print(offset);
	std::cout << " * ";
	getSecondOp().get()->print(offset);
	std::cout << " ) " << std::endl;
}

Set Product::calcProduct(std::vector<int> set1, std::vector<int> set2)
{
	std::vector<int> res;
	for (int i = 0; i < set1.size(); i++)
	{
		for (int j = 0; j < set2.size(); j++)
		{
			res.push_back(set1[i] * set2[j]);
		}
	}
	
	return Set(res);
}
