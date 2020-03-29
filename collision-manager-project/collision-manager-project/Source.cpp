
#include <iostream>
#include "Point2D.h"

using namespace std;

void demonstratePoint2d();

int main()
{
	demonstratePoint2d();
	system("PAUSE");
}

void demonstratePoint2d()
{
	Point2D point2d = Point2D(1,2);
	cout << "point2d : " << endl;
	cout << point2d.toString() << endl;
}