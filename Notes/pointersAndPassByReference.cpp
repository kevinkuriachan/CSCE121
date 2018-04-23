#include <iostream>
using namespace std; 

int meh = 100;

// there is a convention of using a g_ in front of variable names to say they are global 

void clip_to_rect(float x1, float y1, float x2, float y2, float &qx, float &qy )
{
	if (qx < x1) qx = x1;
	if (qx > x2) qx = x2;
	if (qy < y1) qy = y1;
	if (qy > y2) qy = y2;
	return(qx, qy);
}

// &variable : calling with the & is passing by reference. it gives the actual variable to the function
// and allows it to manipulate the original variable that is passed into function. 

//x1, x2, y1, y2 are copies of the variable passed. BUT qx is referring to the mx and changes mx 


void swap( int &a, int &b )
{
	// exchange the two variables 
	
	int t = b;
	b = a;
	a = t;
}


int main()
{
	float mx = 6.0;
	float my = 2.0;
	
	clip_to_rect(-1.0, -1.0, 1.0, 1.0, mx, my)
	
	cout << "mx = " << mx << endl;
	cout << "my = " << my << endl;
	

	return 0;
}