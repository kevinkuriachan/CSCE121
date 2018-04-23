#include <iostream>
#include <assert.h>
#include "prompt.h" // STEP 3
using namespace std;

#define MAXSTR 200

struct url_t {
	char uri[MAXSTR]; // The address itself
	bool is_bookmarked; // True is a favorite	
	url_t *link; // Pointer to next element in the stack
};


void print_stack(url_t* top)
{	
	if (top == NULL)
		cout << "\t\t Empty\n";
	else
	{
		url_t *walker = top;
		while (walker != NULL)
		{
			cout << "\t";
			if (walker->is_bookmarked)
				cout << "*";
			else
				cout << " ";
			cout << "\t" << walker->uri << "\n";
			walker = walker->link; // Move to next position in list
		}
	}
}

int main(int argc, char *argv[])
{
	bool should_quit = false;
	url_t *current_page = NULL;
	url_t *first_fwd_page = NULL;

	do {
		cout << "A minimalist web browser, V0.1\n";
		cout << "Current address  [ ";
		if (current_page == NULL)
			cout << "none";
		else
			cout << current_page->uri;
		cout << " ]\n\n\n";
		cout << "Commands:\n\tN = visit new webpage\n\tS = show browser history\n\tT = toggle bookmark status\n\tB = back in browser history\n\tP = print a poem\n\tQ = quit\n";
		char cmd = prompt("What would you like to do?", "pqnstb");

		if (cmd == 'N') { // visit new webpage
			url_t *new_page = new url_t;
			cout << "What address would you like to visit: ";
			cin.getline(new_page->uri, MAXSTR);
			new_page->is_bookmarked = false;
			
			//This is the push operation:
			new_page->link = current_page; // points to what was formerly the head of the stack

			current_page = new_page; // new_page the head of the stack

		}
		else if (cmd == 'S') { // show history
			cout << "Browser history: \n";
			print_stack(current_page);
			cout << "--------------------\n\n";
			cout << "Browser forward urls: \n";
			print_stack(first_fwd_page);
			

		}
		else if (cmd == 'T') { // toggle bookmark
			if (current_page == NULL)
			{
				cout << "No current page, sorry can't bookmark nothing!\n";
			}
			else 
			{
				if (current_page->is_bookmarked)
				{
					current_page->is_bookmarked = false;
					cout << current_page->uri << " no longer bookmarked\n";
				}
				else
				{
					current_page->is_bookmarked = true;
					cout << current_page->uri << " now a bookmark\n";
				}
			}
		}
		else if (cmd == 'B') { // move backward in browser history
			// This is a stack pop
			if (current_page == NULL)
			{
				cout << "Can't go backward (no current page, no previous page)\n";
			}
			else if (current_page->link == NULL)
			{
				cout << "Can't go backward from current page, no previous one\n";
			}
			else
			{
				// 1. Save a reference:
				url_t *element_we_xfer = current_page;
		
				// 2. Pop stack
				current_page = current_page->link;

				// 3. Push on other stack
				element_we_xfer->link = first_fwd_page;
				first_fwd_page = element_we_xfer;
			}	
		}
		else if (cmd == 'P') { // print a poem

			cout << "\n\n Taking fun\n    as simply fun\n and earnestness\n    in earnist\n shows how thoroughly\n    thou none\n of the two\n    discernest.\n";
			cout << "      -- Piet Hein\n\n";

		} else if (cmd == 'Q') { // quit

			cout << "Okay, bye!\n";
			should_quit = true;

		} 
	} while (!should_quit);


	return 0;
}
