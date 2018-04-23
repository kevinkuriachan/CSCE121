#include <iostream>
using namespace std;

int Lucas(int n)
{
	int L0 = 2;
	int L1 = 1;
	if (n == 0) return L0;
	else if (n == 1) return L1;
	else return ( Lucas(n-1)+Lucas(n-2) );
}

float ratio(int n)
{
	float output;
	return ((0.0+Lucas(n)) / (0.0+Lucas(n-1) ) );
}

float abs(float n)
{
	if (n < 0) return -1*n;
	return n;
}

int main()
{
	int n = 2;
	float oldRatio = ratio(n-1);
	float newRatio = ratio(n);
	float diff = abs(oldRatio-newRatio);
	while (diff > 0.0001)
	{
		newRatio = ratio(n);
		diff = abs(oldRatio-newRatio);
		cout << " n = " << n << " ; ratio of L_n/L_(n-1): " << newRatio << endl;
		oldRatio = newRatio;
		n++;
	}
	return 0;
}
