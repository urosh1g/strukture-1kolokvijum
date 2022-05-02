#include "list.h"

//zadatak na istu foru kao onaj sa teniserima

int main(){
	List lista;
	for(int i = 1; i < 10; i++)
		lista.append(i*i);
	lista.print();
	lista.update(4, 7);
	lista.print();
	return 0;
}
