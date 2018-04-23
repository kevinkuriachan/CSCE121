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


int main()
{
	int num = -1;
	while (num <= 0)
	{
		cout << "Enter an upper limit: ";
		cin >> num; 
	}
	
	//int primes[];
	
	int count = 0;
	for (int i = 1; i <= num; i++)
	{
		if (is_prime(i))
		{
			//primes[i-1] = i;
			count++;
			if (count != 1)
			{
				cout << ", " << i ;
			}
			else 
			{
				cout << i;
			}
		}
	}
	
	
	return 0;
}
