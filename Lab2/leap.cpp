#include <iostream>
using namespace std;

bool isLeap(int year)
{
	if ( (year % 4 == 0) )
	{
		if ( year % 100 == 0)
		{
			if (year % 400 == 0 )
			{
				return true;
			}
			else return false; 
		}
		else 
		{
			return true;
		}
	}
	else 
	{
		return false;
	}
}

int main()
{
	int year = -1;
	while (year < 0 ) 
	{
		cout << "Enter a year: ";
		cin >> year; 
	}
	
	if (isLeap(year))
	{
		cout << year << " is a leap year. " << endl;
	}
	else cout << year << " is NOT a leap year." << endl; 
	
	
	return 0;
}