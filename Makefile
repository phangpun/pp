program : main.o student.o argument.o
	g++ -o program main.o student.o argument.o

main.o : main.cpp
	g++ -o main.o -c main.cpp

student.o : student.cpp student.h
	g++ -o student.o -c student.cpp student.h

argument.o : argument.cpp argument.h
	g++ -o argument.o -c argument.cpp argument.h
