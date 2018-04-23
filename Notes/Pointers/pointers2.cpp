
/*
data segment:

0x123 [100] g_i 

stack:

0xEFA [0xEFB] p
0xEFB [  19 ] a 


*/



#include <iostream>
using namespace std; 

int g_i = 100;

int main()
{
	int a = 19;
	int *p; // pointer to an integer 

	int &r = a;
	
	cout << "g_i = " << g_i << endl;
	cout << "a = " << a << endl;

	cout << "&g_i = " << &g_i << endl; // gets memory location 
	cout << "&a = " << &a << endl;	

	p = &a ; // assign the memory location of a to p 

	cout << "r = " << r << endl; 
	cout << "p = " << p << endl;

	// to get the contents of the mem location stored in p: *p

	cout << "*p + " << *p << endl; // this is called dereferencing 

	// *p is and isn't a number 
	// when we print addresses, it is printed in HEX just to remind us its an address, don't do arithmethic  	

	// we would make the pointer the same data type as what it is pointing to so when we dereference it, it will be treated correctly

	// you will notice that the address of g_i is a small number and the address of a, r are big numbers
	// this is because the data segment goes from small mem location down; stuff in the stack goes from big up to small;

	/* layout of memory (goes top down) 

	small addresses 
	.
	.
	.
	big address 
	*/ 


	// BELOW ARE IDEAS AND CONCEPTS FROM STUDENT QUESTIONS 

	// int *p = 6;      // A
	// *p = 6;          // B

	// A and B are not the same thing

	// A is the same as (int *)p = 6; make a pointer to and integer and call it p:   0xF0C [ 6 ] p
	// B means dereference p and put a 6 there: tries to got to address 6 and then put a 6 into the value at address 6;


	// whenever we pass an array around, it's really passing around a pointer to the array. 
}