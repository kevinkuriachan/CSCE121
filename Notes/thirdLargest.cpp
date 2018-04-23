#include <iostream>
using namespace std;


int main()
{
	int userInput;
	int count =0;
	
	int first = -1;
	int second = -2;
	int third = -3;
	
	do
	{
		
		cout << "Please enter a positive integer (-1 to end): ";
		cin >> userInput;
		cout << endl;
		
		count++;
		
		if (userInput >= first)
		{
			third = second;
			second = first;
			first = userInput;
		} else if (userInput >= second)
		{
			third = second;
			second = userInput;
		} else if (userInput >= third)
		{
			third = userInput;
		}
		
	}
	while (userInput >= 0);
	
	if (count <= 3)
	{
		cout << "You didn't enter enough numbers!" << endl;
	}
	else 
	{
		cout << "The third largest number was " << third << endl;
	}
	
	
	// The problem with this is that it cannot be scaled well; not flexible
	// Ex: you can't easily change it to find the 5th or 17th largest or last number, etc
	return 0;
}