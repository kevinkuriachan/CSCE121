#include <iostream>
using namespace std;
#define MAX_LIST_SIZE 200


void sortList(int list[], int len)
{
	int swaps = 1;
	while (swaps > 0)	
	{
		swaps = 0;
		for(int i = 0; i < len-1; i++)
		{
			if (list[i] > list[i+1])
			{
				int tmp = list[i];
				list[i] = list[i+1];
				list[i+1] = tmp;
				swaps++;
			}
		}
	}
}


bool numInList(int n, int list[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (list[i] ==  n) return true;
	}
	return false;
}

int abs(int n)
{
	if (n<0) return (-1*n);
	return n;
}

int countPos(int list[], int len)
{
	int posNums = 0;
	for (int i = 0; i < len; i++)
	{
		if (list[i] > 0) posNums++;
	}
	return posNums;
}

int countNeg(int list[], int len)
{
	int negNums = 0;
	for (int i = 0; i < len; i++)
	{
		if (list[i] < 0) negNums++;
	}
	return negNums;
}

void seperateSigns(int list[], int len; int posList[], int posNums, int negList[], int negNums)

int main()
{
	int elements;
	cout << "number of elements: ";
	cin >> elements;
	int list[elements];
	for (int i = 0; i < elements; i++)
	{
		cin >> list[i];
	}
	sortList(list, elements);
	int negNums = countNeg(list, elements);
	int posNums = countPos(list, elements);
	int posList[posNums];
	int negList[negNums];

	return 0;
}
