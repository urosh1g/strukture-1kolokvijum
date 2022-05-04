#include <iostream>
#include <cmath>
#include "hashtable.h"

using uint = unsigned int;

HashTable::HashTable(int size):
	m_size(size),
	m_count(0),
	size_bits(log2(size))
{
	array = new Entry[m_size];
}

//kreci od indeksa 3, 6 jedinstvene cifre + 2 za godinu rodjenja
uint HashTable::hashcode(char* oznaka){
	uint hash = 0U;
	for(int i = 3; i < strlen(oznaka); i++){
		uint cifra = (uint)(oznaka[i] - '0');
		hash = (hash << 4) ^ cifra;
	}
	return hash;
}

uint HashTable::compress(uint hashcode){
	float fi = (sqrt(5) - 1) / 2;
	uint constant = fi * pow(2, sizeof(uint)*8);
	return (hashcode * constant) >> (uint)(sizeof(uint)*8 - size_bits);
}

uint HashTable::h(char* oznaka){
	return compress(hashcode(oznaka));
}

uint HashTable::c(int i){
	return i*i;
}

void HashTable::print(){
	for(int i = 0; i < m_size; i++)
		if(array[i].status != EMPTY)
			std::cout << "[" << i << "] " << array[i].igrac << std::endl;
}

bool HashTable::available(int pos){
	return array[pos].status != OCCUPIED;
}

void HashTable::insert(const Igrac& igrac){
	int pos = h(igrac.m_oznaka);
	for(int i = 0; i < m_size; i++){
		int index = (pos + c(i)) % m_size;
		if(available(index)){
			array[index].igrac = igrac;
			array[index].status = OCCUPIED;
			return;
		}
	}
}

Igrac HashTable::find(char* oznaka){
	int pos = h(oznaka);
	for(int i = 0; i < m_size; i++){
		int index = (pos + c(i)) % m_size;
		if(!available(index) && strcmp(array[index].igrac.m_oznaka, oznaka) == 0)
			return array[index].igrac;
		if(array[index].status == EMPTY)
			break;
	}
	return Igrac();
}
