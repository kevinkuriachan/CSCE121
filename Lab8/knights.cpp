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
	return (person->cameWith->cameWith == person);
}

bool checkAllGuestsSymmetric(partyGoer_p person)
{
	assert(person != NULL);
	assert(atARoundTable(person));
	partyGoer_p next = person;	

	do {
		if (next!= NULL && next->cameWith != NULL)
		{
			if (!checkGuestSymmetric(next)) return false;
		}
		next = next->sittingToLeft;

	} while (next != person);

	return true;
}

void removePerson(partyGoer_p p)
{
	assert(p != NULL);
	partyGoer_p current = p;
	while (current->sittingToLeft != p)
	{
		current = current-> sittingToLeft;
	}
	// now current is the person to the right of 
	// person to be removed
	current->sittingToLeft = current->sittingToLeft->sittingToLeft;
}

partyGoer_p lastManSeated(partyGoer_p starter, int n)
{
	assert(starter != NULL);
	assert(atARoundTable(starter));
	partyGoer_p current = starter;
	while (current->sittingToLeft != current)
	{ // loop until one person remains
		for (int i = n; i > 0; i--)
		{
			current = current -> sittingToLeft;
		}
		removePerson(current);
		//if (current->sittingToLeft == current) break;
	}
	return current;
}

int main()
{
	partyGoer_t kay = {"Kay", NULL, NULL};
	partyGoer_t bors = {"Bors the Younger", NULL, &kay};
	partyGoer_t lamorak = {"Lamorak", NULL, &bors};
	partyGoer_t gawain = {"Gawain", NULL, &lamorak};
	partyGoer_t percival = {"Percival", NULL, &gawain};
	partyGoer_t geraint = {"Geraint", NULL, &percival};
	partyGoer_t lancelot = {"Lancelot", NULL, &geraint};
	partyGoer_t arthur = {"Arthur", NULL, &lancelot};
	kay.sittingToLeft = &arthur;

	printRoundTable(&arthur);

	lancelot.cameWith = &arthur;
	arthur.cameWith = &lancelot;
	geraint.cameWith = &lamorak;
	lamorak.cameWith = &geraint;

	partyGoer_p lastMan = NULL;

	lastMan = lastManSeated(&lancelot, 5);

	cout << endl;
	printName(lastMan);
	cout << "gets the bill" << endl;
	return 0;
}