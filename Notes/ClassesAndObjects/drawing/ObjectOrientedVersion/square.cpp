#include "square.h"
#include <iostream>
using namespace std;

Square::Square(int edgeLen) : Rectangle(edgeLen, edgeLen)
{
	// what this does is it calls the Rectangle constructor with
	// the specification that len and width is both the same 
	cout << "making a square" << endl;

	// Rectangle is called first because square might need parts of it 
	// because of this reasoninig, the stuff after the ':' is done first 
	
}