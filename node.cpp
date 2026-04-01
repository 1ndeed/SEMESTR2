#include "Node.h"

namespace containers {

	template<typename T>
	Node<T>::Node(const T& value) : data(value), next(nullptr) {}

	// Явная инстанциация для типа int
	template class Node<int>;

} 
