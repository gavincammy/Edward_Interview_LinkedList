#include "gtest/gtest.h"
#include "LinkedList.h"

/*
LinkedList(); //1. Create a linked list
int insertNode(int data, int position); ////2. Insert data at a position
void deleteNode(const LinkedList & positions); //3. Delete data node
void printLinkedList(); //4. Print entire list
LinkedList searchData(int data); //5. Search Data in the linked list
~LinkedList(); //6. Destroy a linked List

node * getHead(); //Get head member from a linked list
int getLength(); //Get the number of nodes from a linked list
*/

namespace {
  TEST(LinkedListTest, NewObject) {
    LinkedList *list = new LinkedList();
    ASSERT_TRUE(list != NULL);
    delete list;
  }

  TEST(LinkedListTest, DeleteNotExist) {
    LinkedList *list = new LinkedList();
    LinkedList noteToDelete;
    list->deleteNode(noteToDelete);
    ASSERT_EQ(list->getLength(), 0);
    delete list;
  }

  TEST(LinkedListTest, Search) {
    LinkedList *list = new LinkedList();
    list->insertNode(5, 1);

    LinkedList result = list->searchData(5);
    result.printLinkedList();
    delete list;
  }

  TEST(LinkedListTest, InsertAndDeleteTest) {
    LinkedList *list = new LinkedList();
    list->insertNode(1,1);
    list->insertNode(2,2);
    ASSERT_EQ(list->getLength(),2);
    list->printLinkedList();
    list->deleteNode(list->searchData(1));
    list->printLinkedList();
    ASSERT_EQ(list->getLength(),1);
    delete list;
  }

  TEST(LinkedListTest, InsertMiddle) {
    LinkedList *list = new LinkedList();
    list->insertNode(1,1);
    list->insertNode(2,2);
    list->insertNode(3,2);
    list->printLinkedList();
    delete list;
  }

  TEST(LinkedListTest, InsertRandomly) {
    LinkedList *list = new LinkedList();
    list->insertNode(1,5);
    delete list;
  }
}
