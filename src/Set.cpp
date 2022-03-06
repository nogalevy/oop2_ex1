#include "Set.h"

Set::Set(std::vector<int> val)
	:m_setValues(val)
{
	makeSet();
}

void Set::makeSet()
{
	sort();
	unique();
}

std::vector<int> Set::getSet() const
{
	return m_setValues;
}

void Set::printSet() const
{
	std::cout << "{ ";
	for (int i = 0; i < m_setValues.size(); i++)
	{
		std::cout << m_setValues[i] << " ";
	}
	std::cout << "}\n";
}


/*
	Noga: I think we need to use the std::ranges::uniqueand std::ranges::sort
			but for some reason its not recognize 'ranges'

	Tali: Hi nogaaaaaaaaaa, i played around with some includes. I also did a bit of
			research. I couldn't fix the problem but i think it can be either:
				1. something to do with cmake
				2. the version of c++ that we are using. i saw on google that 
					ranges requires c++20 (should we check if it's enabled?)
				3. something to do with clang - i obviously dont understand enough about that
*/ 

void Set::sort()
{
	//std::sort(m_setValues.begin(), m_setValues.end());
	
	//auto ranges = std::ranges;

	std::ranges::sort(m_setValues.begin(), m_setValues.end());
}

void Set::unique()
{
	/*auto newEnd = std::unique(m_setValues.begin(), m_setValues.end());
	m_setValues.erase(newEnd, m_setValues.end());*/

	auto [newEnd, end] = std::ranges::unique(m_setValues);
	m_setValues.erase(newEnd, end);
}
