#include "Composite.h"


Composite::Composite(std::shared_ptr<Operation> first, std::shared_ptr<Operation> second)
	:CompOperation(first, second)
{
	int count = initNumOfSets();
	setNumOfSets(count - 1);
}

Set Composite::calculate(std::vector<Set>& sets)
{
	std::cout << "(";
	Set firstSide = getFirstOp().get()->calculate(sets);
	std::cout << " -> ";
	sets.insert(sets.begin(), firstSide);
	Set secondSide = getSecondOp().get()->calculate(sets);
	std::cout << ")";

	return secondSide;
}

void Composite::print(int& offset)
{
	std::cout << "( ";
	getFirstOp().get()->print(offset);
	std::cout << " -> ";
	getSecondOp().get()->print(offset);
	std::cout << " )";
}



