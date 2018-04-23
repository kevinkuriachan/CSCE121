#include <iostream>
using namespace std; 

int meh = 100;

// there is a convention of using a g_ in front of variable names to say they are global 
// example : g_GlobalVariableName

int my_fun(int x)
{
	int meh = meh;
	/*
	means:
	int meh;
	meh = meh;
	
	memory junk from the past is put into local meh;
	*/
	x++;
	
	return meh;
}

int main()
{
	
	return 0;
}