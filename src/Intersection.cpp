#include "Intersection.h"

Intersection::Intersection( std::shared_ptr<Operation> first,  std::shared_ptr<Operation> second)
	:CompOperation(first, second)
{
}

Intersection::~Intersection()
{
}

Set Intersection::calculate(std::vector<Set> &sets)
{
	Set firstSide = getFirstOp().get()->calculate(sets);
	Set secondSide = getSecondOp().get()->calculate(sets);

	auto res = std::vector<int>();
	std::ranges::set_intersection(firstSide.getSet(), secondSide.getSet(), std::back_inserter(res));

	return Set(res);
}

void Intersection::print(int& offset)
{
	std::cout << " ( ";
	getFirstOp().get()->print(offset);
	std::cout << " ^ ";
	getSecondOp().get()->print(offset);
	std::cout << " ) " << std::endl;
}


