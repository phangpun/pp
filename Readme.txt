[EE205] Data Structures and Algorithms
Project 1 : Student Management System
2018.09.19 Wed
Made by HangHun Jo
student ID : 20110880

Sourse files : main.cpp student.cpp argument.cpp
Header files : student.h argument.h
etc files : Makefile Readme.txt

I implement Manager class with doubly linked list. Manager class gets LeftMost_stuptr and RightMost_stuptr.
RightMost means Head, while LeftMost means Tail. When add_student() method is called, student node is inserted to left direction.

First, I implement find_student() method using operator == overloading, then apply the method in add_student(), compare_student(), delete_student().

If find_student() is not zero, then add_student() has to be error case because already student is in list.

If find_student() is zero, it means that no student is matched with given student so comare_student() returns false.
If find_student() is not zero, find_student() returns index number at which given student is placed. Return value is true when given index and returned index are same.

In delete_student() implementation, if find_student() returns not zero, Student pointer is set to that index. I divide the case  by number of student in list.
If only one data is in list, I just remove that data, while if data number is more than 1, again, 3 cases can be happened. They are the cases Head, Tail, Middle.


I make argument class to handle argument error case.
In argument.cpp and argument.h, there are 4 classes(argument, argument_command, argument_grad, argument_format). 
The parent class is argument class and the others are derived from argument class.

In program, argument is put and check if it is valid and send its argument to variable in main function.
There is three cases to get command input. Those are when command is needed, when grad/undergrad parameter is needed and when 3 or 4 arguments are needed.
All argument pattern are same but print some print output is different for each stage. So I implement each method to show different print contents.