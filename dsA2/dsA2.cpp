/*
 *  FILE            : dsA2.cpp
 *  PROJECT         : SENG1050 - Assignment #2
 *  PROGRAMMER      : Filipe Brito
 *  FIRST VERSION   : 2020-07-18
 *  DESCRIPTION     :
 *		This program demonstrates the difference in number of
 *		comparisons between searching in a long singly-linked
 *		list versus a hash table list.
 */
#include "header.h"
#include "LinkedList.h"
#include <fstream>

void getInput(std::string& buffer);
void newBuckets(LinkedList** list);
void deleteBucketArray(LinkedList** lists);

int main(void)
{
	// Initialization of variables
	LinkedList* bucketList[TABLE_SIZE] = { new LinkedList() };
	newBuckets(bucketList);		// calls newBuckets to initialize the array of objects LinkedList
	LinkedList* longList = new LinkedList();  // creates the object that stores the long list.
	std::string buffer = "";
	int bucketNumber = 0;	// int to store the hash calculation
	int numberOfComparisons[2] = { 1, 2 };

	std::ifstream inFile;
	inFile.open("words.txt",std::ios::in);		// tries to open the words.txt file
	if (!inFile)		// checks if file opened successfully
	{
		printf("Impossible to open file words.txt");
		return FAILURE;
	}

	while (inFile.peek() != EOF)			// as long as End-of-file was not reached
	{
		std::getline(inFile, buffer);									// gets word from words.txt
		bucketNumber = hash((char*)buffer.c_str()) % TABLE_SIZE;		// calculates the hash value
		longList->CreateNode(buffer);									// inserts in the single long list
		bucketList[bucketNumber]->CreateNode(buffer);					// inserts in the hash table

	}


	while (buffer != ".")
	{
		printf("Please type the name you want to find: ");
		getInput(buffer);
		if (buffer != ".")
		{
		longList->SearchForTwice(buffer, longList, bucketList, numberOfComparisons);		// searches in the long list and in the hashing table
		}
	}



	inFile.close();						//closes the file
	deleteBucketArray(bucketList);		//deallocates
	delete longList;					//deallocates

	return SUCCESS;
}


void getInput(std::string& buffer)
{
	char temp[21] = { 0 };
	fgets(temp, STRING_SIZE, stdin);
	sscanf_s(temp, "%s", temp, STRING_SIZE);
	buffer = temp;
}

void newBuckets(LinkedList** list)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		list[i] = new LinkedList();
	}
}

void deleteBucketArray(LinkedList** lists)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		delete lists[i];
	}
}