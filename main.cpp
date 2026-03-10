#include <iostream>
#include "Rectangle.h"
#include "point.h"
#include <clocale>

using namespace std;
/**
* @brief точка входа в программу
* @return 0, если программа выполнена правильно
*/
int main(void)
{
    setlocale(LC_ALL, "Russian");
    Point a(0, 0);
    Point b(0, 4);
    Point c(3, 4);
    Point d(3, 0);

    Rectangle rect1(a, b, c, d);

    cout << "Прямоугольник 1: " << rect1 << endl;
    cout << "Площадь: " << rect1.getS() << endl;
    cout << "Периметр: " << rect1.getPerimeter() << endl;
    cout << "Ширина: " << rect1.getWidth() << ", Высота: " << rect1.getHeight() << endl;
    cout << endl;


    Rectangle rect2;
    cout << "Введите 4 точки прямоугольника (x y для каждой точки):" << endl;
    cin >> rect2;
    cout << "Вы ввели: " << rect2 << endl;
    cout << "Площадь: " << rect2.getS() << endl;
    cout << "Периметр: " << rect2.getPerimeter() << endl;
    return 0;
}

