#include <iostream>
#include "rect.h"

using namespace std;

Rectangle::Rectangle()
{
	cout << "Rectangle constructor with no arguments" << endl;

	width = 1;
	height = 1;
}

Rectangle::Rectangle(int w, int h)
{
	cout << "inside constructor with two parameters" << endl;

	width = w;
	height = h; 
}

Rectangle::~Rectangle() // our destructor 
{
    cout << "Rectangle destructor" << endl;
}


void Rectangle::doubleInSize()
{
	cout << "Inside Rectangle::doubleInSize()" << endl;

	width *= 2;
	height *= 2;

}

void Rectangle::draw()
{
	cout << "inside Rectangle::draw()" << endl;

	for (int i = 0; i < w; i++)
        cout << "*";
    cout << endl;

    for (int j = 1; j < h-1; j++)
    {
        cout << "*";
        for (int i = 1; i < w-1; i++)
            cout << " ";
        cout << "*" << endl;
    }

    for (int i = 0; i < w; i++)
        cout << "*";
    cout << endl;
}