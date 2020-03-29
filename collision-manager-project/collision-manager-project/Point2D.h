#pragma once
#include <string>
#include <sstream>

using namespace std;

struct Point2D
{
public:
	Point2D(void);
	~Point2D(void);
	Point2D(float x, float y);
	float x;
	float y;
	Point2D operator +(Point2D movement);
	Point2D operator +=(Point2D movement);
	Point2D operator -(Point2D movement);
	Point2D operator -=(Point2D movement);
	string toString();
	string toString(string tabbing);
};

