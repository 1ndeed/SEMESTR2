
#include <iostream>
#include <vector>
#include <memory>
#include "Square.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        std::cout << "=== Демонстрация работы с классами Polygon и Square ===\n\n";

        std::cout << "1. Создание квадрата через точки:\n";
        geometry::Point p1(0, 0);
        geometry::Point p2(0, 2);
        geometry::Point p3(2, 2);
        geometry::Point p4(2, 0);

        geometry::Square square1(p1, p2, p3, p4);
        std::cout << "Квадрат 1: " << square1 << "\n";
        std::cout << "Площадь: " << square1.getArea() << "\n";
        std::cout << "Периметр: " << square1.getPerimeter() << "\n";
        std::cout << "Радиус описанной окружности: " << square1.getCircumradius() << "\n\n";

        std::cout << "2. Создание квадрата через пары чисел:\n";
        geometry::Square square2(1, 1, 1, 4, 4, 4, 4, 1);
        std::cout << "Квадрат 2: " << square2 << "\n";
        std::cout << "Площадь: " << square2.getArea() << "\n";
        std::cout << "Периметр: " << square2.getPerimeter() << "\n";
        std::cout << "Радиус описанной окружности: " << square2.getCircumradius() << "\n\n";

        std::cout << "3. Коллекция объектов базового типа:\n";
        std::vector<std::unique_ptr<geometry::Polygon>> polygons;

        polygons.push_back(std::make_unique<geometry::Square>(square1));
        polygons.push_back(std::make_unique<geometry::Square>(square2));

        polygons.push_back(std::make_unique<geometry::Square>(5, 5, 5, 8, 8, 8, 8, 5));

        std::cout << "Итерация по коллекции:\n";
        for (size_t i = 0; i < polygons.size(); ++i) {
            std::cout << "Объект " << (i + 1) << ": " << *polygons[i] << "\n";
            std::cout << "  Площадь: " << polygons[i]->getArea() << "\n";
            std::cout << "  Периметр: " << polygons[i]->getPerimeter() << "\n";
            std::cout << "  Радиус описанной окружности: " << polygons[i]->getCircumradius() << "\n\n";
        }

        std::cout << "4. Демонстрация операторов сравнения:\n";
        geometry::Square square3(0, 0, 0, 2, 2, 2, 2, 0);
        geometry::Square square4(0, 0, 0, 2, 2, 2, 2, 0);
        geometry::Square square5(0, 0, 0, 3, 3, 3, 3, 0);

        std::cout << "square3 == square4: " << (square3 == square4 ? "true" : "false") << "\n";
        std::cout << "square3 == square5: " << (square3 == square5 ? "true" : "false") << "\n";

        std::cout << "5. Демонстрация статического метода ToString:\n";
        std::cout << geometry::Square::ToString(square1) << "\n\n";

        std::cout << "6. Попытка создания некорректного квадрата (ожидается исключение):\n";
        try {
            geometry::Square invalidSquare(0, 0, 0, 2, 2, 2, 3, 0);
        }
        catch (const std::exception& e) {
            std::cout << "Исключение: " << e.what() << "\n";
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nПрограмма завершена успешно.\n";
    return 0;
}
