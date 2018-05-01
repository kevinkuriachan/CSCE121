#include <iostream>
using namespace std;

#include "poly.h"

int main()
{
	Poly p;
	p.add_term(0.45, 0);
	p.add_term(-1.89, 2);
	p.add_term(3.4, 5);
	p.add_term(9,16);
	cout << p.eval(0.0) << endl; // should output 0.45
	cout << p.eval(1.0) << endl; // should output 10.96
	return 0;
}