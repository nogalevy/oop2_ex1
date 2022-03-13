#include "PrintUtilities.h"

void printRed(const std::string str)
{
	std::cout << "\033[1;31m" << str << "\033[0m\n" ;
}

void printCyan(const std::string str)
{
	std::cout << "\033[1;36m" << str << "\033[0m\n";
}

void printBold(const std::string str)
{
	std::cout << "\033[7;37m" << str << "\033[0m\n";
}