#include <iostream>
using namespace std;

#define MAXSUIT 9

struct card_t{
	char suit[MAXSUIT];
	int value; // 1 is ace, 11 jack, 12 queen, 13 king
};

bool isFace(card_t card)
{
	return (card.value > 10 || card.value ==1);
}

void sort(int list[], int n)
{
	int tmp;
	for (int i = 0; i < n-1; i++)
	{
		if (list[i] > list[i+1])
		{
			tmp = list[i];
			list[i+1] = list[i];
			list[i] = tmp;
		}
	}
}

bool isSequence(card_t cards[], int n)
{
	int values[n];
	for (int i = 0; i < n; i++)
	{
		values[i] = cards[i].value;
	}
	sort(values, n);
	for (int i = 0; i < n-1; i++)
	{
		if (values[i] == 1) // if king
		{
			if ( values[i+1] != 13 )
			{
				return false; 	
			} 
		}
		else if (values[i+1] != values[i]+1) 
		{
			return false; 	
		} 
	}
	return true; 
}

int getLenChars(char str[])
{ // returns number of characters in a string 
	int i = 0;
	int len = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}

bool sameString(char first[], char second[])
{ // return true iff two strings are identical, character for character 

    int firstLen = getLenChars(first);
    int secondLen = getLenChars(second);

    if (firstLen != secondLen) return false;
    for (int i = 0; i < firstLen; i++)
    {
    	if (first[i] != second[i]) return false;
    }
    return true;
}

bool sameSuit(card_t cards[], int n)
{
	char testSuit[MAXSUIT];
	int i = 0;
	int lenTestSuit = getLenChars(cards[0].suit);
	for (int i = 0; i < lenTestSuit; i++)
	{
		testSuit[i] = cards[0].suit[i];
	}
	testSuit[lenTestSuit] = '\0';
	for (int i = 0; i< n; i++)
	{
		if (!sameString(cards[i].suit, testSuit))
		{
			return false; 	
		} 
	}
	return true; 
}

bool isFlush(card_t cards[], int n)
{
	return (sameSuit(cards, n) && !isSequence(cards, n));
}

int main()
{
	card_t cards[3] = { {"Club", 1}, {"Club", 13}, {"Heart", 5}};
	cout << isFlush(cards, 3) << endl;
	return 0;
}