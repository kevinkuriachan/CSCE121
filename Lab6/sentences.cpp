#include <iostream>
#include <fstream>
using namespace std; 

#define MAX_LINE_LEN 200

char endPunctuation[3] = {'.', '?', '!'};

int getLenChars(char str[])
{ // returns number of characters in a string 
	int i = 0;
	int len = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}

bool charInArray(char c, char list[])
{
	int len = getLenChars(list);
	for (int i = 0; i < len; i++)
	{
		if (c == list[i]) return true;
	}
	return false;
}

int main()
{
	int length = 0;
	ifstream file("sentences.txt");	// creates a file 'file' and loads "sentences.txt" into it for reading.
	if (!file) 
	{
		cerr << "There was a problem opening the file." << endl;
		return 1;
	}
	char line[MAX_LINE_LEN];

	int numOfChars = 0;

	while (file.good())
	{ // loop until end of file 
		char line[MAX_LINE_LEN];
		char character = file.get();
		while (!charInArray(character, endPunctuation))
		{// loop until end of sentence
			character = file.get();
			line[numOfChars] = character;
			numOfChars++;
		}
		for (int i = 0; i < numOfChars; i++)
		{
			cout << line[i];
		}
		cout << endl;
	}
	//cout << "there are " << numOfChars << " character(s) in this file." << endl;
	return 0;
}