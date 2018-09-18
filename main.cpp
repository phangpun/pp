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

  argument_command arg_command;
  argument_grad arg_grad;
  argument_format arg_format;
  


  while(isLast){
	std::cout << "\n\n\n*---------------------Welcome to Student Management System---------------------*" << std::endl;
	command = arg_command.input_handling();

	switch(command){
	  
	  case 'a':{
		// Type of student you want to add (Graduate student or Undergraduate student)
		  isgrad = arg_grad.input_handling(ADD);
		
		if (isgrad == 1){
			arg_format.input_handling(ADD, isgrad, &index, &name, &stunum, &labname);
			myman.add_student(name, stunum, labname);
		}

		else if (isgrad == 0){
			arg_format.input_handling(ADD, isgrad, &index, &name, &stunum, &freshmenclass);
			myman.add_student(name, stunum, freshmenclass);		  
		}
		
	  }break;

	  case 'c':{
		  isgrad = arg_grad.input_handling(COMPARE);
		
		if (isgrad == 1){
			arg_format.input_handling(COMPARE, isgrad, &index, &name, &stunum, &labname);
			if (myman.compare_student(index, name, stunum, labname)) {
				std::cout << "true: the same" << std::endl;
			}
			else {
				std::cout << "false: different" << std::endl;
			}
			std::cout << "compare to graduate student DONE" << std::endl;
		}
		  
		else if (isgrad == 0){
			arg_format.input_handling(COMPARE, isgrad, &index, &name, &stunum, &freshmenclass);
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
		  isgrad = arg_grad.input_handling(FIND);

		if (isgrad == 1){
			arg_format.input_handling(FIND, isgrad, &index, &name, &stunum, &labname);
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
			arg_format.input_handling(FIND, isgrad, &index, &name, &stunum, &freshmenclass);
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
		  isgrad = arg_grad.input_handling(DELETE);
		  if (isgrad == 1) {
			  arg_format.input_handling(DELETE, isgrad, &index, &name, &stunum, &labname);
			std::cout << "left number : " << myman.delete_student(name, stunum, labname) << std::endl;
			std::cout << "delete graduate student DONE" << std::endl;
		}
		else if (isgrad == 0){
			arg_format.input_handling(DELETE, isgrad, &index, &name, &stunum, &freshmenclass);
			std::cout << "left number : " << myman.delete_student(name, stunum, freshmenclass) << std::endl;
			std::cout << "delete graduate student DONE" << std::endl;
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

