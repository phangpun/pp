#include <iostream>
#include <stdexcept>
#include <string>
#include "student.h"
#include "argument.h"



// //****************************************************************
// //                   MAIN FUNCTION IN PROJECT
// //****************************************************************

int main()
{
  char command;
  Manager myman;
  int isgrad;
  std::string name;
  int stunum;
  std::string labname;
  int freshmenclass;
  int index;
  bool isLast=true;

  std::string inputstring;
  argument inputcommand;


  while(isLast){
	std::cout << "\n\n\n*---------------------Welcome to Student Management System---------------------*" << std::endl;
	std::cout << "What do you want to do?\n1. Add student:a\n2. Compare student:c \n3. Find student:f\n4. Delete student:d\n5. Print all student:p\n6. Quit:q" << std::endl;

	// ******Modify here****** 
	//You need to handle wrong argument format
	while (inputcommand.isWrong(FIRST_INPUT)) {
		std::getline(std::cin, inputstring);
		inputcommand.set(inputstring);
		if (inputcommand.isWrong(FIRST_INPUT)) {
			std::cout << "Invalid argument" << std::endl << std::endl;
			std::cout << "What do you want to do?\n1. Add student:a\n2. Compare student:c \n3. Find student:f\n4. Delete student:d\n5. Print all student:p\n6. Quit:q" << std::endl;
		}
		else break;
	}
	
	command = inputcommand.firstchar();

	switch(command){
	  
	  case 'a':{
		// Type of student you want to add (Graduate student or Undergraduate student)
		std::cout << "Add student executed\n\nType\nUndergraduate:0 Graduate:1"<< std::endl;
		
		// ******Modify here****** 
		//You need to handle wrong argument format

		while (inputcommand.isWrong(GRAD)) {
			std::getline(std::cin, inputstring);
			inputcommand.set(inputstring);
			if (inputcommand.isWrong(GRAD)) {
				std::cout << "Invalid argument" << std::endl << std::endl;
				std::cout << "Type\nUndergraduate:0 Graduat:1" << std::endl;
			}
		}
		isgrad = std::stoi(inputcommand.get());
		
		if (isgrad == 1){
			std::cout << "\nFormat: [name stunum labname]" << std::endl;
		  
			// ******Modify here****** 
			//You need to handle wrong argument format

			while (inputcommand.isWrong(ADD_INPUT, isgrad)) {
				std::getline(std::cin, inputstring);
				inputcommand.set(inputstring);
				if (inputcommand.isWrong(ADD_INPUT, isgrad)) {
					std::cout << "Invalid argument" << std::endl << std::endl;
					std::cout << "Format: [name stunum labname]" << std::endl;
				}
				else break;
			}

			inputcommand.get_to(&name, &stunum, &labname);
			myman.add_student(name, stunum, labname);
		}

		else if (isgrad == 0){
			std::cout << "\nFormat: [name stunum freshmenclass] " << std::endl;
		  
			// ******Modify here****** 
			//You need to handle wrong argument format

			while (inputcommand.isWrong(ADD_INPUT, isgrad)) {
				std::getline(std::cin, inputstring);
				inputcommand.set(inputstring);
				if (inputcommand.isWrong(ADD_INPUT, isgrad)) {
					std::cout << "Invalid argument" << std::endl << std::endl;
					std::cout << "Format: [name stunum freshmenclass]" << std::endl;
				}
				else break;
			}

			inputcommand.get_to(&name, &stunum, &freshmenclass);
			myman.add_student(name, stunum, freshmenclass);		  
		}
		
	  }break;

	  case 'c':{
		std::cout << "Compare student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		
		// ******Modify here****** 
		//You need to handle wrong argument format

		while (inputcommand.isWrong(GRAD)) {
			std::getline(std::cin, inputstring);
			inputcommand.set(inputstring);
			if (inputcommand.isWrong(GRAD)) {
				std::cout << "Invalid argument" << std::endl << std::endl;
				std::cout << "Type\nUndergraduate:0 Graduat:1" << std::endl;
			}
			else break;
		}
		isgrad = std::stoi(inputcommand.get());

		if (isgrad == 1){
			std::cout << "\nTarget student\nFormat: [index name stunum labname]" << std::endl;
		  
			// ******Modify here****** 
			//You need to handle wrong argument format
			while (inputcommand.isWrong(COMPARE_INPUT, isgrad)) {
				std::getline(std::cin, inputstring);
				inputcommand.set(inputstring);
				if (inputcommand.isWrong(COMPARE_INPUT, isgrad)) {
					std::cout << "Invalid argument" << std::endl << std::endl;
					std::cout << "Format: [index name stunum labname]" << std::endl;
				}
				else break;
			}

			inputcommand.get_to(&index, &name, &stunum, &labname);
			if (myman.compare_student(index, name, stunum, labname)) {
				std::cout << "true: the same" << std::endl;
			}
			else {
				std::cout << "false: different" << std::endl;
			}
			std::cout << "compare to graduate student DONE" << std::endl;
		}
		  
		else if (isgrad == 0){
			std::cout << "\nTarget student\nFormat: [index name stunum freshmenclass] " << std::endl;


			while (inputcommand.isWrong(COMPARE_INPUT, isgrad)) {
				std::getline(std::cin, inputstring);
				inputcommand.set(inputstring);
				if (inputcommand.isWrong(COMPARE_INPUT, isgrad)) {
					std::cout << "Invalid argument" << std::endl << std::endl;
					std::cout << "Format: [index name stunum freshmenclass]" << std::endl;
				}
				else break;
			}

			
			inputcommand.get_to(&index, &name, &stunum, &freshmenclass);
			if (myman.compare_student(index, name, stunum, freshmenclass)) {
				std::cout << "true: the same" << std::endl;
			}
			else {
				std::cout << "false: different" << std::endl;
			}
			std::cout << "compare to undergraduate student DONE" << std::endl;
		}


	  }break;

	  case 'f':{
		std::cout << "Find student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		
		// ******Modify here****** 
		//You need to handle wrong argument format
		while (inputcommand.isWrong(GRAD)) {
			std::getline(std::cin, inputstring);
			inputcommand.set(inputstring);
			if (inputcommand.isWrong(GRAD)) {
				std::cout << "Invalid argument" << std::endl << std::endl;
				std::cout << "Type\nUndergraduate:0 Graduat:1" << std::endl;
			}
			else break;
		}
		isgrad = std::stoi(inputcommand.get());

		  
		if (isgrad == 1){
			std::cout << "\nFormat: [name stunum labname]" << std::endl;
		    
			// ******Modify here****** 
			//You need to handle wrong argument format
			while (inputcommand.isWrong(FIND_INPUT, isgrad)) {
				std::getline(std::cin, inputstring);
				inputcommand.set(inputstring);
				if (inputcommand.isWrong(FIND_INPUT, isgrad)) {
					std::cout << "Invalid argument" << std::endl << std::endl;
					std::cout << "Format: [name stunum labname]" << std::endl;
				}
				else break;
			}

			inputcommand.get_to(&name, &stunum, &labname);
			if (myman.find_student(name, stunum, labname) != 0) {
				std::cout << "Found matched one" << std::endl;
				std::cout << "index : " << (myman.find_student(name, stunum, labname)) << std::endl;
			}
			else {
				std::cout << "There is no matched one in list" << std::endl;
			}
			std::cout << "find graduate student DONE" << std::endl;
		}
		else if (isgrad == 0){
			std::cout << "\nFormat: [name stunum freshmenclass]" << std::endl;
		    
			// ******Modify here****** 
			//You need to handle wrong argument format
			while (inputcommand.isWrong(FIND_INPUT, isgrad)) {
				std::getline(std::cin, inputstring);
				inputcommand.set(inputstring);
				if (inputcommand.isWrong(FIND_INPUT, isgrad)) {
					std::cout << "Invalid argument" << std::endl << std::endl;
					std::cout << "Format: [name stunum freshmenclass]" << std::endl;
				}
				else break;
			}

			inputcommand.get_to(&name, &stunum, &freshmenclass);
			if (myman.find_student(name, stunum, freshmenclass) != 0) {
				std::cout << "Found matched one" << std::endl;
				std::cout << "index : " << (myman.find_student(name, stunum, freshmenclass)) << std::endl;
			}
			else {
				std::cout << "There is no matched one in list" << std::endl;
			}
			std::cout << "find graduate student DONE" << std::endl;
		}
		
	  }break;


	  case 'd':{
		std::cout << "Delete student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;

		// ******Modify here****** 
		//You need to handle wrong argument format
		while (inputcommand.isWrong(GRAD)) {
			std::getline(std::cin, inputstring);
			inputcommand.set(inputstring);
			if (inputcommand.isWrong(GRAD)) {
				std::cout << "Invalid argument" << std::endl << std::endl;
				std::cout << "Type\nUndergraduate:0 Graduat:1" << std::endl;
			}
		}
		isgrad = std::stoi(inputcommand.get());

		if (isgrad == 1){
			std::cout << "\nFormat: [name stunum labname]" << std::endl;
		  
			// ******Modify here****** 
			//You need to handle wrong argument format
			while (inputcommand.isWrong(DELETE_INPUT, isgrad)) {
				std::getline(std::cin, inputstring);
				inputcommand.set(inputstring);
				if (inputcommand.isWrong(DELETE_INPUT, isgrad)) {
					std::cout << "Invalid argument" << std::endl << std::endl;
					std::cout << "Format: [name stunum labname]" << std::endl;
				}
				else break;
			}

			inputcommand.get_to(&name, &stunum, &labname);
			std::cout << "left number : " << myman.delete_student(name, stunum, labname) << std::endl;
			std::cout << "delete graduate student DONE" << std::endl;
		}
		else if (isgrad == 0){
			std::cout << "\nFormat: [name stunum freshmenclass]" << std::endl;
		  
			// ******Modify here****** 
			//You need to handle wrong argument format
			while (inputcommand.isWrong(DELETE_INPUT, isgrad)) {
				std::getline(std::cin, inputstring);
				inputcommand.set(inputstring);
				if (inputcommand.isWrong(DELETE_INPUT, isgrad)) {
					std::cout << "Invalid argument" << std::endl << std::endl;
					std::cout << "Format: [name stunum freshmenclass]" << std::endl;
				}
				else break;
			}

			inputcommand.get_to(&name, &stunum, &freshmenclass);
			std::cout << "left number : " << myman.delete_student(name, stunum, freshmenclass) << std::endl;
			std::cout << "delete graduate student DONE" << std::endl;
		}

	  }break;

	  case 'p':{
		std::cout << "Print all executed" << std::endl;
		myman.print_all();
		inputcommand.set("ARGUMENT_STRING");
	  }break;

	  case 'q':{
	  std::cout << "Quit" << std::endl;
	  isLast = false;
	  }break;

	  default:{
		  std::cout << "Invalid argument" << std::endl;
		  inputcommand.set("ARGUMENT_STRING");
	  }break;
	}
	
  }
  return 0;
}

