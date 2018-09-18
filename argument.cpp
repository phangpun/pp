#include <iostream>
#include <string>
#include "argument.h"

bool argument::checkfine(std::string _string, const char FLAG, int gradnumber) {
	int size = _string.size();
	int arg1s = -1, arg1e = -1;
	int arg2s = -1, arg2e = -1;
	int arg3s = -1, arg3e = -1;
	int arg4s = -1, arg4e = -1;
	int arg_number = 0;

	int testint;
	
	switch (FLAG)
	{
	case FIRST_INPUT:
		break;
	case ADD_INPUT:
	case FIND_INPUT:
	case DELETE_INPUT:
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				if (_string.at(i) != ' ') {
					arg1s = i;
					if (_string.at(i + 1) == ' ') {
						arg1e = i;
						arg_number++;
					}
				}
			}
			else if (i == size - 1) {
				if (_string.at(i) != ' ') {
					arg3e = i;
					arg_number++;
				}
			}
			else
			{
				if (_string.at(i) != ' ' && _string.at(i + 1) == ' ') {
					if (arg_number < 1) {
						arg1e = i;
						arg_number++;
					}
					else if (arg_number < 2) {
						arg2e = i;
						arg_number++;
					}
				}
				else if (_string.at(i) == ' ' && _string.at(i + 1) != ' ') {
					if (arg_number < 1) {
						arg1s = i + 1;
					}
					else if (arg_number < 2) {
						arg2s = i + 1;
					}
					else if (arg_number < 3) {
						arg3s = i + 1;
					}
				}
			}
		}

		arg1 = _string.substr(arg1s, (arg1e - arg1s) + 1);
		arg2 = _string.substr(arg2s, (arg2e - arg2s) + 1);
		arg3 = _string.substr(arg3s, (arg3e - arg3s) + 1);

		for (unsigned int i = 0; i < arg2.size(); i++) {
			testint = static_cast<int>(arg2.at(i));
			if (static_cast<int>(arg2.at(i)) < '0' ||
				static_cast<int>(arg2.at(i)) > '9')
				return false;
		}

		if (gradnumber == 0) {
			for (unsigned int i = 0; i < arg3.size(); i++) {
				if (static_cast<int>(arg3.at(i)) < '0' ||
					static_cast<int>(arg3.at(i)) > '9')
					return false;
			}
		}

		return true;

		break;
	case COMPARE_INPUT:
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				if (_string.at(i) != ' ') {
					arg1s = i;
					if (_string.at(i + 1) == ' ') {
						arg1e = i;
						arg_number++;
					}
				}
			}
			else if (i == size - 1) {
				if (_string.at(i) != ' ') {
					arg4e = i;
					arg_number++;
				}
			}
			else
			{
				if (_string.at(i) != ' ' && _string.at(i + 1) == ' ') {
					if (arg_number < 1) {
						arg1e = i;
						arg_number++;
					}
					else if (arg_number < 2) {
						arg2e = i;
						arg_number++;
					}
					else if (arg_number < 3) {
						arg3e = i;
						arg_number++;
					}
				}
				else if (_string.at(i) == ' ' && _string.at(i + 1) != ' ') {
					if (arg_number < 1) {
						arg1s = i + 1;
					}
					else if (arg_number < 2) {
						arg2s = i + 1;
					}
					else if (arg_number < 3) {
						arg3s = i + 1;
					}
					else if (arg_number < 4) {
						arg4s = i + 1;
					}
				}
			}
		}

		arg1 = _string.substr(arg1s, (arg1e - arg1s) + 1);
		arg2 = _string.substr(arg2s, (arg2e - arg2s) + 1);
		arg3 = _string.substr(arg3s, (arg3e - arg3s) + 1);
		arg4 = _string.substr(arg4s, (arg4e - arg4s) + 1);

		for (unsigned int i = 0; i < arg1.size(); i++) {
			if (static_cast<int>(arg1.at(i)) < '0' ||
				static_cast<int>(arg1.at(i)) > '9')
				return false;
		}

		for (unsigned int i = 0; i < arg3.size(); i++) {
			if (static_cast<int>(arg3.at(i)) < '0' ||
				static_cast<int>(arg3.at(i)) > '9')
				return false;
		}

		if (gradnumber == 0) {
			for (unsigned int i = 0; i < arg4.size(); i++) {
				if (static_cast<int>(arg4.at(i)) < '0' ||
					static_cast<int>(arg4.at(i)) > '9')
					return false;
			}
		}

		return true;
		break;
	case GRAD:
		break;
	default:
		std::cout << "default in argumentcheck()" << std::endl;
		break;
	}
	return false;
}


void argument::set(std::string inputstring) {
	_string = inputstring;
}

std::string argument::get() {
	return _string;
}

char argument::firstchar() {
	return _string.at(0);
}

bool argument::isWrong(const char FLAG, int gradnumber) {
	switch (FLAG)
	{
	case FIRST_INPUT :
		if (_string.size() > 1 || _string.size() == 0) return true;
		break;
	case ADD_INPUT :
	case FIND_INPUT :
	case DELETE_INPUT:
		if (number() != 3) return true;
		else {
			if (!checkfine(_string, FLAG, gradnumber)) {
				return true;
			}
		}
		break;
	case COMPARE_INPUT :
		if (number() != 4) return true;
		else {
			if (!checkfine(_string, FLAG, gradnumber)) {
				return true;
			}
		}
		break;
	case GRAD :
		if (_string.size() > 1 || _string.size() == 0) return true;
		else if ( static_cast<int>(firstchar()) != '0' &&
			static_cast<int>(firstchar()) != '1') {
			return true;
		}
		break;
	default:
		std::cout << "default in argument::isWrong()" << std::endl;
		break;
	}

	return false;
}



int argument::number() {
	int size = _string.size();
	int arg_number = 0;
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			if (_string[i] != ' ') arg_number++;
		}
		else {
			if (_string[i] == ' ') {
				if ((i + 1) != size) {
					if (_string[i + 1] != ' ') arg_number++;
				}
			}

		}
	}

	return arg_number;
}

void argument::print() {
	std::cout << "print() : " << _string << std::endl;
}

void argument::get_to(std::string *name, int *stunum, std::string *labname) {
	*name = arg1;
	*stunum = std::stoi(arg2);
	*labname = arg3;
}

void argument::get_to(std::string* name, int* stunum, int* freshmenclass) {
	*name = arg1;
	*stunum = std::stoi(arg2);
	*freshmenclass = std::stoi(arg3);
}

void argument::get_to(int* index, std::string* name, int* stunum, std::string* labname) {
	*index = std::stoi(arg1);
	*name = arg2;
	*stunum = std::stoi(arg3);
	*labname = arg4;
}
void argument::get_to(int* index, std::string* name, int* stunum, int* freshmenclass) {
	*index = std::stoi(arg1);
	*name = arg2;
	*stunum = std::stoi(arg3);
	*freshmenclass = std::stoi(arg4);
}
