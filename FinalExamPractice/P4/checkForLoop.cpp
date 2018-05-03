/*
cannot create an array of visited values because we dont know size.
cannot go through list to find size because there might be a loop.
*/

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

struct item_t;

struct item_t {
	string str;
	item_t * next;
};

struct location_t; 

struct location_t {
	item_t * item;
	location_t * next;
};

bool inList(location_t * head, item_t * check)
{
	location_t * walker = head;
	while(walker != NULL)
	{
		if (walker->item == check) return true;
		walker = walker->next;
	}
	return false;
}

void addToList(item_t * toAdd, location_t * &head)
{
	if (head == NULL)
	{
		head = new location_t;
		head->item = toAdd;
		head->next = NULL;
	}
	else 
	{
		location_t * hold = new location_t;
		hold->item = toAdd;
		hold->next = NULL;
		location_t * walker = head;
		while (walker->next != NULL)
		{
			walker=walker->next;
		} 
		//at this point, walker is last element 
		walker->next = hold;
	}
}

void deleteLocations(location_t * head)
{
	location_t * walker = head;
	while (walker!=NULL)
	{
		location_t * hold = walker->next;
		delete walker;
		walker = hold;
	}
}

bool hasLoop(item_t * head)
{
	item_t * walker = head;
	location_t * locations = new location_t;
	locations->item = NULL;
	locations->next = NULL;
	while (walker != NULL)
	{
		if (inList(locations, walker)) 
		{
			deleteLocations(locations);
			return true;
		}
		addToList(walker, locations);
		walker = walker->next;
	}
	deleteLocations(locations);
	return false;	
}

int main()
{
	item_t * A = new item_t;
	item_t * B = new item_t;
	item_t * C = new item_t;
	item_t * D = new item_t;
	A->str = "A";
	B->str = "B";
	C->str = "C";
	D->str = "D";
	A->next = B; B->next = C; C->next = D; D->next = C;
	cout << hasLoop(A) << endl;

	delete A;
	delete B;
	delete C;
	delete D;

	return 0;
}