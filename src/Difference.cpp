#include "..\include\Difference.h"

Difference::Difference(std::shared_ptr<Operation> first, std::shared_ptr<Operation> second)
	:CompOperation(first, second)
{
	int count = initNumOfSets();
	setNumOfSets(count);
}

Set Difference::calculate(std::vector<Set>& sets)
{
	std::cout << "(";
	Set firstSide = getFirstOp().get()->calculate(sets);
	std::cout << ' ' << DIFF_SYMBOL << ' ';
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
	std::cout << ' ' << DIFF_SYMBOL << ' ';
	getSecondOp().get()->print(offset);
	std::cout << " )";
}
