char msg[100] = "hello!";

int main()
{
  

  return 0;
}


/*

what's happening in the memory?

when we call g++,
 it takes the input and puts it into a box, that is g++:
 -preprocessor
 -compiler  << constructs object code 
 -linker << gives us a.out 
 
 / using the -commands in g++ lets us stop at any stage. 

 the file that comes out also contains the variables we declared. 
 
 What happens when we type ./nameOfProgram 
	a.out (a big binary file) .
	system takes this file and copies it into memory, then jumps to the start and begins executing. 
	
	The segments in the memory dedicated to the program : 
	
000	| text |  << instructions for your code
	| data |  << contains initialized static variables
    | heap |  << can grow or shrink
    |  |   |  << grows down 
	|  V   |
	- -- - -  << if the heap and stack cross, you are out of memory 
	|  ^   |
	|  |   |
fff	| stack|  << grows up 
  	
Memory is a linear object. The addresses on it are scalar values (only one dimension), represented in Hexi deci .

one of the reasons memory is segmented is so that if something like an array overflows, it doesn't affect stack or heap 

a variable in its rawest sense is a memory address. 
	

*/












