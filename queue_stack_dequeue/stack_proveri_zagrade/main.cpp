#include <iostream>
#include <cmath>
#include "stack.h"

bool is_opening(char bracket){
	return bracket == '(' || bracket == '[' || bracket == '{';
}

bool is_closing(char bracket){
	return bracket == ')' || bracket == ']' || bracket == '}';
}

bool checkExpression(std::string izraz){
	Stack<char> brackets;
	for(int i = 0; i < izraz.length(); i++){
		if(is_opening(izraz[i]))
			brackets.push(izraz[i]);
		else if(is_closing(izraz[i])){
			if(brackets.empty()) return false;
			brackets.pop();
		}
	}
	return true;
}

int main(){
	std::string izraz;
	std::getline(std::cin, izraz);
	std::cout << checkExpression(izraz) << std::endl;
	return 0;
}
