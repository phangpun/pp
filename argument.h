// //**********************************************
// //			ARGUMENT CLASS
// //**********************************************

// argument class include argument error handling

class argument {
private:
	std::string _string;
	
protected:
public:
	void set(std::string inputstring);
	char firstchar();
	bool isWrong();
	int number();
	void print();
};