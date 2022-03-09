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
	//std::vector<int> res;
	/*std::ranges::set_intersection(set1.getSet(), set2.getSet(), std::back_inserter(res)); */

	return Set({});
}

