#include <iostream>
#include <string>
// //**********************************************
// //			ARGUMENT CLASS
// //**********************************************

// argument class include argument error handling

enum COMMAND_CASE {ADD,COMPARE,FIND,DELETE};

class argument {
private:
protected:
	std::string linestring;
	virtual void print_intro();
	virtual bool is_valid();
	void print_error();
	void get_line();
public:
};


class argument_command : public argument {
private:
	char command;
protected:
	void print_intro() override;
	bool is_valid() override;
	char output(std::string inputstring);
public:
	char input_handling();
};

class argument_grad : public argument {
private:
	int grad_index;
	COMMAND_CASE com_case;
protected:
	void print_intro() override;
	bool is_valid() override;
	int output(std::string inputstring);
	void setcase(COMMAND_CASE inputcase);
public:
	int input_handling(COMMAND_CASE inputcase);
};

class argument_format : public argument {
private:
	std::string arg1, arg2, arg3, arg4;
	int grad_index;
	COMMAND_CASE com_case;

	int arg_divide();
	bool onlyalpha(std::string inputstring);
	bool onlynumber(std::string inputstring);
protected:
	void print_intro() override;
	bool is_valid() override;
	void setcase(COMMAND_CASE inputcase);
	void setgradindex(int gradindex);
public:
	void input_handling(COMMAND_CASE inputcase, int gradindex, int* index, std::string* name, int* stunum, int* freshmenclass);
	void input_handling(COMMAND_CASE inputcase, int gradindex, int* index, std::string* name, int* stunum, std::string* labname);

};