#include <iostream>
using namespace std;

void bracket_function(char str[])
{
    // This line will print out what is passed on the call-stack to the function:
    cout << "str = " << (void *)str << endl; //C1
    cout << "Bracket Function: ";
    cout << str << endl;
}

void star_function(char *str)
{
    // This line will print out what is passed on the call-stack to the function:
    cout << "str = " << (void *)str << endl; // C2
    cout << "Star Function: ";
    cout << str << endl;
}

int main()
{
    char lyric[] = "...there's a spirit can ne'er be told...";

    star_function(lyric); // L1: Maybe this is a trifle surprising?
    bracket_function(lyric);

    star_function(&lyric[0]);
    bracket_function(&lyric[0]); // L2: And also this?

    // These two show how it can actually be rather useful:
    star_function(&lyric[32]); // C3
    bracket_function(&lyric[32]);  // C4
    
    return 0;
}