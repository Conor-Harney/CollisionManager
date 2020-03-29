#include "Point2D.h"


Point2D::Point2D(void)
{
}


Point2D::~Point2D(void)
{
}

Point2D::Point2D(float x, float y): x(x), y(y)
{
}

Point2D Point2D::operator +(Point2D movement)
{
	x += movement.x;
	y += movement.y;
	return *this;
}

std::string Point2D::toString()
{
	return toString("");
}

string Point2D::toString(string tabbing)
{
	string tab = tabbing;
	std::stringstream strStream;
	strStream << tab << "{" << std::endl;
	tab += "\t";
	strStream << tab << "\"x\"" << ": " <<"\"" + to_string(x) + "\"," << endl;
	strStream << tab << "\"y\"" << ": " <<"\"" + to_string(y) + "\"" << endl;
	tab.resize(tab.size() - 1);
	strStream << tab << "}";
	return strStream.str();
}