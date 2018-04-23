// an array is a data structure that stores a number of the same data type 

#include <iostream>
using namespace std;

#define CAP_NUMS 15		// anything with a # in front is done by the preprocessor and is not put through the compiler

// #include finds item in brackets and copies and pastes it into that location


// therefore #define CAP_NUMS 15 makes it so that 'CAP_NUMS' is replaced by 15 before compiling 

const int MAX_NUMS = 15; // creating constants in the beginning to easily tweak the number

int main()
{
	int nums[CAP_NUMS]; 
	int userInput;
	
	int count =0;
	
	
	do
	{
		
		cout << "Please enter a positive integer (-1 to end): ";
		cin >> userInput;
		cout << endl;
		
		nums[count] = userInput;
		
		count++;

	}
	while ((userInput >= 0) && (count < CAP_NUMS));	//since this is here, it keeps -1 in the end of the array when user quits
	
	cout << "Here is your input: " << endl;
	for (int i = 0; i < count; i ++)
		{cout << "nums[" << i <<"] = " << nums[i] << endl;}
	
	
	return 0;
}

// arrays aren't terribly safe to operate with 
// it allows you to enter more than 15 items, it puts it in memory that is not part of nums
// this might case other variables to be overridden or ruin the contents of the array
// without a check, 'count' would have gotten overridden


// segmentation fault: operating system stops the process to prevent you from accessing
// memory that you don't have access to 




// in C, strings are arrays of chars 