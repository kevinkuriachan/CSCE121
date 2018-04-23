#include <iostream>
#include <assert.h> 
using namespace std;

#define MAXSTR 200

struct person_t; // we put forward declaration since 
typedef person_t *  person_p;

struct person_t 
{
	char name[MAXSTR];
	int age;
	bool alive;
	// we can define relationships between objects 
	person_p my_mother;  
	person_p my_father; 
};



void print_person(person_t pers)
{
	cout << "Name: " << pers.name << endl;
	cout << "Age: " << pers.age << endl;
	if (pers.alive)
		cout << "Alive and well" << endl;
	else
		cout << "Deceased" << endl;
	cout << endl;
}

void print_person_from_pointer(person_p ptr)
{ 
	// we have to dereference when we pass pointers 

	// we should make sure pointers are valid 

	assert(ptr != NULL); // ensures this condition is met before continuing; else quits program 

	cout << "Name: " << ptr->name << endl; // ptr->field := (*ptr).field
	cout << "Age: " << ptr->age << endl;
	// ptr->age = -1; If we change ptr, this changes the underlying person_t
	if (ptr->alive)
		cout << "Alive and well" << endl;
	else
		cout << "Deceased" << endl;

	if (ptr->my_mother != NULL)
		cout << "Has a my_mother" << endl;
	if (ptr->my_father != NULL)
		cout << "Has a father" << endl;
	cout << endl;

}

void print_person_reference(person_t &r)
{ // these references are implicit pointers and are automatically dereferenced 
	// this passes mem address rather than a whole struct 

	cout << "Name: " << r.name << endl;
	cout << "Age: " << r.age << endl;

	if (r.alive)
		cout << "Alive and well" << endl;
	else
		cout << "Deceased" << endl;
	cout << endl;

}

bool person_has_grandma(person_p p)
{// returns true iff p has mother of mother, or mother of father 
	assert( p!= NULL)

	if ((*p).my_mother != NULL)
	{
		person_p q = (*p).my_mother;
		if ((*q).my_mother != NULL) return true;
	}
	if (p->my_father != NULL)
	{
		person_p q = p->my_father;
		if (q->my_mother != NULL) return true;
	}
	return false; 
	// I used *pointer.info and pointer->info interchangably to show they are the same 
}


// a better way to check for grandma

bool person_has_mother(person_p p)
{
	assert (p != NULL);
	return (p->my_mother != NULL);
}

bool person_has_father(person_p p)
{
	assert (p != NULL);
	return (p->my_father != NULL);
}

bool hasGrandma2(person_p p)
{
	if (person_has_mother(p))
	{
		if(person_has_mother(p->my_mother)) return true;
	}
	if (person_has_father(p))
	{
		if(person_has_mother(p->my_father)) return true;
	}
}

int main()
{
	person_t peeps[] = {{"Bob", 10, true, NULL, NULL}, {"Alice", 35, true, NULL, NULL}, {"Cat", 65, false, NULL, NULL}, {"Dorothy", 105, true, NULL, NULL}};

	peeps[0].my_mother = &peeps[1];
	peeps[1].my_mother = &peeps[2];
	peeps[2].my_mother = &peeps[3];

	person_t *best_friend = NULL; // trying to dereference will cause seg fault 
	
	print_person(peeps[1]);
	print_person_from_pointer(&(peeps[1])); // print person from pointer requires a pointer so we pass mem address with &

	print_person_from_pointer(&(peeps[0]));

	print_person_from_pointer(peeps); // prints bob
	// this works because arrays are just references to the first element in it.
							// this is also why we cannot know the size of an array; we are only told the location of its first element 

	best_friend = &(peeps[0]);

	print_person_from_pointer(best_friend); // will print bob now 

	print_person_reference(*best_friend); // this requires a person_t so we just dereference pointers. 

	return 0;
}


// pointers are like arrows. We use * to get to the end of the arrow (dereferencing)

// there is no pass by reference in C so it uses pointers only 