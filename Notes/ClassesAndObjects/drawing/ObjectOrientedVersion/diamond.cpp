#include "diamond.h"
#include <iostream>
using namespace std;

Diamond::Diamond(int the_size)
{
	cout << "Diamonds are forever." << endl;
	size = the_size;
}

void Diamond::draw()
{
	for (int i = 0; i < len -1; i++)
	{
		cout << " ";
	}
	cout << "*\n";
	
	for (int i = 0; i < len -1; i++)
	{
		for (int q = len - 2 -i ; q > 0; q--)
		{
			cout << " ";
		}
		cout << "*";
		
		int j = (((i+1)*2)-1);
		for (int k = 0; k < j; k++)
		{
			cout << " ";
		}
		cout << "*\n";
	}
	// end top half + middle
	
	
	int s = 2*len -3;
	
	for (int i = 0; i < len -2; i++)
	{
		//bottom left 
		for (int j = 0; j < i+1; j++)
		{
			cout << " ";
		}
		cout << "*";
		//end bottom left 
		
		int k = s -2*(i+1);
		
		for (int q = 0; q < k; q++)
		{
			cout << " ";
		}
		cout << "*\n";
	}

	
	//bottom tip 
	for (int i = 0; i < len -1; i++)
	{
		cout << " ";
	}
	cout << "*\n";
	
}

void Diamond::doubleInSize()
{
	size*=2;
}