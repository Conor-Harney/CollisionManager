#include "Point3D.h"


Point3D::Point3D(void)
{
}


Point3D::~Point3D(void)
{
}

Point3D::Point3D(float x, float y, float z): x(x), y(y), z(z)
{
}

Point3D Point3D::operator +(Point3D movement)
{
	return Point3D(x + movement.x, y + movement.y, z + movement.z);
}

Point3D Point3D::operator +=(Point3D movement)
{
	x += movement.x;
	y += movement.y;
	z += movement.z;
	return *this;
}

Point3D Point3D::operator -(Point3D movement)
{
	return Point3D(x - movement.x, y - movement.y, z - movement.z);
}

Point3D Point3D::operator -=(Point3D movement)
{
	x -= movement.x;
	y -= movement.y;
	z -= movement.z;
	return *this;
}
	
string Point3D::toString()
{
	return toString("");
}

string Point3D::toString(string tabbing)
{
	string tab = tabbing;
	std::stringstream strStream;
	strStream << tab << "{" << std::endl;
	tab += "\t";
	strStream << tab << "\"x\"" << ": " <<"\"" + to_string(x) + "\"," << endl;
	strStream << tab << "\"y\"" << ": " <<"\"" + to_string(y) + "\"," << endl;
	strStream << tab << "\"z\"" << ": " <<"\"" + to_string(z) + "\"" << endl;
	tab.resize(tab.size() - 1);
	strStream << tab << "}";
	return strStream.str();
}