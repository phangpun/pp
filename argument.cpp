#include <iostream>
#include <string>
#include "argument.h"


void argument::set(std::string inputstring) {
	_string = inputstring;
}

char argument::firstchar() {
	return _string.at(0);
}

bool argument::isWrong() {
	if (_string.size() > 1) {
		return true;
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

