#include "Calculator.h"


Calculator::Calculator()
	:m_operation({})
{
	initBaseOp();
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

void Calculator::initBaseOp()
{
	//add basic union ( A U B )
	m_operation.emplace_back(std::make_shared<Union>(std::make_shared<Identity>(), std::make_shared<Identity>()));

	//add basic intersection ( A ^ B ) 
	m_operation.emplace_back(std::make_shared<Intersection>(std::make_shared<Identity>(), std::make_shared<Identity>()));

	//add basic difference ( A - B )
	m_operation.emplace_back(std::make_shared<Difference>(std::make_shared<Identity>(), std::make_shared<Identity>()));
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
		handleEval();
		break;
	case UNI:
		handleUnion();
		break;
	case INTER:
		handleInter();
		break;
	case DIFF:
		handleDiff();
		break;
	case PROD:
		handleProd();
		break;
	case COMP:
		handleComp();
		break;
	case DEL:
		handleDelete();
		break;
	case HELP:
		printHelp();
		break;
	case EXIT: //exit
		printCyan("Thank you and goodbye");
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
	return ERROR_NUM;
}

//-----------------------------------------

void Calculator::handleEval()
{
	int command = readCommandNum();
	if (!isValidCommand(command))
	{
		printCommandError();
		return;
	}
	int numOfSets = m_operation[command]->getNumOfSets();

	std::cout << "Please enter " << numOfSets << " sets:\n"; 
	auto sets = readSets(numOfSets);

	Set res = m_operation[command]->calculate(sets);
	std::cout << ' ' << EQUAL_SYMBOL << ' ';
	res.printSet();
	std::cout << "\n";

}

//-----------------------------------------

std::vector<Set> Calculator::readSets(const int numOfSets) const
{
	auto sets = std::vector<Set>();
	auto intVec = std::vector<int>();
	int numOfInts, num;

	for (int i = 0; i < numOfSets; i++)
	{
		std::cin >> numOfInts;
		for (int j = 0; j < numOfInts; j++)
		{
			std::cin >> num;
			intVec.push_back(num);
		}
		sets.push_back(Set(intVec));
		intVec.clear();
	}
	return sets;
}

//-----------------------------------------

void Calculator::handleProd()
{
	auto retVal = getTwoCommands(); 
	
	if (retVal == ERROR_COMMAND_NUM) return;
	m_operation.emplace_back(std::make_shared<Product>(m_operation[retVal[0]], m_operation[retVal[1]]));
}

//-----------------------------------------

void Calculator::handleInter()
{
	auto retVal = getTwoCommands();

	if (retVal == ERROR_COMMAND_NUM) return;
	m_operation.emplace_back(std::make_shared<Intersection>(m_operation[retVal[0]], m_operation[retVal[1]]));
}

//-----------------------------------------

void Calculator::handleUnion()
{
	auto retVal = getTwoCommands();

	if (retVal == ERROR_COMMAND_NUM) return;
	m_operation.emplace_back(std::make_shared<Union>(m_operation[retVal[0]], m_operation[retVal[1]]));
}

//-----------------------------------------

void Calculator::handleDiff()
{
	auto retVal = getTwoCommands(); 

	if (retVal == ERROR_COMMAND_NUM) return;
	m_operation.emplace_back(std::make_shared<Difference>(m_operation[retVal[0]], m_operation[retVal[1]]));
}

//-----------------------------------------

void Calculator::handleComp()
{
	auto retVal = getTwoCommands();

	if (retVal == ERROR_COMMAND_NUM) return;
	m_operation.emplace_back(std::make_shared<Composite>(m_operation[retVal[0]], m_operation[retVal[1]]));
}

//-----------------------------------------

void Calculator::handleDelete()
{
	int commandToDelete = readCommandNum();
	if (!isValidCommand(commandToDelete))
	{
		printCommandError();
		return;
	}
	m_operation.erase(m_operation.begin() + commandToDelete);
}

//-----------------------------------------

std::vector<int> Calculator::getTwoCommands() const
{
	std::vector<int> retVal(2, 0);
	retVal[0] = readCommandNum();
	retVal[1]  = readCommandNum();

	if (!isValidCommand(retVal[0]) || !isValidCommand(retVal[1]))
	{
		printCommandError();
		return ERROR_COMMAND_NUM;
	}

	return retVal;
}

//-----------------------------------------

int Calculator::readCommandNum()const
{
	int command;
	std::cin >> command;
	return command;
}

//-----------------------------------------

bool Calculator::isValidCommand(int command)const
{
	if (command < m_operation.size() && command >= 0) return true;
	return false;
}

//-----------------------------------------

void Calculator::print() const
{
	printBold("\nList of available set operations: \n\n");

	//print options
	int offset = 0;

	for (int i = 0; i <  m_operation.size() ; i++)
	{
		offset = 0;

		std::cout << i << ". ";
		m_operation[i]->print(offset);
		std::cout << std::endl;
	}

	std::cout << "\nEnter command ('help' for the list of available commands): ";
}

//-----------------------------------------

void Calculator::printErrorMsg() const
{
	printRed("Command not found");
}

//-----------------------------------------

void Calculator::printHelp() const
{
	std::cout << "\nThe available commands are:\n"
			<< "* eval(uate) num ... - compute the result of the function #num on the following\n"
			<< "  set(s); each set is prefixed with the count of numbers to read\n"
			<< "* uni(on) num1 num2 - creates an operation that is the union of operation\n"
			<< "  #num1 and operation #num2\n"
			<< "* inter(section) num1 num2 - creates an operation that is the intersection\n"
			<< "  of operation #num1 and operation #num2\n"
			<< "* diff(erence) num1 num2 - creates an operation that is the difference of\n"
			<< "  operation #num1 and operation #num2\n"
			<< "* prod(uct) num1 num2 - creates an operation that returns the product of\n"
			<< "  the items from the results of operation #num1 and operation #num2\n"
			<< "* comp(osite) num1 num2 - creates an operation that is the composition of\n"
			<< "  operation #num1 and operation #num2\n"
			<< "* del(ete) num - delete operation #num from the operation list\n"
			<< "* help - print this command list\n"
			<< "* exit - exit the program\n";
}

//-----------------------------------------

void Calculator::printCommandError() const
{
	printRed("The operation does not exist\n");
}
