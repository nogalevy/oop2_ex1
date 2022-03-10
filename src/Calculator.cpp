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
	{
		std::cout << "evaluate\n";

		std::vector vec = { 1, 5, 6, 3, 12 , 3, 12 , 1, 5 };
		Set newSet = Set(vec);
		newSet.printSet(); //TODO: operator << thanks
		break;
	}	
	case UNI:
	{
	/*	std::vector<Set> sets = { Set({ 1, 2, 3, 4 }), Set({ 2, 56, 675, 56 }) };
		Set res = m_operation[0]->calculate(sets);
	
		res.printSet();*/
		handleUnion();
		break;
	}
	case INTER:
	{
		////inter exeample :
		//std::vector<Set> sets = { Set({ 1, 2, 3, 4 }), Set({ 2, 56, 675, 56 }) };
		//Set res = m_operation[1]->calculate(sets);
		////Intersection inter;
		////Set res = inter.calculate({Set({ 1, 2, 3, 4 }), Set({ 2, 7 ,8 ,9 ,56, 675, 56 })});
		//res.printSet();
		handleInter();
		break;
	}
	case DIFF:
	{
		handleDiff();
		break;
	}
	case PROD:
	{
		handleProd();
	}
		break;
	case COMP:
		break;
	case DEL:
		handleDelete();
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
	return ERROR_NUM; //error TODO: add to constants
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
		return ERROR_COMMAND_NUM; //TODO: constant
	}

	return retVal;

}

int Calculator::readCommandNum()const
{
	int command;
	std::cin >> command;
	return command;
}

bool Calculator::isValidCommand(int command)const
{
	if (command < m_operation.size() && command >= 0) return true;
	return false;
}

void Calculator::print() const
{
	std::cout << "List of available set operations: \n";

	//print options
	int offset = 0;

	for (int i = 0; i <  m_operation.size() ; i++)
	{
		offset = 0;

		std::cout << i << ". ";
		m_operation[i]->print(offset);
		std::cout << std::endl;

	}

	
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

void Calculator::printCommandError() const
{
	std::cout << "The operation does not exist\n";
}
