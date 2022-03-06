#pragma once

#include "Operation.h"


class Union :Operation
{
public:
	//Union();
	Union(Set set1, Set set2);
	~Union();

	//
	Set calculate(const Set&, const Set&);

	//Access Functions
	Set getUnion()const;
private:
	Set m_mySet; //Noga: I dont think we need to save member here. this class just calc union of two sets, no?
};