#include <iostream>
#include <math.h>
using namespace std;

float manning(float h, float q, float n, float s, float b)
{
	float eval = q - ((1.49/n)*(pow((b*h),(5/3))/pow((b+(2*h)),(2/3)))*(pow(s,(1/2))));
  	return eval;
}

bool isPositive(float n)
{
	if (n > 0) return true;
	return false; 
}

bool isNegative(float n)
{
	if (n < 0 ) return true;
	return false; 
}

bool sameSign(float a, float b)
{
	if ((isNegative(a) && isNegative(b)) || ( isPositive(a) && isPositive(b) )) return true;
	return false; 
}

int main()
{
	float q = 450.0;
 	float s = 0.0007;
 	float b = 25.0;
  	float n = 0.02;

  	float hmin = 0;
  	float hmax = 10000;
  	float evalmin = manning(hmin, q,n,s,b);
  	float evalmax = manning(hmax, q,n,s,b);

  	float h = (hmin+hmax) /2; 

  	float eval = (h, q,n,s,b);
  	cout << evalmin << " "  << evalmax << " " <<  eval << endl ;

  	
  	while (abs(eval) > 0.0001)
  	{
  		if (sameSign(eval, evalmax))
  		{
  			cout << "!!!!" << endl; 
  			hmax = h;
  		}
  		else if (sameSign(eval, evalmin))
  		{
  			cout << "****" << endl; 
  			hmin = h;
  		}
  		h = (hmin+hmax) / 2; 
  		evalmin = manning(hmin, q,n,s,b);
  		evalmax = manning(hmax, q,n,s,b);
  		eval = manning(h, q,n,s,b);
  		cout << "H: " << h << " ; eval: " << eval <<endl; 
  		cout << "hmin: " << hmin << " hmax: " << hmax << endl;
  	}
  	cout << h << endl;
}