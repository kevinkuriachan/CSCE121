#include <iostream>
#include <fstream>
using namespace std;

#define MAXLINE 100

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

void toUpper(char input[])
{
	int length = getLenChars(input);
	for (int i = 0; i < length; i++)
	{
		if ((input[i] >= 'a') && (input[i] <= 'z'))
		{// if the character is lowercase 
			input[i] -= 32; // maker uppercase
		}
	}
}

bool isLetter(char c)
{
	return((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

void countChars(char inputLine[], int len, int counts[], int &totalLetters)
{
	for (int i = 0; i < len; i++)
	{
		if (isLetter(inputLine[i]) )
		{
			totalLetters++;
			counts[int(inputLine[i]) - 65]++;
		}
	}
}

void printCounts(int counts[])
{
	for (int i = 0; i < 26; i++)
	{
		cout << char(i+65) << " : " << counts[i] << endl;
	}
}

void findFrequencies(int counts[], int totalLetters, float frequencies[])
{
	for (int i = 0; i < 26; i++)
	{
		if (counts[i] > 0)
		{
			frequencies[i] = (0.0+counts[i])/(0.0+totalLetters);
		}
		
	}
}

void printFrequencies(float frequencies[])
{
	for (int i = 0; i < 26; i++)
	{
		cout << char(i+65) << " : " << frequencies[i] << endl;
	}
}

void printAllData(int counts[],float frequencies[],int totalLetters)
{
	cout << "Total letter count: " << totalLetters << endl;
	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << char(i+65) << ": count: " << counts[i] << " frequencies: " << frequencies[i] << endl;
	}
}


int main()
{
	ifstream file; 
	file.open("input.txt", ios_base::in);
	if (!file)
	{
		cout << "error reading file" << endl;
		return 2;
	}
	int counts[26] = {0}; // counts[0] is count of A; [25] for Z
	int totalLetters = 0;
	float frequencies[26] = {0.0};
	char inputLine[MAXLINE];
	while (file.getline(inputLine, MAXLINE)) //while able to get lines from file 
	{
		toUpper(inputLine);
		int len = getLenChars(inputLine);
		countChars(inputLine, len, counts, totalLetters);
	}
	findFrequencies(counts, totalLetters, frequencies);
	printAllData(counts, frequencies, totalLetters);
	file.close();

	return 0; 
}