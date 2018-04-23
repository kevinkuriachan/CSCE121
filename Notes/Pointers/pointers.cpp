/*

0x331  [   58   ] h 
0x335  [ 0x339  ] r    <- 'r' hold memory location of 'a' 
0x339  [   19   ] a 
[         main          ]

*/

#include <iostream>
using namespace std; 

int main()
{
	int a = 19;
	int &r = a; 

	a = 27;
	r++; 
	cout << "a: " << a << endl;  // 28
	cout << "r: " << r << endl;  // 28


	// since they both changed, r and a must be the same thing under the hood;
	// what is the r ? 
	// when we say r++ it doesnt change r from 0x339 to 0x400. It changes whats at the memory location 0x339;

	int h = 2*a; 

	// how to make 'r' refer to 'h' 

	//if we say r = h; it changes value of 'a' to 'h' so it doesn't work 

	r &= h;



	return 0;
}