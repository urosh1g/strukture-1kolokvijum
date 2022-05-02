#include "llnode.h"

template<typename T> LLNode<T>::LLNode(){
	m_next = nullptr;
}

template<typename T> LLNode<T>::LLNode(T podatak){
	m_podatak = podatak;
	m_next = nullptr;
}

template<typename T> LLNode<T>::LLNode(T podatak, LLNode* next){
	m_podatak = podatak;
	m_next = next;
}
