#include "LinkedList.h"
#include <stdexcept>

namespace containers {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        os << list.ToString();
        return os;
    }
    template<typename T>
    void LinkedList<T>::copyFrom(const LinkedList<T>& other) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    template<typename T>
    void LinkedList<T>::clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    template<typename T>
    LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

    template<typename T>
    LinkedList<T>::LinkedList(const std::initializer_list<T> init) : head(nullptr), size(0) {
        for (const auto& value : init) {
            push_back(value);
        }
    }

    template<typename T>
    LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr), size(0) {
        copyFrom(other);
    }

    template<typename T>
    LinkedList<T>::~LinkedList() {
        clear();
    }

    template<typename T>
    LinkedList<T>& const LinkedList<T>::operator=(const LinkedList<T>& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    template<typename T>
    void LinkedList<T>::push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++size;
    }

    template<typename T>
    void LinkedList<T>::push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        ++size;
    }

    template<typename T>
    void LinkedList<T>::insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        if (index == 0) {
            push_front(value);
            return;
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        current->next = newNode;
        ++size;
    }

    template<typename T>
    void LinkedList<T>::pop_back() {
        if (isEmpty()) {
            throw std::out_of_range("Список пуст");
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        --size;
    }

    template<typename T>
    void LinkedList<T>::pop_front() {
        if (isEmpty()) {
            throw std::out_of_range("Список пуст");
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        --size;
    }

    template<typename T>
    void LinkedList<T>::erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        if (index == 0) {
            pop_front();
            return;
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        --size;
    }

    template<typename T>
    bool LinkedList<T>::remove(const T& value) {
        int index = find(value);
        if (index != -1) {
            erase(index);
            return true;
        }
        return false;
    }

    template<typename T>
    int LinkedList<T>::find(const T& value) const {
        Node<T>* current = head;
        size_t index = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return static_cast<int>(index);
            }
            current = current->next;
            ++index;
        }
        return -1;
    }

    template<typename T>
    void LinkedList<T>::modify(size_t index, const T& value) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = value;
    }

    template<typename T>
    T& LinkedList<T>::operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    template<typename T>
    const T& LinkedList<T>::operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    template<typename T>
    size_t LinkedList<T>::getSize() const {
        return size;
    }

    template<typename T>
    bool LinkedList<T>::isEmpty() const {
        return size == 0;
    }


    template<typename T>
    std::string LinkedList<T>::ToString() const {
        std::stringstream ss;
        ss << "[";
        Node<T>* current = head;
        while (current != nullptr) {
            ss << current->data;
            if (current->next != nullptr) {
                ss << ", ";
            }
            current = current->next;
        }
        ss << "]";
        return ss.str();
    }

    template class LinkedList<int>;

} 
