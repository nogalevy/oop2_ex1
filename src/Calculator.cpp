#include "Calculator.h"


Calculator::Calculator()
{
}

//-----------------------------------------

void Calculator::run()
{
	while(1) 
	{
		print();
		getCommand();
	}	
}

//-----------------------------------------

void Calculator::getCommand()
{
	std::string command;
	std::cin >> command;

	doCommand(interp(command));
}

//-----------------------------------------

void Calculator::doCommand(int command)
{
	switch (command)
	{
	case EVAL:
	{
		std::cout << "evaluate\n";

		std::vector vec = { 1, 5, 6, 3, 12 , 3, 12 , 1, 5 };
		Set newSet = Set(vec);
		newSet.printSet();
	}
		
		break;
	case UNI:
		break;
	case INTER:
		break;
	case DIFF:
		break;
	case PROD:
		break;
	case COMP:
		break;
	case DEL:
		break;
	case HELP:
		printHelp();
		break;
	case EXIT: //exit
		exit(EXIT_SUCCESS);
		break;
	default: // error?
		printErrorMsg();
		break;
	}
}

//-----------------------------------------

int Calculator::interp(std::string command) const
{
	for (int i = 0; i < NUM_OF_COMMAND ; i++)
	{
		if (COMMANDS_STR[i].compare(command) == 0)
			return Commands(i);
	}
	return -1; //error
}

//-----------------------------------------

void Calculator::print() const
{
	std::cout << "List of available set operations: \n";

	//print options

	std::cout << "Enter command ('help' for the list of available commands): ";
}

//-----------------------------------------

void Calculator::printErrorMsg() const
{
	std::cout << "NO!\n";
}

//-----------------------------------------

void Calculator::printHelp() const
{
	std::cout << "help\n";
}
