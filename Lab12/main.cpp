#include <iostream>
#include <string>
#include "sets.h"
using namespace std;

//struct set_of_str_t;
//set_of_str_t * create_set_of_str();

int main(int argc, char *argv[])
{
    //set_of_str_t * fruity_set = NULL;
    set_of_str_t * fruity_set = create_set_of_str();

    add_item(fruity_set, "apple"); 
    add_item(fruity_set, "orange"); 
    add_item(fruity_set, "banana"); 
    add_item(fruity_set, "jackfruit"); 
    add_item(fruity_set, "jackfruit");  // add twice
    print_list(fruity_set);
    //set_of_str_t * tasty_set = NULL;
    set_of_str_t *tasty_set = create_set_of_str();
    add_item(tasty_set, "jackfruit"); 
    add_item(tasty_set, "ice cream");  

    //set_of_str_t *both_set = intersection(fruity_set, tasty_set);

    //destroy_set_of_str(both_set);
    destroy_set_of_str(tasty_set);
    destroy_set_of_str(fruity_set);
}