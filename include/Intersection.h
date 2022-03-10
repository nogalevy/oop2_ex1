#pragma once

#include "CompOperation.h"


class Intersection : public CompOperation
{
public:
	//Intersection();
	Intersection( std::shared_ptr<Operation> first,  std::shared_ptr<Operation> second);
	~Intersection();

	// 
	Set calculate(std::vector<Set> &sets);
	virtual void print(int& offset);
private:
	
};