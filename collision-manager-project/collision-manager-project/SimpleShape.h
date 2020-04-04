#ifndef SIMPLESHAPE_H
#define SIMPLESHAPE_H
#include <String>
#include <list>
#include "Point2D.h"
#include "Line.h"
#include "Enums.h"

using namespace std;

class SimpleShape
{
public:
	
	SimpleShape(list<Point2D> bounds);
	Point2D getPosition();
	bool collision(Enums::CollisionType collisionType, Point2D targetPoint);
	bool collision(Enums::CollisionType collisionType, SimpleShape targetShape);
	void move(Point2D movement);
	list<Point2D> getBounds();
	float getRadius();
	Point2D getCenter();

private:
	~SimpleShape(void);
	list<Point2D> m_points;
	Point2D m_center;
	float m_minX;
	float m_maxX;
	float m_minY;
	float m_maxY;
	float m_shortestRadius;
	float m_longestRadius;

	void recalculateBounds(list<Point2D> newPoints);
	void calculateMinMaxGeoPoints();//store the min and max x and y points (box bounds)
	void calculateMinMaxRadiuses();//Store the distances between the center and the closest and furthest bound 
	bool circleCollision(Point2D targetPoint);
	bool boxCollision(Point2D targetPoint);
	bool pixleCollision(Point2D targetPoint);
	bool circleCollision(SimpleShape targetShape);
	bool boxCollision(SimpleShape targetShape);
	bool pixleCollision(SimpleShape targetShape);
};

#endif