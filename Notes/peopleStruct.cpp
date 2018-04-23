#include <iostream>
#include <assert.h> 
using namespace std;

#define MAXSTR 200

struct person_t 
{
	char name[MAXSTR];
	int age;
	bool alive;
};


// defines a custom type for pointers:
typedef person_t *  person_p;

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


int main()
{
	person_t peeps[3] = {{"Bob", 10, true}, {"Alice", 15, true}, {"Gertrude", 105, false}};

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