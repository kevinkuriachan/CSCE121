#include <iostream>
using namespace std;

int main()
{
    float row_one[2] = {3.0, 1.4};
    float row_two[3] = {4.5, 7.2, 5.6};
    float row_three[4] = {15.6, 18.4, 22.2, 105.0};

    float *different_sized[3] = {row_one, row_two, row_three}; // D1

    cout << "different_sized := " << endl;
    cout << "\t" << different_sized[0][0] << "\t" << different_sized[0][1] << endl;
    cout << "\t" << different_sized[1][0] << "\t" << different_sized[1][1] << "\t" << different_sized[1][2] << endl;
    cout << "\t" << different_sized[2][0] << "\t" << different_sized[2][1] << "\t" << different_sized[2][2] << "\t" << different_sized[2][3] << endl << endl;

    float **synonym = different_sized; // that's also a pointer to a pointer

    cout << "synonym := " << endl;
    cout << "\t" << synonym[0][0] << "\t" << synonym[0][1] << endl;
    cout << "\t" << synonym[1][0] << "\t" << synonym[1][1] << "\t" << synonym[1][2] << endl;
    cout << "\t" << synonym[2][0] << "\t" << synonym[2][1] << "\t" << synonym[2][2] << "\t" << synonym[2][3] << endl << endl;

    cout << "&different_sized \t= " << &different_sized<< endl;
    cout << "&synonym \t\t= " << &synonym << endl;
    cout << "different_sized \t= " << different_sized<< endl;
    cout << "synonym \t\t= " << synonym << endl;
    cout << "different_sized[1] \t= " << different_sized[1] << endl;
    cout << "synonym[1] \t\t= " << synonym[1] << endl;

    return 0;
}