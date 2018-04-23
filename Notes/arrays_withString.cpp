// an array is a data structure that stores a number of the same data type 

#include <iostream>
using namespace std;

#define STRLEN 100

char lower_to_upper(char c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		return c - 'a' + 'A';
	}
	return c;
}

// double quotes " mean array of chars. single quote ' means char 

// difference between a capital and lowercase is 32 ( a bit ) 

// ASCII values are unsigned (go from 0 to 255); 255 + 1 = 0;


int main()
{
	char name[STRLEN];
	cout << "Please enter a name: " << endl;
	cin >> name; // this is dangerous 
	// also, if you put firstName [space] lastName, it will only take firstName because cin stops reading at space
	
	cout << "Name = '" << name "'\n";
	
	/*
	for (int i = 0; i <STRLEN; i++)
	{
		cout << name[i] <<" ," << endl;		// will show why it is dangerous 
	}
	*/
	
	for (int i = 0; name[i] != "\n"; i++)
	{
		cout << name[i] << endl;
	}
	
	for (int i = 0; name[i] != "\n"; i++)
	{
		cout << lower_to_upper(name[i]) << endl;
	}
	
	return 0;
}
