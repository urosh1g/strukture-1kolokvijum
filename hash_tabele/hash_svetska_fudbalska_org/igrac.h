#pragma once
#include <iostream>
#include <cstring>

class Igrac {
private:
	char *m_oznaka, *m_ime, *m_prezime, *m_reprezentacija;
	int m_broj;
public:
	Igrac();
	Igrac(char* oznaka, char* ime, char* prezime, char* reprezentacija, int broj);
	Igrac& operator=(const Igrac& other);
	friend std::ostream& operator<<(std::ostream& ostr, const Igrac& igrac);
	~Igrac();
	friend class HashTable;
};
