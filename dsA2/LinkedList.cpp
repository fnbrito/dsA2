/*
 *  FILE            : LinkedList.cpp
 *  PROJECT         : SENG1050 - Assignment #2
 *  PROGRAMMER      : Filipe Brito
 *  FIRST VERSION   : 2020-07-18
 *  DESCRIPTION     :
 *		This file contains the methods for the
 *		class LinkedList. These methods were tailored to
 *      apply logic that is required of a linked list.
 *      Insertion is done in the same function that creates the node.
 *      Nodes are organized in an alphabetically ordered manner.
 */

#include "LinkedList.h"

    //
    //  FUNCTION    :   LinkedList (constructor)
    //  DESCRIPTION :   Creates and initializes an object of class
    //                  LinkedList using with a NULL value for the head.
    //  PARAMETERS  :   void
    //  RETURNS     :   void      
    //
LinkedList::LinkedList(void)
{
    head = NULL; // initializes the WordNode* head
}


    //
    //  FUNCTION    :   ~LinkedList (destructor)
    //  DESCRIPTION :   Eliminates an object of class LinkedList.
    //  PARAMETERS  :   void
    //  RETURNS     :   void      
    //
LinkedList::~LinkedList(void)
{

}


//
//  FUNCTION    :   CreateNode
//  DESCRIPTION :   Creates and initializes a struct WordNode inside the
//                  and inserts it alphabetically in the linked-list.
//  PARAMETERS  :   word    :   std::string - Word to be put inside object->word.
//  RETURNS     :   int     : 0 (SUCCESS) - Success
//                          : -1 (FAILURE)- Failure
//
int LinkedList::CreateNode(std::string word)
{
    WordNode* temp = new WordNode;
        temp->word = word;
        temp->next = NULL;
    WordNode* current = head;
    WordNode* backup = head;

    if (head == NULL) // first exception, empty list
    {
        head = temp;
        temp = NULL;
        return FAILURE;
    }
    else if (head->next == NULL) // second exception, one-item list
    {
        if (head->word.compare(word) <= 0) // if it comes after
        {
            head->next = temp; //sets to after
            return SUCCESS;
        }
        else // if it comes before
        {
            temp->next = head;  // assigns current head to next...
            head = temp;        // and replaces the head with new node.
            return SUCCESS;
        }
    }

    if (head->word.compare(word) >= 0) //third exception, new node comes before the head
    {
        temp->next = head;
        head = temp;
        return SUCCESS;
    }

    // after the exceptions we only have a normal list

    while (current->next != NULL) //go until the end of the list
    {
        backup = current;           // keeps a backup of the current node each loop
        current = current->next;    // advances to the next node

        if (current->word.compare(word) >= 0) // when the new word comes later than current word
        {
            backup->next = temp;    // assigns it in between the two nodes
            temp->next = current;
            return 0;
        }
    }

    //end of the list reached, assign new node to the end
    current->next = temp;
    return 0;
}



//
//  FUNCTION    :   SearchLinkedList
//  DESCRIPTION :   Searches inside the object in search of a match while also keeping
//                  a count of how many comparisons were made.
//  PARAMETERS  :   word    :   std::string - Word to be searched for.
//                  int*    :   comparisonCount - pointer to an int to store the count of comparison
//  RETURNS     :   WordNode*:  Pointer to the node where the match was found.
//
WordNode* LinkedList::SearchLinkedList(std::string searchWord, int* comparisonCount)
{
    *comparisonCount = 0;
    WordNode* current = this->head;
    if (this->head != NULL)
    {
        while (current != NULL)
        {
            *comparisonCount = *comparisonCount + 1;
            
            if (current->word < searchWord)
            {
                current = current->next;
                continue;
            }
            else if (current->word == searchWord)
            {
                return current;
            }
            else if (current->word > searchWord)
            {
                return NULL;
            }
        }
    }
    return NULL;
}


//
//  FUNCTION    :   SearchForTwice
//  DESCRIPTION :   Calls the SearchLinkedList function, prints the result then does its own searching
//                  into a hashtable and prints the results.
//  PARAMETERS  :   word    :   std::string - Word to be searched for.
//                  LinkedList*:longList    - Pointer an object to be searched with SearchLinkedList.
//                  LinkedList*:hashTable[] - Pointer to an array of LinkedList objects to be searched with this function.
//                  int*    :   comparisonCount - array of ints to store the count of comparison from both searches.
//  RETURNS     :   void
//
void LinkedList::SearchForTwice(std::string searchWord, LinkedList* longList, LinkedList* hashTable[], int comparisonCount[2])
{
    unsigned int hashNumber = hash((char*)searchWord.c_str()) % TABLE_SIZE;
    WordNode* current = NULL;


    current = longList->SearchLinkedList(searchWord, comparisonCount);
    if (current != NULL)
    {
        printf("\t%s was found in the linked list in %d comparisons\n", searchWord.c_str(), *comparisonCount);
    }
    else
    {
        printf("\t%s was NOT found in the linked list in %d comparisons\n", searchWord.c_str(), *comparisonCount);

    }

    current = hashTable[hashNumber]->head;
    comparisonCount++;
    *comparisonCount = 0;
    if (current != NULL)
    {
        while (current != NULL)
        {
            *comparisonCount = *comparisonCount + 1;

            if (current->word < searchWord)
            {
                if (current->next == NULL)
                {
                    printf("\t%s was NOT found in the hash table bucket in %d comparisons\n", searchWord.c_str(), *comparisonCount);
                    break;
                }
                current = current->next;
                continue;
            }
            else if (current->word == searchWord)
            {
                printf("\t%s was found in the hash table bucket in %d comparisons\n", searchWord.c_str(), *comparisonCount);
                break;
            }
            else if (current->word > searchWord)
            {
                printf("\t%s was NOT found in the hash table bucket in %d comparisons\n", searchWord.c_str(), *comparisonCount);
                break;
            }
        }

    }
}


//
//  FUNCTION    :   Display
//  DESCRIPTION :   Prints the contents of the linked-list object, one word per line.
//  PARAMETERS  :   void
//  RETURNS     :   void
//
void LinkedList::Display(void)
{
    WordNode* temp;
    temp = head;
    while (temp->next != NULL)
    {
        printf("%s\n", temp->word.c_str());
        temp = temp->next;
    }
    if (temp != NULL)
        printf("%s\n", temp->word.c_str());
}