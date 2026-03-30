#include "../task3/Square.h"
#include"../task3/point.h"
#include "CppUnitTest.h"
#include <sstream>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace geometry;

namespace Tests
{

    TEST_CLASS(SquareTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Square square;
            Assert::IsTrue(true);
        }

        // 2. Тест конструктора с точками
        TEST_METHOD(TestConstructorWithPoints)
        {
            Point p1(0, 0);
            Point p2(0, 2);
            Point p3(2, 2);
            Point p4(2, 0);

            Square square(p1, p2, p3, p4);

            Assert::AreEqual(8.0, square.getPerimeter());
            Assert::AreEqual(4.0, square.getArea());
            Assert::AreEqual(std::sqrt(2.0), square.getCircumradius());
        }

        // 3. Тест конструктора с координатами
        TEST_METHOD(TestConstructorWithCoordinates)
        {
            Square square(0, 0, 0, 2, 2, 2, 2, 0);

            Assert::AreEqual(8.0, square.getPerimeter());
            Assert::AreEqual(4.0, square.getArea());
        }

        // 4. Тест конструктора копирования
        TEST_METHOD(TestCopyConstructor)
        {
            Square original(0, 0, 0, 2, 2, 2, 2, 0);
            Square copy(original);

            Assert::AreEqual(original.getPerimeter(), copy.getPerimeter());
            Assert::AreEqual(original.getArea(), copy.getArea());
            Assert::AreEqual(original.getCircumradius(), copy.getCircumradius());
        }

        // 5. Тест оператора присваивания
        TEST_METHOD(TestAssignmentOperator)
        {
            Square original(0, 0, 0, 2, 2, 2, 2, 0);
            Square assigned;

            assigned = original;

            Assert::AreEqual(original.getPerimeter(), assigned.getPerimeter());
            Assert::AreEqual(original.getArea(), assigned.getArea());
            Assert::AreEqual(original.getCircumradius(), assigned.getCircumradius());
        }

        // 6. Тест самоприсваивания
        TEST_METHOD(TestSelfAssignment)
        {
            Square square(0, 0, 0, 2, 2, 2, 2, 0);
            double originalPerimeter = square.getPerimeter();

            square = square;

            Assert::AreEqual(originalPerimeter, square.getPerimeter());
        }

        // 7. Тест оператора сравнения ==
        TEST_METHOD(TestEqualityOperator)
        {
            Square square1(0, 0, 0, 2, 2, 2, 2, 0);
            Square square2(0, 0, 0, 2, 2, 2, 2, 0);
            Square square3(0, 0, 0, 3, 3, 3, 3, 0);

            Assert::IsTrue(square1 == square2);
            Assert::IsFalse(square1 == square3);
        }

        // 8. Тест оператора сравнения !=
        TEST_METHOD(TestInequalityOperator)
        {
            Square square1(0, 0, 0, 2, 2, 2, 2, 0);
            Square square2(0, 0, 0, 2, 2, 2, 2, 0);
            Square square3(0, 0, 0, 3, 3, 3, 3, 0);

            Assert::IsFalse(square1 != square2);
            Assert::IsTrue(square1 != square3);
        }

        // 9. Тест метода getPerimeter()
        TEST_METHOD(TestGetPerimeter)
        {
            Square square(0, 0, 0, 2, 2, 2, 2, 0);
            Assert::AreEqual(8.0, square.getPerimeter());

            Square square2(0, 0, 0, 5, 5, 5, 5, 0);
            Assert::AreEqual(20.0, square2.getPerimeter());
        }

        // 10. Тест метода getArea()
        TEST_METHOD(TestGetArea)
        {
            Square square(0, 0, 0, 2, 2, 2, 2, 0);
            Assert::AreEqual(4.0, square.getArea());

            Square square2(0, 0, 0, 5, 5, 5, 5, 0);
            Assert::AreEqual(25.0, square2.getArea());
        }

        // 11. Тест метода getCircumradius()
        TEST_METHOD(TestGetCircumradius)
        {
            Square square(0, 0, 0, 2, 2, 2, 2, 0);
            double expected = 2.0 * std::sqrt(2.0) / 2.0;
            Assert::AreEqual(expected, square.getCircumradius());

            Square square2(0, 0, 0, 4, 4, 4, 4, 0);
            double expected2 = 4.0 * std::sqrt(2.0) / 2.0;
            Assert::AreEqual(expected2, square2.getCircumradius());
        }

        // 12. Тест метода ToString()
        TEST_METHOD(TestToString)
        {
            Square square(0, 0, 0, 2, 2, 2, 2, 0);
            std::string result = square.ToString();

            Assert::IsTrue(result.find("Square") != std::string::npos);
            Assert::IsTrue(result.find("(0, 0)") != std::string::npos);
            Assert::IsTrue(result.find("(0, 2)") != std::string::npos);
            Assert::IsTrue(result.find("(2, 2)") != std::string::npos);
            Assert::IsTrue(result.find("(2, 0)") != std::string::npos);
        }

        // 13. Тест статического метода ToString
        TEST_METHOD(TestStaticToString)
        {
            Square square(0, 0, 0, 2, 2, 2, 2, 0);
            std::string result = Square::ToString(square);

            Assert::IsTrue(result.find("Square") != std::string::npos);
        }

        // 14. Тест оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Square square(0, 0, 0, 2, 2, 2, 2, 0);
            std::stringstream ss;
            ss << square;

            std::string result = ss.str();
            Assert::IsTrue(result.find("Square") != std::string::npos);
        }

        // 15. Тест оператора ввода >>
        TEST_METHOD(TestInputStreamOperator)
        {
            Square square;
            std::string input = "(0,0)(0,2)(2,2)(2,0)";
            std::stringstream ss(input);

            ss >> square;

            Assert::AreEqual(8.0, square.getPerimeter());
        }

        // 16. Тест метода read()
        TEST_METHOD(TestReadMethod)
        {
            Square square;
            std::string input = "(0,0)(0,2)(2,2)(2,0)";
            std::stringstream ss(input);

            square.read(ss);

            Assert::AreEqual(8.0, square.getPerimeter());
        }

        // 17. Тест статического метода readFromStream
        TEST_METHOD(TestReadFromStream)
        {
            std::string input = "(0,0)(0,2)(2,2)(2,0)";
            std::stringstream ss(input);

            Square square = Square::readFromStream(ss);

            Assert::AreEqual(8.0, square.getPerimeter());
        }

        // 18. Тест на некорректный квадрат (неправильные координаты)
        TEST_METHOD(TestInvalidSquareThrowsException)
        {
            auto func = []() {
                Square square(0, 0, 0, 2, 2, 2, 3, 0);
                };

            Assert::ExpectException<std::invalid_argument>(func);
        }

        // 19. Тест цепочечного присваивания
        TEST_METHOD(TestChainedAssignment)
        {
            Square square1(0, 0, 0, 2, 2, 2, 2, 0);
            Square square2, square3;

            square3 = square2 = square1;

            Assert::AreEqual(square1.getPerimeter(), square2.getPerimeter());
            Assert::AreEqual(square1.getPerimeter(), square3.getPerimeter());
        }

        // 20. Тест метода getPerimeter с некорректным объектом
        TEST_METHOD(TestGetPerimeterWithInvalidObject)
        {
            Square square;
            Assert::AreEqual(0.0, square.getPerimeter());
        }

        // 21. Тест метода getArea с некорректным объектом
        TEST_METHOD(TestGetAreaWithInvalidObject)
        {
            Square square;
            Assert::AreEqual(0.0, square.getArea());
        }

        // 22. Тест метода getCircumradius с некорректным объектом
        TEST_METHOD(TestGetCircumradiusWithInvalidObject)
        {
            Square square;
            Assert::AreEqual(0.0, square.getCircumradius());
        }

        // 23. Тест полиморфизма через базовый класс
        TEST_METHOD(TestPolymorphism)
        {
            std::unique_ptr<Polygon> polygon = std::make_unique<Square>(0, 0, 0, 2, 2, 2, 2, 0);

            Assert::AreEqual(8.0, polygon->getPerimeter());
            Assert::AreEqual(4.0, polygon->getArea());
            Assert::AreEqual(std::sqrt(2.0), polygon->getCircumradius());
        }

        // 24. Тест коллекции объектов базового класса
        TEST_METHOD(TestCollectionOfPolygons)
        {
            std::vector<std::unique_ptr<Polygon>> polygons;
            polygons.push_back(std::make_unique<Square>(0, 0, 0, 2, 2, 2, 2, 0));
            polygons.push_back(std::make_unique<Square>(0, 0, 0, 4, 4, 4, 4, 0));

            Assert::AreEqual(8.0, polygons[0]->getPerimeter());
            Assert::AreEqual(16.0, polygons[1]->getPerimeter());
            Assert::AreEqual(4.0, polygons[0]->getArea());
            Assert::AreEqual(16.0, polygons[1]->getArea());
        }
    };
}


namespace Tests
{
    TEST_CLASS(PointTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Point p;
            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        // 2. Тест конструктора с параметрами
        TEST_METHOD(TestParameterizedConstructor)
        {
            Point p(3.5, 7.2);
            Assert::AreEqual(3.5, p.getX());
            Assert::AreEqual(7.2, p.getY());
        }

        // 3. Тест конструктора с целыми числами
        TEST_METHOD(TestConstructorWithIntegers)
        {
            Point p(5, 10);
            Assert::AreEqual(5.0, p.getX());
            Assert::AreEqual(10.0, p.getY());
        }

        // 4. Тест метода getX()
        TEST_METHOD(TestGetX)
        {
            Point p(4.5, 6.7);
            Assert::AreEqual(4.5, p.getX());
        }

        // 5. Тест метода getY()
        TEST_METHOD(TestGetY)
        {
            Point p(4.5, 6.7);
            Assert::AreEqual(6.7, p.getY());
        }

        // 6. Тест оператора равенства == (равные точки)
        TEST_METHOD(TestEqualityOperator_EqualPoints)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 3.5);

            Assert::IsTrue(p1 == p2);
        }

        // 7. Тест оператора равенства == (разные точки)
        TEST_METHOD(TestEqualityOperator_DifferentPoints)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 4.0);
            Point p3(3.0, 3.5);

            Assert::IsFalse(p1 == p2);
            Assert::IsFalse(p1 == p3);
        }

        // 8. Тест оператора неравенства !=
        TEST_METHOD(TestInequalityOperator)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 3.5);
            Point p3(2.5, 4.0);

            Assert::IsFalse(p1 != p2);
            Assert::IsTrue(p1 != p3);
        }

        // 9. Тест оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Point p(3.14, 2.71);
            std::stringstream ss;
            ss << p;

            std::string result = ss.str();
            Assert::IsTrue(result.find("(") != std::string::npos);
            Assert::IsTrue(result.find(")") != std::string::npos);
            Assert::IsTrue(result.find("3.14") != std::string::npos);
            Assert::IsTrue(result.find("2.71") != std::string::npos);
        }

        // 10. Тест оператора вывода << с отрицательными числами
        TEST_METHOD(TestOutputStreamOperator_NegativeNumbers)
        {
            Point p(-5.5, -10.2);
            std::stringstream ss;
            ss << p;

            std::string result = ss.str();
            Assert::IsTrue(result.find("-5.5") != std::string::npos);
            Assert::IsTrue(result.find("-10.2") != std::string::npos);
        }

        // 11. Тест оператора ввода >> (формат (x, y))
        TEST_METHOD(TestInputStreamOperator_ValidFormat)
        {
            Point p;
            std::string input = "(15.5, 20.3)";
            std::stringstream ss(input);

            ss >> p;

            Assert::AreEqual(15.5, p.getX());
            Assert::AreEqual(20.3, p.getY());
        }

        // 12. Тест оператора ввода >> с целыми числами
        TEST_METHOD(TestInputStreamOperator_IntegerValues)
        {
            Point p;
            std::string input = "(10, 20)";
            std::stringstream ss(input);

            ss >> p;

            Assert::AreEqual(10.0, p.getX());
            Assert::AreEqual(20.0, p.getY());
        }

        // 13. Тест оператора ввода >> с отрицательными числами
        TEST_METHOD(TestInputStreamOperator_NegativeValues)
        {
            Point p;
            std::string input = "(-7.5, -12.3)";
            std::stringstream ss(input);

            ss >> p;

            Assert::AreEqual(-7.5, p.getX());
            Assert::AreEqual(-12.3, p.getY());
        }

        // 14. Тест оператора ввода >> с пробелами
        TEST_METHOD(TestInputStreamOperator_WithSpaces)
        {
            Point p;
            std::string input = "(  10  ,   20  )";
            std::stringstream ss(input);

            ss >> p;

            Assert::AreEqual(10.0, p.getX());
            Assert::AreEqual(20.0, p.getY());
        }

        // 15. Тест оператора ввода >> (несколько точек подряд)
        TEST_METHOD(TestInputStreamOperator_MultiplePoints)
        {
            Point p1, p2;
            std::string input = "(1.0, 2.0)(3.0, 4.0)";
            std::stringstream ss(input);

            ss >> p1 >> p2;

            Assert::AreEqual(1.0, p1.getX());
            Assert::AreEqual(2.0, p1.getY());
            Assert::AreEqual(3.0, p2.getX());
            Assert::AreEqual(4.0, p2.getY());
        }

        // 16. Тест цепочечного вывода
        TEST_METHOD(TestChainedOutputStream)
        {
            Point p1(1.0, 2.0);
            Point p2(3.0, 4.0);
            std::stringstream ss;

            ss << p1 << " " << p2;

            std::string result = ss.str();
            Assert::IsTrue(result.find("(1, 2)") != std::string::npos);
            Assert::IsTrue(result.find("(3, 4)") != std::string::npos);
        }

        // 17. Тест цепочечного ввода
        TEST_METHOD(TestChainedInputStream)
        {
            Point p1, p2;
            std::string input = "(1.0,2.0)(3.0,4.0)";
            std::stringstream ss(input);

            ss >> p1 >> p2;

            Assert::AreEqual(1.0, p1.getX());
            Assert::AreEqual(2.0, p1.getY());
            Assert::AreEqual(3.0, p2.getX());
            Assert::AreEqual(4.0, p2.getY());
        }

        // 18. Тест оператора равенства с очень близкими числами
        TEST_METHOD(TestEqualityOperator_VeryCloseNumbers)
        {
            Point p1(0.1 + 0.2, 0.3);
            Point p2(0.3, 0.3);
            Assert::IsTrue(p1 == p2);
        }

        // 19. Тест оператора неравенства с очень близкими числами
        TEST_METHOD(TestInequalityOperator_VeryCloseNumbers)
        {
            Point p1(0.1 + 0.2, 0.3);
            Point p2(0.3, 0.3);
            Assert::IsFalse(p1 != p2);
        }

        // 20. Тест оператора вывода << с нулевыми координатами
        TEST_METHOD(TestOutputStreamOperator_ZeroCoordinates)
        {
            Point p(0, 0);
            std::stringstream ss;
            ss << p;

            std::string result = ss.str();
            Assert::IsTrue(result.find("0") != std::string::npos);
        }

        // 21. Тест оператора ввода >> с нулевыми координатами
        TEST_METHOD(TestInputStreamOperator_ZeroCoordinates)
        {
            Point p;
            std::string input = "(0, 0)";
            std::stringstream ss(input);

            ss >> p;

            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        // 22. Тест сравнения с самим собой
        TEST_METHOD(TestEqualityOperator_SelfComparison)
        {
            Point p(5.0, 10.0);

            Assert::IsTrue(p == p);
        }

        // 23. Тест транзитивности оператора равенства
        TEST_METHOD(TestEqualityOperator_Transitivity)
        {
            Point p1(2.0, 3.0);
            Point p2(2.0, 3.0);
            Point p3(2.0, 3.0);

            Assert::IsTrue(p1 == p2);
            Assert::IsTrue(p2 == p3);
            Assert::IsTrue(p1 == p3);
        }
    };
}
