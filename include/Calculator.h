#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <memory>
#include <string>

#include "Set.h"
#include "Union.h"
#include "Identity.h"
#include "Intersection.h"
#include "Product.h"


enum Commands { EVAL, UNI, INTER, DIFF, PROD, COMP, DEL, HELP, EXIT };
const int NUM_OF_COMMAND = 9;
const std::string COMMANDS_STR[NUM_OF_COMMAND] = { "eval", "uni", "inter", "diff", "prod", "comp", "del", "help", "exit"};

class Calculator
{
public:
	Calculator();
	void run();
private:
	std::vector<std::shared_ptr<Operation>> m_operation; //evaluate, union, intersection .....................

	void getCommand();
	void doCommand(int command);
	int interp(std::string command)const;



	//print functions:
	void print()const;
	void printErrorMsg()const;
	void printHelp()const;


};