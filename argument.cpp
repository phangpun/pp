#include <iostream>
#include <string>
#include "argument.h"


void argument::set(std::string inputstring) {
	_string = inputstring;
}

std::string argument::get() {
	return _string;
}

char argument::firstchar() {
	return _string.at(0);
}

bool argument::isWrong(const char FLAG) {
	switch (FLAG)
	{
	case FIRST_INPUT :
		if (_string.size() > 1) return true;
		break;
	case ADD_INPUT :
		if (this->number() != 3) return true;
		else if (this->firstchar() == ' ') return true;
		else {

		}
		break;
	case COMPARE_INPUT :
		break;
	case FIND_INPUT :
		break;
	case DELETE_INPUT :
		break;
	case CHANGE_INPUT :
		break;
	case GRAD :
		if (_string.size() > 1) return true;
		else if ( static_cast<int>(this->firstchar()) - 48 != 0 &&
			static_cast<int>(this->firstchar()) - 48 != 1) {
			return true;
		}
		break;
	default:
		break;
	}

	return false;
}

int argument::number() {
	int size = _string.size();
	int number = 0;
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			if (_string[i] != ' ') number++;
		}
		else if(i == size){

		}
		else {
			if (_string[i] == ' ') {
				if ((i + 1) != size) {
					if (_string[i + 1] != ' ') number++;
				}
			}

		}
	}

	return number;
}

void argument::print() {
	std::cout << "print() : " << _string << std::endl;
}
/*
void toinput(std::string name, int stunum, std::string labname) {

}
void toinput(std::string name, int stunum, int freshmenclass);

void toinput(int index, std::string name, int stunum, std::string labname);
void toinput(int index, std::string name, int stunum, int freshmenclass);
*/