// STEP 1

#include <iostream>
using namespace std;

// save as [name].cpp
// compile as:
// g++ -c name.cpp 

char upcase(char c)
{
    if (('a' <= c) && (c <= 'z')) return (c - 'a' + 'A');
    return c;
}

// a hand function for using a menu system
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
