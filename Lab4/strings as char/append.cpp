#include <iostream>
using namespace std;

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

int usedLen(char str[])
{ // returns number of charaters + 1 for the terminating \0 
	int i = 0;
	int len = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return ++len;
}

void appendX_unsafe(char str[])
{ // modifies the input, appending an X to it. 

	str[getLenChars(str)] = 'X';
}

void appendX(char str[], int len)
{ // modifies the input, only appending an X if it would still be within bounds
	int used = usedLen(str);
    if (used < len) 
    	{
    		str[getLenChars(str)] = 'X';
    	}
}

void catstrings(char first[], int fst_len, char second[])
{ // concatenate second to the end of first, while not overrunning first
	int charsFirst = getLenChars(first);
	int usedFirst = usedLen(first);
	int available = fst_len - usedFirst;
	for (int i = 0; i < available; i++)
	{
		char thingToAdd = second[i];
		first[charsFirst + i] = second[i];
	}
	first[fst_len] = '\0';
}

bool string_eq(char first[], char second[])
{ // return true iff two strings are identical, character for character 

    int firstLen = getLenChars(first);
    int secondLen = getLenChars(second);

    if (firstLen != secondLen) return false;
    for (int i = 0; i < firstLen; i++)
    {
    	if (first[i] != second[i]) return false;
    }

    return true;
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

bool string_eq_nocase(char first[], char second[])
{ // a case insensitive check for string equality
	toUpper(first);
	toUpper(second);
    if ( string_eq(first, second) ) return true;
	return false; 
}

void strip_dup_spaces(char str[])
{ // removes all consecutive spaces from str
	int len = usedLen(str);
	for (int i = 0; i < len-1; i++)
	{
		while((str[i] == ' ') && (str[i+1] == ' ') )
		{
			for (int j = i; j < len-1; j++)
			{
				str[j] = str[j+1];
			}
		}
	}
}
 
bool contains_sub_str(char haystack[], char needle[])
{ // return true iff needle appears within haystack
	int len2 = getLenChars(needle);
	int len1 = usedLen(haystack);
	char test[len2];
	test[len2] = '\0';

	for (int i = 0; i < len1-len2; i++)
	{
		if (haystack[i] == needle[0])
		{
			for(int j = 0; j < len2; j++)
			{
				test[j] = haystack[i+j];
			}
			if (string_eq(test, needle)) return true;			
		}

	}

	return false;
}

int index_sub_str(char haystack[], char needle[])
{ // return true iff needle appears within haystack
	int len2 = getLenChars(needle);
	int len1 = usedLen(haystack);
	char test[len2];
	test[len2] = '\0';

	for (int i = 0; i < len1-len2; i++)
	{
		if (haystack[i] == needle[0])
		{
			for(int j = 0; j < len2; j++)
			{
				test[j] = haystack[i+j];
			}
			if (string_eq(test, needle)) return i;			
		}

	}

	return -1;
}

bool del_first_occur(char input[], char cut[])
{ // if cut appears in input, remove it and return true; 
  // otherwise leave input as is and return false
  if (!contains_sub_str(input, cut)) return false;
  int lenIn = usedLen(input);
  int lenCut = getLenChars(cut);
  int indexCut = index_sub_str(input, cut);
  for (int i =0; i < lenCut; i++)
  {
	for (int j = indexCut; j < lenIn; j++)
	{
		input[j] = input[j+1];
	}
  }
  return true;
}


int main()
{
	int len = 100;
	char first[len];
	char second[len];

	cout << "Enter haystack: ";
	cin.getline(first,len);
	cout << "Enter needle: ";
	cin.getline(second,len);
	//cout << "Enter second string: " << endl;
	//cin.getline(second,len); 
	/*
	if (string_eq_nocase(first, second)) cout << "same\n";
	else cout << "NOT! same" << endl;
	*/
	//catstrings(first, len, second);
	//strip_dup_spaces(first);
	
	//cout << first << endl;


	bool nan = del_first_occur(first, second);
	strip_dup_spaces(first);
	cout << first << endl;

	return 0;
}