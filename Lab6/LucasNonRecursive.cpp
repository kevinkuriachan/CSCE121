#include <iostream>
using namespace std;

long Lucas(int n)
{
	long list[n+1];
	list[0] = 2;
	list[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		list[i] = list[i-1]+list[i-2];
	}
	return list[n];

}

int main()
{
	int n;
	cout << "Enter a number (n): " ;
	cin >> n;
	cout << "L_" << n << " = " << Lucas(n) << endl;
	return 0;
}