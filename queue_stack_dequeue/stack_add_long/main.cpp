#include <iostream>
#include <cstring>
#include "stack.h"

//radi samo za pravilno zadate operande
//ako slucajno naidje neki char koji nije [0-9]
//pogresno racuna
char* AddLong(char* o1, char* o2){
	Stack<char> broj1, broj2, rezultat;

	//inicijalizacija
	for(int i = 0; i < strlen(o1); i++)
		broj1.push(o1[i]);
	for(int i = 0; i < strlen(o2); i++)
		broj2.push(o2[i]);
	int prethodni_prenos = 0;

	while(!broj1.empty() && !broj2.empty()){
		int c1 = broj1.pop() - '0', c2 = broj2.pop() - '0';
		int prenos = (c1 + c2 + prethodni_prenos) / 10;
		char cifra = prenos ? ((c1 + c2 + prethodni_prenos) % 10) + '0' : (c1 + c2 + prethodni_prenos + '0');
		rezultat.push(cifra);
		prethodni_prenos = prenos;
	}

	//jedan od stackova prazan
	Stack<char>* ostalo = broj1.empty() ? &broj2 : &broj1;
	while(!ostalo->empty()){
		int c1 = ostalo->pop() - '0';
		int prenos = (c1 + prethodni_prenos) / 10;
		char cifra = prenos ? ((c1 + prethodni_prenos) % 10) + '0' : (c1 + prethodni_prenos + '0');
		rezultat.push(cifra);
		prethodni_prenos = prenos;
	}
	if(prethodni_prenos == 1) rezultat.push('1');

	//smestanje rezultata u char*
	int size = rezultat.size();
	char* rez_str = new char[size + 1];
	int i;
	for(i = 0; i < size; i++)
		rez_str[i] = rezultat.pop();
	rez_str[i] = '\0';
	return rez_str;
}

int main(){
	char broj1[50], broj2[50];
	std::cin >> broj1 >> broj2;
	std::cout << AddLong(broj1, broj2) << std::endl;
	return 0;
}
