#include "stack.h"

template<typename T>
Stack<T>::Stack():
	count(0)
{
}

template<typename T>
bool Stack<T>::empty(){
	return count <= 0;
}

template<typename T>
int Stack<T>::size(){
	return count;
}

template<typename T>
void Stack<T>::push(T val){
	list.insert_head(val);
	count++;
}

template<typename T>
T Stack<T>::pop(){
	count--;
	return list.remove_head();
}

template<typename T>
T Stack<T>::peek(){
	if(!empty())
		return list.head->m_podatak;
}

template<typename T>
void Stack<T>::clear(){
	list.clear();
}

template<typename T>
void Stack<T>::print(){
	LLNode<T>* tmp = list.head;
	while(tmp){
		if(tmp->m_next)std::cout << tmp->m_podatak << "->";
		else std::cout << tmp->m_podatak;
		tmp = tmp->m_next;
	}
	std::cout << std::endl;
}
