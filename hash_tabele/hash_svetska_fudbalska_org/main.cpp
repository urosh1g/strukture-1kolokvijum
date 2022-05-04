#include "hashtable.h"

int main(){
	HashTable tabela;
	Igrac i1((char*)"00246462703", (char*)"Uros", (char*)"Lazic", (char*)"Srbija", 5);
	Igrac i2((char*)"00147182000", (char*)"Nikola", (char*)"Stojiljkovic", (char*)"Srbija", 1);
	Igrac i3((char*)"00147552601", (char*)"Stefan", (char*)"Stankovic", (char*)"Srbija", 2);
	Igrac i4((char*)"00147583402", (char*)"Aleksandar", (char*)"Stojkovic", (char*)"Srbija", 3);
	Igrac i5((char*)"00147402103", (char*)"Ksenija", (char*)"Seizovic", (char*)"Srbija", 4);
	tabela.insert(i1);
	tabela.insert(i2);
	tabela.insert(i3);
	tabela.insert(i4);
	tabela.insert(i5);
	tabela.print();
	Igrac trazeni = tabela.find((char*)"00147583402");
	std::cout << "Trazeni igrac : " << trazeni << std::endl;
	return 0;
}
