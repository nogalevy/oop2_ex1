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
		std::cout << "evaluate";
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
	std::cout << "Command not found\n";
}

//-----------------------------------------

void Calculator::printHelp() const
{
	std::cout << "The available commands are:\n"
			<< "* eval(uate) num ... - compute the result of the function #num on the following\n"
			<< "set(s); each set is prefixed with the count of numbers to read\n"
			<< "* uni(on) num1 num2 - creates an operation that is the union of operation\n"
			<< "#num1 and operation #num2\n"
			<< "* inter(section) num1 num2 - creates an operation that is the intersection\n"
			<< "of operation #num1 and operation #num2\n"
			<< "* diff(erence) num1 num2 - creates an operation that is the difference of\n"
			<< "operation #num1 and operation #num2\n"
			<< "* prod(uct) num1 num2 - creates an operation that returns the product of\n"
			<< "the items from the results of operation #num1 and operation #num2\n"
			<< "* comp(osite) num1 num2 - creates an operation that is the composition of\n"
			<< "operation #num1 and operation #num2\n"
			<< "* del(ete) num - delete operation #num from the operation list\n"
			<< "* help - print this command list\n"
			<< "* exit - exit the program\n";
}
