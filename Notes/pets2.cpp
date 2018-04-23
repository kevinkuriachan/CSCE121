#include <iostream>
#include <assert.h>
using namespace std;

#define MAXSTR 200

enum species_t {
	dog,
	cat,
	horse,
	parrot
};

struct pet_t {
	char name[MAXSTR];
	int age;
	species_t type;
};

const char *print_species(species_t s)
{
	switch (s)
	{
		case dog: return "dog";
		case cat: return "cat";
		case horse : return "horse";
		case parrot: return "parrot";
	}

}

void print_pet(pet_t *p)
{
	assert(p != NULL);
	cout << "---------------" << endl;
	cout << "Name : " << p->name << endl;
	cout << "Age  : " << p->age << endl;
	cout << "Type : " << print_species(p->type) << endl;
	cout << "---------------" << endl;
}



species_t get_species()
{
	while (true)
	{
		char c;	
		cin >> c;
		switch (c)
		{
			case 'd':
			case 'D': return dog;

			case 'c':
			case 'C': return cat;

			case 'h':
			case 'H': return horse;

			case 'p':
			case 'P': return parrot;

			default :	
				cout << "Please enter a D, C, H, or P only" << endl;
		}
	}
}

float *float_adder_example(float a, float b)
{
	float *c = new float;
	*c = a+b;
	return c;
}


pet_t *get_pets_from_input(int n)
{

	pet_t* all_pets = new pet_t[n];

	/* Notice that the pointers have quite different numerical values
	pet_t stack_pets[n];
	cout << "Heap : " << all_pets << endl;
	cout << "Stack : " << stack_pets << endl;
	*/
	
	for (int i = 0; i < n; i++)
	{
		cout << "What is pet #" << i+1 <<"'s name: ";
		cin >> all_pets[i].name;

		cout << "What is " << all_pets[i].name << "'s? [D,C,H,P] ";
		all_pets[i].type = get_species();

		cout << "What is " << all_pets[i].name << "'s age? :";
		cin >> all_pets[i].age;


		cout << endl;
	}
	return all_pets;
}

/*
 
	void foo(int n)
	{
		int n = 10;
		do {
			int n = 100;

		} while (false);


	}
 
 
 
 
 * */

int main(int argc, char **argv)
{
	int n;

	float *f = float_adder_example(10, 100);
	cout << " f = " << *f << endl;
	delete f;

	cout << "How many pets do you have? ";
	cin >> n;
	assert(n > 0);

	pet_t* all_my_pets = get_pets_from_input(n);

	cout << "Summary of your animals: " << endl;
	for (int i = 0; i < n; i++)
		print_pet(&all_my_pets[i]);

	delete[] all_my_pets;

	cout << "How many pets does your brother have? ";
	cin >> n;
	assert(n > 0);

	pet_t* all_bros_pets = get_pets_from_input(n);

	cout << "Summary of your brother's animals: " << endl;
	for (int i = 0; i < n; i++)
		print_pet(&all_bros_pets[i]);


	return 0;
}