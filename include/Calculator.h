#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <memory>
#include <string>

#include "utilities.h"
#include "PrintUtilities.h"

#include "Set.h"
#include "Union.h"
#include "Identity.h"
#include "Intersection.h"
#include "Product.h"
#include "Difference.h"
#include "Composite.h"


class Calculator
{
public:
	Calculator();
	void run();
private:
	std::vector<std::shared_ptr<Operation>> m_operation; //evaluate, union, intersection .....................

	void initBaseOp();
	void getCommand();
	void doCommand(int command);
	int interp(const std::string command)const;


	//handle commands functions
	void handleEval() const; 
	void handleProd();
	void handleInter();
	void handleUnion();
	void handleDiff();
	void handleComp();
	void handleDelete();


	std::vector<int> getTwoCommands()const;
	int readCommandNum()const;
	bool isValidCommand(int command)const;
	std::vector<Set> readSets(const int numOfInputs)const;

	
	//print functions:
	void print()const;
	void printErrorMsg()const;
	void printHelp()const;
	void printCommandError()const;

};