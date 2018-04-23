#include <iostream>
using namespace std;

float abs(float x)
{
	if (x<0) return -1.0*x;
	else if (x>0) return x;
	else return 0;
}

int main()
{
	float f = 0.7;
	if (abs(f-0.7) < 0.00001)
	{
		cout << "Yes" << endl;
	} 
	else cout << "No" << endl;
	return 0;
}