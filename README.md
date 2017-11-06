A sigly linked list application

version 1.0.0
--This version does not handle all types of user input error.(e.g. user enters '12%$-' when the desired input is an integer)
--This version does not check integer overflow.

### test framework
[https://github.com/google/googletest](https://github.com/google/googletest)

### install google test framework
1. git clone https://github.com/google/googletest.git
2. cmake .
3. make && make install

### Run test
1. Compile `LinkedList_unittest.cc` and `test_main.cc` using `make gtest`
2. run gtest `./gtest`

all test cases are in LinkedList_unittest
