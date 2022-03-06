#include "Union.h"

//Union::Union() : m_mySet()
//{
//}

Union::Union(Set set1, Set set2)
	:m_mySet({}) //const
{
	auto result = std::vector<int>();
	std::ranges::set_union(set1.getSet(), set2.getSet(), std::back_inserter(result));

}

Union::~Union()
{
}
