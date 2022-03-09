#include "Identity.h"

Identity::Identity()
{
	setNumOfSets(1);
}

Identity::~Identity()
{
}

Set Identity::calculate(std::vector<Set> &sets)
{
	Set identity = sets[0]; 
	
	//TODO: copy constructor Set
	//Tali: is there a chance it will recieve null? if so should we check (and are there any other things we need to check for)
	sets.erase(sets.begin());

	return identity;
}
