#include <iostream>
#include "LinkedList.h"
#include <clocale>

using namespace containers;

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена успешно
 */
int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== Демонстрация работы с линейным односвязным списком ===\n\n";


    std::cout << "1. Конструктор со списком инициализации:\n";
    LinkedList<int> list1 = { 10, 20, 30, 40, 50 };
    std::cout << "list1: " << list1 << "\n";
    std::cout << "Размер: " << list1.getSize() << "\n";
    std::cout << "Пустой? " << (list1.isEmpty() ? "да" : "нет") << "\n\n";

    std::cout << "2. Конструктор копирования:\n";
    LinkedList<int> list2(list1);
    std::cout << "list2 (копия list1): " << list2 << "\n\n";

    std::cout << "3. Оператор присваивания:\n";
    LinkedList<int> list3;
    list3 = list1;
    std::cout << "list3 (присвоен list1): " << list3 << "\n\n";

    std::cout << "4. Вставка элементов:\n";
    list1.push_back(60);
    std::cout << "После push_back(60): " << list1 << "\n";

    list1.push_front(5);
    std::cout << "После push_front(5): " << list1 << "\n";

    list1.insert(3, 25);
    std::cout << "После insert(3, 25): " << list1 << "\n\n";

    std::cout << "5. Удаление элементов:\n";
    list1.pop_back();
    std::cout << "После pop_back(): " << list1 << "\n";

    list1.pop_front();
    std::cout << "После pop_front(): " << list1 << "\n";

    list1.erase(2);
    std::cout << "После erase(2): " << list1 << "\n";

    list1.remove(30);
    std::cout << "После remove(30): " << list1 << "\n\n";

    std::cout << "6. Поиск элемента:\n";
    std::cout << "list1: " << list1 << "\n";
    int findValue = 40;
    int index = list1.find(findValue);
    if (index != -1) {
        std::cout << "Элемент " << findValue << " найден на позиции " << index << "\n";
    }
    else {
        std::cout << "Элемент " << findValue << " не найден\n";
    }

    findValue = 100;
    index = list1.find(findValue);
    if (index != -1) {
        std::cout << "Элемент " << findValue << " найден на позиции " << index << "\n";
    }
    else {
        std::cout << "Элемент " << findValue << " не найден\n";
    }
    std::cout << "\n";

    std::cout << "7. Модификация элемента:\n";
    std::cout << "До изменения: " << list1 << "\n";
    list1.modify(1, 99);
    std::cout << "После modify(1, 99): " << list1 << "\n\n";


    std::cout << "8. Оператор доступа по индексу:\n";
    std::cout << "list1[0] = " << list1[0] << "\n";
    std::cout << "list1[2] = " << list1[2] << "\n";
    list1[1] = 100;
    std::cout << "После list1[1] = 100: " << list1 << "\n\n";

    std::cout << "9. Итерация по элементам:\n";
    std::cout << "Элементы списка: ";
    for (size_t i = 0; i < list1.getSize(); ++i) {
        std::cout << list1[i];
        if (i < list1.getSize() - 1) std::cout << " -> ";
    }
    std::cout << "\n\n";


    std::cout << "10. Работа с пустым списком:\n";
    LinkedList<int> emptyList;
    std::cout << "Пустой список: " << emptyList << "\n";
    std::cout << "Размер: " << emptyList.getSize() << "\n";
    std::cout << "Пустой? " << (emptyList.isEmpty() ? "да" : "нет") << "\n";

    emptyList.push_back(42);
    std::cout << "После push_back(42): " << emptyList << "\n";
    std::cout << "Размер: " << emptyList.getSize() << "\n\n";

    std::cout << "11. Очистка списка:\n";
    std::cout << "До очистки: " << list2 << "\n";
    list2.clear();
    std::cout << "После clear(): " << list2 << "\n";
    std::cout << "Размер: " << list2.getSize() << "\n\n";

    std::cout << "12. Проверка на исключения:\n";
    LinkedList<int> testList;
    try {
        std::cout << "Попытка получить элемент из пустого списка: ";
        testList[0];
    }
    catch (const std::out_of_range& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    try {
        std::cout << "Попытка удалить из пустого списка: ";
        testList.pop_front();
    }
    catch (const std::out_of_range& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    try {
        std::cout << "Попытка вставить по неверному индексу: ";
        testList.insert(5, 10);
    }
    catch (const std::out_of_range& e) {
        std::cout << "Исключение: " << e.what() << "\n";
    }

    std::cout << "\nПрограмма завершена успешно.\n";
    return 0;
}
