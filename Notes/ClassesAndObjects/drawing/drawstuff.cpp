#include <iostream>
#include "promptuser.h"
using namespace std;

void draw_ex(int sz)
{
    int extent = sz - 2;
    for (int j = 0; j <= extent/2; j++)
    {
        for (int i = 0; i < j; i++)
            cout << " ";
        cout << "*";
        for (int i = 1; i < extent-2*j+1; i++)
            cout << " ";
        cout << "*";
        cout << endl;
    }

    if (extent % 2 == 1)
    {
        for (int i = 0; i <= extent/2; i++)
            cout << " ";
        cout << "*" << endl;
    }

    for (int j = extent/2; j >= 0; j--)
    {
        for (int i = 0; i < j; i++)
            cout << " ";
        cout << "*";
        for (int i = 1; i < extent-2*j+1; i++)
            cout << " ";
        cout << "*";
        cout << endl;
    }


}

void draw_diamond(int sz)
{
    // Insert Lab Work here...
}

void draw_rect(int w, int h)
{
    for (int i = 0; i < w; i++)
        cout << "*";
    cout << endl;

    for (int j = 1; j < h-1; j++)
    {
        cout << "*";
        for (int i = 1; i < w-1; i++)
            cout << " ";
        cout << "*" << endl;
    }

    for (int i = 0; i < w; i++)
        cout << "*";
    cout << endl;
}

int main(int argc, char **argv)
{
    char ans;

    do {
        cout << "Interactive shape drawer" << endl << endl;;
        cout << "I can draw the following shapes: " << endl;
        cout << "\tX: An X" << endl;
        cout << "\tD: A diamond" << endl;
        cout << "\tR: A rectangle" << endl;
        cout << endl;
        ans = prompt("What would you like? (Choose a shape, or Q to quit) ", "xdrq");

        if (ans == 'X')
        {   
                int sz = prompt_for_int("What size?", 3, 15);
                draw_ex(sz);
        }
        else if (ans == 'D')
        {
                int sz = prompt_for_int("What size?", 3, 15);
                draw_diamond(sz);
        }
        else if (ans == 'R')
        {
                int wd = prompt_for_int("What width?", 3, 15);
                int he = prompt_for_int("And height?", 3, 15);
                draw_rect(wd, he);
        }   

    } while (ans != 'Q');

    cout << endl;

    return 0;
}


