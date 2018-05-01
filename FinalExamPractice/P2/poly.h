#include <iostream>
using namespace std;

#ifndef __POLY__
#define __POLY__

struct term;

class Poly {

	public:

	Poly(); // constructor 
	virtual ~Poly(); // deconstructor 
	void add_term(double coeff, int degree);
	double eval(double x);
	
	private:

	term * head;

};


#endif 