#include <iostream>
#include <string>
// //**********************************************
// //			ARGUMENT CLASS
// //**********************************************

//COMMAND_CASE is divided to 4 cases
enum COMMAND_CASE {ADD,COMPARE,FIND,DELETE};


//argument class : parent class of command, grad and format
class argument {
private:
protected:
	std::string linestring; //variable for get line string;
	virtual void print_intro(); //print argument format(information)
	virtual bool is_valid(); //for error handling
	void print_error(); //print error message
	void get_line(); //for get a line input
public:
};

//argument_command : to get command(one char) from command input
class argument_command : public argument {
private:
	char command; //variable for return command char
protected:
	void print_intro() override;
	bool is_valid() override;
	char output(std::string inputstring);// to set return value
public:
	char input_handling(); //the set of function
};


//argument_grad : to get grad(0) integer or undergrad(1) integer
class argument_grad : public argument {
private:
	int grad_index; //variable for return 0 or 1
	COMMAND_CASE com_case; //variable for stage
protected:
	void print_intro() override;
	bool is_valid() override;
	int output(std::string inputstring);// to set return value
	void setcase(COMMAND_CASE inputcase);// to set stage
public:
	int input_handling(COMMAND_CASE inputcase); //the set of function
};

class argument_format : public argument {
private:
	std::string arg1, arg2, arg3, arg4;//variable for return valid argument
	int grad_index; //variable for stage
	COMMAND_CASE com_case; //variable for stage

	int arg_divide(); //to convert line to arguments (return value : number of argument)
	bool onlyalpha(std::string inputstring); //to check argument has only alphabet char
	bool onlynumber(std::string inputstring); //to check argument has only digit char
protected:
	void print_intro() override;
	bool is_valid() override;
	void setcase(COMMAND_CASE inputcase);
	void setgradindex(int gradindex);
public:
	//for undergraduate student
	void input_handling(COMMAND_CASE inputcase, int gradindex, int* index, std::string* name, int* stunum, int* freshmenclass);
	//for graduate student
	void input_handling(COMMAND_CASE inputcase, int gradindex, int* index, std::string* name, int* stunum, std::string* labname);

};