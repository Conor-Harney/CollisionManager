#include "SimpleShape.h"

SimpleShape::SimpleShape(list<Point2D> bounds)
{
	recalculateBounds(bounds);
}

Point2D SimpleShape::getPosition()
{
	return m_center;
}

bool SimpleShape::collision(Enums::CollisionType collisionType, Point2D targetPoint)
{
	switch(collisionType)
	{
		case Enums::CollisionType::Circle:
			return circleCollision(targetPoint);
		case Enums::CollisionType::Box:
			return boxCollision(targetPoint);
		default:
			return pixleCollision(targetPoint);
	}
	return false;
}

bool SimpleShape::collision(Enums::CollisionType collisionType, SimpleShape targetShape)
{
	switch(collisionType)
	{
		case Enums::CollisionType::Circle:
			return circleCollision(targetShape);
		case Enums::CollisionType::Box:
			return boxCollision(targetShape);
		default:
			return pixleCollision(targetShape);
	}
	return false;
}

void SimpleShape::move(Point2D movement)
{
	for(list<Point2D>::iterator iter = m_points.begin(); iter != m_points.end(); ++iter)
	{
		*iter += movement;
	}
	recalculateBounds(m_points);
}

list<Point2D> SimpleShape::getBounds()
{
	return m_points;
}

float SimpleShape::getRadius()
{
	return m_longestRadius;
}

Point2D SimpleShape::getCenter()
{
	return m_center;
}

/*---PRIVATE----*/

SimpleShape::~SimpleShape()
{
}

void SimpleShape::recalculateBounds(list<Point2D> newPoints)
{
	m_points = newPoints;
	calculateMinMaxGeoPoints();
	m_center = Point2D(m_minX + ((m_maxX -m_minX) / 2), m_minY + ((m_maxY -m_minY) / 2));
	calculateMinMaxRadiuses();
}

void SimpleShape::calculateMinMaxGeoPoints()
{//store the min and max x and y points (box bounds)
	list<Point2D>::iterator iter = m_points.begin();
	m_minX = iter->x;
	m_maxX = iter->x;
	m_minY = iter->y;
	m_maxY = iter->y;

	for(iter++ ;iter != m_points.end(); ++iter)
	{
		if(iter->x > m_maxX) m_maxX = iter->x;
		else if(iter->x < m_minX) m_minX = iter->x;
		if(iter->y > m_maxY) m_maxY = iter->y;
		else if(iter->y < m_minY) m_minY = iter->y;
	}
}
	
void SimpleShape::calculateMinMaxRadiuses()
{//Store the distances between the center and the closest and furthest bound 
	list<Point2D>::iterator iter = m_points.begin();
	float currentRadius = Line::getLength(m_center, *iter);
	m_shortestRadius = currentRadius;
	m_longestRadius = currentRadius;

	for(iter++ ;iter != m_points.end(); ++iter)
	{
		currentRadius = Line::getLength(m_center, *iter);
		if(currentRadius > m_longestRadius) m_longestRadius = currentRadius;
		else if(currentRadius < m_shortestRadius) m_shortestRadius = currentRadius;
	}
}

bool SimpleShape::circleCollision(Point2D targetPoint)
{
	return Line::getLength(m_center, targetPoint) < m_longestRadius;
}

bool SimpleShape::boxCollision(Point2D targetPoint)
{
	if(targetPoint.x >= m_minX && targetPoint.x <= m_maxX)
		if(targetPoint.y >= m_minY && targetPoint.y <= m_maxY)
			return true;
	return false;
}

bool SimpleShape::pixleCollision(Point2D targetPoint)
{
	//todo
	return false;
}

bool SimpleShape::circleCollision(SimpleShape targetShape)
{
	return Line::getLength(m_center, targetShape.getCenter()) < (getRadius() + targetShape.getRadius());
}

bool SimpleShape::boxCollision(SimpleShape targetShape)
{
	for(Point2D targetPoint : targetShape.getBounds())
		if(boxCollision(targetPoint))
			return true;
	return false;
}

bool SimpleShape::pixleCollision(SimpleShape targetShape)
{
	//todo
	return false;
}
