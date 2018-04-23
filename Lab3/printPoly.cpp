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

int main()
{
    float p1_coeff[max_degree] = {2.3, 0.0, 1.2, -9.3, 8.4};

    cout << "P_1(x) = ";
    prettyPrint(p1_coeff, 4);
    cout << endl;

    return 0;
}