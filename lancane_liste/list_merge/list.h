#pragma once
#include "node.h"

class List {
public:
	Node *head, *tail;
public:
	List(Node* head = nullptr);
	bool empty();
	void insert_head(int value);
	void append(int value);
	int remove_head();
	void print();
	void clear();
	~List();
};
