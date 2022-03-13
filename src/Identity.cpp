#include "Identity.h"

Identity::Identity()
{
	setNumOfSets(1);
}

Set Identity::calculate(std::vector<Set> &sets)
{
	Set identity = sets[0]; 
	identity.printSet();

	//TODO: copy constructor Set
	//Tali: is there a chance it will recieve null? if so should we check (and are there any other things we need to check for)
	
	sets.erase(sets.begin());

	return identity;
}

void Identity::print(int& offset)
{
	std::cout << char(FIRST_LETTER + (offset % 26)) << (offset >= 26 ? "'" : "");

	offset++;
}
