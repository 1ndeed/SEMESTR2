#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <sstream>
#include "Node.h"

namespace containers {

    /**
     * @brief Класс линейного односвязного списка
     * @tparam T тип данных, хранящихся в списке
     */
    template<typename T>
    class LinkedList {
    private:
        Node<T>& head;
        size_t size;

        /**
         * @brief Копирует содержимое другого списка
         * @param other - список для копирования
         */
        void copyFrom(const LinkedList<T>& other);

        /**
         * @brief Очищает список (вспомогательный метод)
         */
        void destroy();

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        LinkedList();

        /**
         * @brief Конструктор со списком инициализации
         * @param init - список инициализации
         */
        LinkedList(const std::initializer_list init);

        /**
         * @brief Конструктор копирования
         * @param other - другой список
         */
        LinkedList(const LinkedList&& other);

        /**
         * @brief Деструктор
         */
        ~LinkedList();

        /**
         * @brief Оператор присваивания
         * @param other - другой список
         * @return ссылка на текущий объект
         */
        LinkedList& operator=(const LinkedList&& other);

        /**
         * @brief Вставка элемента в конец списка
         * @param value - значение элемента
         */
        void push_back(const T& value);

        /**
         * @brief Вставка элемента в начало списка
         * @param value - значение элемента
         */
        void push_front(const T& value);

        /**
         * @brief Вставка элемента по индексу
         * @param index - позиция для вставки
         * @param value - значение элемента
         */
        void insert(const size_t index, const T& value);

        /**
         * @brief Удаление элемента из конца списка
         */
        void pop_back();

        /**
         * @brief Удаление элемента из начала списка
         */
        void pop_front();

        /**
         * @brief Удаление элемента по индексу
         * @param index - позиция элемента
         */
        void erase(const size_t index);

        /**
         * @brief Удаление элемента по значению (первое вхождение)
         * @param value - значение для удаления
         * @return true, если элемент найден и удален
         */
        bool remove(const T& value);

        /**
         * @brief Поиск элемента по значению
         * @param value - значение для поиска
         * @return индекс элемента или -1, если не найден
         */
        int find(const T& value) const;

        /**
         * @brief Изменение элемента по индексу
         * @param index - позиция элемента
         * @param value - новое значение
         */
        void modify(const size_t index, const T& value);

        /**
         * @brief Получение элемента по индексу
         * @param index - позиция элемента
         * @return ссылка на элемент
         */
        T& operator[](const size_t index);

        /**
         * @brief Получение элемента по индексу (константная версия)
         * @param index - позиция элемента
         * @return константная ссылка на элемент
         */
        const T& operator[](const size_t index) const;

        /**
         * @brief Получение размера списка
         * @return количество элементов
         */
        size_t getSize() const;

        /**
         * @brief Проверка, пуст ли список
         * @return true, если список пуст
         */
        bool isEmpty() const;

        /**
         * @brief Очистка списка
         */
        void clear();

        /**
         * @brief Сериализация в строку
         * @return строковое представление списка
         */
        std::string ToString() const;

        /**
         * @brief Оператор вывода
         */
        template<typename T>
        std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);
    };

} 
