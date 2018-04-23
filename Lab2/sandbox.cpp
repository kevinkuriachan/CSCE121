#include <iostream>
using namespace std;

int getBit(int n, int i) 
{ // gets the value of the i'th bit of n
  // where they are labeled right to left, starting from 0.
  //  The "units" are at 0, (so even or odd numbers alter this entry)
  //  The "twos" at 1, etc.

	return (n >> i) & 1; 
}

int sumOfBin(int dec) // converted to use bitwise 
{
	int sum = 0;
	int rem = dec;
	int i = 0;
	while ( rem!= 0)
	{
		sum += getBit(dec, i);
		rem = rem >> 1;
		i++;
	}
	cout << endl;
	return sum;
}

long long exp(int base, int power) // exponentiates power to base 
{
	long long output = 1;
	for (int i = 1; i < power +1; i++)
	{
		output = base*output;
	}
	
	return output;
}

long long raisedExpPow2(int base, int m)
{ // compute (b^m) when m is a power of two
	int move = sumOfBin(base);
	base = base << move;
	return exp(base, m);
}

long long raiseExpPow(int b, int m)
{// compute (b^m) when m is any positive integer 
	int sqPow = sumOfBin(m);
	long long PowTerm = raisedExpPow2(b, sqPow);
	//cout << "First Term: " << PowTerm << endl;
	long long output = PowTerm;
	if (m%2 == 1)
	{
		output = output * b;
	}
	//cout << "Second Term" << output << endl; 
	return output;
	
}

int main()
{
	int i = 4;
	int power = 3;

	cout << "sum: " << raiseExpPow(i, power) << endl;
	
}