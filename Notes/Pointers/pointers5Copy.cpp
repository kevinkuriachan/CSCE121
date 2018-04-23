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
	personT peeps[3] = {{"Bob", 13, true}, {"Alive", 15, true}, {"Cat", 105, false}};
	printPerson(&(peeps[0]));
	return 0;
}