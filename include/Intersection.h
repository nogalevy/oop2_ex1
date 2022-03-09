#pragma once

#include "CompOperation.h"


class Intersection : CompOperation
{
public:
	//Intersection();
	Intersection();
	~Intersection();

	// 
	Set calculate(std::vector<Set> sets);

	//Access Functions
	//Set getUnion()const;
private:
	
};