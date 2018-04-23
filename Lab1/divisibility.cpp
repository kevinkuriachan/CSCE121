#include <iostream>
using namespace std;

int main()
{
	int num1 = -1;
	int num2 = -1;
	
	while (num1 < 0)
	{
		cout << "Please enter a number: \n";
		cin >> num1;
	}

	while (num2 < 0)
	{
		cout << "Please enter a second number: \n";
		cin >> num2;

	}


	int big;
	int small;

	if (num1 > num2)
	{
		big = num1;
		small = num2;
	}
	else
	{
		big = num2;
		small = num1;
	}

	if ((big == 0) || (small == 0))
	{
		cout << "Cannot divide by 0\n";
		return 1;
	}

	int divisibility = big/small;

	cout << "Thank you. Did you know that " << big << " divides " << small << " a total of " << divisibility << " times?";
}
