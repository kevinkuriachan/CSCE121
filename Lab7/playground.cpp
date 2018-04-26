#include <iostream>
using namespace std;

struct sequenceT{
	int elements;
	int list[7];
};

void sortSequence(sequenceT &seq)
{
	int len = seq.elements;
	int swaps = 1;
	while (swaps > 0)	
	{
		swaps = 0;
		for(int i = 0; i < len-1; i++)
		{
			if (seq.list[i] > seq.list[i+1])
			{
				int tmp = seq.list[i];
				seq.list[i] = seq.list[i+1];
				seq.list[i+1] = tmp;
				swaps++;
			}
		}
	}
}



int main()
{
	int n = 7;
	sequenceT seq = {7,{3,2,7,1,8,4,6}};
	sortSequence(seq);
	int len = seq.elements;
	for (int i = 0; i < len; i++)
	{
		cout << seq.list[i] << endl;
	}
	return 0;
}
