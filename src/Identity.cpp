#include "Identity.h"

Identity::Identity()
{
	setNumOfSets(1); //TODO: const
}

Set Identity::calculate(std::vector<Set> &sets)
{
	Set identity = sets[0]; 
	identity.printSet();

	sets.erase(sets.begin());

	return identity;
}

void Identity::print(int& offset)
{
	std::cout << char(FIRST_LETTER + (offset % 26)) << (offset >= 26 ? "'" : "");

	offset++;
}
