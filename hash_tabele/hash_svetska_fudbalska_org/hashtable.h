#pragma onca
#include "igrac.h"

class HashTable {
//pomocni tipovi
private:
	enum Status {
		EMPTY,
		FREE,
		OCCUPIED
	};
	struct Entry {
		Igrac igrac;
		Status status;
		Entry(Igrac i = Igrac(), Status s = EMPTY):
			igrac(i),
			status(s)
		{}
		Entry& operator=(Entry other){
			igrac = other.igrac;
			status = other.status;
			return *this;
		}
	};
//klasa
private:
	Entry* array;
	int m_size, m_count;
	unsigned int size_bits;
	unsigned int hashcode(char* oznaka);
	unsigned int compress(unsigned int hashcode);
	unsigned int h(char* oznaka);
	unsigned int c(int i);
	bool available(int pos);
public:
	HashTable(int size = 1024);
	void print();
	void insert(const Igrac& igrac);
	Igrac find(char* oznaka);
};
