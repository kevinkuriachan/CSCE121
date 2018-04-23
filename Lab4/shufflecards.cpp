#include <iostream>
using namespace std;

string num[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
string spade = "\u2660";
string heart = "\u2665";
string diamond = "\u2666";
string club = "\u2663";
string suit[4] = {spade, heart, diamond, club};
string cards[52];

void generateCards(string cards[])
{
	for (int i = 0; i < 13; i++)
	{
		cards[i] += spade;
		cards[i+13] += heart;
		cards[i+(13*2)] += diamond;
		cards[i+(13*3)] += club;

	}
	for (int i = 0; i < 52; i += 13)
	{
		for (int j = 0; j < 13; j++)
		{
			cards[i+j] += num[j];
		}
	}
}

void shuffle(string cards[52])
{
	string top[26];
	string bottom[26];
	for (int i = 0; i < 26; i++)
	{
		top[i] = cards[i];
		bottom[i] = cards[i+26];
	}
	for (int i = 0, j=0; i < 52-1; i+=2,j++) 
	{
		cards[i] = bottom[j];
		cards[i+1] = top[j];
	}
}

int main()
{
	generateCards(cards);
	cout << "unshuffled " << endl;
	for (int i =0; i < 52; i++)
	{
		cout << cards[i] << endl;
	}
	cout << endl << "shuffled: " << endl;
	
	for (int i = 0; i < 8; i++)
	{
		shuffle(cards);
	}

	for(int i = 0; i < 52; i++)
	{
		cout << cards[i] << endl;
	}
	return 0;
}
