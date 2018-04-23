#include <iostream>
using namespace std;

#define MAX_DEGREE 15

// structs are a way to represent multiple data types 

struct polynomial_t {
	float coeffs[];
	int degree;
}; // <-- note the semicolon

// arrays inside structs are not pass by reference. 

// whenever an array is passed into a function, the array itself is not passed, the memory address for it is passed.

/* 

struct c_t{
	char s[100];
};

void f2(c_t m)
{
	// ...
}

you can pass strucs by reference likes so: 
void f3(c_t &x) {} 

*/


// putting functions in stucts:

struct example_t {
	float coeffs[];
	int degree;
	void p();
}; 

void p()
{
	//example function 
}

void ShowingHowToUseStruc(polynomial_t p2)
{
	int deg = p2.degree;
	float stuff[] = p2.coeffs;
	// can also do p2.coeffs[i] to get element at index i 
}


int main()
{
	float p1Coeffs[MAX_DEGREE];

	// initializing a struct 
	// dataType name = {first item, second item}
	polynomial_t p2 = {{4.5, 1.0, 0.0, 3.4}, 3};
	return 0;
}