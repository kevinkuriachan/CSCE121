#include <iostream>
using namespace std;

struct example_t {
	int count[3];
	int n;
};

int main()
{
	example_t example = { {1 ,2 ,3}, 5 };
	for (int i = 0; i < 3; i++)
	{
		cout << example.count[i] << endl;
	}

	return 0;
}
