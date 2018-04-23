#include <iostream>
using namespace std; 


int main()
{
	float a = 7.0;

	cout << "a = " << a << endl;	// console: a = 7

	float &r = a; // every time I mention r, I am talking about a also 

	cout << "r = " << r << endl;	// console: r = 7

	r = 9.0;

	cout << "a = " << a << endl;	// console: a = 9
	cout << "r = " << r << endl;	// console: r = 9

}