#include <iostream>
#include <cmath>
#include "stack.h"

bool isnum(char c){
	return c >= '0' && c <= '9';
}

bool operacija(char c){
	return c == '+' || c == '-' || c == '*' || c == '/';
}

float operisi(float a, float b, char op){
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


//izraz nema blanko znake i svi operandi su jednocifreni
float izracunaj(std::string prefix){
	Stack<float> stack;
	std::string num;
	for(int i = prefix.length() - 1; i >= 0; i--){
		num = "";
		if(isnum(prefix[i]))
			stack.push(prefix[i] - '0');
		if(operacija(prefix[i])){
			float a = stack.pop();
			float b = stack.pop();
			stack.push(operisi(a, b, prefix[i]));
			continue;
		}
	}
	return stack.peek();
}

int main(){
	std::string izraz;
	std::getline(std::cin, izraz);
	std::cout << izracunaj(izraz) << std::endl;
	return 0;
}
