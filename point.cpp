#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <iostream>
#include "Rectangle.h"
#include "point.h"

using namespace std;


Point::Point(const double x, const double y) : x(x), y(y)
{
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::distanceTo(const Point& other) const
{
    double x = this->x - other.x;
    double y = this->y - other.y;
    return sqrt(x * x + y * y);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x << ";" << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p.x >> p.y;
    return is;
}
