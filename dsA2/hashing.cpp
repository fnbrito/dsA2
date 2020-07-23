/*
 *  FILE			: hashing.cpp
 *  PROJECT			: SENG1050 - Assignment #2
 *  PROGRAMMER		: Dan Bernstein
 *  FIRST VERSION	: 2020-07-18
 *	DESCRIPTION		:
 *      Function to calculate the hash value from the hash key (str).
 *      The djb2 was created by Dan Bernstein
 *      Copied from Hash Tables lecture in the Data Structures Course - Conestoga College
 */


unsigned long hash(char* str)
{
	unsigned long hash = 5381;
	int	c = 0;
	while ((c = *str++) != '\0')
	{
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}