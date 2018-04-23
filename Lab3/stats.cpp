#include <iostream>
using namespace std;

void orderPair(int &x, int &y)
{ 
	if (x > y) 
	{
		int temp = x;
		x = y;
		y = temp; 
	}
}

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void threeInARow( int &x, int &y, int &z) 
{
	orderPair(x, y);
	orderPair(y, z); 
	orderPair(x, y);
}

void dec_list(int input[], int num)
{ // Takes input, a list with num entries, orders it by decreasing elements.
  // Alters input so that the entries are in reverse order
	
	for (int j = 0; j < num; j++ )
	{
		for ( int i = 0; i < num -2; i++) 
		{
			threeInARow(input[i+2], input[i+1], input[i]);
		}
	}
}

void asc_list(int input[], int num)
{ // Takes input, a list with num entries, orders it by increasing elements.
  // Alters input so that the entries are in reverse order
	
	for (int j = 0; j < num; j++ )
	{
		for ( int i = 0; i < num -2; i++) 
		{
			threeInARow(input[i], input[i+1], input[i+2]);
		}
	}
}

void rev_list(int input[], int num)
{
	for (int i = 0; i < num/2; i++)
	{
		swap(input[i], input[num-1-i]);
	}
}

/*
float mode(char list[], int n)
{
	char most = list[0];
}
*/

int count(char list[], int n, char c)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (list[i] == c ) num++;
	}
	return num;
}

char mode(char list[], int n)
{
	char most = 'a';
	int countMost = 0;
	for (int i = 0; i < n; i++ )
	{
		if (count(list, n, list[i]) > countMost)
		{
			most = list[i];
			countMost = count(list, n, list[i]);
		}
	}
	return most; 
}

int main() 
{

	int num = 14;
	int list[14] = {4, 3, 2, 1, 12, 8, 57, 17, 23, 74, 89, 35, 21, 19};
	rev_list(list, 14);
	for (int i =0; i < num; i++)
	{
		cout << list[i] << endl; 
	}
	char chars[14] = {"4", "3", "2", "1", "12", "8", "57", "17", "23", "74", "89", "35", "8", "8"};
	cout << "mode: " << mode(chars, num) << endl;
	
}






