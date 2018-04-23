/* Basic HTML validator. Ok, a really, really basic one. */
#include <iostream>
#include <string>
#include <assert.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    stack_t *tag_stack = NULL; 

    tag_stack = create_stack();

    push_on_stack(tag_stack, "one");
    push_on_stack(tag_stack, "two");
    push_on_stack(tag_stack, "three");
    push_on_stack(tag_stack, "four");
    push_on_stack(tag_stack, "five");
    push_on_stack(tag_stack, "six");
    push_on_stack(tag_stack, "seven");
    push_on_stack(tag_stack, "eight");
    push_on_stack(tag_stack, "nine");

    while (!is_empty_stack(tag_stack))
        cout << "Got: " << pop_off_stack(tag_stack) << endl;

    destroy_stack(tag_stack);

    return 0;
}

