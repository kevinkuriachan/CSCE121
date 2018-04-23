#include <iostream>
using namespace std;

//part 1 

int SumOfNums(long n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum+=i;
	}
	return sum;
}

int numOfDigits(long k) // outputs the number of digits in a number 
{
	long num = k;
	int len = 0;
	bool done = false;
	
	while(!done)
	{
		num  = num/10;
		len++;
		if (num == 0) 
		{
			done = true;
		}
	}
	
	return len;
}


long exp(int base, int power) // exponentiates power to base 
{
	long output = 1;
	for (int i = 1; i < power +1; i++)
	{
		output = base*output;
	}
	
	return output;
}

int getDigit(long n, int index) // gives you integer value of digit at [i] index 
{
	long num = n;
	int len = numOfDigits(num);
	long divisor = exp(10, ((len-1) - index) );
	int digit = (num / divisor)%10; 
	return digit;
	
}


long SumOfDigits(long n)
{
	long num = n;
	int sum = 0;
	
	for (int i = 0; i < numOfDigits(num); i++)
	{

		sum += getDigit(num, i);
	}

	return sum;
}

long reverseNum(long n)
{
	long reversed = 0;
	int len = numOfDigits(n);
	int digits[len];
	for (int i = 0; i < len; i++)
	{
		digits[len-1-i] = getDigit(n, i);
	}

	for (int i = 0; i < len; i++)
	{
		reversed = reversed + (digits[i] * exp(10, len-1-i));
	}
	return reversed;
}

long SumWithDigitsReversed(long n)
{
	return (n+reverseNum(n));
}

// end part 1 

int main()
{
	cout << SumOfNums(100) <<endl;
	cout << SumOfDigits(15290) << endl;
	cout << SumWithDigitsReversed(15290) << endl;
	
	return 0;
}
