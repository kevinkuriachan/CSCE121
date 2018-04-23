#include <iostream>
#include <fstream>
#include <sstream> // This defines something like cin, but set up to be a given string
#include <string>
#include <assert.h>
using namespace std;

struct animal_t {
    string desc; // A description of the animal
    int age; // Age of the animal
    bool is_nocturnal; // True is the animal is nocturnal

    animal_t *prev; // Pointer to previous animal in the list
    animal_t *next; // Pointer to the next animal in the list
};

struct facility_t {
    string name; // Name of the facility

    int animal_count; // A count of the elements in the linked list
    animal_t *head; // Head of the doubly-linked list
    animal_t *tail; // Tail of the doubly-linked list
};


// Forward declarations:
void add_animal_to_facility_head(facility_t *facility, animal_t *ani);

void print_animal(animal_t *ani)
{ /*
        This function prints the details of the animal pointed to by the
        argument.
    */
    
    assert(ani != NULL);

    cout << ani->desc;
    cout << " is " << ani->age << " years old";
    if (ani->is_nocturnal)
        cout << " and is nocturnal." << endl;
    else
        cout << " and isn't nocturnal." << endl;
}

void add_new_animal_to_inventory(facility_t *facility, string desc, int age, bool noct)
{
    /* 
        This function will allocate new memory to create a new animal,
        and add it to the given facility.
     */
    
    assert(facility != NULL);

    animal_t *newcomer = new animal_t;
    assert(newcomer != NULL);

    newcomer->desc = desc; // This will copy the string's details for us
    newcomer->age = age; 
    newcomer->is_nocturnal = noct; 

    newcomer->prev = NULL; // Initialize the linked list pointers not to point to anything
    newcomer->next = NULL;

    add_animal_to_facility_head(facility, newcomer);
}

void add_animal_to_facility_head(facility_t *facility, animal_t *ani)
{
    /* 
        Given an animal and a facility, adds the animal to the head
        of the list associated with the facility.
     */

    assert(facility != NULL);
    assert(ani != NULL);

    ani->prev = NULL;
    ani->next = facility->head;
    if (facility->head != NULL) {
        // Linked list is empty
        assert(facility->tail != NULL);      // If this fails, the list is in some inconsistent state
        assert(facility->animal_count != 0); // If this fails, the list is in some inconsistent state

        facility->head->prev = ani;
        facility->head = ani;
    } else {
        assert(facility->tail == NULL);      // If this fails, the list is in some inconsistent state
        assert(facility->animal_count == 0); // If this fails, the list is in some inconsistent state

        facility->head = ani;
        facility->tail = ani;
    }

    facility->animal_count++;
}

void print_facility_inventory(facility_t *facility)
{
    /*
        Print out all the animals associated with a facility
     */

    assert(facility != NULL);

    animal_t *a = facility->head;
    while (a != NULL) {
        cout << "\t";
        print_animal(a);
        a = a->next;
    }

    cout << endl;
}

void print_facility_summary(facility_t *f)
{
    /* 
        Produces a "pretty" display of a given facility 
     */
    assert(f != NULL);

    cout << "================================================================" << endl;
    cout << f->name << endl;
    print_facility_inventory(f);
    cout << "================================================================" << endl;
}

animal_t * find_animal(facility_t *facility, string name)
{    
    /* 
        Searches through the given facility's inventory to try find an
        animal with a matching name.

        Function returns a pointer to the animal is one is found,
            or NULL otherwise.
     */
    assert(facility != NULL);

    animal_t *a = facility->head;
    while (a != NULL) {
        if (a->desc == name)
                return a;
        a = a->next;
    }

    return NULL;
}

void initialize_facility(facility_t *facility, string name)
{
    assert(facility != NULL);

    facility->name = name;  // When you use the assignment operator on strings, 
    // they copy the data over, unlike char[]'s

    facility->head = NULL; // Initialize the linked list to be empty
    facility->tail = NULL;      //  ditto
    facility->animal_count = 0; // ditto
}

facility_t *create_facility(string name, string file_to_load_from)
{
    facility_t *new_fac = NULL;

    ifstream infile;

    // Open the file
    infile.open(file_to_load_from, ios_base::in);
    
    if (!infile) {
        cerr << "Couldn't open '" << file_to_load_from << "', for reading." << endl;
        exit(1);
    }

    new_fac = new facility_t;

    initialize_facility(new_fac, name); // Set up the facility details, using the string in name

    string line;

    // Read in the file
    while (getline(infile, line)) {
        //cout << "Got line '" << line << "'" << endl;
        stringstream ss(line); // string stream is a handy way to get a string to allow us
        // to use the >> operator to pull of the words
        string desc;
        int age;
        string str_noct;
        ss >> desc >> age >> str_noct;
        bool noct;
        if (str_noct == "yes") { // The comparison operator checks whether the string is the same, character by character
            noct = true;
        } else if (str_noct == "no") {
            noct = false;
        } else {
            cerr << "File '" << file_to_load_from << "' has an unexpected format. The string '" << str_noct << "' isn't understood." << endl;
            exit(1);
        }
        //cout << "Split as: [" << desc << "] [" << age << "] [" << noct << "]" << endl;
        add_new_animal_to_inventory(new_fac, desc, age, noct);
    }

    // Close this file
    infile.close();

    return new_fac;
}

animal_t * unlink_from_inventory(animal_t * animal, facility_t * facility)
{
	// after this call, the animal_t should exist 
	// but no longer be part of the doubly linked list.
	assert(animal!=NULL);
	animal_t * previous = animal->prev;
	animal_t * next = animal->next; 
	animal_t * output = animal;
	if (next!=NULL && previous!=NULL)
	{
		next->prev = previous;
		previous->next = next;
	}
	if (next == NULL && previous != NULL)
	{ // if animal is last in facility
		previous->next = NULL;
		facility->tail = previous;
	}
	if (previous == NULL && next!= NULL)
	{ // if animal is first in facility 
		facility->head = next;
		next->prev = NULL;
	}
	output->next = NULL;
	output->prev = NULL;
	facility->animal_count--;
	return output;
}


void free_animal_mem(animal_t * &animal, facility_t* facility)
{
  // After this call, no more memory is associated with the given animal_t
	assert(animal!=NULL);
	assert(facility!=NULL);
	animal_t * toDelete = unlink_from_inventory(animal, facility);
	delete toDelete;
	toDelete = NULL;
}

void free_facility_mem(facility_t * &facility)
{
	// After this call, no memory is associated with the given facility_t 
	if (facility->head == NULL)
	{
		delete facility;
		facility = NULL; 
		return;
	}
	else 
	{
		while(facility->head != NULL)
		{
			animal_t * toRemove = unlink_from_inventory(facility->head, facility);
			free_animal_mem(toRemove, facility);
		}
	}

}

void add_animal_after(facility_t * facility, animal_t * before, animal_t * toInsert)
{
	
}

int main(int argc, char *argv[])
{
    facility_t *cp, *esco, *mm;

    cp = create_facility("Central Park Zoo", "central_park_zoo.txt");
    print_facility_summary(cp);

    esco = create_facility("Escobar's Menagerie", "escobar.txt");
    print_facility_summary(esco);

    mm = create_facility("Mimi's Marsupials", "mimis.txt");
    print_facility_summary(mm);

    //US - China dispute 
    facility_t * bj = new facility_t;
    initialize_facility(bj, "Beijing Zoo");
    animal_t * panda = unlink_from_inventory(find_animal(cp, "Panda"), cp);
    add_animal_to_facility_head(bj, panda);
    print_facility_summary(cp);
    print_facility_summary(bj);

    free_facility_mem(cp);
    free_facility_mem(esco);
    free_facility_mem(mm);
    free_facility_mem(bj);

    return 0;
}
