#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class LLNode {
public:
	T m_podatak;
	LLNode* m_next;

	LLNode();
	LLNode(T);
	LLNode(T, LLNode*);
};


struct LListException : public std::runtime_error {
	std::string m_msg;
	LListException(std::string msg) :
		std::runtime_error(msg)
	{
		m_msg = msg ;
	}
	const char* what() const throw(){
		return m_msg.c_str();
	}
};

#include "llnode.cpp"
