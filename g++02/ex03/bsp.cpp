#include "Point.hpp"
#include "Fixed.hpp"

//Returns: True if the point is inside the triangle. False otherwise.
//Thus, if the point is a vertex or on edge, it will return False.

float getPlaneEquation(const Point& a, const Point& b, const Point& c, const Point& point) {
    (void)c;
    return ((b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX())).toFloat();
}

// BSP ile noktanın üçgenin içinde olup olmadığını kontrol etme
bool bsp(const Point& a, const Point& b, const Point& c, const Point& point) {
    float plane1 = getPlaneEquation(a, b, c, point);
    float plane2 = getPlaneEquation(b, c, a, point);
    float plane3 = getPlaneEquation(c, a, b, point);

    return (plane1 >= 0 && plane2 >= 0 && plane3 >= 0) || (plane1 <= 0 && plane2 <= 0 && plane3 <= 0);
}