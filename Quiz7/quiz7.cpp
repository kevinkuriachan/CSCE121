#include <iostream>
using namespace std;


struct point_t { // Points with integer coordinates 

 int x; 

 int y; 

};


struct rect_t { // A rectangle defined by two corners

 point_t upper_left; 

 point_t lower_right;

};

int rect_width(rect_t *r) 

{ // Return the width 
 return (r->lower_right.x)-(r->upper_left.x);

}

int main()
{
	rect_t rect = {{2,4}, {4,2}};
	cout << rect_width(&rect) << endl;
	return 0;
}