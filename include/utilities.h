#pragma once

#include <string>

const int NUM_OF_COMMAND = 9;
enum Commands { EVAL, UNI, INTER, DIFF, PROD, COMP, DEL, HELP, EXIT };
const std::string COMMANDS_STR[NUM_OF_COMMAND] = { "eval", "uni", "inter", "diff", "prod", "comp", "del", "help", "exit" };


const int ERROR_NUM = -1;
const std::vector<int> ERROR_COMMAND_NUM = { ERROR_NUM, ERROR_NUM };

const char FIRST_LETTER = 'A';


//operators symbols:
const std::string UNI_SYMBOL = "U";
const std::string INTER_SYMBOL = "^";
const std::string DIFF_SYMBOL = "-";
const std::string PROD_SYMBOL = "*";
const std::string COMP_SYMBOL = "->";
