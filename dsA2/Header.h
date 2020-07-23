/*
 *  FILE            : Header.h
 *  PROJECT         : SENG1050 - Assignment #2
 *  PROGRAMMER      : Filipe Brito
 *  FIRST VERSION   : 2020-07-18
 */
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>


#define TABLE_SIZE 127
#define STRING_SIZE 20
#define SUCCESS 0;
#define FAILURE -1;


typedef struct WordNode
{
	std::string word;
	struct WordNode* next;
} WordNode;


unsigned long hash(char* str);  // Hashing function