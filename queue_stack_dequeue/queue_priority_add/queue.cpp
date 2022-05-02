#include "queue.h"
#include <iostream>

template<typename T>
Queue<T>::Queue(){
	front = rear = nullptr;
}

template<typename T>
bool Queue<T>::empty(){
	return front == nullptr;
}

template<typename T>
void Queue<T>::AddPriority(float pri, T* data){
	if(empty()){
		front = rear = new Node<T>(pri, data, nullptr);
		return;
	}
	Node<T>* iter = front, *prev = nullptr;
	//0.0->0.2->0.2->1.2
	while(iter && iter->pri < pri){
		prev = iter;
		iter = iter->next;
	}
	if(!prev){
		front = new Node<T>(pri, data, front);
		return;
	}
	prev->next = new Node<T>(pri, data, prev->next);
}

template<typename T>
T* Queue<T>::dequeue(){
	if(empty()) return nullptr;
	Node<T>* to_delete = front;
	front = front->next;
	T* to_return = to_delete->data;
	delete to_delete;
	return to_return;
}

template<typename T>
void Queue<T>::print(){
	Node<T>* iter = front;
	while(iter){
		std::cout << *iter;
		if(iter->next) std::cout << "->";
		iter = iter->next;
	}
	std::cout << std::endl;
}

template<typename T>
Queue<T>::~Queue(){
	while(!empty())
		delete dequeue();
}
