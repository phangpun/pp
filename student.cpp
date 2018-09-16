#include <iostream>
#include <string>
#include "student.h"

// //****************************************************************
// //                   REQUIRED FUNCTIONALITY IN PROJECT
// //****************************************************************

// 1. You need to implement every detail of the function defined below
// 2. You additionally need to implement getInfo methods in each classes.
// 3. You additionally need to implement 'operator overloading' with '==' which compares two students whether all the members are the same



int Manager::add_student(std::string name, int stunum, std::string labname)
{
  // Adds Grad_Student object with given argument
  // Returns the total number of objects in the student array after adding
	Grad_Student* GS = new Grad_Student;
	if (numberofstu == 0) {
		RightMost_stuptr = GS;
		LeftMost_stuptr = GS;
		GS->setRptr(NULL);
		GS->setLptr(NULL);
	}
	else {
		GS->setRptr(LeftMost_stuptr);
		LeftMost_stuptr->setLptr(GS);
		LeftMost_stuptr = GS;
		GS->setLptr(NULL);
	}
	indexArray[numberofstu] = GS;
	GS->setInfo(++numberofstu, name, stunum, labname);
  std::cout << "add graduate student DONE" << std::endl;
  return 0;
};

int Manager::add_student(std::string name, int stunum, int freshmenclass)
{
  // Creates Undergrad_Student object with given argument
  // Returns the total number of objects in the student array after adding
	Undergrad_Student* UGS = new Undergrad_Student;
	if (numberofstu == 0) {
		RightMost_stuptr = UGS;
		LeftMost_stuptr = UGS;
		UGS->setRptr(NULL);
		UGS->setLptr(NULL);
	}
	else {
		UGS->setRptr(LeftMost_stuptr);
		LeftMost_stuptr->setLptr(UGS);
		LeftMost_stuptr = UGS;
		UGS->setLptr(NULL);
	}
	indexArray[numberofstu] = UGS;
	UGS->setInfo(++numberofstu, name, stunum, freshmenclass);
  std::cout << "add undergraduate student DONE" << std::endl;
  return 0;
};

// You need to implement operator overloading and use it in compare_student

bool Manager::compare_student(int index, std::string name, int stunum, int freshmenclass)
{
  // Compares whether the object with given index argument in the student array is the same to Undergrad_Student object with given arguments followed by index.
  // Returns true if they are the same, false otherwise
	Student indexstudent = *indexArray[index - 1];
	Student target;
	target.setInfo(index, name, stunum);
	if (indexstudent == target) {
		std::cout << "true: the same" << std::endl;
		std::cout << "compare to undergraduate student DONE" << std::endl;
		return true;
	}

	std::cout << "false: different" << std::endl;
	std::cout << "compare to undergraduate student DONE" << std::endl;
	return false;


};

bool Manager::compare_student(int index, std::string name, int stunum, std::string labname)
{
  // Compares whether the (index argument)th object in the student array is the same to Grad_Student object with given given argument follwed by index.
  // Returns true if they are the same, false otherwise
  std::cout << "compare to graduate student DONE" << std::endl;
  return true;
};

int Manager::find_student(std::string name, int stunum, std::string labname)
{
  // Finds the Grad_Student object in the student array which is the same to Grad_Student object with given argument
  // This method should print all the information about matched object
  // Returns index of matched object (index of first object = 1), 0 if there's no match
  std::cout << "find graduate student DONE" << std::endl;
  return true;
};

int Manager::find_student(std::string name, int stunum, int freshmenclass)
{
  // Finds the Undergrad_Student object in the student array which is the same to Undergrad_Student object with given argument
  // This method should prints all the information about matched object
  // Returns index of matched object (index of first object = 1), 0 if there's no match
  std::cout << "find undergraduate student DONE" << std::endl;
  return 0;
};

int Manager::delete_student(std::string name, int stunum, std::string labname)
{
  // Deletes the Grad_Student object in the student array which is the same to Grad_Student object with given argument, does nothing if there's no matching
  // Returns the total number of objects in the student array after deleting
  std::cout << "delete graduate student DONE" << std::endl;
  return 0;
};

int Manager::delete_student(std::string name, int stunum, int freshmenclass)
{
  // Deletes the Undergrad_Student object in the student array which is the same to Undergrad_Student object with given argument, does nothing if there's no matching
  // Returns the total number of objects in the student array after deleting
  std::cout << "delete undergraduate student DONE" << std::endl;
  return 0;
};

int Manager::print_all()
{
  // Prints the all the information of existing object in the student array
  // Returns the total number of objects in the student array
	if (numberofstu != 0) {
		printptr = RightMost_stuptr;
		for (int i = 0; i < numberofstu; i++) {
			printptr->getInfo();
			std::cout << std::endl;
			printptr = printptr->getLptr(printptr);
		}
	}
	else {
		std::cout<<"empty data"<<std::endl;
	}
  std::cout << "print all DONE" << std::endl;
  return 0;
};

bool operator == (const Student& x, const Student& y)
{
  // operating overloading part. 
  // Check whether two students x, y have same information or not. 
  // Return true if two students are same, false otherwise.
  // p.s. this function must be used in at least "find_student ()" and "compare_student ()"
	if (x.m_name != y.m_name) {
		if (x.m_stunum != y.m_stunum) {
			return false;
		}
	}
  return true;
}




// // **********************************************
// // Class Student area
// // **********************************************

void Student::getInfo() {
	std::cout << "index : " << m_index << std::endl;
	std::cout << "name : " << m_name << std::endl;
	std::cout << "student number : " << m_stunum << std::endl;
}

void Student::setInfo(int index, std::string name, int stunum) {
	m_index = index;
	m_name = name;
	m_stunum = stunum;
}

void Student::setRptr(Student* studentptr) {
	m_Rightptr = studentptr;
}

void Student::setLptr(Student* studentptr) {
	m_Leftptr = studentptr;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
Student* Student::getRptr(Student* studentptr) {
	return studentptr->m_Rightptr;
}

Student* Student::getLptr(Student* studentptr) {
	return studentptr->m_Leftptr;
}

std::string Student::getname() {
	return m_name;
}

int Student::getstunum() {
	return m_stunum;
}

// // **********************************************
// // Class Grad_Student area
// // **********************************************

void Grad_Student::getInfo() {
	std::cout << "index : " << m_index << std::endl;
	std::cout << "name : " << m_name << std::endl;
	std::cout << "student number : " << m_stunum << std::endl;
	std::cout << "labname : " << m_labname << std::endl;
}

void Grad_Student::setInfo(int index, std::string name, int stunum, std::string labname) {
	m_index = index;
	m_name = name;
	m_stunum = stunum;
	m_labname = labname;
}

std::string Grad_Student::getlabname() {
	return m_labname;
}

// // **********************************************
// // Class Undergrad_Student area
// // **********************************************

void Undergrad_Student::getInfo() {
	std::cout << "index : " << m_index << std::endl;
	std::cout << "name : " << m_name << std::endl;
	std::cout << "student number : " << m_stunum << std::endl;
	std::cout << "freshmenclass : " << m_freshmenclass << std::endl;
}

void Undergrad_Student::setInfo(int index, std::string name, int stunum, int freshmenclass){
	m_index = index;
	m_name = name;
	m_stunum = stunum;
	m_freshmenclass = freshmenclass;
}

int Undergrad_Student::getfreshmenclass() {
	return m_freshmenclass;
}