#include <iostream>
#include "promptuser.h"
#include "rect.h"
#include "diamond.h"

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

        Shape *shape = NULL; // at this point, we don't know what data type within shape this will
                            // point to 

        if (ans == 'X')
        {   
                int sz = prompt_for_int("What size?", 3, 15);
                shape = new X(sz);
                shape->draw();
        }
        else if (ans == 'D')
        {
                int sz = prompt_for_int("What size?", 3, 15);
                Diamond d(sz);
                d.draw(); // will chech if draw() is a method in d (diamond), if not, it will go a heirarchy up and check
                // will try to use the method defined in the lowest heirarchy 
        }
        else if (ans == 'R')
        {
                int wd = prompt_for_int("What width do you want: ", 3, 15);
                int he = prompt_for_int("What height do you want: ", 3, 15);
                Rectangle *rect = new Rectangle(wd, he);
                rect->draw();
                delete rect; 

                /* The above creates a rectangle dynamically
                This is the alternative: 
                Rectangle rect(wd, he);
                rect.draw();
                */
        }   
        // when you get to this point, shape should have a value 
        if (shape != NULL) cout << "you allocated a new shape!" << endl;

    } while (ans != 'Q');

    // there is currently a memory leak
    
    cout << endl;

    return 0;
}


