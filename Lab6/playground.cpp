#include <iostream>
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
		cout << list[i] << endl;
		if (c == list[i]) return true;
	}
	return false;
}

int main()
{
	char c = 'a';
	int i = 0;
	cout << getLenChars(endPunctuation) << endl;
	bool cInStr = charInArray(c, endPunctuation);
	return 0;
}
