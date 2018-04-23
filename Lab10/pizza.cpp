#include <iostream>
#include <assert.h>
using namespace std;

#define SIZECOUNT 3
#define CRUSTCOUNT 2
#define FLAVORCOUNT 4
#define PAYMENTCOUNT 3

const char sizeOptions[] = "SML";
const char crustOptions[] = "ST";
const char flavorOptions[] = "MPHV";
const char paymentOptions[] = "CD";
const char extraCheeseOptions[] = "YN";
const char deliveryOptions[] = "YN";

enum diameter_t {
	small,
	medium,
	large
};

enum crust_t {
	skinny,
	thick
};

enum flavor_t {
	margarita,
	pepperoni,
	hawaiian,
	vegetarian
};

enum payment_t {
	cash,
	debit
};

struct pizza_t {
	diameter_t size;
	crust_t crust;
	flavor_t flavor;
	bool extraCheese;
	payment_t payment;
	bool needsDelivery;
	pizza_t * nextOrder;
};

char upcase(char c)
{
	if ((c >='a') && (c <= 'z')) return (c - 32);
	return c;
}

const char *returnSize(diameter_t size)
{
	switch(size)
	{
		case small: return "small";
		case medium: return "medium";
		case large: return "large";
	}
}

const char * returnCrust(crust_t crust)
{
	switch(crust)
	{
		case skinny: return "skinny";
		case thick: return "thick";
	}
}

const char * returnFlavor(flavor_t flavor)
{
	switch(flavor)
	{
		case margarita: return "margarita";
		case pepperoni: return "pepperoni";
		case hawaiian: return "hawaiian";
		case vegetarian: return "vegetarian";
	}
}

const char * returnPayment(payment_t payment)
{
	switch(payment)
	{
		case cash: return "cash";
		case debit: return "debit";
	}
}

bool charInArray(char c, const char s[]) 
{ // assumes string is null terminated
	int i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i++]) return true;
	}
	return false; 
}

char prompt(const char msg[], const char validChoices[])
{
	char input;
	if (validChoices[0] == '\0') return '\0';
	cout << "--------------------------" << endl;
	cout << "      Ordering System     " << endl;
	cout << "--------------------------" << endl;
	cout << "Options: " << endl;
	cout << "\t'N' - Create new order" << endl;
	cout << "\t'S' - Show order queue" << endl;
	cout << "\t'F' - Complete first order" << endl;
	cout << "\t'P' - Show phone orders" << endl;
	cout << "\t'D' - Show delivery queue" << endl;
	cout << "\t'U' - Complete first delivery" << endl;
	cout << "\t'C' - Clear order queue" << endl;
	cout << "\t'Q' - Quit" << endl;
	cout << msg << " ";
	while (true)
	{
		cout << "[";
		int i = 0;
		while (validChoices[i] != '\0')
		{
			cout << upcase(validChoices[i]);
			if (validChoices[i+1] != '\0') cout << "/";
			i++;
		}
		cout << "] ";
		cin >> input;
		if (charInArray(upcase(input), validChoices)) return upcase(input);
	}

}

void printPizza(pizza_t* pizza)
{
	cout << "--------------------------" << endl;
	cout << "Size:         " << returnSize(pizza->size) << endl;
	cout << "crust:        " << returnCrust(pizza->crust) << endl;
	cout << "flavor:       " << returnFlavor(pizza->flavor) << endl;
	cout << "extra cheese: ";
	if (pizza->extraCheese) cout << "yes" << endl;
	else cout << "no" << endl;
	cout << "payment:      " << returnPayment(pizza->payment) << endl;
	if (pizza->needsDelivery) cout << "*DELIVERY REQUESTED*" << endl; 
	cout << "--------------------------" << endl;
}

pizza_t* createNewOrder()
{
	cout << "--------------------------" << endl;
	cout << "   CREATING NEW ORDER" << endl;
	cout << "--------------------------" << endl;
	pizza_t * order = new pizza_t;
	char sizeSelection = 'k';
	while (!charInArray(upcase(sizeSelection),sizeOptions))
	{
		cout << "Select size [(s)mall, (m)edium, (l)arge]: ";
		cin >> sizeSelection;
		//cout << "size selection: " << sizeSelection << endl;	
	}
	//cout << "upcase: " <<  upcase(sizeSelection) << endl;
	//cout << "size: " << small << endl;
	switch(upcase(sizeSelection)) 
	{
		case 'S': order->size = small;
			break; 
		case 'M': order->size = medium;
				break;
		case 'L': order->size = large;
				break; 
		case default: 
			cout << "something went wrong" << endl;
			return 1;
	}
	//cout << "size assigned: " << order->size << endl;
	cout << endl;

	char crustSelection = 'k';
	while(!charInArray(upcase(crustSelection), crustOptions))
	{
		cout << "Select crust [(s)kinny, (t)hick]: ";
		cin >> crustSelection;
	}
	switch(upcase(crustSelection)) 
	{
		case 'S': order->crust = skinny;
			break;
		case 'T': order->crust = thick;
			break;
		case default: 
			cout << "something went wrong" << endl;
			return 1;
	}
	cout << endl;

	char flavorSelection = 'k';
	while (!charInArray(upcase(flavorSelection),flavorOptions))
	{
		cout << "Select flavor [(m)argarita, (p)epperoni, (h)awaiian, (v)egetarian]: ";
		cin >> flavorSelection;	
	}
	switch(upcase(flavorSelection)) 
	{
		case 'M': order->flavor = margarita;
			break;
		case 'P': order->flavor = pepperoni;
			break;
		case 'H': order->flavor = hawaiian;
			break;
		case 'V': order->flavor = vegetarian;
			break;
		case default: 
			cout << "something went wrong" << endl;
			return 1;
	}
	cout << endl;

	char extraCheeseSelect = 'k';
	while (!charInArray(upcase(extraCheeseSelect), extraCheeseOptions))
	{
		cout << "Extra cheese? [(y)es, (n)o]: ";
		cin >> extraCheeseSelect;
	}
	switch(upcase(extraCheeseSelect))
	{
		case 'Y': order->extraCheese = true;
			break;
		case 'N': order->extraCheese = false;
			break;
		case default: 
			cout << "something went wrong" << endl;
			return 1;
	}
	cout << endl;

	char paymentSelection = 'k';
	while(!charInArray(upcase(paymentSelection), paymentOptions))
	{
		cout << "Select payment [(c)ash, (d)ebit]: ";
		cin >> paymentSelection;
	}
	switch(upcase(paymentSelection)) 
	{
		case 'C': order->payment = cash;
			break;
		case 'D': order->payment = debit;
			break;
		case default: 
			cout << "something went wrong" << endl;
			return 1;
	}
	cout << endl;

	char deliverySelection = 'k';
	while (!charInArray(upcase(deliverySelection), deliveryOptions))
	{
		cout << "Needs Delivery? [(y)es, (n)o]: ";
		cin >> deliverySelection;
	}
	switch(upcase(deliverySelection))
	{
		case 'Y': order->needsDelivery = true;
			break;
		case 'N': order->needsDelivery = false;
			break;
		case default: 
			cout << "something went wrong" << endl;
			return 1;
	}
	cout << endl;


	order->nextOrder = NULL;
	return order;
}


void addOrderToQueue(pizza_t *newOrder, pizza_t *&qFront, pizza_t *&qBack)
{ // adds a pizza to the end of the queue so that it's nextOrder is NULL
	newOrder->nextOrder = NULL;
	if (qFront == NULL)
	{ // if no orders in queue 
		//cout << "inside line 236" << endl;
		qFront = newOrder;
		qBack = newOrder;
	}
	else 
	{ // links order into queue
		qBack->nextOrder = newOrder;
		qBack = newOrder;
	}
}

void deleteLinkedList(pizza_t * &frontOrder)
{
	pizza_t * walker = frontOrder;
	while (walker!=NULL)
	{
		pizza_t * hold = walker->nextOrder;
		delete walker;
		walker = hold; 
	}
	frontOrder = NULL;
}

void printQueue(pizza_t * qFront)
{
	cout << "--------------------------" << endl;
	cout << "       ORDER QUEUE        " << endl;
	cout << "--------------------------" << endl;
	if (qFront == NULL)
	{ // if queue is empty 
		cout << "    -- queue empty --" << endl;
	}
	else 
	{
		pizza_t  * walker = qFront;
		while(walker!= NULL)
		{
			printPizza(walker);	
			walker = walker->nextOrder;
		} 
		cout << endl;
	}
	
}

void showPhoneOrders(pizza_t * qFront)
{
	cout << "--------------------------" << endl;
	cout << "     PHONE ORDER QUEUE    " << endl;
	cout << "--------------------------" << endl;
	if (qFront == NULL)
	{ // if queue is empty 
		cout << "    -- queue empty --" << endl;
	}
	else 
	{
		pizza_t  * walker = qFront;
		while(walker!= NULL)
		{
			
			if (walker->needsDelivery == true) printPizza(walker);	
			walker = walker->nextOrder;
		} 
		cout << endl;
	}
}

void removeFirstOrder(pizza_t * &qFront)
{
	if (qFront == NULL)
	{
		cout << " -- NOTHING HERE TO COMPLETE -- " << endl;
		return;
	}
	assert(qFront != NULL);
	pizza_t * hold = qFront->nextOrder;
	delete qFront;
	qFront = hold;
}

void transferToStack(pizza_t * &oldFront, pizza_t * & oldBack, pizza_t * &newFront, pizza_t * &newBack )
{ // moves item from old stack to new stack. 
	assert(oldFront != NULL);
	pizza_t * hold = oldFront->nextOrder;
	addOrderToQueue(oldFront, newFront, newBack);
	oldFront = hold;
}

void completeFirstOrder(pizza_t * &qFront, pizza_t * &qBack, pizza_t *&qDeliveryFront, pizza_t *&qDeliveryBack)
{
	assert(qFront != NULL);
	pizza_t * pizza = qFront;
	if (!(pizza->needsDelivery))
	{
		removeFirstOrder(qFront);
	}
	else 
	{ // moves pizza to delivery queue 
		transferToStack(qFront, qBack, qDeliveryFront, qDeliveryBack);
	}

}

void decideWhatToDo(char input)
{
	//
}

int main()
{
	const char menuOptions[] = "NSFDUPCQ";
	const char menuMsg[] = "What would you like to do?";
	pizza_t * qFront = NULL;
	pizza_t * qBack = NULL;
	pizza_t * qDeliveryFront = NULL;
	pizza_t * qDeliveryBack = NULL;
	char input = '0';
	while (input != 'Q')
	{
		input = prompt(menuMsg, menuOptions);
		if (input == 'N')
		{
			addOrderToQueue(createNewOrder(), qFront, qBack);
		}
		if (input == 'S') printQueue(qFront);
		if (input == 'F') completeFirstOrder(qFront, qBack, qDeliveryFront, qDeliveryBack);
		if (input == 'C') deleteLinkedList(qFront);
		if (input == 'P') showPhoneOrders(qFront);
		if (input == 'U') removeFirstOrder(qDeliveryFront);
		if (input == 'D') printQueue(qDeliveryFront);
	}
	deleteLinkedList(qFront);
	cout << "--------------------------" << endl;
	cout << "         Good Bye         " << endl;
	cout << "--------------------------" << endl;
	return 0;
}

/* NOTES 

the back (or end, right before NULL) 
should be the most recent order;

The front is the oldest order (the first one put in);

*/