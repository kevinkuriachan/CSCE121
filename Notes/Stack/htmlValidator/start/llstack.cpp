#include "stack.h" // We implement this functionality
#include <string> /* Using the C++ standard string type */
#include <assert.h>
using namespace std;

struct stack_item_t {
   string data; 
   stack_item_t *next;
};

struct stack_t {
   stack_item_t *head;
};


stack_t *create_stack()
{
    stack_t *stk = new stack_t; // Make a new data structure to store the stack
    assert(stk != NULL); // If this failed, we're in trouble
    stk->head = NULL;
    return stk;
}

void destroy_stack(stack_t *stk)
{
    assert(stk != NULL);
    stack_item_t *p = NULL;

    while (!is_empty_stack(stk)) // Remove and free the items
        pop_off_stack(stk);

    delete stk; // Delete the stack itself
}

void push_on_stack(stack_t *stk, string s)
{
    assert(stk != NULL);
     
    stack_item_t *p = new stack_item_t; // Create a stack item
    assert(p != NULL); // If this failed, we're in trouble

    p->data = s; // String will copy all the necessary bits
    p->next = stk->head;
    stk->head = p;
}

bool is_empty_stack(stack_t *stk) 
{
    assert(stk != NULL);
    return (stk->head == NULL);
}

string pop_off_stack(stack_t *stk)
{
    assert(stk != NULL);
    assert(stk->head != NULL); // Stack must not be empty

    stack_item_t *p = stk->head;
    stk->head = stk->head->next;
    string ret = p->data;   
    delete p;
    return ret;
}

string peek_top_of_stack(stack_t *stk)
{
    assert(stk != NULL);
    assert(stk->head != NULL); // Stack must not be empty

    return stk->head->data;
}


