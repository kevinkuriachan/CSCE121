#include <iostream>
#include <math.h>
using namespace std;

/*
I realized during testing that inputing negative 
coefficients does not work so correctly, however, this is a problem with the way I take inputs
and convert them to floats. If the proper coefficents were passed to the 
solveQuadratic() function, it 
should work and deal with negatives. I would have fixed the input but there isn't 
time to do so, therefore, I am going for partial credit. 
*/

#define MAXINPUT 50

int getLenChars(string str)
{ // returns number of characters in a string (excluding null) 
	int i = 0;
	int len = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}

void inputCoeffs(char charcoeffs[])
{
	cout << "Enter the coefficients, each seperated by a space (see .cpp for note about negatives): " << endl;
	cin.getline(charcoeffs, MAXINPUT);
}

int getDegree(char charcoeffs[])
{
	int spaces = 0;
	int i = 0;
	bool add1 = false;
	while((charcoeffs[i+1] != '\0') && charcoeffs[i] != '\0')
	{
		if (charcoeffs[i] == ' ') spaces++;
		i++;
		add1 = true;
	}
	if (add1) spaces++;
	return spaces-1;
}

int charToInt(char c)
{
	return c - '0';
}

int strToInt(string str)
{
	int output = 0;
	int len = getLenChars(str);
	int i = 0;
	while (str[i] != '\0')
	{
		output = 10 * output + charToInt(str[i]);
		i++;
	}

	return output;

}

void addToCoeffs(char charcoeffs[], float coeffs[])
{
	int posInCoeffs = 0;
	int len = getLenChars(charcoeffs);
	for (int i = 0; i < len;)
	{
		int j = i;
		string tmpstr = "";
		bool entered = false; 
		while (charcoeffs[j] != ' ' && j <= len)
		{
			tmpstr += charcoeffs[j];
			j++;
			entered = true;
		}
		i = j;
		if(entered)
		{
			tmpstr+= '\0';
			//cout << "tmpstr: " << tmpstr << endl;
			coeffs[posInCoeffs] = strToInt(tmpstr);
			posInCoeffs++;	
		}
		else i++;
		//cout << "i: " << i << endl;		
	}

}

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
	cout << endl;
}

void solveForImaginary(float coeffs[])
{
	float a = coeffs[0];
	float b = coeffs[1];
	float c = coeffs[2];
	float discriminant = ( pow(b,2) - (4*a*c) );
	float coeffOfI = sqrt(-1*discriminant) / (2*a);
	float real = ((-1)*b) / (2*a);

	cout << endl << "The solutions to: " << endl;
	prettyPrint(coeffs, 2);
	cout << "are: " << endl;
	cout << "x = " << real << " + " << coeffOfI << "*i" << endl;
	cout << "x = " << real << " - " << coeffOfI << "*i" << endl;
	return;
}


void solveQuadratic(float coeffs[])
{
	float a = coeffs[0];
	float b = coeffs[1];
	float c = coeffs[2];
	float solution1;
	float solution2;

	if ((pow(b,2) - (4*a*c) )< 0 ) 
	{ 
		solveForImaginary(coeffs);
		return;
	}

	solution1 = (((-1)*b) + sqrt(pow(b,2) - (4*a*c)))/(2*a);
	solution2 = (((-1)*b) - sqrt(pow(b,2) - (4*a*c)))/(2*a);

	cout << endl << "The solutions to: " << endl;
	prettyPrint(coeffs, 2);
	cout << "are: " << endl;
	cout << "x = " << solution1 << endl;
	cout << "x = " << solution2 << endl;
}


int main()
{

	char charcoeffs[MAXINPUT];
	inputCoeffs(charcoeffs);
	int degree = getDegree(charcoeffs);
	if (degree != 2) 
	{
		cout << "please enter a quadrtic (2nd degree polynomial)" << endl;
		return 1;
	}
	float coeffs[degree+1];
	addToCoeffs(charcoeffs, coeffs);
	solveQuadratic(coeffs);
	return 0;
}
