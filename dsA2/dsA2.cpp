#include "header.h"
#include "linkedList.h"
#include <iostream>
#include <fstream>


void newBuckets(linkedList** list);
void deleteBucketArray(linkedList** lists);

int main(void)
{
	linkedList* bucketList[TABLE_SIZE] = { new linkedList() };
	linkedList* longList = new linkedList();
	newBuckets(bucketList);
	std::string buffer = "";
	int bucketNumber = 0;
	int numberOfComparisons[2] = { 1, 2 };

	std::ifstream inFile;
	inFile.open("words.txt",std::ios::in);
	if (!inFile)
	{
		std::cerr << "Impossible to open file words.txt";
		return FAILURE;
	}

	while (inFile.peek() != EOF)
	{
		std::getline(inFile, buffer);
		bucketNumber = hash((char*)buffer.c_str()) % TABLE_SIZE;
		bucketList[bucketNumber]->CreateNode(buffer);
		longList->CreateNode(buffer);
	}


	while (buffer != ".")
	{
		printf("Please type the name you want to find: ");
		getInput(buffer);
		if (buffer != ".")
		{
		bucketNumber = hash((char*)buffer.c_str()) % TABLE_SIZE;
		longList->SearchForTwice(buffer, longList, bucketList, numberOfComparisons);
		}
	}



	inFile.close();
	deleteBucketArray(bucketList);
	delete longList;

	return SUCCESS;
}


void getInput(std::string& buffer)
{
	char temp[21] = { 0 };
	fgets(temp, STRING_SIZE, stdin);
	sscanf_s(temp, "%s", temp, STRING_SIZE);
	buffer = temp;
}

void newBuckets(linkedList** list)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		list[i] = new linkedList();
	}
}

void deleteBucketArray(linkedList** lists)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		delete lists[i];
	}
}