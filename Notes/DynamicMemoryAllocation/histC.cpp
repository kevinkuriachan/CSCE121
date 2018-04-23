#include <iostream>
#include <assert.h>
#include "prompt.h"
using namespace std;

#define MAXSTR 200

char upcase(char c)
{
    if (('a' <= c) && (c <= 'z')) return (c - 'a' + 'A');
    return c;
}

char prompt(const char msg[], const char valid_choices[])
{
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
    
    do {
        cout << "Commands:\n\tP = print a poem\n\tQ = quit\n";
        char cmd = prompt("What would you like to do?", "pq");

        if (cmd == 'P') { // print a poem

            cout << "\n\n Taking fun\n    as simply fun\n and earnestness\n    in earnist\n shows how thoroughly\n    thou none\n of the two\n    discernest.\n";
            cout << "      -- Piet Hein\n\n";
       
        } else if (cmd == 'Q') { // quit

            cout << "Okay, bye!\n";
            should_quit = true;

        } 
    } while (!should_quit);

    
    return 0;
}
