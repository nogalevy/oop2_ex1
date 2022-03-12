#include "Union.h"


Union::Union (std::shared_ptr<Operation> first, std::shared_ptr<Operation> second)
	:CompOperation(first, second)
{
	int count = initNumOfSets();
	setNumOfSets(count);
}

Set Union::calculate(std::vector<Set> &sets)
{
	std::cout << "(";
	Set firstSide = getFirstOp().get()->calculate(sets);
	std::cout << ' ' << UNI_SYMBOL << ' ';
	Set secondSide = getSecondOp().get()->calculate(sets);
	std::cout << ")";

	auto res = std::vector<int>();
	std::ranges::set_union(firstSide.getSet(), secondSide.getSet(), std::back_inserter(res));

	return Set(res);
}

void Union::print(int& offset)
{
	std::cout << "( ";
	getFirstOp().get()->print(offset);
	std::cout << ' ' << UNI_SYMBOL << ' ';
	getSecondOp().get()->print(offset);
	std::cout << " )";
}



