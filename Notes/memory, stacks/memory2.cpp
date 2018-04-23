#include <iostream>
using namespace std; 

const int thresh = 15; // threshold is 15

int large_abs(int x, int n)
{
	if (x < 0 ) 
		x = -x;
	
	if (x >= n) 
		return x;
	
	return 0; 
}

int main()
{
	int v;
	cout << "Give me a number: " <<endl;
	cin >> v; 
	
	float f = large_abs(v, thresh);
	return 0;
}

/* 

15 is put into a memory location in the data segment before the program runs // lets the address eee
Data: 
eee [ 15 ]  thresh

// space for int v is not allocated until runtime 

stack:

the moment we begin, we have to allocate some memory onto the stack for main 

          [ m ] << gets 15 from thresh 
          [ x ] << becomes -19 when v is passed into x, then becomes 19  
 ->  [ large abs     ] << functions use memory // when returned, memory pointer comes back here and new functions overwrite what exists here 
 FF3    |      | } space for float, because float is bigger than int 
        |     f| } << becomes 19.0 when large abs returns 
 FFB    [ -19 v]    << block of memory for int v  (-19 in this example) 
 FFF [   main        ] 
 
 when we remove stuff from he stack, we "pop the stack" 
 */
 
 
 
 
 
 
 
 
 
 
 
 