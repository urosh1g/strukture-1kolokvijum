#pragma once
#include "node.h"

template<typename T>
class Queue{
private:
	Node<T>* front, *rear;
public:
	Queue();
	bool empty();
	void AddPriority(float pri, T* data);
	T* dequeue();
	void print();
	~Queue();
};

#include "queue.cpp"
