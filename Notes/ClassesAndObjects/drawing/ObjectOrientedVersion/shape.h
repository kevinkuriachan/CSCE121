#ifndef __SHAPE_H__ // if this has not been defined before, do the following: 
#define __SHAPE_H__ // underscore underscore name underscore 'H' underscore underscore is one of the conventions we can use 

// WHENEVER WE CREATE HEADER FILES, WE SHOULD USE THE PRACTICE TO INCLUDE THIS OPENING 

class Shape {
// this says what all shapes have in common

	public:
		virtual void draw() = 0; // virtual means it can be overwritten if a more appropriate method lower in the heirarchy 
		virtual void doubleInSize() = 0;
		// pointing them to 0 is the same as null
		// therefore, the function pointer points to null
		// at this point, these functions do not exist.
		// this is called an abstract class 
		// it doesn't actually point to address 0, 
		// its being used as a keyword for abstract 
}


#endif // end line 1 (like a closing brace)

/*

int main()
{
	int i = 0;
	Rectangle r;  // Rectangle is analygous to int, r is analygous to i;
}

shape:
	rectangle: has all properties of shape
		square: has all properties of rectangle 
	X: 

rect.h defines Shape with #include shape.h
x.h defines Shape with #include shape.h 

because of this, the main program defines shape before.
Program will not compile because of this. 


*/