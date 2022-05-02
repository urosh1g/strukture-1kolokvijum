#pragma once
#include <iostream>

template <typename T>
struct Node {
	T* data;
	Node* next;
	float pri;
	Node(float pri = 0.f, T* data = new T(), Node* next = nullptr);
	friend std::ostream& operator<<(std::ostream& ostr, Node& n){
		ostr << "[" << n.pri << "|" << *n.data << "]";
		return ostr;
	}
};

#include "node.cpp"
