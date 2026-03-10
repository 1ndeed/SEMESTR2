#pragma once
#include <iostream>
#include <vector>
#include "point.h"


class Rectangle
{
private:
    /**
    * @brief p1,p2,p3,p4 - вершины прямоугольника, с координатами
    */
    Point p1, p2, p3, p4; 
    /**
    * @brief проверка на прямоугольник
    * @return выводит 1, если прямоугольник, иначе 0
    */
    bool isRectangle() const;
    /**
    * @brief сортировка точек от центра по часовой стрелке
    */
    void sortPoints();

public:
    /**
    * @brief конструктор, создает прямоугольник по умолчанию
    */
    Rectangle();
    /**
    * @brief конструктор, создает прямоугольник с указанными вершинами, проверяет прямоугольник, сортирует точки
    * @param point1 - точка 1
    * @param point2 - точка 2
    * @param point3 - точка 3
    * @param point4 - точка 4
    */
    Rectangle(const Point& point1, const Point& point2, const Point& point3, const Point& point4);

    /**
    * @brief выводит точку p1
    * @return p1
    */
    Point getP1() const;
    /**
   * @brief выводит точку p2
   * @return p2
   */
    Point getP2() const;
    /**
   * @brief выводит точку p3
   * @return p3
   */
    Point getP3() const;
    /**
   * @brief выводит точку p4
   * @return p4
   */
    Point getP4() const;
    /**
    * @brief выводит все 4 точки 
    * @return 4 точки
    */
    std::vector<Point> getAllPoints() const;
    /**
    * @brief высчитывает ширину прямоугольника
    * @return ширина
    */
    double getWidth() const;
    /**
    * @brief высчитывает высоту прямоугольника
    * @return высота
    */
    double getHeight() const;
    /**
    * @brief высчитывает площадь прямоугольника
    * @return площадь
    */
    double getS() const;
    /**
    * @brief высчитывает периметр прямоугольника
    * @return периметр
    */
    double getPerimeter() const;



    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);
    friend std::istream& operator>>(std::istream& is, Rectangle& rect);
};
