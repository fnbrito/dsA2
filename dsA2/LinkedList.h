/*
 *  FILE          : LinkedList.h
 *  PROJECT       : SENG1050 - Assignment #2
 *  PROGRAMMER    : Filipe Brito
 *  FIRST VERSION : 2020-07-18
 */
/*
 *	NAME    :	LinkedList
 *	PURPOSE :	The class Linked List is made to be the starting point to a singly-linked linked list.
 *				Its only data member is a pointer to a struct WordNode called head. It contains the prototypes
 *              functions that manage and relate a linked list, these are (but not limited to) insertion,
 *              printing and searching.
 */
#pragma once
#include "header.h"

// Class declaration
class LinkedList
{
private:
	
	WordNode* head;     // This will store the pointer to the first element of the linked list.


public:
	
	LinkedList(void); // Default constructor: initializes head to NULL.
	~LinkedList(void); // Default destructor.
	int CreateNode(std::string word); // Function to created an alphabetically sorted linked list.
	WordNode* SearchLinkedList(std::string searchWord, int* comparisonCount); // Function to search a singly-linked list, returning a pointer to the element found.
	void SearchForTwice(std::string searchWord, LinkedList* longList, LinkedList* hashTable[], int comparisonCount[2]); // Calls the SearchLinkedList and searches a hashtable, displaying compared results.
    void Display(void); // Displays the contents of the linked list one item per line.
};