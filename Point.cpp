#include "Point.h"

void Point::changePoint(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::changePoint(Point point)
{
    this->x = point.getX();
    this->y = point.getY();
}

void Point::changeX(int x)
{
    this->x = x;
}

void Point::changeY(int y)
{
    this->y = y;
}

int Point::getX()
{
    return this->x;
}

int Point::getY()
{
    return this->y;
}