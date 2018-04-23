#include <string> /* Using the C++ standard string type */
using namespace std;

struct stack_t; // Forward declaration to a type describing a stack

// This is an API (Application Programmer's Interface) for an
// ADT (Abstract Data Type) describing a stack

// Functions to bring a stack into existence and to vaporize it
stack_t *create_stack(); // Allocates and initializes a new stack.
    // Use note: It gives a pointer, that should later be destroyed when you're finished with it.

void destroy_stack(stack_t *); // Destroys an existing stack
    // Use note: The stack must have been previously created via create_stack

// Functions to use the stack
void push_on_stack(stack_t *, string); // Add the string to the given stack

bool is_empty_stack(stack_t *); // Tells you whether the given stack is empty or not

string pop_off_stack(stack_t *); // Removes the top of the stack, and returns it. 
    // Use note: The stack should not be empty

string peek_top_of_stack(stack_t *); // Look at the top of the stack without removing the item
    // Use note: Functionally equivalent to popping an item, then pushing that item back on, and returning it. (Though, may be significantly faster.)




