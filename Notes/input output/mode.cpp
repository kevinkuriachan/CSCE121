#include <iostream>
#include <fstream>
using namespace std;
const int MAX = 100;

int calculateMode(int a[], int n)
{
	int mode = 0;
	int mode2 = -1;
	int freq[MAX] = {0};

	for (int i = 0; i < n; i++)
	{
		freq[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (mode < freq[i]) mode = i;
		else if (mode == freq[i]) mode2 = i;
	}
	/*
	if (mode2 > 0 ) // this is commented out because I realize it is wrong
	{
		mode = (mode+mode2)/2;
	}
	*/
	return mode; 
}

int main()
{
	int a[MAX];
	int n;

	// INPUT 

	cout << "Enter number of elements: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}


	// STEP 2 

	int mode = calculateMode(a, n);

	// STEP 3 
	cout << "Mode: " << mode << endl;

	return 0;
}