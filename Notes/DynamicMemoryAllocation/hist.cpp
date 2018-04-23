#include <iostream>
#include <assert.h>
using namespace std;

#define MAXSTR 200

struct url_t {
    char uri[MAXSTR]; // The actual address
    bool is_fav; // Bookmarked?
    url_t * link; // Pointer to next element in the stack
};

char upcase(char c)
{ // converts char c to uppercaes
    if (('a' <= c) && (c <= 'z')) return (c - 'a' + 'A');
    return c;
}

char prompt(const char msg[], const char valid_choices[])
{ // returns the letter selected by user 
    char inp[100];
    if (valid_choices[0] == '\0') return '\0'; // Empty choices = prompt is moot
    cout << msg << " ";
    while (true) {
        cout << "[";
        int i = 0;
        while (valid_choices[i] != '\0') {
            cout << upcase(valid_choices[i]);
            if (valid_choices[i+1] != '\0') cout << "/";
            i++;
        }
        cout << "] ";
        cin.getline(inp, 100); 
        i = 0;
        while (valid_choices[i] != '\0') {
            if (upcase(inp[0]) == upcase(valid_choices[i]))
                return upcase(inp[0]);
            i++;
        }
    }
}


int main(int argc, char *argv[])
{
    bool should_quit = false;
    
    url_t *current_page = NULL; // Stack is empty
    url_t *fwd_pages = NULL; // Other stack is empty too

    do {

        // Print out/render our web browser 
        cout << "Simple www\n";
        cout << "Current page: [ ";
        if (current_page == NULL)
        {
            cout << "none";
        } else
        {
            cout << current_page->uri;
        }
        cout << " ]\n\n";

        cout << "Commands:\n\tN = visit new page\n\tT = toggle bookmark of current page\n\tB = back in browser history\n\tS = show browsing history\n\tP = print a poem\n\tQ = quit\n";
        char cmd = prompt("What would you like to do?", "pqnhstb");

        if (cmd == 'N') { // visit a new page
            //url_t ver_on_stack; If we did this instead, it would be vaporized at the closing brace
            url_t *new_page = new url_t; // This allocates a whole struct, including the string, the link, etc.
            assert(new_page != NULL);
            cout << "What page would you like to visit: ";
            cin.getline(new_page->uri, MAXSTR);
                
            new_page->is_fav = false;
            new_page->link = current_page;

            current_page = new_page;

            // puts input string into uri of new_page (pointer to a struct)
            // current page becomes the link (to previous page) of the new page.
            // current page becomes new page 

            // TODO: We should empty the fwd_pages stack
            
        }
        else if (cmd == 'S') { // print history
            cout << "\nBrowsing History:\n";
            if (current_page == NULL) {
                cout << "\tNo pages visited yet! Get busy!\n";
            }
            else
            {
                url_t *walker = current_page;
                while (walker != NULL) {
                    cout << "\t";
                    if (walker->is_fav)
                        cout << "*";
                    else
                        cout << " ";
                    cout  << "\t" << walker->uri << endl;
                    walker = walker->link;
                }   
            }
            cout <<" ------------------------\n";
            cout <<" Forward pages:\n";
            if (fwd_pages == NULL) {
                cout << "\tNo pages fwd pages!\n";
            }
            else
            { // if there are forward pages : 
                url_t *walker = fwd_pages; // creates a pointer to move through stack 
                while (walker != NULL) {
                    cout << "\t";
                    if (walker->is_fav)
                        cout << "*";
                    else
                        cout << " ";
                    cout  << "\t" << walker->uri << endl;
                    walker = walker->link; // will keep going through stack until walker reaches NULL 
                }   
            }
            cout <<" ------------------------\n";

        }
        else if (cmd == 'T') { // toggle bookmark 
            if (current_page == NULL)
            {
                cout << "Sorry, there is no current page!\n";
            }
            else {
                if (current_page->is_fav)
                {
                    cout << current_page->uri << " no long fav'd." << endl;
                    current_page->is_fav = false;
                } else
                {
                    cout << current_page->uri << " is now a favorite." << endl;
                    current_page->is_fav = true;
                }
            }
        }
        else if (cmd == 'B') { // go back in history
            if (current_page == NULL) {
                cout << "Sorry, there is no current or previous page!\n";
            } else if (current_page->link == NULL) {
                cout << "Sorry, there is no previous page!\n";
            }
            else
            {   
                assert(current_page != NULL);
                url_t * next_to_be_current = current_page->link;
                
                current_page->link = fwd_pages;
                fwd_pages = current_page;
    
                current_page = next_to_be_current;
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
