#include <iostream>
using namespace std;

struct word_t;

struct word_t {
	char *str; // a pointer to the string data
	word_t *next;
};

int end_of_word(char s[], int b)
{
	int i = b;
	while (s[i] != " " && s[i] != '\0')
	{
		i++;
	}
	return i;
}

word_t * split(char str[])
{ // returns the head of a linked list

}

void clean_up(word_t * head)
{

}

void print_list(word_t * head)
{
	word_t * walker = head;
	while (walker != NULL)
	{
		cout << walker->str << " " ;
		walker = walker->next;
	}
	cout << endl;
}

int main()
{


	return 0;
}