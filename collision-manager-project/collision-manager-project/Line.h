#pragma once
#include "Point2D.h"
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Line
{
public:
	Line(void);
	~Line(void);
	Line(Point2D p1, Point2D p2);
	void resize(float scale);//Resize maintaining the center point
	void resizeAnchorP1(float scale);//resize maintaing p1
	void resizeAnchorP2(float scale);//resize maintaing p2
	Point2D getP1();
	void setP1(Point2D p1);
	Point2D getP2();
	void setP2(Point2D p2);
	void move(Point2D movement);
	Point2D getCenter();
	float getLength();
	string toString();
	string toString(string tabbing);
	Point2D getDirection();
	Line directionRageForCollision(Point2D targetPoint);// Get the range of directions a line must be pointed from a starting point to clide with this line;
	bool collision(Line targetLine);// check if the target line colllides with this line;
	static Point2D getDirection(Point2D p1, Point2D p2);
	static Point2D getDirection(Point2D p1, Point2D p2, float length);
	static float getLength(Point2D p1, Point2D p2);
	static Point2D getCenter(Point2D p1, Point2D p2);

private:
	Point2D m_p1;
	Point2D m_p2;
	Point2D m_center;
	float m_length;
	void calculateFromPoints(Point2D p1, Point2D p2);
	bool directionInDirectionRange(Point2D direction, Line range);
	
};

