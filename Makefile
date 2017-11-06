CC=g++

CFLAGS=-c -Wall

all: LinkedList_Project

LinkedList_Project:   LinkedList_Project.o LinkedList.o
		      $(CC) LinkedList_Project.o LinkedList.o -o LinkedList_Project

LinkedList_Project.o: LinkedList_Project.cpp
		      $(CC) $(CFLAGS) LinkedList_Project.cpp

LinkedList.o: 	      LinkedList.cpp
		      $(CC) $(CFLAGS) LinkedList.cpp

clean:
		      rm -rf *o LinkedList_Project
