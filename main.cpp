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

	std::cout << "What do you want to do?\n1. Add student:a\n2. Compare student:c \n3. Find student:f\n4. Delete student:d\n5. Change student:c\n6. Print all student:p\n7. Quit:q" << std::endl;

	// ******Modify here****** 
	//You need to handle wrong argument format
	while (inputcommand.isWrong(FIRST_INPUT)) {
		std::getline(std::cin, inputstring);
		inputcommand.set(inputstring);
		std::cout << "<<< Error : You type too long argument >>>" << std::endl << std::endl;
		std::cout << "What do you want to do?\n1. Add student:a\n2. Compare student:c \n3. Find student:f\n4. Delete student:d\n5. Change student:c\n6. Print all student:p\n7. Quit:q" << std::endl;
	}
	
	command = inputcommand.firstchar();

	switch(command){
	  
	  case 'a':{
		// Type of student you want to add (Graduate student or Undergraduate student)
		std::cout << "Add student executed\n\nType\nUndergraduate:0 Graduate:1"<< std::endl;
		
		// ******Modify here****** 
		//You need to handle wrong argument format

		while (isLast) {
		  std::cin >> isgrad;
		  if (isgrad == 1){
		    std::cout << "\nFormat: [name stunum labname]" << std::endl;
		  
		    // ******Modify here****** 
		    //You need to handle wrong argument format
		    std::cin >> name >> stunum >> labname;
		    myman.add_student(name, stunum, labname);
			isLast = false;
		  }

		  else if (isgrad == 0){
		    std::cout << "\nFormat: [name stunum freshmenclass] " << std::endl;
		  
		    // ******Modify here****** 
		    //You need to handle wrong argument format
		    std::cin >> name >> stunum >> freshmenclass;
		    myman.add_student(name, stunum, freshmenclass);		  
			isLast = false;
		  }
		  
		  else{
		    std::cout << "\n(Error : You type the wrong number)" << std::endl;
		    std::cout << "Type\nUndergraduate:0 Graduat:1" << std::endl;
		  }
		}

		isLast = true; // initialize pending condition.
		
	  }break;

	  case 'c':{
		std::cout << "Compare student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		
		// ******Modify here****** 
		//You need to handle wrong argument format
		while (isLast){
		  std::cin >> isgrad;
		  if (isgrad == 1){
		    std::cout << "\nTarget student\nFormat: [index name stunum labname]" << std::endl;
		  
		    // ******Modify here****** 
		    //You need to handle wrong argument format
		    std::cin >> index >> name >> stunum >> labname;
		    myman.compare_student(index, name, stunum, labname);
		  }
		  
		  else if (isgrad == 0){
		    std::cout << "\nTarget student\nFormat: [index name stunum freshmenclass] " << std::endl;
		    std::cin >> index >> name >> stunum >> freshmenclass;
		    myman.compare_student(index, name, stunum, freshmenclass);
		  }

		  else{
		    std::cout << "\n(Error : You type the wrong number)" << std::endl;
		    std::cout << "Type\nUndergraduated:0 Graduated:1" << std::endl;
		  }
		}

		isLast = true; // initialize pending condition.
	  }break;

	  case 'f':{
		std::cout << "Find student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;
		
		// ******Modify here****** 
		//You need to handle wrong argument format
		while (isLast){
		  std::cin >> isgrad;
		  
		  if (isgrad == 1){
		    std::cout << "\nFormat: [name stunum labname]" << std::endl;
		    
		    // ******Modify here****** 
		    //You need to handle wrong argument format
		    std::cin >> name >> stunum >> labname;
		    myman.find_student(name, stunum, labname);
		  }
		  else if (isgrad == 0){
		    std::cout << "\nFormat: [name stunum freshmenclass]" << std::endl;
		    
		    // ******Modify here****** 
		    //You need to handle wrong argument format
		    std::cin >> name >> stunum >> freshmenclass;
		    myman.find_student(name, stunum, freshmenclass);
		  }

		  else{
		    std::cout << "\n(Error : You type the wrong number)" << std::endl;
		    std::cout << "Type\nUndergraduated:0 Graduated:1" << std::endl;
		  }
		}

		isLast = true; //initialize pending condition.
	  }break;


	  case 'd':{
		std::cout << "Delete student executed\n\nType\nUndergraduate:0 Graduate:1" << std::endl;

		// ******Modify here****** 
		//You need to handle wrong argument format
		while (isLast) {
			std::cin >> isgrad;

			if (isgrad == 1){
			  std::cout << "\nFormat: [name stunum labname]" << std::endl;
		  
			  // ******Modify here****** 
			  //You need to handle wrong argument format
			  std::cin >> name >> stunum >> labname;
			  myman.find_student(name, stunum, labname);
			}
			else if (isgrad == 0){
			  std::cout << "\nFormat: [name stunum freshmenclass]" << std::endl;
		  
			  // ******Modify here****** 
			  //You need to handle wrong argument format
			  std::cin >> name >> stunum >> freshmenclass;
			  myman.find_student(name, stunum, freshmenclass);
			}
			else {
				std::cout << "\n(Error : You type the wrong number)" << std::endl;
				std::cout << "Type\nUndergraduated:0 Graduated:1" << std::endl;
			}
		}
	  }break;

	  case 'p':{
		std::cout << "Print all executed" << std::endl;
		myman.print_all();
	  }break;

	  case 'q':{
	  std::cout << "Quit" << std::endl;
	  isLast = false;
	  }break;

	  default:{
		std::cout << "Invalid argument" << std::endl;
	  }break;
	}
	
  }
  return 0;
}

