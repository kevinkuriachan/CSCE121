/* STACK DATA STRUCTURE */

// behaves the same way the stack does 
// heap data structure and heap do not behave the same 

/*

|=|   a container with spring at bottom. stuff added to top. 
|=|		there are functions: push and pop.
|Z|		push adds to the container, pop removes and returns top element.
|Z|
|Z|   

Push pop push leaves you with the original structure. 
using stacks can tell you if parentheses are balanced. [()]{} last element opened should be the first closed 

Implementing it:
				_____v	 ______V   _____V
[start pointer|^]  [7.0 |^]  [3.14|^] [1.12| ]
				  ^
			[22.1| ] // to add this, the pointer on 22.1 points to 7.0, then start pointer points to 22.1

