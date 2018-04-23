#include <iostream>
using namespace std;

void tester1()
{
	int x;
	cout << "uninitialized x = " << x << endl;
	x = 13;
	cout << "now x = " << x <<endl;
}

void tester2(int &z)
{
}

int main()
{
	int v = 19;
	tester1();
	tester2(v);
	tester1(); // uninitialized x is now 32767. why ?? 
	return 0;
}

/*
[bottom of stack; down is up] 

1) space for main
2) space allocated for int v, value set to 19;
		mark (a);
3) space for tester 1
4) 		space for int x
5)		value of x set to 13 
6) 3-5 marked as clear (pointer moves to the beginning of it to write on top of it)
7) space 3 becomes space for tester 2;

	// how do pass by reference? 
	// enough information is given so that the original variable can be modified at its original memory location 
	// the weird number returned by line 21 of the code is a memory address for mark (a)
	
*/