#include <iostream>
#include "x.h"
using namespace std;

X::X(int size)
{
	cout << "X constructor" << endl;
	this->size = size; // 'this' says we are referring to the size inside the X class 
}