#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <memory>

class Calculator
{
public:
	Calculator();
	void run();
private:
	std::shared_ptr<int> m_operation; //evaluate, union, intersection .....................

	void print()const;

};