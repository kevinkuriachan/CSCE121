#include <iostream>
#include <string>
#include <assert.h>
#include "sets.h"
using namespace std;

struct str_t {
	string word;
	str_t * next;
};

struct set_of_str_t {
	str_t * head;
}; 

set_of_str_t * create_set_of_str()
{
	set_of_str_t * set = new set_of_str_t;
	assert(set!=NULL); // something went wrong
	set->head = NULL;
	return set;
}

void print_list(set_of_str_t * list)
{
	str_t * walker = list->head;
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
	str_t * walker = list->head;
	while (walker != NULL)
	{
		if (walker->word == element) return true;
		walker = walker->next;
	}
	return false;
}


void add_item(set_of_str_t * &list, string toAdd)
{
	//set_of_str_t * hold = list;
	assert(list!=NULL);
	str_t * newElement = new str_t;
	newElement->word = toAdd;
	newElement->next = list->head;
	list->head = newElement;
}

void del_item(set_of_str_t * &list, string toDelete)
{
	if (list == NULL) return;
	if (!contains_item(list, toDelete)) return;
	str_t * walker = list->head; 
	str_t * prev = walker;
	while(walker!= NULL)
	{
		if (walker->word == toDelete)
		{ // if current element is the one to delete
			if (walker == list->head)
			{ // to delete first element 
				list->head = walker->next;
				delete walker;
				walker = list->head;
			}
			else if (walker->next == NULL)
			{ // to delete last element 
				prev->next = NULL;
				delete walker;
			}
			else 
			{ // delete any elements in between first and last
				prev->next = walker->next;
				delete walker;
				walker = prev->next;
			}
		}
		else 
		{ // if nothing is removed
			prev = walker;
			walker = walker-> next;
		}
	}
}

set_of_str_t * union_(set_of_str_t* listA, set_of_str_t* listB)
{
	set_of_str_t * both = create_set_of_str();
	str_t * walkerA = listA->head;
	str_t * walkerB = listB->head;
	if (is_empty(listA) && is_empty(listB)) return both;
	while (walkerA!=NULL)
	{
		add_item(both, walkerA->word);
		walkerA = walkerA->next;
	}
		while (walkerB!=NULL)
	{
		add_item(both, walkerB->word);
		walkerA = walkerB->next;
	}
	return both;
}

set_of_str_t * intersection(set_of_str_t * listA, set_of_str_t *listB)
{
	set_of_str_t * cross = create_set_of_str();
	str_t * walkerA = listA->head;
	if (is_empty(listA) || is_empty(listB)) return cross;
	while (walkerA != NULL)
	{
		if (contains_item(listB, walkerA->word) && !contains_item(cross, walkerA->word))
		{
			add_item(cross, walkerA->word);
		}
		walkerA = walkerA->next;
	}
	return cross;
}

bool is_empty(set_of_str_t* list)
{
	return (list == NULL);
}


void destroy_set_of_str(set_of_str_t * &list)
{
	str_t * walker = list->head;
	while (walker!=NULL)
	{
		str_t * hold = walker->next;
		delete walker;
		walker = hold;
	}
	list->head = NULL;
	delete list;
}

