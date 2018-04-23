#include <iostream> 		// includes cin and cout 
#include <fstream>			// allows input / output to a file 
using namespace std;


// cin takes input that user types into a file and 
// puts it into the variable it's pointed at

// input is given into cout and cout puts it onto the console 

const int MAX = 100;
const int MIN = 10;

int main()
{
	fstream fout("HelloWorld.txt", fstream::out); // fstream::out means write only file
	fout << "Hello World " << endl; // writes to file 

	// fstream fout() declares an object. In this case, a writable file 
	// can also do fstream file; and then later, file.open('name.txt');

	fout.close(); // closes the object 'fout'. 

	fstream fin("HelloWorld.txt", fstream::in); // open in read mode 
	char a[MAX];
	do	// returns true if we are not at end of file 
	{	// read until end of file has been reached 
		fin >> a;
		cout << a << " " ; 
	}
	while (fin.good());

	cout << endl;
	fin.close();

	return 0;
}