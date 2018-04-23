#include <iostream>
using namespace std;

void tester1()
{
	int x;
	cout << "uninitialized x = " << x << endl;
	x = 13;
	cout << "now x = " << x <<endl;
}

void tester2(int z[]) // arrays are implicitly passed by reference 
{	// because the size of array is not included in the parameter, so tester2 does not know its size 
	// what happens is you are passed a reference to the data ( gives you mem location of first element ) 
	// can find elements because each int  is 4 byes so you can go forth by adding 4 to mem address 
}

int main()
{
	int v[5] = {20,21,22,23,24};
	tester1();
	tester2(v);
	tester1();
	return 0;
} 