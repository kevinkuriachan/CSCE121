#include <iostream>	// cin, cout, etc 
#include <fstream>	// to open a file
#include <assert.h> // to check preconditions
using namespace std; 

/*
valid inputs:
xxx-xxx-xxxx
xxx.xxx.xxxx
(xxx)xxx.xxxx
xxxxxxxxxx
*/

#define MAX 50

#define KEYPADCOUNT 10 
const char phone_keypad[KEYPADCOUNT][5] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRQ", "TUV", "WXYZ"}
// ^ created an array (size 10) of arrays of chars size 5

const char validDigits[] = "0987654321";	// declaring it as a const prevents it from being changed later 
const char ValidNonDigits[] = "-(). +ABCDEFGHIJKLMNOPQRSTUVWXYZ";

typdef long phoneNumT;// defines a new data type; 
// advantage is that this allows you to change data type of phone num here and it changes it everywhere 

bool isDigitSpecialized(char c)
{ // returns true if c is '0', '1', '2', '3', ... '9'
	return (c <= '9' && c >= '0');
}

bool is_char_in_list(char ch, char list[])
{ // return true if char is in list, else return false 
	assert(ch != '\0');	// since all lists contain '\0' as a terminator, checking to 
						// look for the null character is not defined 
	int i = 0;
	while (list[i] != '\0')
	{
		if (list[i] == ch) return true;
		i++;
	}
	return false;
}

bool isDigit(char c)
{
	return is_char_in_list(c, validDigits);
}

int value_of_digit(char c)
{ // returns the integer equivalent of a char digit . ex : '5' outputs 5

	assert(isDigit(c));
	return (c - '0');
}

int parse_phone_digits(const char s[]);

phoneNumT parse_phone_numbers(const char str[]) // const char -> ensures nothing is changed in the array 
{	// returns true if the string can be parsed into a phone number 
	char pureDigits[MAX];
	//cout << "parse_phone_numbers got '" << str << "'" << endl;

	int i = 0, j = 0; 
	while(str[i] != '\0')
	{
		if (isDigitSpecialized(str[i]))
		{
			pureDigits[j] = str[i];
			j++;
		}
		else if (!ValidPhoneChar(str[i]))
		{
			cerr << "I dont know what to do with that input:" << endl;
			cerr << str << endl;
		}
		i++;
	}
	pureDigits[j] = '\0'; 

	cout << "pureDigits: = " << pureDigits << endl; 

	return parse_phone_digits(pureDigits);
}

phoneNumT parse_phone_digits(const char s[]) // this will overflow so we could make it return a long and that would fix the problem
{ // but there is a new technique : type def 
	phoneNumT ret = 0;
	int i = 0;
	while(s[i] != '\n')
	{ // moves left to right throught string 
		ret = 10 * ret + value_of_digit(s[i]);
		i++;
	}
	return ;
}

void incrementPhoneNum(chat workingNum[])
{
	
}

void printAllVanities(char phNum[])
{ // given: phNums[] contains only numerical digits 
  // prints all the vanity numbers with the same phone number 
	char workingNum[12];
	bool canStillIncriment;

	cout << "printAllVanities got num = " << num << endl;
	// can think of the key pad as a weird number system.
	makeSmallestNum(workingNum, num);
	do
	{
		incrementPhoneNum(workingNum);
		cout << workingNum << endl;
		canStillIncriment = stillLargerNum(workingNum);	
	}
	while (canStillIncriment)
}

int main()
{
	const char input_fname[] = "numbers.txt"; 
	char line[MAX];
	char phoneChars[12];

	fstream file;

	file.open(input_fname, ios_base::in);

	if(!file)
	{
		cerr << "Couldn't open '" << input_fname << "', sorry." << endl;
		return 1; 
	}

	int counter = 0; 
	while (file.getline(line,MAX))
	{
		//cout << counter++ << ") got line = " << line << endl;

		if (!parse_phone_numbers(line, num))
		{
			ifs.close();
			cerr << "issue reading line" << endl;
		}
		printAllVanities(phoneChars);
	}

	file.close();

	return 0;
}