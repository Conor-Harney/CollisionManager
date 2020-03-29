
#include <iostream>
#include "Point2D.h"
#include "Point3D.h"
#include "Line.h"

using namespace std;

void demonstratePoint2d();
void demonstratePoint3d();
void demonstrateLine();

int main()
{
	demonstrateLine();
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

void demonstrateLine()
{
	Line line  = Line(Point2D(1,0), Point2D(2,0));
	cout << line.toString() << endl;
	line.move(Point2D(-1,0));
	cout << "Moved line left one unit" << endl;
	cout << line.toString() << endl;
	line.resize(0.5);
	cout << "resized the line to 50%" << endl;
	cout << line.toString() << endl;
	line.resizeAnchorP1(2.0);
	cout << "resized the line to 200% anchoring to p1" << endl;
	cout << line.toString() << endl;
	line.resizeAnchorP2(0.25);
	cout << "resized the line to 25% anchoring to p2" << endl;
	cout << line.toString() << endl;
}