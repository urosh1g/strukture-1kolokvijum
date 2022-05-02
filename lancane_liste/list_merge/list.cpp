#include <iostream>
#include "list.h"

List::List(Node* hhead){
	if(!hhead){
		head = tail = nullptr;
		return;
	}
	Node* iter = hhead;
	while(iter){
		append(iter->value);
		iter = iter->next;
	}
}

bool List::empty(){
	return head == nullptr;
}

void List::insert_head(int value){
	head = new Node(value, head);
	if(!tail) tail = head;
}

void List::append(int value){
	if(empty()){
		insert_head(value);
		return;
	}
	tail->next = new Node(value, nullptr);
	tail = tail->next;
}

int List::remove_head(){
	if(!head) return -1;
	int to_return = head->value;
	Node* to_delete = head;
	head = head->next;
	delete to_delete;
	to_delete = nullptr;
	return to_return;
}

void List::print(){
	Node* iter = head;
	while(iter){
		std::cout << iter->value;
		if(iter->next)
			std::cout << "->";
		iter = iter->next;
	}
	std::cout << std::endl;
}

void List::clear(){
	while(!empty())
		remove_head();
}

List::~List(){
	clear();
}
