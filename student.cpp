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
	if (numberofstu >= 300) {
		std::cout << "add undergraduate student FAIL" << std::endl;
		std::cout << "There is no capacity. (Max number of student : 300)" << std::endl;
		return 0;
	}
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
	GS->setInfo(name, stunum, labname);
	numberofstu++;
	std::cout << "add graduate student DONE" << std::endl;
	return 0;
};

int Manager::add_student(std::string name, int stunum, int freshmenclass)
{
  // Creates Undergrad_Student object with given argument
  // Returns the total number of objects in the student array after adding
	if (numberofstu >= 300) {
		std::cout << "add undergraduate student FAIL" << std::endl;
		std::cout << "There is no capacity. (Max number of student : 300)" << std::endl;
		return 0;
	}

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
	UGS->setInfo(name, stunum, freshmenclass);
	numberofstu++;
	std::cout << "add undergraduate student DONE" << std::endl;
	return 0;
};

// You need to implement operator overloading and use it in compare_student

bool Manager::compare_student(int index, std::string name, int stunum, int freshmenclass)
{
  // Compares whether the object with given index argument in the student array is the same to Undergrad_Student object with given arguments followed by index.
  // Returns true if they are the same, false otherwise
	if (index > numberofstu) {
		std::cout << "false: index number is bigger than the number of students in data" << std::endl;
		std::cout << "compare to undergraduate student DONE" << std::endl;
		return false;
	}

	Student* Student_present = RightMost_stuptr;
	Student* Student_next = Student_present->getLptr();

	for (int i = 1; i < index; i++) {
		Student_present = Student_next;
		Student_next = Student_present->getLptr();
	}

	if (dynamic_cast<Undergrad_Student*>(Student_present) != NULL) {
		Undergrad_Student indexStudent = *(dynamic_cast<Undergrad_Student*>(Student_present));
		Undergrad_Student inputStudent;
		inputStudent.setInfo(name, stunum, freshmenclass);


		if (indexStudent == inputStudent) {
			if (indexStudent.getfreshmenclass() == inputStudent.getfreshmenclass()) {
				std::cout << "true: the same" << std::endl;
				std::cout << "compare to undergraduate student DONE" << std::endl;
				return true;
			}
		}
	}
	
	std::cout << "false: different" << std::endl;
	std::cout << "compare to undergraduate student DONE" << std::endl;
	return false;
};

bool Manager::compare_student(int index, std::string name, int stunum, std::string labname)
{
  // Compares whether the (index argument)th object in the student array is the same to Grad_Student object with given given argument follwed by index.
  // Returns true if they are the same, false otherwise
	if (index > numberofstu) {
		std::cout << "false: index number is bigger than the number of students in data" << std::endl;
		std::cout << "compare to undergraduate student DONE" << std::endl;
		return false;
	}

	Student* Student_present = RightMost_stuptr;
	Student* Student_next = Student_present->getLptr();

	for (int i = 1; i < index; i++) {
		Student_present = Student_next;
		Student_next = Student_present->getLptr();
	}

	if (dynamic_cast<Grad_Student*>(Student_present) != NULL) {
		Grad_Student indexStudent = *(dynamic_cast<Grad_Student*>(Student_present));
		Grad_Student inputStudent;
		inputStudent.setInfo(name, stunum, labname);


		if (indexStudent == inputStudent) {
			if (indexStudent.getlabname() == inputStudent.getlabname()) {
				std::cout << "true: the same" << std::endl;
				std::cout << "compare to graduate student DONE" << std::endl;
				return true;
			}
		}
	}

	std::cout << "false: different" << std::endl;
	std::cout << "compare to graduate student DONE" << std::endl;
	return false;
};

int Manager::find_student(std::string name, int stunum, std::string labname)
{
  // Finds the Grad_Student object in the student array which is the same to Grad_Student object with given argument
  // This method should print all the information about matched object
  // Returns index of matched object (index of first object = 1), 0 if there's no match
	Grad_Student indexstudent;
	Grad_Student target;
	target.setInfo(name, stunum, labname);
	for (int i = 0; i < numberofstu; i++) {
		if (indexstudent == target) {
			if (indexstudent.getlabname() == target.getlabname()) {
				std::cout << "Found matched one!" << std::endl << std::endl;
				indexstudent.getInfo();
				std::cout << std::endl << "find graduate student DONE" << std::endl;
				return true;
			}
		}
	}
	std::cout << "find graduate student DONE" << std::endl;
	return 0;
};

int Manager::find_student(std::string name, int stunum, int freshmenclass)
{
  // Finds the Undergrad_Student object in the student array which is the same to Undergrad_Student object with given argument
  // This method should prints all the information about matched object
  // Returns index of matched object (index of first object = 1), 0 if there's no match
	Undergrad_Student indexstudent;
	Undergrad_Student target;
	target.setInfo(name, stunum, freshmenclass);
	for (int i = 0; i < numberofstu; i++) {
		if (indexstudent == target) {
			if (indexstudent.getfreshmenclass() == target.getfreshmenclass()) {
				std::cout << "Found matched one!" << std::endl << std::endl;
				indexstudent.getInfo();
				std::cout << std::endl << "find undergraduate student DONE" << std::endl;
				return true;
			}
		}
	}
	std::cout << "find undergraduate student DONE" << std::endl;
	return 0;
};

int Manager::delete_student(std::string name, int stunum, std::string labname)
{
  // Deletes the Grad_Student object in the student array which is the same to Grad_Student object with given argument, does nothing if there's no matching
  // Returns the total number of objects in the student array after deleting
	Grad_Student indexstudent;
	Grad_Student target;
	target.setInfo(name, stunum, labname);

	Grad_Student* Gradptr;
	Undergrad_Student* Undergradptr;
	for (int i = 0; i < numberofstu; i++) {
		if (indexstudent == target) {
			if (indexstudent.getlabname() == target.getlabname()) {
				std::cout << "Deleting one data" << std::endl;

				if (numberofstu == 1) {
					RightMost_stuptr = NULL;
					LeftMost_stuptr = NULL;
				}
				else if (Gradptr == RightMost_stuptr) {
					RightMost_stuptr = (Gradptr->getLptr());
					(Gradptr->getLptr())->setRptr(NULL);
					

					while (i < (numberofstu - 1)) {
						Gradptr->setInfo(Gradptr->getname(),
							Gradptr->getstunum(),
							Gradptr->getlabname());

						Undergradptr->setInfo(Undergradptr->getname(),
							Undergradptr->getstunum(),
							Undergradptr->getfreshmenclass());
						
						i++;
					}
				}
				else if (Gradptr == LeftMost_stuptr) {
					LeftMost_stuptr = (Gradptr->getRptr());
					(Gradptr->getRptr())->setLptr(NULL);

					delete Gradptr;
				}
				else {
					(Gradptr->getLptr())->setRptr(Gradptr->getRptr());
					(Gradptr->getRptr())->setLptr(Gradptr->getLptr());

					delete Gradptr;

					while (i < (numberofstu - 1)) {
						Gradptr->setInfo(Gradptr->getname(),
							Gradptr->getstunum(),
							Gradptr->getlabname());

						Undergradptr->setInfo(Undergradptr->getname(),
							Undergradptr->getstunum(),
							Undergradptr->getfreshmenclass());

						i++;
					}

				}
				
				numberofstu--;
				std::cout << std::endl << "delete graduate student DONE" << std::endl;
				std::cout << numberofstu << " students are left" << std::endl;
				return numberofstu;
			}
		}
	}
	std::cout << "delete graduate student DONE" << std::endl;
	return 0;
};

int Manager::delete_student(std::string name, int stunum, int freshmenclass)
{
  // Deletes the Undergrad_Student object in the student array which is the same to Undergrad_Student object with given argument, does nothing if there's no matching
  // Returns the total number of objects in the student array after deleting
	Undergrad_Student indexstudent;
	Undergrad_Student target;
	target.setInfo(name, stunum, freshmenclass);

	Undergrad_Student* Undergradptr;
	Grad_Student* Gradptr;
	for (int i = 0; i < numberofstu; i++) {
		if (indexstudent == target) {
			if (indexstudent.getfreshmenclass() == target.getfreshmenclass()) {
				std::cout << "Deleting one data" << std::endl;

				if (numberofstu == 1) {
					RightMost_stuptr = NULL;
					LeftMost_stuptr = NULL;
				}
				else if (Undergradptr == RightMost_stuptr) {
					RightMost_stuptr = (Undergradptr->getLptr());
					(Undergradptr->getLptr())->setRptr(NULL);


					while (i < (numberofstu - 1)) {
						Undergradptr->setInfo(Undergradptr->getname(),
							Undergradptr->getstunum(),
							Undergradptr->getfreshmenclass());

						Gradptr->setInfo(Gradptr->getname(),
							Gradptr->getstunum(),
							Gradptr->getlabname());

						i++;
					}
				}
				else if (Undergradptr == LeftMost_stuptr) {
					LeftMost_stuptr = (Undergradptr->getRptr());
					(Undergradptr->getRptr())->setLptr(NULL);
					
					delete Undergradptr;
				}
				else {
					(Undergradptr->getLptr())->setRptr(Undergradptr->getRptr());
					(Undergradptr->getRptr())->setLptr(Undergradptr->getLptr());

					delete Undergradptr;

					while (i < (numberofstu - 1)) {
						Undergradptr->setInfo(Undergradptr->getname(),
							Undergradptr->getstunum(),
							Undergradptr->getfreshmenclass());

						Gradptr->setInfo(Gradptr->getname(),
							Gradptr->getstunum(),
							Gradptr->getlabname());

						i++;
					}

				}

				numberofstu--;
				std::cout << std::endl << "delete graduate student DONE" << std::endl;
				std::cout << numberofstu << " students are left" << std::endl;
				return numberofstu;
			}
		}
	}
	std::cout << "delete graduate student DONE" << std::endl;
	return 0;
};

int Manager::print_all()
{
  // Prints the all the information of existing object in the student array
  // Returns the total number of objects in the student array
	if (numberofstu != 0) {
		printptr = RightMost_stuptr;
		for (int i = 0; i < numberofstu; i++) {
			std::cout << "index : " << (i + 1) << std::endl;
			printptr->getInfo();
			std::cout << std::endl;
			printptr = printptr->getLptr();
		}
		std::cout << "print all DONE" << std::endl;
		std::cout << numberofstu<< " students are in lists" << std::endl;
		return numberofstu;
	}
	else {
		std::cout<<"empty data"<<std::endl;
	}
  std::cout << "print all DONE" << std::endl;
  return 0;
};

Manager::~Manager() {
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
	if (a.getname() != b.getname()) {
		return false;
	}
	if (a.getstunum() != b.getstunum()) {
		return false;
	}
  return true;
}




// // **********************************************
// // Class Student area
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
// // Class Grad_Student area
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
// // Class Undergrad_Student area
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