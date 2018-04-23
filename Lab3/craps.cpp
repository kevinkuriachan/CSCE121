#include <iostream>
using namespace std;

const int LEN = 12;
int LIST[LEN] = {5,1,3,6,4,4,5,6,2,4,3,2};

bool verifyInput(int input[], int len){
	if (len%2 != 0){
		cout << "ERROR: there must be an even amount of numbers" << endl;
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if ((input[i] > 6) || (input[i] < 1)) 
		{
			cout << "ERROR: invalid number(s) in array" << endl;
			return false;
		}
	}
	return true;
}

// outputs. 
void playerWin(){
	cout << "Player wins" << endl; 
}

void houseWin(){
	cout << "House wins" << endl;
}

void more(){
	cout << "More rolls are still needed" << endl;
}
// 

bool cont(int v){
	int cont[6] = {4,5,6,8,9,10};
	for (int j = 0; j < 6; j++){
		if ( cont[j] == v ){
			return true;
		}
	}
	return false;
}

int main()
{
	bool valid = verifyInput(LIST, LEN);
	if (!valid) return 1; 
	int first = LIST[0]+LIST[1];
	if ((first == 7) || (first == 11)) { // rules for player win 
		playerWin();
		return 0;
	}
	if (( (first == 2) || (first == 3) ) || (first == 12)){ // rules for house win
		houseWin();
		return 0;
	}
	if ( cont(first) ){
		for (int i = 2; i<LEN; i = i+2){
			int sum = LIST[i] + LIST[i+1];
			if ( sum == first ) {
				playerWin();
				return 0;
			}
			if ( sum == 7 ) {
				houseWin();
				return 0;
			}
		}
		more();
		return 0;
	}
	
	
	
	
}








