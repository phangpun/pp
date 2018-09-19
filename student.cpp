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

	//to avoid same student addition
	if (find_student(name, stunum, labname)) {
		std::cout << "add graduate student FAIL" << std::endl;
		std::cout << "The student is already in list" << std::endl;
		return numberofstu;
	}

	//to avoid overload to list (maximum 300)
	if (numberofstu >= 300) {
		std::cout << "add graduate student FAIL" << std::endl;
		std::cout << "There is no capacity. (Max number of student : 300)" << std::endl;
		return numberofstu;
	}

	//allocation for new grad student
	Grad_Student* GS = new Grad_Student;
	if (numberofstu == 0) {
		//pointer setting for first data
		RightMost_stuptr = GS;
		LeftMost_stuptr = GS;
		GS->setRptr(NULL);
		GS->setLptr(NULL);
	}
	else {
		//pointer setting
		GS->setRptr(LeftMost_stuptr);
		LeftMost_stuptr->setLptr(GS);
		LeftMost_stuptr = GS;
		GS->setLptr(NULL);
	}

	//data setting
	GS->setInfo(name, stunum, labname);

	//total number setting
	numberofstu++;

	return numberofstu;
};

int Manager::add_student(std::string name, int stunum, int freshmenclass)
{
	// Creates Undergrad_Student object with given argument
	// Returns the total number of objects in the student array after adding

	//to avoid same student addition
	if (find_student(name, stunum, freshmenclass)) {
		std::cout << "add undergraduate student FAIL" << std::endl;
		std::cout << "The student is already in list" << std::endl;
		return numberofstu;
	}
	
	//to avoid overload to list (maximum 300)
	if (numberofstu >= 300) {
		std::cout << "add undergraduate student FAIL" << std::endl;
		std::cout << "There is no capacity. (Max number of student : 300)" << std::endl;
		return numberofstu;
	}

	//allocation for new undergrad student
	Undergrad_Student* UGS = new Undergrad_Student;
	if (numberofstu == 0) {
		//pointer setting for first data
		RightMost_stuptr = UGS;
		LeftMost_stuptr = UGS;
		UGS->setRptr(NULL);
		UGS->setLptr(NULL);
	}
	else {
		//pointer setting
		UGS->setRptr(LeftMost_stuptr);
		LeftMost_stuptr->setLptr(UGS);
		LeftMost_stuptr = UGS;
		UGS->setLptr(NULL);
	}
	
	//data setting
	UGS->setInfo(name, stunum, freshmenclass);

	//total number setting
	numberofstu++;
	
	
	return numberofstu;
};

// You need to implement operator overloading and use it in compare_student

bool Manager::compare_student(int index, std::string name, int stunum, int freshmenclass)
{
  // Compares whether the object with given index argument in the student array is the same to Undergrad_Student object with given arguments followed by index.
  // Returns true if they are the same, false otherwise
	
	//error handling for wrong index
	if (index > numberofstu) {
		std::cout << "Warning: index number is bigger than the number of students in list" << std::endl;
		return false;
	}

	//find same student in list
	if (find_student(name, stunum, freshmenclass) != 0) {
		//compare index
		if (index == find_student(name, stunum, freshmenclass)) {
			return true;
		}
	}
	return false;
};

bool Manager::compare_student(int index, std::string name, int stunum, std::string labname)
{
  // Compares whether the (index argument)th object in the student array is the same to Grad_Student object with given given argument follwed by index.
  // Returns true if they are the same, false otherwise
  
    //error handling for wrong index
	if (index > numberofstu) {
		std::cout << "Warning: index number is bigger than the number of students in list" << std::endl;
		return false;
	}

	//find same student in list
	if (find_student(name, stunum, labname) != 0) {
		//compare index
		if (index == find_student(name, stunum, labname)) {
			return true;
		}
	}
	return false;
};

int Manager::find_student(std::string name, int stunum, std::string labname)
{
  // Finds the Grad_Student object in the student array which is the same to Grad_Student object with given argument
  // This method should print all the information about matched object
  // Returns index of matched object (index of first object = 1), 0 if there's no match
	
    //for empty list
	if (numberofstu == 0) {
		return 0;
	}

	//pointer set, start from RightMost(Head)
	Student* Student_present = RightMost_stuptr;
	Student* Student_next = Student_present->getLptr();

	//set grad_student with given argument 
	Grad_Student inputStudent;
	inputStudent.setInfo(name, stunum, labname);

	//scan for all data in list
	for (int i = 0; i < numberofstu; i++) {
		
		if (*Student_present == inputStudent) {//operator overloading(check name, stunum)
			if ((dynamic_cast<Grad_Student*>(Student_present)) != NULL) {//if it is grad_student
				if ((dynamic_cast<Grad_Student*>(Student_present))->getlabname() ==
					inputStudent.getlabname()) {
					return (i + 1);//return index
				}
			}
		}
		
		//pointer shift to next(left) student
		Student_present = Student_next;
		if (Student_present != NULL) {//error handling when present is tail
			Student_next = Student_present->getLptr();
		}
	}
	return 0;
};

int Manager::find_student(std::string name, int stunum, int freshmenclass)
{
  // Finds the Undergrad_Student object in the student array which is the same to Undergrad_Student object with given argument
  // This method should prints all the information about matched object
  // Returns index of matched object (index of first object = 1), 0 if there's no match
    //for empty list
	if (numberofstu == 0) {
		return 0;
	}

	//pointer set, start from RightMost(Head)
	Student* Student_present = RightMost_stuptr;
	Student* Student_next = Student_present->getLptr();

	//set grad_student with given argument 
	Undergrad_Student inputStudent;
	inputStudent.setInfo (name, stunum, freshmenclass);

	//scan for all data in list
	for (int i = 0; i < numberofstu; i++) {

		if (*Student_present == inputStudent) {//operator overloading(check name, stunum)
			if ((dynamic_cast<Undergrad_Student*>(Student_present)) != NULL) {//if it is grad_student
				if ((dynamic_cast<Undergrad_Student*>(Student_present))->getfreshmenclass() ==
					inputStudent.getfreshmenclass()) {
					return (i + 1);//return index
				}
			}
		}

		//pointer shift to next(left) student
		Student_present = Student_next;
		if (Student_present != NULL) {//error handling when present is tail
			Student_next = Student_present->getLptr();
		}
	}
	return 0;
};

int Manager::delete_student(std::string name, int stunum, std::string labname)
{
  // Deletes the Grad_Student object in the student array which is the same to Grad_Student object with given argument, does nothing if there's no matching
  // Returns the total number of objects in the student array after deleting
	
    //finding student first
	if (find_student(name, stunum, labname) != 0) {

		//pointer setting
		Student* Student_present = RightMost_stuptr;
		Student* Student_next = Student_present->getLptr();

		//pointer shift to position of index
		for (int i = 0; i < find_student(name, stunum, labname) - 1; i++) {
			Student_present = Student_next;
			Student_next = Student_present->getLptr();
		}
		
		//case : one data in list 
		if (numberofstu == 1) {
			delete Student_present;
			return --numberofstu;
		}
		//case : multi data in list
		else {
			//doubly linked list pointer setting
			if (Student_present->getRptr() == NULL) {//present pointer pose to head
				RightMost_stuptr = Student_present->getLptr();
				(Student_present->getLptr())->setRptr(NULL);
				delete Student_present;
			}
			else if (Student_present->getLptr() == NULL) {//present pointer pose to tail
				LeftMost_stuptr = Student_present->getRptr();
				(Student_present->getRptr())->setLptr(NULL);
				delete Student_present;
			}
			else {//present pointer pose to middle
				(Student_present->getLptr())->setRptr(Student_present->getRptr());
				(Student_present->getRptr())->setLptr(Student_present->getLptr());
				delete Student_present;
			}
			// return left number
			return --numberofstu;
		}
	}
	
	return numberofstu;
};

int Manager::delete_student(std::string name, int stunum, int freshmenclass)
{
  // Deletes the Undergrad_Student object in the student array which is the same to Undergrad_Student object with given argument, does nothing if there's no matching
  // Returns the total number of objects in the student array after deleting
	
    //finding student first
	if (find_student(name, stunum, freshmenclass) != 0) {

		//pointer setting
		Student* Student_present = RightMost_stuptr;
		Student* Student_next = Student_present->getLptr();

		//pointer shift to position of index
		for (int i = 0; i < find_student(name, stunum, freshmenclass) - 1; i++) {
			Student_present = Student_next;
			Student_next = Student_present->getLptr();
		}

		//case : one data in list 
		if (numberofstu == 1) {
			delete Student_present;
			return --numberofstu;
		}
		//case : multi data in list
		else {
			//doubly linked list pointer setting
			if (Student_present->getRptr() == NULL) {//present pointer pose to head
				RightMost_stuptr = Student_present->getLptr();
				(Student_present->getLptr())->setRptr(NULL);
				delete Student_present;
			}
			else if (Student_present->getLptr() == NULL) {//present pointer pose to tail
				LeftMost_stuptr = Student_present->getRptr();
				(Student_present->getRptr())->setLptr(NULL);
				delete Student_present;
			}
			else {//present pointer pose to middle
				(Student_present->getLptr())->setRptr(Student_present->getRptr());
				(Student_present->getRptr())->setLptr(Student_present->getLptr());
				delete Student_present;
			}
			// return left number
			return --numberofstu;
		}
	}
	return numberofstu;
};

int Manager::print_all()
{
  // Prints the all the information of existing object in the student array
  // Returns the total number of objects in the student array

	if (numberofstu != 0) {//when list is not empty
		printptr = RightMost_stuptr;
		for (int i = 0; i < numberofstu; i++) {
			std::cout << "index : " << (i + 1) << std::endl;
			printptr->getInfo();
			std::cout << std::endl;
			printptr = printptr->getLptr();
		}
		std::cout << "print all DONE" << std::endl;
		std::cout << "left number : " << numberofstu << std::endl;
		return numberofstu;
	}
	else {//when list empty
		std::cout<<"empty data"<<std::endl;
	}
  std::cout << "print all DONE" << std::endl;
  return 0;
};

Manager::~Manager() {
	//clear all memory in list
	Student* student_present = LeftMost_stuptr;
	for (int i = 0; i < numberofstu; i++) {
		Student* student_next = student_present->getRptr();
		delete student_present;
		student_present = student_next;
	}
}

bool operator == (const Student& x, const Student& y)
{
  // operating overloading part. 
  // Check whether two students x, y have same information or not. 
  // Return true if two students are same, false otherwise.
  // p.s. this function must be used in at least "find_student ()" and "compare_student ()"
	Student a = x;
	Student b = y;

	//name check
	if (a.getname() != b.getname()) {
		return false;
	}
	//studnet number check
	if (a.getstunum() != b.getstunum()) {
		return false;
	}
  return true;
}




// // **********************************************
// // Class Student methods
// // **********************************************

void Student::getInfo() {
	std::cout << "name : " << m_name << std::endl;
	std::cout << "student number : " << m_stunum << std::endl;
}

void Student::setInfo(std::string name, int stunum) {
	m_name = name;
	m_stunum = stunum;
}

void Student::setRptr(Student* studentptr) {
	m_Rightptr = studentptr;
}

void Student::setLptr(Student* studentptr) {
	m_Leftptr = studentptr;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
Student* Student::getRptr() {
	return m_Rightptr;
}

Student* Student::getLptr() {
	return m_Leftptr;
}

std::string Student::getname() {
	return m_name;
}

int Student::getstunum() {
	return m_stunum;
}

// // **********************************************
// // Class Grad_Student methods
// // **********************************************

void Grad_Student::getInfo() {
	std::cout << "name : " << m_name << std::endl;
	std::cout << "student number : " << m_stunum << std::endl;
	std::cout << "labname : " << m_labname << std::endl;
}

void Grad_Student::setInfo(std::string name, int stunum, std::string labname) {
	m_name = name;
	m_stunum = stunum;
	m_labname = labname;
}

std::string Grad_Student::getlabname() {
	return m_labname;
}

// // **********************************************
// // Class Undergrad_Student methods
// // **********************************************

void Undergrad_Student::getInfo() {
	std::cout << "name : " << m_name << std::endl;
	std::cout << "student number : " << m_stunum << std::endl;
	std::cout << "freshmenclass : " << m_freshmenclass << std::endl;
}

void Undergrad_Student::setInfo(std::string name, int stunum, int freshmenclass){
	m_name = name;
	m_stunum = stunum;
	m_freshmenclass = freshmenclass;
}

int Undergrad_Student::getfreshmenclass() {
	return m_freshmenclass;
}