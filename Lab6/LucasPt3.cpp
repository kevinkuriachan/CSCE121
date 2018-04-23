#include <iostream>
using namespace std;

int Lucas(int n, long &LucasCount)
{
	LucasCount++;
	cout << "number of times recursion is called: " << LucasCount << endl;
	int L0 = 2;
	int L1 = 1;
	if (n == 0) return L0;
	else if (n == 1) return L1;
	else return ( Lucas(n-1, LucasCount)+Lucas(n-2,LucasCount) );
}

int main()
{
	int n;
	long LucasCount = 0;
	cout << "Enter a number (n): " ;
	cin >> n;
	cout << "L_" << n << " = " << Lucas(n, LucasCount) << endl;
	return 0;
}
