#include <iostream>
using namespace std;
#define MAX_STR 200

struct personT{
	char name[MAX_STR];
	int age;
	bool alive;
};

typedef personT *personPointer; // we can redefine how we declare a pointer 

void printPerson(personPointer p) // we can use a pointer here so the whole struct is not copied to pass into the function 
{ //^  same as: void printPerson(personT *p)
	cout << "Name: " << (*p).name << endl;
	// (*p).name is so common that there is notation for it: p->name 
	cout << "Age: " << p->age << endl;

	if ((*p).alive) cout << "Alive" << endl;
	else cout << "Deceased" << endl;
	cout << endl;
}

void birthday(personT *person)
{ //increments the age of the person 
	person->age++;

}

int main()
{
	personT p1 = {"Bob", 13. true};
	personT p2 = {"Alice", 15, true};
	personT p3 = {"Cat", 105, false};

	printPerson(p1);
	printPerson(p2);
	printPerson(p3);

	personT* bff; // (person*) bff // a new pointer of type person is created 
	bff = &p2;

	cout << "My best friend: " << endl;
	printPerson(*bff);

	return 0;
}

/*
why use pointers:

to manipulate memory but you don't know how much mem;
creating a chain of references;
using multiple names of for the same thing ;

*/