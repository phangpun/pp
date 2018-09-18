#include <iostream>
#include <string>
// //**********************************************
// //			ARGUMENT CLASS
// //**********************************************

// argument class include argument error handling

//FLAG for isWrong() function
const char FIRST_INPUT = 0;
const char ADD_INPUT = 1;
const char COMPARE_INPUT = 2;
const char FIND_INPUT = 3;
const char DELETE_INPUT = 4;
const char GRAD = 5;


class argument {
private:
	std::string _string = "ARGUMENT_STRING";
	std::string arg1;
	std::string arg2;
	std::string arg3;
	std::string arg4;
	bool checkfine(std::string _string, const char FLAG, int gradnumber);

protected:
public:
	void set(std::string inputstring);
	std::string get();
	char firstchar();
	bool isWrong(const char FLAG, int gradnumber = 0);
	int number();
	void print();
	
	void get_to(std::string* name, int* stunum, std::string* labname);
	void get_to(std::string* name, int* stunum, int* freshmenclass);
	void get_to(int* index, std::string* name, int* stunum, std::string* labname);
	void get_to(int* index, std::string* name, int* stunum, int* freshmenclass);
	
};