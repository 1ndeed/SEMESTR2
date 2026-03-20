#pragma once
#include "Polygon.h"
#include <vector>


namespace geometry {
    class Square : public Polygon {
    private:
        /**
        * @brief VERTEX_COUNT -  постоянное количество вершин квадрата, для проверки
        */
        static const int VERTEX_COUNT = 4;

        /**
        * @brief  проверяет длину динамического массива с вершинами квадрата с постоянным количеством вершин, проверяет неотрицательность сторон, их равную длину, углы
        * @return true, если все условия выполнены
        */
        bool isValidSquare() const;

    public:
        /**
        * @brief конструктор, создает квадрат по умолчанию
        */
        Square();
        /**
        * @brief конструктор, создает квадрат с указанными вершинами, вызывает проверку на квадрат
        * @param p1 - точка 1
        * @param p2 - точка 2
        * @param p3 - точка 3
        * @param p4 - точка 4
        */
        Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
        /**
        * @brief конструктор, создает квадрат с указанными координатами вершин, вызывает проверку на квадрат
        * @param x1 - координата по оси x вершины 1
        * @param y1 - координата по оси y вершины 1
        * @param x2 - координата по оси x вершины 2
        * @param y2 - координата по оси y вершины 2
        * @param x3 - координата по оси x вершины 3
        * @param y3 - координата по оси y вершины 3
        * @param x4 - координата по оси x вершины 4
        * @param y4 - координата по оси y вершины 4
        */
        Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

        /**
        * @brief сериализация в строку
        */
        std::string ToString() const override;
        /**
        * @brief высчитывает площадь квадрата
        * @return S
        */
        double getArea() const override;
        /**
        * @brief высчитывает периметр квадрата
        * @return P
        */
        double getPerimeter() const override;
        /**
        * @brief высчитывает радиус описанной окружности квадрата
        * @return r
        */
        double getCircumradius() const override;
        /**
        * @brief метод чтения из стандартного потока ввода
        */
        void read(std::istream& is) override;
        /**
        * @brief проверяет точки на совпадение
        * @param other-другая точка
        * @return true, если точки совпадают
        */
        bool operator==(const Square& other) const;
        /**
        * @brief проверяет точки на несовпадение
        * @param other-другая точка
        * @return true, если точки не совпадают
        */
        bool operator!=(const Square& other) const;

        /**
        * @brief сериализация в строку
        */
        static std::string ToString(const Square& square);

        /**
        * @brief метод чтения из стандартного потока ввода
        */
        static Square readFromStream(std::istream& is);
    };
}
