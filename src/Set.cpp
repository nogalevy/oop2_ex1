#include "Set.h"

Set::Set(const std::vector<int> val)
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
		std::cout << m_setValues[i] << (i == (m_setValues.size() - 1) ? " " : ", ");
	}
	std::cout << "}";
}


void Set::sort()
{
	std::ranges::sort(m_setValues.begin(), m_setValues.end());
}

void Set::unique()
{
	auto [newEnd, end] = std::ranges::unique(m_setValues);
	m_setValues.erase(newEnd, end);
}
