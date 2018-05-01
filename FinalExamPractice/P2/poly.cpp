#include <iostream>
using namespace std;

#include "poly.h"

double pow(double base, int exponent)
{
	double output = 1;

	for (int i = 0; i < exponent; i++)
	{
		output *= base;
	}
	return output;
}

struct term {

	double coeff;
	int degree; 
	term * next;
};

Poly::Poly()
{
	head = NULL;
}

Poly::~Poly()
{
	term * walker = head;
	while (walker != NULL)
	{
		term * hold = walker->next;
		delete walker;
		walker = walker->next;
	}
}

void Poly::add_term(double c, int deg)
{
	term * toAdd = new term;
	toAdd->coeff = c;
	toAdd->degree = deg;
	toAdd->next = NULL;
	term * walker = head;
	if (head == NULL)
	{
		head = toAdd;
		return;
	}
	while (walker->next != NULL)
	{
		walker = walker->next;
	} 
	// at this point, walker is the last term
	walker->next = toAdd;
}

double Poly::eval(double x)
{
	double sum = 0;
	term * walker = head;
	while (walker != NULL)
	{
		sum += ((walker->coeff)*pow(x,walker->degree));
		walker = walker->next;
	}
	return sum;
}

