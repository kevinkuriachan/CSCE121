#include <iostream>
using namespace std;

// we use & to get the mem location of a variable 
// we use * to either a) dereference a pointer or b) declare something is a pointer 

/*

double d = 13;
d = d+1; on the right, it is refering to the value in the box; on the left, it is refering to the box (where the new value should be stored);
double *p;
p = &d;
double e = (*p)+23 // says d is a pointer, the astrisk says "go to the end of the arrow and use that value" 

		 [      ] e
[ ]p --> [  14  ] d


the most common cause for seg faults is that someone is trying to dereference an uninitialized pointer 

*/

#define MAX_STR 200

struct personT{
	char name[MAX_STR];
	int age;
	bool alive;
}

int main()
{
	double d = 12;

	double *p = &d;

	double *q = NULL; // if we try to look at this pointer and see the mem location it holds, it says 0.
					// the operating system will never allocate a mem location at 0, so we can say that a pointer holding zero is 
	 				// uninitialized ;
					// dereferencing the NULL pointer will result in a seg fault 
	q = &d; // if we put a star in front of q (*q = &d), it will cause problems 

	return 0;
}