#include <iostream>
#include <math.h>
using namespace std;

struct pointT {
	int x;
	int y;
};

struct triangleT{
	pointT pts[3];
};

void printPoints(triangleT tri)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "(" << tri.pts[i].x << ", " << tri.pts[i].y << ") ";
	}
	cout << endl;
}

void orderPoints(triangleT &tri)
{ // will reorder the points by increasing x value. If two points 
  // have same x, will sort by y 
	pointT A = tri.pts[0];
	pointT B = tri.pts[1];
	pointT C = tri.pts[2];

	for (int j = 0; j < 3; j++)
	{
		for(int i = 0; i < 2; i++)
		{
			if (tri.pts[i].x > tri.pts[i+1].x)
			{
				pointT tmp = tri.pts[i];
				tri.pts[i] = tri.pts[i+1];
				tri.pts[i+1] = tmp;
			} 
			else if (tri.pts[i].x == tri.pts[i+1].x)
			{
				if (tri.pts[i].y > tri.pts[i+1].y)
				{
					pointT tmp = tri.pts[i];
					tri.pts[i] = tri.pts[i+1];
					tri.pts[i+1] = tmp;
				}
			}
		}
	}
}

bool samePoints(pointT p1, pointT p2)
{
	if (p1.x == p2.x && p1.y == p2.y) return true;
	return false; 
}

bool isDegenerate(triangleT triangle)
{ // are the points district
	if (samePoints(triangle.pts[0], triangle.pts[1]) || samePoints(triangle.pts[0], triangle.pts[2]) || samePoints(triangle.pts[1], triangle.pts[2])) return false;
	return true;
}

float length(pointT p1, pointT p2)
{ // finds length between p1 and p2
	int x1 = p1.x;
	int y1 = p1.y;

	int x2 = p2.x;
	int y2 = p2.y;

	float dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

	return dist; 
}

float dot(pointT p1, pointT p2)
{ // dot product 
	return ((p1.x*p2.x) + (p1.y*p2.y));
}

float radianToDegree(float radian)
{ // converts a radian to degree 
	return ((radian*180)/ 3.14159265359);
}

double angleRad(pointT p1, pointT pIntersect, pointT p3)
{ // returns the p1 - pIntersect - p3 angle 
	float lenToP1 = length(pIntersect, p1);
	float lenToP3 = length(pIntersect, p3);

	pointT vectorP1 = {p1.x - pIntersect.x, p1.y - pIntersect.y}; 
	pointT vectorP3 = {p3.x - pIntersect.x, p3.y - pIntersect.y}; 

	pointT origin = {0,0};
	float lenP1 = length(origin, vectorP1);
	float lenP3 = length(origin, vectorP3);

	double theta = acos((dot(vectorP1, vectorP3))/(lenP1*lenP3));
	return theta; 
}

double angleDeg(pointT p1, pointT pIntersect, pointT p3)
{
	return radianToDegree(angleRad(p1, pIntersect, p3));
}

bool isRight(triangleT triangle)
{
	int xA = (triangle.pts[0]).x;
	int yA = (triangle.pts[0]).y;

	int xB = (triangle.pts[1]).x;
	int yB = (triangle.pts[1]).y;

	int xC = (triangle.pts[2]).x;
	int yC = (triangle.pts[2]).y;

	float lenAB = length(triangle.pts[0], triangle.pts[1]);
	float lenAC = length(triangle.pts[0], triangle.pts[2]);
	float lenBC = length(triangle.pts[1], triangle.pts[2]);

	if ((pow(lenAB,2) + pow(lenAC, 2) == pow(lenBC,2) ) || (pow(lenAC,2) + pow(lenBC, 2) == pow(lenAB,2) ) ) return true;
	return false;
}

bool isIdentical(triangleT a, triangleT b)
{ // Check whether two triangle_t's  describe geometric shape in an identical position

  if (samePoints(a.pts[0], b.pts[0]) && samePoints(a.pts[1], b.pts[1]), samePoints(a.pts[2], b.pts[2])) return true;
  return false; 
}

bool isCongruent(triangleT a, triangleT b)
{ // Check whether the triangle_t's are congruent 
  // can compare lengths and angles?

}

bool isSimilar(triangleT a, triangleT b)
{ // Check whether the triangle_t's are similar

  //  ... 
}


int main()
{
	triangleT t1 = { {{0, 0}, {3, 0}, {0, 4}} }; 
    triangleT t2 = { {{90, 0}, {90, -4}, {87, 0}} };

    printPoints(t2);
    orderPoints(t2);
    printPoints(t2);
	return 0;
}
