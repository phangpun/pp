#include <iostream>
#include <string>
#include <ctype.h>
#include "argument.h"

// //**********************************************
// //			argument class methods
// //**********************************************
void argument::print_intro() {
	std::cout << "argument print_intro()" << std::endl;
}

void argument::print_error() {
	std::cout << "Invalid argument" << std::endl << std::endl;
}

void argument::get_line() {
	std::getline(std::cin, linestring);
}

bool argument::is_valid() {
	std::cout << "argument is_valid()" << std::endl;
	return false;
}





// //**********************************************
// //	   argument_command class methods
// //**********************************************
void argument_command::print_intro() {
	std::cout << "What do you want to do?\n1. Add student:a\n2. Compare student:c \n3. Find student:f\n4. Delete student:d\n5. Print all student:p\n6. Quit:q" << std::endl;
}

bool argument_command::is_valid() {
	if (linestring.size() == 0 || linestring.size() > 1) return false;

	if (linestring == "a" || linestring == "c" || linestring == "f" ||
		linestring == "d" || linestring == "p" || linestring == "q"  ) 
		return true;
	
	return false;
}

char argument_command::output(std::string inputstring) {
	command = *(inputstring.c_str());
	return command;
}

char argument_command::input_handling() {
	print_intro();
	get_line();
	while (!is_valid()) {
		print_error();
		print_intro();
		get_line();
	}
	return output(linestring);
}



// //**********************************************
// //         argument_grad class methods
// //**********************************************
void argument_grad::print_intro() {
	switch (com_case)
	{
	case ADD:
		std::cout << "Add student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		break;
	case COMPARE:
		std::cout << "Compare student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		break;
	case FIND:
		std::cout << "Find student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		break;
	case DELETE:
		std::cout << "Delete student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		break;
	default:
		std::cout << "error:argument_grad class print_intro() " << std::endl;
		break;
	}
	
}

bool argument_grad::is_valid() {
	if (linestring.size() == 0 || linestring.size() > 1) return false;

	if (linestring == "0" || linestring == "1") return true;

	return false;
}

int argument_grad::output(std::string inputstring) {
	grad_index = std::stoi(inputstring);
	return grad_index;
}

void argument_grad::setcase(COMMAND_CASE inputcase) {
	com_case = inputcase;
}

int argument_grad::input_handling(COMMAND_CASE inputcase) {
	setcase(inputcase);
	print_intro();
	get_line();
	while (!is_valid()) {
		print_error();
		print_intro();
		get_line();
	}
	return output(linestring);
}



// //**********************************************
// //         argument_format class methods
// //**********************************************

int argument_format::arg_divide() {
	//for string index
	int argstartindex[4] = { -1,-1,-1,-1 };
	int argendindex[4] = { -1,-1,-1,-1 };
	int argnum = 0;
	if (linestring.size() >= 5) {
		for (unsigned int i = 0; i < linestring.size(); i++) {
			if (i == 0) { //first char
				if (!isblank(linestring.at(i))) { //not blank
					argnum++;
					argstartindex[0] = i;
					if (isblank(linestring.at(i + 1))) {
						argendindex[0] = i;
					}
				}
				else { //blank
					if (!isblank(linestring.at(i + 1))) {
						argnum++;
						argstartindex[0] = i + 1;
					}
				}
			}
			else if (i == (linestring.size() - 1)) { //last char
				if (!isblank(linestring.at(i))) { //not blank
					argendindex[argnum - 1] = i;
				}
			}
			else { //middle char
				if ( !isblank(linestring.at(i)) && // not blank
					isblank(linestring.at(i + 1)) ) { //blank
					argendindex[argnum - 1] = i;
				}
				else if (isblank(linestring.at(i)) && //blank
					!isblank(linestring.at(i + 1))) { // not blank
					argnum++;
					argstartindex[argnum - 1] = i + 1;
				}
			}
		}

		if (argnum == 3) {
			arg1 = linestring.substr(argstartindex[0], (argendindex[0] - argstartindex[0] + 1));
			arg2 = linestring.substr(argstartindex[1], (argendindex[1] - argstartindex[1] + 1));
			arg3 = linestring.substr(argstartindex[2], (argendindex[2] - argstartindex[2] + 1));
		}
		else if (argnum == 4) {
			arg1 = linestring.substr(argstartindex[0], (argendindex[0] - argstartindex[0] + 1));
			arg2 = linestring.substr(argstartindex[1], (argendindex[1] - argstartindex[1] + 1));
			arg3 = linestring.substr(argstartindex[2], (argendindex[2] - argstartindex[2] + 1));
			arg4 = linestring.substr(argstartindex[3], (argendindex[3] - argstartindex[3] + 1));
		}
	}
	return argnum;
}

bool argument_format::onlyalpha(std::string inputstring) {
	for (unsigned int i = 0; i < inputstring.size(); i++) {
		if (isalpha(inputstring.at(i))) continue;
		else return false;
	}
	return true;
}

bool argument_format::onlynumber(std::string inputstring) {
	for (unsigned int i = 0; i < inputstring.size(); i++) {
		if (isdigit(inputstring.at(i))) continue;
		else return false;
	}
	return true;
}

void argument_format::print_intro() {
	if (grad_index == 1) {
		switch (com_case)
		{
		case ADD:
		case FIND:
		case DELETE:
			std::cout << "Format: [name stunum labname]" << std::endl;
			break;
		case COMPARE:
			std::cout << "Format: [index name stunum labname]" << std::endl;
			break;
		default:
			std::cout << "error:argument_format class print_intro() " << std::endl;
			break;
		}
	}
	else if (grad_index == 0) {
		switch (com_case)
		{
		case ADD:
		case FIND:
		case DELETE:
			std::cout << "Format: [name stunum freshmenclass]" << std::endl;
			break;
		case COMPARE:
			std::cout << "Format: [index name stunum freshmenclass]" << std::endl;
			break;
		default:
			std::cout << "error:argument_format class print_intro() " << std::endl;
			break;
		}
	}
}

bool argument_format::is_valid() {
	int argnum = arg_divide();
	if (argnum < 3 && argnum > 4) return false;

	if (grad_index == 1) {//graduate
		switch (com_case)
		{
		case ADD:
		case FIND:
		case DELETE:
			if (argnum != 3) return false;
			if (onlyalpha(arg1) && onlynumber(arg2) && onlyalpha(arg3)) return true;
			break;
		case COMPARE:
			if (argnum != 4) return false;
			if (onlynumber(arg1) && onlyalpha(arg2) && 
				onlynumber(arg3) && onlyalpha(arg4)) return true;
			break;
		default:
			std::cout << "error:argument_format class is_valid() " << std::endl;
			break;
		}
	}
	else if (grad_index == 0) {//undergraduate
		switch (com_case)
		{
		case ADD:
		case FIND:
		case DELETE:
			if (argnum != 3) return false;
			if (onlyalpha(arg1) && onlynumber(arg2) && onlynumber(arg3)) return true;
			break;
		case COMPARE:
			if (argnum != 4) return false;
			if (onlynumber(arg1) && onlyalpha(arg2) &&
				onlynumber(arg3) && onlynumber(arg4)) return true;
			break;
		default:
			std::cout << "error:argument_format class is_valid() " << std::endl;
			break;
		}
	}
	
	return false;
}

void argument_format::setcase(COMMAND_CASE inputcase) {
	com_case = inputcase;
}

void argument_format::setgradindex(int gradindex) {
	grad_index = gradindex;
}

void argument_format::input_handling(COMMAND_CASE inputcase, int gradindex, int* index, std::string* name, int* stunum, int* freshmenclass) {
	setcase(inputcase);
	setgradindex(gradindex);
	print_intro();
	get_line();
	while (!is_valid()) {
		print_error();
		print_intro();
		get_line();
	}

	if (inputcase == COMPARE) {
		*index = std::stoi(arg1);
		*name = arg2;
		*stunum = std::stoi(arg3);
		*freshmenclass = std::stoi(arg4);
	}
	else {
		*name = arg1;
		*stunum = std::stoi(arg2);
		*freshmenclass = std::stoi(arg3);
	}
}

void argument_format::input_handling(COMMAND_CASE inputcase, int gradindex, int* index, std::string* name, int* stunum, std::string* labname) {
	setcase(inputcase);
	setgradindex(gradindex);
	print_intro();
	get_line();
	while (!is_valid()) {
		print_error();
		print_intro();
		get_line();
	}

	if (inputcase == COMPARE) {
		*index = std::stoi(arg1);
		*name = arg2;
		*stunum = std::stoi(arg3);
		*labname = arg4;
	}
	else {
		*name = arg1;
		*stunum = std::stoi(arg2);
		*labname = arg3;
	}
}