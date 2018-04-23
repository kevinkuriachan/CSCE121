#include <iostream>
#include <assert.h>
using namespace std;

#define STRLEN 200

struct partyGoer_t; 

typedef struct partyGoer_t * partyGoer_p;

struct partyGoer_t {
	char name[STRLEN];
	partyGoer_p cameWith;
	partyGoer_p sittingToLeft;
};

bool atARoundTable(partyGoer_p p)
{
	assert(p != NULL);
	partyGoer_p next = p;

	do {
		if (next == NULL) return false;
		next = next->sittingToLeft;
	} while ( next != p);

	return true; 
}

void printName(partyGoer_p person)
{
	assert(person != NULL);
	char *name = person->name;
	int i = 0;
	while (name[i] != '\0')
	{
		cout << name[i];
		i++;
	}
	cout << endl;
}

void printRoundTable(partyGoer_p person)
{
	assert(person != NULL);
	assert(atARoundTable(person));
	cout << "From " << person->name << " to the left:" << endl;

	partyGoer_p next = person;
	cout << endl;
	do {
		printName(next);
		next = next->sittingToLeft;
	} while (next != person);
	cout << endl << "...and back to " << person->name << endl;
}

bool checkGuestSymmetric(partyGoer_p person)
{
	assert(person != NULL);
	assert(person->cameWith != NULL);
	// /*
	cout << "(insideCheck: ";
	printName(person);
	cout << " came with ";
	printName(person->cameWith);
	cout << "who came with " ;
	printName(person->cameWith->cameWith);
	cout << (person->cameWith->cameWith == person) << endl; 
	// */
	return (person->cameWith->cameWith == person);
}

bool checkAllGuestsSymmetric(partyGoer_p person)
{
	assert(person != NULL);
	assert(atARoundTable(person));
	partyGoer_p next = person;	

	do {
		cout << "CheckingALL: "; printName(next);
		if (next!= NULL && next->cameWith != NULL)
		{
			if (!checkGuestSymmetric(next)) return false;
		}
		next = next->sittingToLeft;

	} while (next != person);

	return true;
}

int main()
{

	partyGoer_t test1[] = {
        {"Arthur", &test1[1], &test1[1]},
        {"Lancelot", &test1[0], &test1[3]},
        {"Gawain", NULL, &test1[6]},
        {"Geraint", &test1[6], &test1[4]},
        {"Percival", NULL, &test1[2]},
        {"Bors the Younger", NULL, &test1[7]},
        {"Lamorak", &test1[3], &test1[5]},
        {"Kay", NULL, NULL},
        };

    if (checkAllGuestsSymmetric(test1))
        cout << "All came in pairs" << endl; 
    else
        cout << "Not all came_with are in pairs" << endl;

	return 0;
}