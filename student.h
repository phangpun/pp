// //***************************************************************
// //                   CLASS USED IN PROJECT
// //****************************************************************

class Student{
 private:
 protected:
	 int m_stunum = 0;
	 std::string m_name = "M_NAME";
	 
	 //doubly linked list
	 Student* m_Rightptr; //pointer to Right Student data
	 Student* m_Leftptr;  //pointer to Left Student data
 public:
	 virtual void getInfo();
	 virtual void setInfo(std::string name, int stunum);
	 void setRptr(Student* studentptr);
	 void setLptr(Student* studentptr);
	 Student* getRptr();
	 Student* getLptr();

	 std::string getname();
	 int getstunum();
};

class Grad_Student: public Student{
 private:
 protected:
	 std::string m_labname = "M_LAB_NAME";
 public:	
	 virtual void getInfo() override;
	 void setInfo(std::string name, int stunum, std::string labname);

	 std::string getlabname();
};

class Undergrad_Student: public Student{
 private:
 protected:
	 int m_freshmenclass = 0;
 public:
	 virtual void getInfo() override;
	 void setInfo(std::string name, int stunum, int freshmenclass);

	 int getfreshmenclass();
};


class Manager {
private:
	Student* RightMost_stuptr = NULL; //Head
	Student* LeftMost_stuptr = NULL; //Tail
	Student* printptr = NULL; //pointer for print_all() method
	int numberofstu = 0; //total number of student in list

protected:
public:
	int add_student(std::string name, int stunum, std::string labname);
	int add_student(std::string name, int stunum, int freshmenclass);
	bool compare_student(int index, std::string name, int stunum, std::string labname);
	bool compare_student(int index, std::string name, int stunum, int freshmenclass);
	int find_student(std::string name, int stunum, std::string labname);
	int find_student(std::string name, int stunum, int freshemenclass);
	int delete_student(std::string name, int stunum, std::string labname);
	int delete_student(std::string name, int stunum, int freshmenclass);
	int print_all();

	~Manager();//destructor to remove all data in list
};

bool operator == (const Student& x, const Student& y);