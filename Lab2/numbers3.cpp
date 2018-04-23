#include <iostream>
using namespace std;



bool is_prime(int n)
{
	int temp = 0;
	for (int i = 2; i < n; i++)
	{
		temp = n%i;
		if (temp == 0)
		{
			return false;
		}
	}
	return true;
}

int findPrimeSums(int n, int &a, int &b)
{
	int num = n;

	int half = num/2;
	int i = 1;
	if (num > 2) i = 2;
	for (i; i < half+1; i++)
	{
		int j = num - i;
		
		if ((is_prime(i)) && (is_prime(j)) )
		{
			a = i;
			b = j;
			return 0;
		}
	}

}

int main()
{
	int num = -1;
	while ( (num <= 0) || (num%2 != 0))
	{
		cout << "Enter a positive even integer: ";
		cin >> num; 
	}
	
	int a = 0;
	int b = 0;
	
	int nan = findPrimeSums(num, a, b);
	
	cout << num << " = " << a << " + " << b << endl;
	
	return 0;
}
