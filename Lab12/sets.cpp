#include <iostream>
#include <string>
#include <assert.h>
#include "sets.h"
using namespace std;

struct set_of_str_t {
	string word;
	set_of_str_t * next;
}; 

set_of_str_t * create_set_of_str()
{
	set_of_str_t * set = new set_of_str_t;
	assert(set!=NULL); // something went wrong
	set->word = "";
	set->next = NULL;
	return set;
}

void print_list(set_of_str_t * list)
{
	set_of_str_t * walker = list;
	while (walker!=NULL)
	{
		string toPrint = walker->word;
		cout << toPrint << endl;
		walker = walker->next;
	}
}

bool contains_item(set_of_str_t * list, string element)
{
	if (list == NULL) return false;
	set_of_str_t * walker = list;
	while (walker != NULL)
	{
		if (walker->word == element) return true;
		walker = walker->next;
	}
	return false;
}
//&
void add_item(set_of_str_t * &list, string toAdd)
{
	//set_of_str_t * hold = list;
	set_of_str_t * newElement = new set_of_str_t;
	newElement->word = toAdd;
	newElement->next = list;
	list = NULL;
}

void del_item(set_of_str_t * &list, string toDelete)
{
	if (list == NULL) return;
	if (!contains_item(list, toDelete)) return;

}

set_of_str_t * union_(set_of_str_t* listA, set_of_str_t* listB)
{
	set_of_str_t * cross = new set_of_str_t;
}

set_of_str_t * intersection(set_of_str_t * listA, set_of_str_t *listB)
{
	//
}

bool is_empty(set_of_str_t* list)
{
	return (list == NULL);
}

//&
void destroy_set_of_str(set_of_str_t * &list)
{
	set_of_str_t * walker = list;
	while (walker!=NULL)
	{
		set_of_str_t * hold = walker->next;
		delete walker;
		walker = hold;
	}
	list = NULL;
}

