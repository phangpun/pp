#include <iostream>
#include <string>
// //***************************************************************
// //                   CLASS USED IN PROJECT
// //****************************************************************

class Student{
	// ******Modify here******
	// You need to properly define member variable in Student class
 private:
 protected:
	 int m_index = 0;
	 int m_stunum = 0;
	 std::string m_name = "M_NAME";

	 Student* m_Rightptr;
	 Student* m_Leftptr;
 public:
	// ******Modify here******
	// You need to implement get function which prints out every information about student argument in pure virtual function here


	 virtual void getInfo();
	 virtual void setInfo(int index, std::string name, int stunum);
	 void setRptr(Student* studentptr);
	 void setLptr(Student* studentptr);
	 Student* getRptr();
	 Student* getLptr();

	 int getindex();
	 std::string getname();
	 int getstunum();

};

class Grad_Student: public Student{
	// ******Modify here******
	// You need to properly define member variable in Grad_Student class
 private:
 protected:
	 std::string m_labname = "M_LAB_NAME";
 public:	
	// ******Modify here******
	// You need to implement get function in detail

	 void getInfo();
	 void setInfo(int index, std::string name, int stunum, std::string labname);

	 std::string getlabname();
};

class Undergrad_Student: public Student{
	// ******Modify here******
	// You need to properly define member variable in Undergrad_Student class
 private:
 protected:
	 int m_freshmenclass = 1;
 public:
	// ******Modify here******
	// You need to implement get function in detail
	 void getInfo();
	 void setInfo(int index, std::string name, int stunum, int freshmenclass);

	 int getfreshmenclass();
};


class Manager {
	// ******Modify here******
	// You need to properly define member variable in Manager class
private:
	Student* RightMost_stuptr = NULL;
	Student* LeftMost_stuptr = NULL;
	Student* printptr = NULL;
	int numberofstu = 0;

	Grad_Student** Grad_indexArray = new Grad_Student*[300];
	Undergrad_Student** Undergrad_indexArray = new Undergrad_Student*[300];
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

	~Manager();
};

bool operator == (const Student& x, const Student& y);
