//============================================================================
// Name        : LinkedList_Project.cpp
// Author      : Edward
// Version     : 1.0.0
//		 		 --This version does not handle all types of user input error.
//		   		 (e.g. user enters '12%$-' when the desired input is an integer)
//		 		 --This version does not check integer overflow.
// Copyright   : N/A
// Description : A simple singly linked list application in C++, ANSI-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, char ** argv) {
	//Print out the application instructions
	std::cout << "MENU" << std::endl;
	std::cout << "1. Insert Data at a position" << std::endl;
	std::cout << "2. Delete data node " << std::endl;
	std::cout << "3. Print entire list" << std::endl;
	std::cout << "4. Search Data in the list" << std::endl;
	std::cout << "0. Exit the application" << std::endl;
	std::cout << std::endl;

	//Create a new linked list
	LinkedList linkedlist;

	while (1) {
		std::cout
				<< std::endl << "Please enter a number (0 ~ 4) to choose from one of the options." 
				<< std::endl << "Press <Enter> to confirm" << std::endl;
		int option;
		std::cin >> option;

		//I/O for inserting data at a position
		if (option == 1) {
			std::cout
					<< "Enter an integer (0 ~ 2,147,483,647) and the position (1 ~ "
					<< (linkedlist.getLength() + 1) << ")"
					<< ", separated by <SPACE>" << std::endl;
			int data;
			int position;
			//keep looping until a valid input is entered
			while (1) {
				std::cin >> data >> position;
				if (position > linkedlist.getLength() + 1) {
					std::cout << "Invalid position."
							<< "Please enter an integer (0 ~ 2,147,483,647) and position (1 ~ "
							<< (linkedlist.getLength() + 1) << ")"
							<< ", separated by <SPACE>" << std::endl;
				}
				//TODO: check integer overflow
				else
					break;
			}
			//insert data into $linkedlist
			if (linkedlist.insertNode(data, position))
				std::cout << "Heap overflow. You can't enter any more data"
						<< std::endl;
		}

		//I/O for deleting data node
		else if (option == 2) {
			std::cout << "Enter the data to delete." << std::endl;
			int data;
			std::cin >> data;
			//Empty list
			if (linkedlist.getLength() == 0)
				std::cout << "The linked list is empty." << std::endl;
			else {
				//Create a linked list $search_result to store the position(s) of apperance
				LinkedList search_result = linkedlist.searchData(data);

				if (search_result.getLength() == 0)
					std::cout << "This data is not in the linked list."
							<< std::endl;
				else {
					//Display the position(s) of appearance
					std::cout << "The number " << data
							<< " appears at position ";
					node * current = search_result.getHead();
					while (current != NULL) {
						std::cout << current->data << " ";
						current = current->next;
					}
					std::cout << "in the linked list" << std::endl;
					//TODO: optimize away -1 ending
					std::cout
							<< "Please enter the position(s) where you want to delete the data from "
							<< "and enter -1 to end. (e.g. x y z -1)"
							<< std::endl;

					//Create a linked list $positionsToRemove to store the position(s) to remove
					LinkedList positionsToRemove;
					int position;
					int p = 1;
					while (1) {
						std::cin >> position;
						if (position == -1)
							break;
						//error if the input position is invalid
						if (search_result.searchData(position).getLength()
								== 0) {
							std::cout << "Invalid position." << std::endl;
							break;
						} else
							positionsToRemove.insertNode(position, p++);
					}
					//delete the data that appears at $positionsToRemove from the $linkedlist
					linkedlist.deleteNode(positionsToRemove);
				}
			}
		}

		//I/O for printing entire list
		else if (option == 3) {
			linkedlist.printLinkedList();
		}

		//I/O for searching data in the list
		else if (option == 4) {
			std::cout << "Enter the data to search." << std::endl;
			int data;
			std::cin >> data;
			//Empty list
			if (linkedlist.getLength() == 0)
				std::cout << "The linked list is empty." << std::endl;
			else {
				//Create a linked list $search_result to store the position(s) of occurrence
				LinkedList search_result = linkedlist.searchData(data);

				if (search_result.getLength() == 0)
					std::cout << "This data is not in the linked list."
							<< std::endl;
				else {
					//Display the position(s) of appearance
					std::cout << "The number " << data
							<< " appears at position ";
					node * current = search_result.getHead();
					while (current != NULL) {
						std::cout << current->data << " ";
						current = current->next;
					}
					std::cout << "in the linked list" << std::endl;
				}
			}
		}

		//exit the program
		else if (option == 0) {
			exit(0);
		}

		//Invalid option
		else
			std::cout << "Not a valid option. You need to choose from 0-4."
					<< std::endl;
	}

	return 0;
}

