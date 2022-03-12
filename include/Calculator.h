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
#include "Difference.h"

enum Commands { EVAL, UNI, INTER, DIFF, PROD, COMP, DEL, HELP, EXIT };
const int NUM_OF_COMMAND = 9;
const std::string COMMANDS_STR[NUM_OF_COMMAND] = { "eval", "uni", "inter", "diff", "prod", "comp", "del", "help", "exit"};
const int ERROR_NUM = -1;
const std::vector<int> ERROR_COMMAND_NUM = { ERROR_NUM, ERROR_NUM };

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
	int interp(std::string command)const;


	//handle commands functions
	void handleEval(); //Tali: which of these needs consts
	void handleProd();
	void handleInter();
	void handleUnion();
	void handleDiff();
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