#include <iostream> 
using namespace std; 

bool nand(bool a, bool b)
{ // is ( a NAND b)
	if ( a && b ) return false;
	else return true;
}

bool nor(bool a, bool b)
{ // is (a NOR b)
	if ( !a && !b ) return true;
	else return false; 
}

bool exclusiveOr(bool a, bool b)
{ // is ( a EXCLUSIVE-OR b ) 
	if ( ( !a && b ) || ( a && !b ) ) return true;
	else return false; 
}

int main()
{
	
	return 0;
}