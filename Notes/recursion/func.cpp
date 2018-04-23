#include <iostream>
using namespace std;

long fact(int k)
{
	long f = 1;
	for ( int i =1; i <= k; i++)
	{
		f = f *i;
	}
	return f;
}

long fact2(int k)	// recursion is when the function calls itself
{
	if (k == 1) return 1;
	return k*fact2(k-1);
}

// recursive functions show that every time a function is called, new space is allocated for the parameters. 



int main()
{
	
	int n; 
	cout << " please enter a number: " << endl;
	cin >> n;
	
	cout << n << "! = " << fact(n) << endl;
	cout << "also: " << n << "! = " << fact2(n) << endl; 
	
	return 0;
	
}