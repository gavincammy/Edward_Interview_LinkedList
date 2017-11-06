/*
 * LinkedList.h
 *
 *  Created on: Nov 3, 2017
 *      Author: Edward
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//define a node structure
struct node {
	int data;
	node * next;
};

//LinkedList class definition
class LinkedList {
private:
	node* head;
	int length; //number of nodes in the linked list

public:
	LinkedList(); //1. Create a linked list
	int insertNode(int data, int position); ////2. Insert data at a position
	void deleteNode(const LinkedList & positions); //3. Delete data node
	void printLinkedList(); //4. Print entire list
	LinkedList searchData(int data); //5. Search Data in the linked list
	~LinkedList(); //6. Destroy a linked List

	node * getHead(); //Get head member from a linked list
	int getLength(); //Get the number of nodes from a linked list
};

#endif /* LINKEDLIST_H_ */
