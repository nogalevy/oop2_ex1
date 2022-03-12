#include "..\include\Difference.h"

Difference::Difference(std::shared_ptr<Operation> first, std::shared_ptr<Operation> second)
	:CompOperation(first, second)
{
	int count = initNumOfSets();
	setNumOfSets(count);
}

Difference::~Difference()
{
}

int Difference::initNumOfSets()
{
	int count1 = getFirstOp().get()->getNumOfSets();
	int count2 = getSecondOp().get()->getNumOfSets();

	return (count1 + count2);
}

Set Difference::calculate(std::vector<Set>& sets)
{
	std::cout << "(";
	Set firstSide = getFirstOp().get()->calculate(sets);
	std::cout << " - ";
	Set secondSide = getSecondOp().get()->calculate(sets);
	std::cout << ")";

	auto res = std::vector<int>();
	std::ranges::set_difference(firstSide.getSet(), secondSide.getSet(), std::back_inserter(res));

	return Set(res);
}

void Difference::print(int& offset)
{
	std::cout << "( ";
	getFirstOp().get()->print(offset);
	std::cout << " - ";
	getSecondOp().get()->print(offset);
	std::cout << " )";
}
