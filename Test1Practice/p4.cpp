#include <iostream>
using namespace std;

int findRep(int in[], int inLen, int reqLen)
{
	int first = -1;
	int count = 0;
	for (int i = 0; i < inLen -1; i++)
	{ // iterates through elements 
		if (in[i] == in[i+1]) // compares current value to next value 
		{
			first = i; // sets first to current index
			while (in[i] == in[i+1] && i < inLen)
			{ // iterates until the next number is no longer than same as current
				// i < inLen ensures we dont go out of array
				count++;
				i++;
			}
			count++; // this counts the last element
			if (count == reqLen) return first; // if the run is right
			first = -1; // if run is wrong, reset values;
			count = 0;
		}
	}
	return first;
}

int main()
{
	int list[] = {1,0,-3,4,6,6,6,8,8,-7,2,2,2,2};
	cout << findRep(list, 14, 4) << endl;
	return 0;
}