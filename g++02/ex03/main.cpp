#include "Point.hpp"
#include "Fixed.hpp"

int main()
{
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);
    Point Point(2.0f, 2.0f);

    bool isInside = bsp(a, b, c, Point);

    if (isInside)
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is outside the triangle." << std::endl;
    return 0;
}