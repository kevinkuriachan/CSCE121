#include <iostream>
using namespace std;

void mystery(int l[], int n)
{
	int tmp = l[0];
	for (int i = 0; i < n -1; i++)
	{
		l[i] = l[i+1];
	}
	l[n-1] = tmp;
}

int main()
{
	int l[] = {100, 200, 300, 400, 500};
	int n = 5;
	mystery(l, n);
	for (int i = 0; i < n; i++)
	{
		cout << l[i] << endl;
	}
	return 0;
}