// //***************************************************************
// //                   CLASS USED IN PROJECT
// //****************************************************************

class Manager{
	// ******Modify here******
	// You need to properly define member variable in Manager class
 private:
	 Student * RightMost_stuptr = NULL;
	 Student * LeftMost_stuptr = NULL;
	 int numberofstu = 0;
 protected:
 public:
	// ******Modify here******
	// You need to implement every methods in Manager class
	int add_student(std::string name, int stunum, std::string labname);
	int add_student(std::string name, int stunum, int freshmenclass);
	bool compare_student(int index, std::string name, int stunum, std::string labname);
	bool compare_student(int index, std::string name, int stunum, int freshmenclass);
	int find_student(std::string name, int stunum, std::string labname);
	int find_student(std::string name, int stunum, int freshemenclass);
	int delete_student(std::string name, int stunum, std::string labname);
	int delete_student(std::string name, int stunum, int freshmenclass);
	int print_all();

};

class Student{
	// ******Modify here******
	// You need to properly define member variable in Student class
 private:
 protected:
	 std::string m_name;
	 int m_stunum;
	 int m_index;

	 Student *m_Right;
	 Student *m_Left;
 public:
	// ******Modify here******
	// You need to implement get function which prints out every information about student argument in pure virtual function here
	 void getInfo();
	 void setInfo(std::string name, int stunum);
	 void setRptr(Student * studentptr);
	 void setLptr(Student * studentptr);
	 Student* getRptr(Student * studentptr);
	 Student* getLptr(Student * studentptr);

};

class Grad_Student: public Student{
	// ******Modify here******
	// You need to properly define member variable in Grad_Student class
 private:
 protected:
	 std::string m_labname;
 public:	
	// ******Modify here******
	// You need to implement get function in detail
	 void getInfo();
	 void setInfo(std::string name, int stunum, std::string labname);
};

class Undergrad_Student: public Student{
	// ******Modify here******
	// You need to properly define member variable in Undergrad_Student class
 private:
 protected:
	 int m_freshmenclass;
 public:
	// ******Modify here******
	// You need to implement get function in detail
	 void getInfo();
	 void setInfo(std::string name, int stunum, int freshmenclass);
};
