#include <iostream>
using namespace std;

int main()
{
	int size = -1;

	while (size <= 0)
	{
		cout << "A number please: ";
		cin >> size;
	}

	cout << endl;

	int arms = size -1;

	for (int k = 0; k < arms*2 +1; k++)
	{
		if (k == arms)
		{
			for (int i = 0; i < arms*2+1; i++)
			{
				if (i == (arms))
				{
					cout << "+";
				}
				else
				{
					cout << "-";
				}
			}
			cout << endl;
		}
		else
		{

				for (int i = 0; i < arms; i++)
				{
					cout << " ";
				}
				cout << "|";
				cout << endl;

		}
	}



}
