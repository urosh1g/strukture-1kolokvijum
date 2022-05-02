#include <iostream>
#include <cmath>
#include "stack.h"

bool isnum(char c){
	return c >= '0' && c <= '9';
}

bool operacija(char c){
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int operisi(int a, int b, char op){
	switch(op){
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return 0;
	}
}

int izracunaj(std::string postfix){
	Stack<int> stack;
	std::string num;
	for(int i = 0; i < postfix.length(); i++){
		num = "";
		if(postfix[i] == ' ')  continue;
		if(operacija(postfix[i])){
			int b = stack.pop();
			int a = stack.pop();
			stack.push(operisi(a, b, postfix[i]));
			continue;
		}
		while(isnum(postfix[i])){
			num += postfix[i++];
		}
		stack.push(std::stoi(num));
	}
	return stack.peek();
}

int main(){
	std::string izraz;
	std::getline(std::cin, izraz);
	std::cout << izracunaj(izraz) << std::endl;
	return 0;
}
