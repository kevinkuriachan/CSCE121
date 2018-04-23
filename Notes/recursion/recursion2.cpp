#include <iostream>
using namespace std;

bool isMcNugget(int n)
{
	if (n < 4 ) return false;
	if (n == 4) return true;
	if (n == 6) return true;
	if (n == 9) return true;
	if (n == 20) return true;	// This is really redundant.
	
	return ( ( isMcNugget(n-20) ) || (isMcNugget(n-9)) || (isMcNugget(n-6)) || (isMcNugget(n-4)) ) ;
		// returns true if n-aMcNuggetNumber is true, else returns false 
	
}

int main()
{
	int n;
	cout << "Enter a number: " << endl;
	cin >> n;
	
	if (isMcNugget(n))
		cout << n << " is a McNugget number!" << endl;
	
	return 0; 
}