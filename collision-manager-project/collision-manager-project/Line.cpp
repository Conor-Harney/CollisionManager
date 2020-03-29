#include "Line.h"


Line::Line(void)
{
}


Line::~Line(void)
{
}

Line::Line(Point2D p1, Point2D p2)
{
	calculateFromPoints(p1,p2);
}

void Line::resize(float scale)
{
	Point2D direction = Point2D((m_p1.x - m_p2.x) / m_length, (m_p1.y - m_p2.y) / m_length);
	m_length *= scale;
	m_p1.x = m_center.x + direction.x * (m_length / 2);
	m_p1.y = m_center.y + direction.y * (m_length / 2);
	m_p2.x = m_center.x - (direction.x * (m_length / 2));
	m_p2.y = m_center.y - (direction.y * (m_length / 2));
}

void Line::resizeAnchorP1(float scale)
{
	Point2D direction = getDirection();
	m_length *= scale;
	m_p2 = m_p1 + Point2D((direction.x * m_length), (direction.y * m_length));
	calculateFromPoints(m_p1, m_p2);
}

void Line::resizeAnchorP2(float scale)
{
	Point2D direction = getDirection();
	m_length *= scale;
	m_p1 = m_p2 - Point2D((direction.x * m_length), (direction.y * m_length));
	calculateFromPoints(m_p1, m_p2);
}

Point2D Line::getP1()
{
	return m_p1;
}

void Line::setP1(Point2D p1)
{
	calculateFromPoints(p1, m_p2);
}

Point2D Line::getP2()
{
	return m_p2;
}

void Line::setP2(Point2D p2)
{
	calculateFromPoints(m_p1, p2);
}

void Line::calculateFromPoints(Point2D p1, Point2D p2)
{
	m_p1 = p1;
	m_p2 = p2;
	m_length = sqrt(pow((m_p2.x - m_p1.x), 2) + pow((m_p2.y - m_p1.y), 2));
	m_center = Point2D((m_p2.x+m_p1.x)/2, (m_p2.y+m_p1.y)/2);
}

void Line::move(Point2D movement)
{
	calculateFromPoints(m_p1 + movement, m_p2 + movement);
}

Point2D Line::getCenter()
{
	return m_center;
}

float Line::getLength()
{
	return m_length;
}

string Line::toString()
{
	return toString("");
}

Point2D Line::getDirection()
{
	return Point2D((m_p2.x - m_p1.x) / m_length, (m_p2.y - m_p1.y) / m_length);
}

string Line::toString(string tabbing)
{
	string tab = tabbing;
	std::stringstream strStream;
	strStream << tab << "{" << endl;
	tab += "\t";
	strStream << tab << "\"p1\"" << ": " << endl << m_p1.toString(tab) + "," << endl;
	strStream << tab << "\"p2\"" << ": " << endl << m_p2.toString(tab) + "," << endl;
	strStream << tab << "\"center\"" << ": " <<"\"" + m_center.toString(tab) + "\"," << endl;
	strStream << tab << "\"length\"" << ": " <<"\"" + to_string(m_length) + "\"" << endl;
	tab.resize(tab.size() - 1);
	strStream << tab << "}";
	return strStream.str();
}