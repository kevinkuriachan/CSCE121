#include <iostream>
using namespace std;

void tester1()
{
	int x;
	cout << "uninitialized x = " << x << endl;
	x = 13;
	cout << "now x = " << x <<endl;
}

void tester2()
{
	int a = 100;
}

int main()
{
	tester1();	// prints x= 0, then x= 13;
	tester2();	// prints a = 100;
	tester1();	// prints x = 100, then x = 100
				// second test1 is built on where test2 used to be so it takes up that space in the stack. 
	
	return 0;
}


/*

no global variables in this program. 
The runtime goes like this 

1) space taken up in memory by main 
2) space taken up by tester1 
3) space allocated for int x;
4) space taken by function 'cout' and then that space is cleared when cout is done
5) int x is set to 13;
6) 'cout' takes up space then space is cleared. 
7) the space in 2,3 marked as vacant but the data still exists. 
8) space allocated for tester2 (same space used by tester1) 
9) space created for int a and 100 assigned to it (where x used to be )


What we have been talking about is called the "call stack" 
	- provides the illusion of the abstract stack 




















