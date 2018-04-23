#include <iostream>
using namespace std;

int cube(int base)
{
	return (base*base*base);
}


int main()
{
	int n = -1;
	while (n<=0)
	{
		cout << "Enter and integer n: ";
		cin >> n; 
	}
	cout << endl;
	



	for (int j = 1; j <= n; j ++)
	{
		int distNums = 0;
		for (int first = 1; first <= n; first++)
		{
			for (int second = first; second <= n; second++)
			{
				int sumOfCubes = cube(first) + cube(second);
				//cout << "" << first << " " << second << " " << sumOfCubes << endl; //TESTING
				if (sumOfCubes == j)
				{
					cout << "n = " << first <<"^3 + " << second << "^3" <<endl;
					distNums++;
				}
			}
		}	
		
		if (distNums != 0)
		{
			cout << "n: " << j <<endl;
			cout << "Distinct combinations: " << distNums << endl;
			cout << endl << endl;
		}
		
	}
	return 0;
}
