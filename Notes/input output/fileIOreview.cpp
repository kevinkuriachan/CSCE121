#include <fstream> // allows us to use file input and output;
#include <iostream>
using namespace std;

#define MAX 200

// what defines a word: A-Z, a-z, 0-9, &,',-

bool validChar(char c)
{
	if ( ('A' <= c) && (c <= 'Z') ) return true;
	if ( ('a' <= c) && ('z' >= c) ) return true; 
	if ( '\'' == c) return true; // have to use \ before a ' since '' is used to define chars 
	// + conditions for the other characters 

	return false;
}

void revSingleWord(char s[], int startIndex, int endIndex)
{
	cout << "inside reverse single word" << endl;
	for ( int i = 0; i < (endIndex-startIndex)/2; i++)
	{
		// swap s[f+i] and s[l-i] 
		char hold = s[startIndex+i];
		s[startIndex+i] = s[endIndex-i];
		s[endIndex-i] = hold;
	}
}

void revSingleWordRecurusive(char s[], int startIndex, int endIndex)
{
	if (startIndex >= endIndex) return;
	char hold = s[startIndex];
	s[startIndex] = s[endIndex];
	s[endIndex] = hold; 
	revSingleWordRecurusive(s, startIndex+1, endIndex-1);
}

void revWords(char s[]) // assume null terminated 
{

	int i = 0; 

	while (s[i] != '\0')
	{
		cout << "inside line 44" << endl;
		int startIndex = i;
		// gobble leading whitespace (non valid chars) 
		while (!validChar(s[startIndex]) && s[startIndex] != '\0')
		{
			startIndex++;
			cout << "inside line 49"  << endl;	
		} 
		cout << "line 55" << endl;
		if (s[startIndex] == '\0') return; 
		// now startIndex is at the beginning of a word

		i = startIndex;
		int j = i;
		// i will be at beginning, j will be at end;

		while(validChar(s[i])) j++; 
		revSingleWord(s, i, j-1);
		i = j; 
	}
}

int main()
{
	char inputLine[MAX];

	ifstream ifs; // creates an input object
	ofstream ofs; // creates output object

	ifs.open("input.txt", ios_base::in); // opens the file 
	if(!ifs)
	{
		cout << "failed to open" << endl;
		return 3;
	}

	ofs.open("output.txt", ios_base::out);
	if (!ofs)
	{
		cout << "failed to open output file" << endl;
		ifs.close(); // if we got this far, ifs is open so lets close it before leaving 
		return 2;
	}

	while(ifs.getline(inputLine, MAX)) // while able to get lines 
	{
		//cout << "inside while loop" << endl;
		//cout << inputLine << endl;
		revWords(inputLine); // we want to reverse individual words in place, rather than reversing the whole line 
		ofs << inputLine << endl;
	}

	ifs.close();
	ofs.close();

	return 0;
}