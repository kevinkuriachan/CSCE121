#include <iostream>
#define MAX_CHARS 200
using namespace std;

int getLenChars(char str[])
{ // returns number of characters in a string 
  // not including the terminating null char
	int i = 0;
	int len = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
		if (i > MAX_CHARS) return -1; // ensures the loop isnt infinite
	}
	return len;
}

int char_occurs(char str[], char chr)
{

	int len = getLenChars(str);
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == chr) count++;
	}
	return count;

}

int main()
{
	char str[MAX_CHARS];
	char chr;
	cout << "enter your string: " ;
	cin.getline(str, MAX_CHARS);
	cout << "which character are you counting? ";
	cin >> chr;
	int numOfChr = char_occurs(str, chr);
	cout << chr << " occurs " << numOfChr << " times." << endl;
	return 0;
}