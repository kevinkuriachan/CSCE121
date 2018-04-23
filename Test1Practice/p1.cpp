#include <iostream>
using namespace std;

int getListOfCommon(int list1[], int p, int list2[], int q, int out[], int outcap)
{
	int i = 0; int j = 0; int k = 0;
	while (i < p && j < q)
	{
		if (k >= outcap) return k;
		if (list1[i] == list2[j]) 
		{
			if (k < outcap) 
			{ 
				out[k] = list1[i]; 
				i++; j++; k++;
			}
			else return k;
		}
		if (list1[i] < list2[j]) i++;
		if (list2[j] < list1[i]) j++;
	}
	return k;
}

void printList(int list[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << list[i] << endl;
	}
}

int main()
{
	int outcap = 4;
	int out[outcap];
	int list1[] = {1,5,7,9,12}; int p = 5;
	int list2[] = {1,3,4,5,6,7,8}; int q = 7;
	int size = getListOfCommon(list1, p, list2, q, out, outcap);
	printList(out, size);

	return 0;
}