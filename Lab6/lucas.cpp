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

int main()
{
	int n;
	cout << "Enter a number (n): " ;
	cin >> n;
	cout << "L_" << n << " = " << Lucas(n);
	return 0;
}
