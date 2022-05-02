#pragma once

struct Node {
	int value;
	Node* next;
	Node(int value = 0, Node* next = nullptr);
};
