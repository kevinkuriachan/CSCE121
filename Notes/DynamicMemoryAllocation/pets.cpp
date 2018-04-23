#include <iostream>
using namespace std;

#define STRMAX 200

enum species_t {
	dog,	// given the value 0
	cat,	// given value 1
	parrot, // given value 2
	horse	// given value 3
};

struct pet_t {
	char name[STRMAX];
	int age;
	species_t type;
};

void printPet(pet_t *pet)
{
	assert(pet != NULL);
	cout << "----------------------" << endl;
	cout << "Name: " << pet->name << endl;
	cout << "Age: " << pet->age << endl;
	cout << "Type: " << pet->type << endl;
	cout << "----------------------" << endl; 
}

const char *nameOfSpecies(species_t s)
{
	switch (s) {
		case dog: return "dog";
		case cat: return "cat";
		case horse: return "horse";
		case parrot: return "parrot";
	}
}

species_t readInSpecies()
{
	char c;
	while (true)
	{
		cin >> c;
		switch (c) {
			case 'd': 
			case 'D': return dog;
			case 'c':
			case 'C': return cat;
			case 'h':
			case 'H': return horse;
			case 'p':
			case 'P': return parrot;
		}
	}
}

pet_t* getAllPetsFromInput(int n)
{
	pet_t *pets = new pets_t[n]; 

	// if the operating system is unable to allocate the needed memory, it will return a null pointer 

	for (int i = 0; i < n; i++)
	{
		cout << "What is pet #" << i+1 << "'s name? ";
		cin >> pets[i].name;

		cout << "What is " << pets[i].name << "? " ;
		pets[i].type = nameOfSpecies();

		cout << "What is " << pets[i].name << "'s age? " ;
		cin >> pets[i].age;
	}

	return pets;
}

int main(int argc, char **argv)
{
	int n;

	cout << "How many pets do you have? " ;
	cin > n;

	pet_t *allPets = getAllPetsFromInput(n);

	for (int i = 0; i < n; i++)
	{
		printPet(allPets[i]);
	}

	// [a] no longer interested in my pets.
	delete[] allPets; // we have to say delete array because allPets refers to the first element
					  // so we have to say delete the whole array

	cout << "How many pets does your brother have? " ;
	cin >> n;
	allPets = getAllPetsFromInput(n); // what happens here?? (without line [a])
	// first set of pets still exists in memory (in the heap)
	// but now it is lost to use because we have nothing referring to it now.
	// this is called a memory leak because the memory is used and cannot be written over of found 
	// so what we should do is return the memory back to the system; see line [a]

	return 0;
}

/*

0000    [ .text ]
data {	[ .data ]
	 {  [ .bss  ]
		[ heap  ]  <- we will learn how to create variables here so the mem address is valid after 
		[   |   ]     functions return 
		[   V   ]
		---------
		[       ]
		[       ]
		[   ^   ]
		[   |   ]
FFFF 	[ stack ]


	int v = 10; // the memory address associated with v is preserved
				// from here onwards

	while (false)
	{
		int v = 100; // now there is 
	}

*/

// there are some languages with what are called 'garbage collectors' which will
// clear up memory without pointers pointing to it anymore 