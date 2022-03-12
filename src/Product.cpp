#include "Product.h"

Product::Product(std::shared_ptr<Operation> first, std::shared_ptr<Operation> second)
	:CompOperation(first, second)
{
	int count = initNumOfSets();
	setNumOfSets(count);
}

Set Product::calculate(std::vector<Set>& sets)
{
	std::cout << "(";
	Set firstSide = getFirstOp().get()->calculate(sets);
	std::cout << ' ' << PROD_SYMBOL << ' ';
	Set secondSide = getSecondOp().get()->calculate(sets);
	std::cout << ")";

	auto res = std::vector<int>();

	return calcProduct(firstSide.getSet(), secondSide.getSet());;
}

void Product::print(int& offset)
{
	std::cout << "( ";
	getFirstOp().get()->print(offset);
	std::cout << ' ' << PROD_SYMBOL << ' ';
	getSecondOp().get()->print(offset);
	std::cout << " )";
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
