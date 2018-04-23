#include <iostream>
using namespace std;


void refs_to_pair(int &a, int &b, int * &min, int * &max) // passes a pointer by ref
{
	//we pass a and b by reference because we want the pointers 
	// to point to the original location of the values
	// else it will point to location of the copy of a and b inside the function
	// this memory is wiped after the function returns
	
	if (a > b)
	{
		max = &a;
		min = &b;
	}
	else 
	{
		min = &a;
		max = &b;
	}
}

int main()
{

	return 0;
}