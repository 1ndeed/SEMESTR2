#pragma once

namespace containers {

    /**
     * @brief Класс узла односвязного списка
     * @tparam T тип данных, хранящихся в узле
     */
    template<typename T>
    class Node {
    public:
        T data;
        Node<T>* next;

        /**
         * @brief Конструктор узла
         * @param value - значение для хранения в узле
         */
        explicit Node(const T& value);
    };

} 
