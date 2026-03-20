#define _USE_MATH_DEFINES
#include "Square.h"
#include <cmath>
#include <sstream>
#include <stdexcept>

namespace geometry {
    Square::Square()
    {
    }

    Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    {
        vertices.push_back(p1);
        vertices.push_back(p2);
        vertices.push_back(p3);
        vertices.push_back(p4);

        if (!isValidSquare()) {
            throw std::invalid_argument("Некорректные вершины для квадрата");
        }
    }

    Square::Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    {
        vertices.push_back(Point(x1, y1));
        vertices.push_back(Point(x2, y2));
        vertices.push_back(Point(x3, y3));
        vertices.push_back(Point(x4, y4));

        if (!isValidSquare()) {
            throw std::invalid_argument("Некорректные вершины для квадрата");
        }
    }

    bool Square::isValidSquare() const {
        if (vertices.size() != VERTEX_COUNT) {
            return false;
        }
        std::vector<double> sides;
        for (size_t i = 0; i < vertices.size(); ++i) {
            const Point& p1 = vertices[i];
            const Point& p2 = vertices[(i + 1) % vertices.size()];

            double dx = p2.getX() - p1.getX();
            double dy = p2.getY() - p1.getY();
            double side = std::sqrt(dx * dx + dy * dy);

            if (side < 0) {
                return false;
            }
            sides.push_back(side);
        }


        for (size_t i = 1; i < sides.size(); ++i) {
            if (std::abs(sides[i] - sides[0]) > std::numeric_limits<double>::epsilon()) {
                return false;
            }
        }

        for (size_t i = 0; i < vertices.size(); ++i) {
            const Point& p1 = vertices[i];
            const Point& p2 = vertices[(i + 1) % vertices.size()];
            const Point& p3 = vertices[(i + 2) % vertices.size()];

            double v1x = p2.getX() - p1.getX();
            double v1y = p2.getY() - p1.getY();
            double v2x = p3.getX() - p2.getX();
            double v2y = p3.getY() - p2.getY();

            double dot = v1x * v2x + v1y * v2y;
            if (std::abs(dot) > std::numeric_limits<double>::epsilon()) {
                return false;
            }
        }

        return true;
    }

    std::string Square::ToString() const {
        std::stringstream ss;
        ss << "Square: ";
        for (size_t i = 0; i < vertices.size(); ++i) {
            ss << "v" << (i + 1) << "=" << vertices[i];
            if (i < vertices.size() - 1) {
                ss << ", ";
            }
        }
        return ss.str();
    }

    double Square::getArea() const {
        double side = getPerimeter() / 4.0;
        return side * side;
    }

    double Square::getPerimeter() const {
        if (vertices.size() != VERTEX_COUNT) {
            return 0.0;
        }

        double perimeter = 0.0;
        for (size_t i = 0; i < vertices.size(); ++i) {
            const Point& p1 = vertices[i];
            const Point& p2 = vertices[(i + 1) % vertices.size()];

            double dx = p2.getX() - p1.getX();
            double dy = p2.getY() - p1.getY();
            perimeter += std::sqrt(dx * dx + dy * dy);
        }
        return perimeter;
    }

    double Square::getCircumradius() const {
        if (vertices.size() != VERTEX_COUNT) {
            return 0.0;
        }

        double side = getPerimeter() / 4.0;
        return side * std::sqrt(2.0) / 2.0;
    }

    void Square::read(std::istream& is) {
        std::vector<Point> newVertices;
        newVertices.resize(VERTEX_COUNT);

        char bracket;
        double x, y;
        char comma;

        for (int i = 0; i < VERTEX_COUNT; ++i) {
            is >> bracket >> x >> comma >> y >> bracket;
            newVertices[i] = Point(x, y);
        }

        vertices = newVertices;
        if (!isValidSquare()) {
            throw std::invalid_argument("Некорректные вершины для квадрата при чтении");
        }
    }

    bool Square::operator==(const Square& other) const {
        if (vertices.size() != other.vertices.size()) {
            return false;
        }

        for (size_t i = 0; i < vertices.size(); ++i) {
            if (vertices[i] != other.vertices[i]) {
                return false;
            }
        }
        return true;
    }

    bool Square::operator!=(const Square& other) const {
        return !(*this == other);
    }

    std::string Square::ToString(const Square& square) {
        return square.ToString();
    }

    Square Square::readFromStream(std::istream& is) {
        Square square;
        square.read(is);
        return square;
    }
}
