#include <iostream>
using namespace std; 

/* Hero's method:

takes input s, there is a recurrence relation:

	x0 = s, e;
	
	x_(i+1) = x_i - ((x_i)^2 - s)/(2 x_i)
	
	do until |x_(i+1) - x_i | < e ;
	
	Here is a function to implement hero's method
	
*/ 
bool is_even(int x)
{
	return ((x % 2) ==0);	// return true if condition met, else return false;
}

bool is_divisible_by_5(int x)
{
	return ((x%5) == 0);
}


// single ampersand (&) does the same thing as below: forces check of both conditions 
bool my_and(bool a, bool b)
{
	return (a && b); 
}

int main()
{
	int n;
	cout << "Please give me a number: " << endl;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cout << i << "\t";
		if (is_even(i) && is_divisible_by_5(i)) // if the first condition is not met, it will not check second condition 
		{
			cout << "is divisible by 10." << endl;
		}
		else 
		{
			cout << "is NOT divisible by 10." << endl;
		}
	}
	
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	