#pragma once
#include "header.h"

class linkedList
{
private:
	
	WordNode* head;


public:
	
	linkedList(void);
	~linkedList(void);
	int CreateNode(std::string word);
	void Display(void);
	WordNode* SearchLinkedList(std::string searchWord, int* comparisonCount);
	void SearchForTwice(std::string searchWord, linkedList* longList, linkedList* hashTable[], int comparisonCount[2]);
};