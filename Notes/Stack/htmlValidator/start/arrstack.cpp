#include "stack.h" // We implement this functionality
#include <string> /* Using the C++ standard string type */
#include <assert.h>
using namespace std;

#define CAPACITY 10

struct stack_t {
   string data[CAPACITY]; // Pointer to array of items
   int count; // Number in the stack so far
};


stack_t *create_stack()
{
    stack_t *arrstk = new stack_t; // Make a new data structure to store the stack
    assert(arrstk != NULL);
    arrstk->count = 0;
}

void destroy_stack(stack_t *arrstk)
{
    assert(arrstk != NULL);
    delete arrstk; // Delete the stack 
}

void push_on_stack(stack_t *arrstk, string s)
{
    assert(arrstk != NULL);
    assert(arrstk->count < CAPACITY); // Are you trying to push too much on?

    arrstk->data[arrstk->count++] = s;
}

bool is_empty_stack(stack_t *arrstk) 
{
    assert(arrstk != NULL);
    return (arrstk->count == 0);
}

string pop_off_stack(stack_t *arrstk)
{
    assert(arrstk != NULL);
    arrstk->count--;
    return arrstk->data[arrstk->count]; // We know that this data was still there
}

string peek_top_of_stack(stack_t *arrstk)
{
    assert(arrstk != NULL);
    return arrstk->data[arrstk->count-1];
}


