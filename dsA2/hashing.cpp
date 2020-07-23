// The djb2 was created by Dan Bernstein
// Copied from Hash Tables lecture in the Data Structures Course - Conestoga College
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