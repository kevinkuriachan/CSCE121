// it is conventional to create classes with first letter capitalized 

// we can make methods public (anyone can call it and modify it) or private (only functions in the class can call or modify them)

#include "shape.h" 
					// what this says is that the things that are public in shape are public in rectangle
					// if it was private Shape { ...  , then the things that are public in shape are private in rectangle 
class  Rectangle : public Shape { // : public Shape says that rectangle is a shape and the things that are public in shape are public in Rectangle.

	public:
	// Methods 
	Rectangle(); // when then name of a class is used as name of function, it is a constructor.
	Rectangle(int w, int h); // we can have multiple constructors, for different number of arguments. 
	// you can do stuff like check here that the w and h are positive
	// then later you can assume they are positive because only functions
	// in this class could have modified them 

	virtual ~Rectangle() // a destructor, all destructors should be made virtual 

	virtual void doubleInSize();

	virtual void draw();

	private:
	// Fields
	int width;
	int height;

};