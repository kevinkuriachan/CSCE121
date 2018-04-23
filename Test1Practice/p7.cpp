#include <iostream>
#include <fstream>
using namespace std;

char endPunctuation[] = ".?!";

bool validChar(char c)
{
	if ( (c >= 'A') && (c <= 'Z')) return true;
	if ( (c >= 'a') && (c <= 'z')) return true;
	if (c == '&' || c == '-' || c == '\'') return true;
	return false; 
}

void revSingleWord(char s[], int f, int l)
{
	for (int i = 0; i < (l-f+1)/2; i++)
	{
		char hold = s[f+i];
		s[f+i] = s[l-i];
		s[l-i] = hold;
	}
}

void revSingleWordRecursive(char s[], int f, int l)
{
	if (f >= l) return;
	char hold = s[f];
	s[f] = s[l];
	s[l] = hold;

	revSingleWordRecursive(s, f+1, l-1);
}

void revWords(char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		int j = i;
		while (!validChar(s[j]) && s[j] != '\0')
		{
			j++;
		}
		// j is now the beginning of a word
		i = j;
		while (validChar(s[j]))
		{
			j++;
		}
		revSingleWord(s, i, j-1);
		i = j;
	}
	
}

int main()
{
	char s[] =  "this is a string of char's and now it should! be reversed";
	revWords(s);
	cout << s << endl;
	return 0;
}