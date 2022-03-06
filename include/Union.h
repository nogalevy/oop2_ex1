#pragma once

#include "Operation.h"


class Union :Operation
{
public:
	//Union();
	Union(Set set1, Set set2);
	~Union();

	//Access Functions
	Set getUnion()const;
private:
	Set m_mySet;
};