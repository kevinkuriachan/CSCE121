#include <iostream>
using namespace std;

const int max_degree = 15;

void prettyPrint(float coeffs[], int degree)
{
	for (int i =0; i <= degree; i++)
	{
		if (coeffs[i] != 0)
		{
			if (i==degree){
				cout << " + (" << coeffs[i] << ")";
			}
			else if (degree-i == 1){
				cout << "(" << coeffs[i] << ")*x ";
			}
			else {
				cout << "(" << coeffs[i] << ")*x^" << degree-i  << " + ";
			}
		}
	}
}

float power(float base, int exp)
{
	float output = 1;
	for (int i = 1; i <= exp; i++)
	{
		output = base*output;
	}
	

	return output;
}

float poly_eval(float coeffs[], int degree, float x)
{ // evaluates a polynomial at x. The polynomial representation has
  // taking in degree+1 coefficients in coeffs, with the highest degrees
  // appearing first.
    
	float output = 0;
	
	for (int i =0; i <= degree; i++)
	{
		float mult = power(x, degree-i);
		output += coeffs[i] * mult;
	}
	return output;
	
}

float horners_method(float coeffs[], int degree, float x)
{ // evaluates a polynomial at x. The polynomial representation has
  // taking in degree+1 coefficients in coeffs, with the highest degrees
  // appearing first.
	
	float output = ((coeffs[0]*x) + coeffs[1]);
	
	for (int i = 2; i <= degree; i++)
	{
		output = (output*x) + coeffs[i];
	}
  
	return output;

}

int main()
{
    float p1_coeff[max_degree] = {2.3, 0.0, 1.2, -9.3, 8.4};

    cout << "P_1(x) = ";
    prettyPrint(p1_coeff, 4);
    cout << endl;
	cout << poly_eval(p1_coeff,4,5) << endl;	
	cout << endl;
	cout << horners_method(p1_coeff, 4,5) << endl;

    return 0;
}

