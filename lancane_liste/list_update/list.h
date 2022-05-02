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
	void update(int value, int add);
	int remove_head();
	void print();
	void clear();
	~List();
private:
	void swap_neighbours(Node* prev, Node* current);
};
