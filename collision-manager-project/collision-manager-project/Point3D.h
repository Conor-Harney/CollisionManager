#pragma once
#include <string>
#include <sstream>

using namespace std;

struct Point3D
{
public:
	Point3D(void);
	~Point3D(void);
	Point3D(float x, float y, float z);
	float x;
	float y;
	float z;
	Point3D operator +(Point3D movement);
	string toString();
	string toString(string tabbing);
};

