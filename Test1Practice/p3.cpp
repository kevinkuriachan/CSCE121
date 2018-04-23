#include <iostream>
using namespace std;

const int n = 3;

int* all(int v[n][n]) // takes a square matrix of ints, returns a pointer to an int. 
{ // Assumption: v contains non-negative integers
	int m = 0;
	int *ret = NULL; // creates a null pointer . 
	
	// if nothing is done with the pointer, NULL is returned, which breaks the loop in line 23
	for (int i=0; i < n; i++) //iterates through every element 
		for (int j=0; j < n; j++)
			if (v[i][j] > m) // if current element is greater than m, m is set to the current element 
			{
				m = v[i][j];
				ret = &(v[i][j]); // the ret pointer is set to address of current element 
			}
	return ret; 
	// returns ret pointer, which is the location of the greatest value in the array 
}

int main() {
	int t[n][n] = {{1, 23, 1}, {4, 0, 6}, {0, 12, 3}}; // Every element >= 0
	int *p = all(t); // initializes pointer to greatest element. 
	while (p != NULL) 
	{
		cout << *p << endl;
		*p = 0;
		p = all(t); // will print the elements in decreasing order. 
	}
	return 0;
}