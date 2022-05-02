#pragma once
#include "llist.h"

template<typename T>
class Stack {
private:
	LList<T> list;
	int count;
public:
	Stack();
	bool empty();
	int size();
	void push(T val);
	T pop();
	T peek();
	void clear();
	void print();
};
#include "stack.cpp"
