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
	return getDirection(m_p1, m_p2);
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

Line Line::directionRageForCollision(Point2D targetPoint)
{// Get the range of directions a line must be pointed from a starting point to clide with this line;
	Point2D p1Direction = getDirection(targetPoint, m_p1);
	Point2D p2Direction = getDirection(targetPoint, m_p2);
	Point2D rangeStartPoint = Point2D(p1Direction.x <= p2Direction.x ? p1Direction.x : p2Direction.x, p1Direction.y <= p2Direction.y ? p1Direction.y : p2Direction.y);
	Point2D rangeEndPoint = Point2D(p1Direction.x >= p2Direction.x ? p1Direction.x : p2Direction.x, p1Direction.y >= p2Direction.y ? p1Direction.y : p2Direction.y);
	return Line(rangeStartPoint, rangeEndPoint);
}
	
bool Line::collision(Line targetLine)
{// check if the target line colllides with this line;
	bool lineSegmentWouldHit = false;
	Point2D targetLineDirection = targetLine.getDirection();
	Line directRangeFromTargetP1 = directionRageForCollision(targetLine.getP1());
	bool infiniteLineWouldHit = directionInDirectionRange(targetLineDirection, directRangeFromTargetP1);
	if(infiniteLineWouldHit)
	{//A line of infinite length from target line p1 in the direction of the target line would, eventually hit this line.
		Point2D targetLineReverseDirection = Point2D(-targetLineDirection.x, -targetLineDirection.y);
		Line directRangeFromTargetP2 = directionRageForCollision(targetLine.getP2());
		lineSegmentWouldHit = directionInDirectionRange(targetLineReverseDirection, directRangeFromTargetP2);
	}
	return lineSegmentWouldHit;
}

Point2D Line::getDirection(Point2D p1, Point2D p2)
{
	return Line::getDirection(p1,p2, Line::getLength(p1,p2));
}

Point2D Line::getDirection(Point2D p1, Point2D p2, float length)
{
	return Point2D((p2.x - p1.x) / length, (p2.y - p1.y) / length);
}

float Line::getLength(Point2D p1, Point2D p2)
{
	return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

Point2D Line::getCenter(Point2D p1, Point2D p2)
{
	return Point2D((p2.x+p1.x)/2, (p2.y+p1.y)/2);
}

/*---Private---*/

void Line::calculateFromPoints(Point2D p1, Point2D p2)
{
	m_p1 = p1;
	m_p2 = p2;
	m_length = getLength(p1,p2);
	m_center = getCenter(p1,p2);
}

bool Line::directionInDirectionRange(Point2D direction, Line range)
{
	if(direction.x >= min(range.getP1().x, range.getP2().x))
		if(direction.x <= max(range.getP1().x, range.getP2().x))
			if(direction.y >= min(range.getP1().y, range.getP2().y))
				if(direction.y <= max(range.getP1().y, range.getP2().y))
					return true;
	return false;
}
