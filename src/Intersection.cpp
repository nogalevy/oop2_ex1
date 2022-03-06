#include "..\include\Intersection.h"

Intersection::Intersection()
{
}

Intersection::~Intersection()
{
}

Set Intersection::calculate(const Set& set1, const Set& set2)
{
	std::vector<int> res;
	std::ranges::set_intersection(set1.getSet(), set2.getSet(), std::back_inserter(res));

	return res;
}
