#include "llist.h"
#include "llnode.h"

template<typename T>
LList<T>::LList(){
	head = tail = nullptr;
}

template<typename T>
bool LList<T>::empty(){
	return head == nullptr;
}

template<typename T>
void LList<T>::insert_head(T val){
	if(empty()){
		tail = head = new LLNode<T>(val);
		return;
	}
	head = new LLNode<T>(val, head);
}

template<typename T>
void LList<T>::insert_tail(T val){
	if(empty()){
		tail = head = new LLNode<T>(val);
	}
	tail->m_next = new LLNode<T>(val);
	tail = tail->m_next;
}

template<typename T>
T LList<T>::remove_tail(){
	LLNode<T>* prev = head;
	if(head == tail) {
		T podatak = tail->m_podatak;
		delete tail;
		head = tail = nullptr;
		return podatak;
	}
	while(prev->m_next != tail)
		prev = prev->m_next;
	T podatak = tail->m_podatak;
	delete tail;
	prev->m_next = nullptr;
	tail = prev;
	return podatak;
}

template<typename T>
T LList<T>::remove_head(){
	if(empty())
		throw new LListException("Removing from empty list!");
	LLNode<T>* toDelete = head;
	head = head->m_next;
	T podatak = toDelete->m_podatak;
	delete toDelete;
	return podatak;

}

template<typename T>
void LList<T>::print(){
	LLNode<T>* iter = head;
	while(iter != nullptr){
		if(iter->m_next != nullptr)
			std::cout << iter->m_podatak << "->";
		else 
			std::cout << iter->m_podatak;
		iter = iter->m_next;
	}
	std::cout << std::endl;
}

template<typename T>
void LList<T>::clear(){
	while(!empty())
		remove_head();
}

template<typename T>
LList<T>::~LList(){
	clear();
}
