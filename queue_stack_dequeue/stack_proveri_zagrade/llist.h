#pragma once
#include "llnode.h"

template<typename T>
class LList {
public:
	LLNode<T> *head, *tail;
public:
	LList();
	bool empty();
	virtual void insert_tail(T);
	virtual void insert_head(T);
	virtual T remove_tail();
	virtual T remove_head();
	void print();
	void clear();
	~LList();
};

#include "llist.cpp"
