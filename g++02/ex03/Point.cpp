#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(float _x, float _y): x(_x), y(_y)
{
}

Point::Point(const Point &other): x(other.x), y(other.y){}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}

Point::~Point(){}

Fixed   Point::getX() const
{
    return(x);
}
Fixed   Point::getY() const
{
    return(y);
}