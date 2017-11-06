CC=g++

CFLAGS=-c -Wall

CXXFLAGS += -g -Wall -Wextra -pthread

all: LinkedList_Project

LinkedList_Project:   LinkedList_Project.o LinkedList.o
		      $(CC) LinkedList_Project.o LinkedList.o -o LinkedList_Project

LinkedList_Project.o: LinkedList_Project.cpp
		      $(CC) $(CFLAGS) LinkedList_Project.cpp

LinkedList.o: 	      LinkedList.cpp
		      $(CC) $(CFLAGS) LinkedList.cpp

GTEST_DIR = ./test
UNITTEST_SRC = $(GTEST_DIR)/LinkedList_unittest.cc 
TEST_MAIN_SRC = $(GTEST_DIR)/test_main.cc
CPPFLAGS = -I./ 

LinkedList_unittest.o : $(UNITTEST_SRC) LinkedList.h
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $(UNITTEST_SRC)

test_main.o: $(TEST_MAIN_SRC)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_MAIN_SRC)

gtest: LinkedList_unittest.o LinkedList.o test_main.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread -lgtest $^ -o $@

clean:
		      rm -rf *o LinkedList_Project
