#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>
using namespace std;


char upcase(char c)
{
    if (('a' <= c) && (c <= 'z')) return (c - 'a' + 'A');
    return c;
}

char prompt(const char msg[], const char valid_choices[])
{
    string inp;
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
        getline(cin, inp); 
        i = 0;
        while (valid_choices[i] != '\0') {
            if (upcase(inp[0]) == upcase(valid_choices[i]))
                return upcase(inp[0]);
            i++;
        }
    }
}

int prompt_for_int(const char msg[], const int min, const int max)
{
    string inp;
    cout << msg << " ";
    while (true) {
        cout << "[" << min << "-" << max << "] ";
        getline(cin, inp); 
        stringstream ss(inp);
        int o;
        ss >> o;
        if ((min <= o) && (o <= max))
            return o;
    }
}

void prompt_for_pause()
{
    cout << "(Hit enter to continue.)" << endl;
    string line;
    getline(cin, line);
}



