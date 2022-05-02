#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists){
	ListNode* merged = nullptr, *ptr = nullptr;
	int min, index;
	int empty;
	while(true){
		empty = 0;
		min = INT_MAX;
		for(int i = 0; i < lists.size(); i++){
			if(lists[i]){
				if(lists[i]->val < min){
					index = i;
					min = lists[i]->val;
				}
			}
			else empty++;
		}
		if(empty == lists.size()) break;
		lists[index] = lists[index]->next;
		if(!merged)
			merged = ptr = new ListNode(min);
		else {
			ptr->next = new ListNode(min);
			ptr = ptr->next;
		}
	}
	return merged;
}

int main(){
	ListNode* lista1 = new ListNode(1);
	ListNode* lista2 = new ListNode(1);
	ListNode* lista3 = new ListNode(2);
	ListNode* tmp = lista1;
	tmp->next = new ListNode(4);
	tmp = tmp->next;
	tmp->next = new ListNode(5);
	tmp = lista2;
	tmp->next = new ListNode(3);
	tmp = tmp->next;
	tmp->next = new ListNode(4);
	tmp = lista3;
	tmp->next = new ListNode(6);
	vector<ListNode*> liste;
	liste.push_back(lista1);
	liste.push_back(lista2);
	liste.push_back(lista3);
	tmp = mergeKLists(liste);
	while(tmp){
		std::cout << tmp->val << "->";
		tmp = tmp->next;
	}
	std::cout << std::endl;
	return 0;
}
