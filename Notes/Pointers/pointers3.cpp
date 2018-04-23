#include <iostream>
using namespace std; 

int g_i = 100;

int main()
{
	int array[5] = {3,4,5,6,7};
	int *p;
	p = array; // this puts mem location of array into p but we didn't have to say &array 
				// this is because arrays are passed as references already 

		
}