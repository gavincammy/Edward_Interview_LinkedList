/*
 * LinkedList.cpp
 *
 *  Created on: Nov 3, 2017
 *      Author: Edward
 */

#include <iostream>
#include "LinkedList.h"

/*
1. Create a linked list

This constructor will create a linked list

@param  void
@return void
*/
LinkedList::LinkedList() {
	head = NULL;
	length = 0;
}

/*
2. Insert data at a position

This function will insert $data at $position

@param  int  $positions stores the position(s) to remove
@return int  0 for success and 1 for failure
*/
int LinkedList::insertNode(int data, int position) {
	//check heap overflow
	//return 1 if 'new' fails
	node * temp;
	temp = new (std::nothrow) node;
	if (temp != NULL) {
		temp->data = data;
		temp->next = NULL;
	} else
		return 1;

	//if position is the head of the 'linkedlist'
	if (position == 1) {
		temp->next = head;
		head = temp;
		length++;
		return 0;
	}

	//if position is not the head of the 'linkedlist'
	node * current = head;
	for (int i = 0; i < position - 2; i++) {
		current = current->next;
	}
	temp->next = current->next;
	current->next = temp;
	length++; //increment the length of the 'linkedlist'
	return 0;
}

/*
3. Delete the data

This function will delete the data that appears at $positions
from $this linked list

@param const LinkedList & $positions stores the position(s) to remove
@return void
*/
void LinkedList::deleteNode(const LinkedList & positions) {
	//create a dummy head before the head of $this linked list
	//this is used for deleting the first number
	node dummy_head_node;
	node * dummy_head = &dummy_head_node;
	dummy_head->data = 0;
	dummy_head->next = head;

	node * list_current = head;
	node * list_previous = dummy_head;
	node * positions_current = positions.head;
	int previous_position = 0;

	while (positions_current != NULL) {
		//traverse in $this linked list to the next position to be deleted
		for (int i = previous_position; i < positions_current->data - 1; i++) {
			list_current = list_current->next;
			list_previous = list_previous->next;
		}
		//delete the node and update all the pointers
		node* temp = list_previous->next;
		list_previous->next = list_current->next;
		previous_position = positions_current->data;
		positions_current = positions_current->next;
		list_current = list_current->next;
		delete temp;
	}
	head = dummy_head->next;
}

/*
4. Print entire list

This function will print the entire list

@param  void
@return void
*/
void LinkedList::printLinkedList() {
	if (head == NULL) {
		std::cout << "The linked list is empty." << std::endl;
		return;
	}

	std::cout << "The linked list is ";
	node * current = head;
	while (current != NULL) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

/*
5. Search data in $this list

This function will search $data in $this list

@param  int          $data   the data to be searched
@return LinkedList 	 returns an object of LinkedList that stores the position(s) where $data appears
*/
LinkedList LinkedList::searchData(int data) {
	LinkedList temp_list;
	node * current = head;
	int position = 0;
	int p = 1; //used for reversing the list to output an ascending list
	while (current != NULL) {
		if (current->data == data) {
			temp_list.insertNode(position + 1, p++);
		}
		current = current->next;
		position++;
	}
	return temp_list;
}

/*
6. Destroy a linked list

This destructor will destroy a linked list

@param  void
@return void
*/
LinkedList::~LinkedList() {
	node* current = head;
	while (current != NULL) {
		node* temp = current;
		current = current->next;
		delete temp;
	}
}

//Get head member from $this linked list
node * LinkedList::getHead() {
	return head;
}

//Get the number of nodes from $this linked list
int LinkedList::getLength() {
	return length;
}
