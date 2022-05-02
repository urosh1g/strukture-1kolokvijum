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

//za neefikasno resenje :D:D
void List::swap_neighbours(Node* prev, Node* current){
	if(!prev){
		head = current->next;
		current->next = head->next;
		head->next = current;
		return;
	}
	prev->next = current->next;
	current->next = current->next->next;
	prev->next->next = current;
}

/*
 * validno, ali neefikasno resenje 
void List::update(int value, int add){
	Node* iter = head, *prev = nullptr;
	while(iter && iter->value != value){
		prev = iter;
		iter = iter->next;
	}
	if(!iter) return;
	iter->value += add;
	while(iter->next){
		if(iter->value < iter->next->value) return;
		swap_neighbours(prev, iter);
		prev = prev->next;
	}
}
*/

/*
 *	Efikasnije resenje, nadji mi trazeni
 *	nadji mi prvi veci
 *	i ubaci trazeni pre prvog veceg
 *	umesto stalnog swapovanja do veceg
 * */
void List::update(int value, int add){
	Node* iter = head, *prev = nullptr;
	while(iter && iter->value != value){
		prev = iter;
		iter = iter->next;
	}
	if(!iter) return;
	iter->value += add;
	Node* n_iter = iter->next, *n_prev = iter;
	while(n_iter && n_iter->value < iter->value){
		n_iter = n_iter->next;
		n_prev = n_prev->next;
	}
	prev->next = iter->next;
	iter->next = n_iter;
	n_prev->next = iter;
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
