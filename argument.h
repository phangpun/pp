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
const char CHANGE_INPUT = 5;


class argument {
private:
	std::string _string = "ARGUMENT_STRING";
	
protected:
public:
	void set(std::string inputstring);
	char firstchar();
	bool isWrong(const char FLAG);
	int number();
	void print();
	/*
	void toinput(std::string name, int stunum, std::string labname);
	void toinput(std::string name, int stunum, int freshmenclass);

	void toinput(int index, std::string name, int stunum, std::string labname);
	void toinput(int index, std::string name, int stunum, int freshmenclass);
	*/
};