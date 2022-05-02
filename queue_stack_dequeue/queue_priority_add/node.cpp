#include "node.h"

template<typename T>
Node<T>::Node(float prioritet, T* data, Node* next):
	pri(prioritet),
	data(data),
	next(next)
{
}
