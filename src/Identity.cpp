#include "Identity.h"

Identity::Identity()
{
	setNumOfSets(ID_NUM_OF_SETS);
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
