#include <iostream>
using namespace std;


void tester1()
{
	int x;
	cout << "uninitialized x = " << x << endl;
	x = 13;
	cout << "now x = " << x <<endl;
}

void tester2(int z)
{
}

int main()
{
	tester1();
	tester2(9); // passes 9 to tester2 
	tester1();	// uninitialized x has value of 9.
	return 0;
}

/*

1) space given for main
2) space given for tester1
3) space given for int x
4) x changed to 13
5) 2, 3 marked as clear 
6) tester2 is run with 9 copied into it. space 3 is marked as z and given value 9;

what happens with uninitialized values is compiler and platform dependent. 

*/