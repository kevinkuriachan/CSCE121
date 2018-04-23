#include <iostream>
using namespace std;

float CtoF(float cel)
{
	return ((cel*(9.0/5.0))+32.0);
}

float FtoC(float fer)
{
	return ((fer - 32.0) *(5.0/9.0) );
}

void toUpper(char &unit)
{
	if ( unit >= 'a')
	{
		unit = unit - 32;
	}
	
}

int main()
{
	float temp;
	char unit;
	
	bool invalid = true;
	
	cout << "Please enter a temperature: " ;
	cin >> temp; //cout << endl;
	
	while (invalid)
	{
		cout << "Is that in Fahrenheit or Celsius? [F/C] ";
		cin >> unit; // cout << endl;
		toUpper(unit);
		if ((unit == 'F') || (unit == 'C'))
		{
			invalid = false;
		}
		
	}
	
	//cout << "Is that in Fahrenheit or Celsius? [F/C] ";
	//cin >> unit; cout << endl;
	
	//toUpper(unit);
	
	float output;
	char outUnit;
	
	if (unit == 'F')
	{
		output = FtoC(temp);
		outUnit = 'C';
	}
	else
	{
		output = CtoF(temp);
		outUnit = 'F';
	}

	cout << "Well, "<< temp << unit << " is " << output << outUnit << "." << endl;
	
	return 0;
}
