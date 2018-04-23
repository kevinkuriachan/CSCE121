#include <iostream>
using namespace std; 

/* Hero's method:

takes input s, there is a recurrence relation:

	x0 = s, e;
	
	x_(i+1) = x_i - ((x_i)^2 - s)/(2 x_i)
	
	do until |x_(i+1) - x_i | < e ;
	
	Here is a function to implement hero's method
	
*/ 

float abs(float x)
{
	if (x<0) return -x;
	return x;
}


float herosMethod(float s, float eps)
{
	float x;
	float x_next = s;
	
	do
	{
		x = x_next;
		x_next = x - ((x*x)-s)/(2.0 * x);
		
		
		cout << "x = " << x << "; x_next = " << x_next << endl;
	}
	while (abs(x_next - x) >= eps );
	
	return x_next;
}

int main()
{
	float in;
	cout << "Please give me a number: " << endl;
	cin >> in;
	
	float out = herosMethod(in, 0.0001);
	cout << "Output = " << out;
	
	
	return 0;
}
	