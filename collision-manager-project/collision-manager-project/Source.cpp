
#include <iostream>
#include "Point2D.h"
#include "Point3D.h"

using namespace std;

void demonstratePoint2d();
void demonstratePoint3d();

int main()
{
	demonstratePoint3d();
	system("PAUSE");
}

void demonstratePoint2d()
{
	Point2D point2d = Point2D(1,2);
	cout << "point2d : " << endl;
	cout << point2d.toString() << endl;
}

void demonstratePoint3d()
{
	Point3D point3d = Point3D(1,2,1);
	cout << "point3d : " << endl;
	cout << point3d.toString() << endl;
}