#pragma once

#include <iostream>
#include "Set.h"

 
class Operation
{
public:
	Operation() = default;
	~Operation();

	/* 
		TODO:
		calculate recieve vector of sets ?
		
		
	*/
	

	virtual Set calculate(std::vector<Set> sets) = 0;

};