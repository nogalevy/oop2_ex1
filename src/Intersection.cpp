#include "Intersection.h"

Intersection::Intersection( std::shared_ptr<Operation> first,  std::shared_ptr<Operation> second)
	:CompOperation(first, second)
{
	int count = initNumOfSets();
	setNumOfSets(count);
}

Set Intersection::calculate(std::vector<Set> &sets)
{
	std::cout << "(";
	Set firstSide = getFirstOp().get()->calculate(sets);
	std::cout << " ^ ";
	Set secondSide = getSecondOp().get()->calculate(sets);
	std::cout << ")";

	auto res = std::vector<int>();
	std::ranges::set_intersection(firstSide.getSet(), secondSide.getSet(), std::back_inserter(res));

	return Set(res);
}

void Intersection::print(int& offset)
{
	std::cout << "( ";
	getFirstOp().get()->print(offset);
	std::cout << " ^ ";
	getSecondOp().get()->print(offset);
	std::cout << " )";
}


