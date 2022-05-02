#include <iostream>
#include <limits.h>
#include "list.h"

Node* merge(Node* h1, Node* h2){
	Node* new_list = nullptr, *iter = nullptr;
	int to_insert;
	if(h1->value > h2->value){
		to_insert = h2->value;
		h2 = h2->next;
	}
	else {
		to_insert = h1->value;
		h1 = h1->next;
	}
	new_list = iter = new Node(to_insert);
	while(h1 && h2){
		if(h1->value > h2->value){
			to_insert = h2->value;
			h2 = h2->next;
		}
		else {
			to_insert = h1->value;
			h1 = h1->next;
		}
		iter->next = new Node(to_insert);
		iter = iter->next;
	}
	Node* others = h1 ? h1 : h2;
	while(others){
		iter->next = new Node(others->value);
		iter = iter->next;
		others = others->next;
	}
	return new_list;
}

/*
 * U sustini ovaj algoritam bi trebalo da radi za N lancanih listi
 * */

Node* merge(Node* h1, Node* h2, Node*h3){
	List** lista = new List*[4];
	int min, index = -1;
	lista[0] = new List(h1);
	lista[1] = new List(h2);
	lista[2] = new List(h3);
	//izlazna lista
	lista[3] = new List();
	int empty = 0;
	while(empty != 3){
		empty = 3;
		min = INT_MAX;
		for(int i = 0; i < 3; i++){
			if(!lista[i]->empty()){
				if(lista[i]->head->value < min){
					index = i;
					min = lista[i]->head->value;
					empty--;
				}
			}
			else
				empty++;
		}
		lista[index]->remove_head();
		lista[3]->append(min);
	}
	return lista[3]->head;
}

int main(){
	List *list1, *list2, *list3;
	int ulaz;
	std::cout << "Insert first list" << std::endl;
	list1 = new List();
	while(1){
		std::cin >> ulaz;
		if(ulaz == 0) break;
		list1->append(ulaz);
	}
	std::cout << "Insert second list" << std::endl;
	list2 = new List();
	while(1){
		std::cin >> ulaz;
		if(ulaz == 0) break;
		list2->append(ulaz);
	}
	std::cout << "Insert third list" << std::endl;
	list3 = new List();
	while(1){
		std::cin >> ulaz;
		if(ulaz == 0) break;
		list3->append(ulaz);
	}
	list1->print();
	list2->print();
	list3->print();
	Node* tmp = merge(list1->head, list2->head, list3->head);
	Node* iter = tmp;
	while(iter){
		std::cout << iter->value;
		if(iter->next)
			std::cout << "->";
		iter = iter->next;
	}
	std::cout << std::endl;
	delete list1;
	delete list2;
	return 0;
}
