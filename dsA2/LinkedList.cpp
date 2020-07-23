#include "linkedList.h"

linkedList::linkedList(void)
{
    head = NULL; // initializes the WordNode* head
}

linkedList::~linkedList(void)
{

}

int linkedList::CreateNode(std::string word)
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
        return 0;
    }
    else if (head->next == NULL) // second exception, one-item list
    {
        if (head->word.compare(word) <= 0) // if it comes after
        {
            head->next = temp; //sets to after
            return 0;
        }
        else // if it comes before
        {
            temp->next = head;  // assigns current head to next...
            head = temp;        // and replaces the head with new node.
            return 0;
        }
    }

    if (head->word.compare(word) >= 0) //third exception, new node comes before the head
    {
        temp->next = head;
        head = temp;
        return 0;
    }

    // normal list

    while (current->next != NULL) //go until the end of the list
    {
        backup = current;
        current = current->next;

        if (current->word.compare(word) >= 0)
        {
            backup->next = temp;
            temp->next = current;
            return 0;
        }
    }

    //end of the list reached, assign new node to the end
    current->next = temp;
    return 0;
}

WordNode* linkedList::SearchLinkedList(std::string searchWord, int* comparisonCount)
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

void linkedList::SearchForTwice(std::string searchWord, linkedList* longList, linkedList* hashTable[], int comparisonCount[2])
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


void linkedList::Display(void)
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