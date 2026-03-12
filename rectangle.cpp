#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Rectangle.h"
#include "point.h"

using namespace std;

Rectangle::Rectangle(const Point& point1, const Point& point2, const Point& point3, const Point& point4): p1(point1), p2(point2), p3(point3), p4(point4)
{
    if (!isRectangle())
    {
        cout << "Ошибка: точки не образуют прямоугольник!\n";
        exit(EXIT_FAILURE);
    }
    sortPoints();
}

bool Rectangle::isRectangle() const
{
    double d12 = p1.distanceTo(p2);
    double d23 = p2.distanceTo(p3);
    double d34 = p3.distanceTo(p4);
    double d41 = p4.distanceTo(p1);
    double d13 = p1.distanceTo(p3); 
    double d24 = p2.distanceTo(p4); 

   

    bool samepoints = !(fabs(d12) < numeric_limits<double>::epsilon() || fabs(d23) < numeric_limits<double>::epsilon() || fabs(d34) < numeric_limits<double>::epsilon() || fabs(d41) < numeric_limits<double>::epsilon() || fabs(d13) < numeric_limits<double>::epsilon() || fabs(d24) < numeric_limits<double>::epsilon());
    
    bool sidesEqual = (fabs(d12 - d34) <numeric_limits<double>::epsilon()) && (fabs(d23 - d41) < numeric_limits<double>::epsilon());

    bool diagonalsEqual = (fabs(d13 - d24) < numeric_limits<double>::epsilon());

    return sidesEqual && diagonalsEqual && samepoints;
}

void Rectangle::sortPoints()
{
    double centerX = (p1.getX() + p2.getX() + p3.getX() + p4.getX()) / 4;
    double centerY = (p1.getY() + p2.getY() + p3.getY() + p4.getY()) / 4;
    Point center(centerX, centerY);


    vector<Point> points = { p1, p2, p3, p4 };

    sort(points.begin(), points.end(), [center](const Point& a, const Point& b) {
        double angleA = atan2(a.getY() - center.getY(), a.getX() - center.getX());
        double angleB = atan2(b.getY() - center.getY(), b.getX() - center.getX());

        if (angleA < 0) 
        {
            angleA += 2 * M_PI;
        }
        if (angleB < 0)
        {
            angleB += 2 * M_PI;
        }

        return angleA < angleB;
        });

    p1 = points[0];
    p2 = points[1];
    p3 = points[2];
    p4 = points[3];
}

Point Rectangle::getP1() const
{
    return p1;
}

Point Rectangle::getP2() const
{
    return p2;
}

Point Rectangle::getP3() const
{
    return p3;
}

Point Rectangle::getP4() const
{
    return p4;
}

vector<Point> Rectangle::getAllPoints() const
{
    return { p1, p2, p3, p4 };
}

double Rectangle::getWidth() const
{
    return p1.distanceTo(p4); 
}

double Rectangle::getHeight() const
{
    return p1.distanceTo(p2); 
}

double Rectangle::getS() const
{
    return getWidth() * getHeight();
}

double Rectangle::getPerimeter() const
{
    return 2 * (getWidth() + getHeight());
}


std::ostream& operator<<(std::ostream& os, const Rectangle& rect)
{
    os << rect.p1 << " " << rect.p2 << " "
        << rect.p3 << " " << rect.p4;
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rect)
{
    is >> rect.p1 >> rect.p2 >> rect.p3 >> rect.p4;

    if (!rect.isRectangle())
    {
        cout << "Ошибка: точки не образуют прямоугольник!\n";
        exit(1);
    }
    else
    {
        rect.sortPoints();
    }

    return is;
}
