#include "queue.h"
#include <iostream>

struct Data {
	std::string value;
	Data(std::string val):
		value(val)
	{}
	friend std::ostream& operator<<(std::ostream& ostr, Data& d){
		ostr << d.value;
		return ostr;
	}
};

int main(){
	Queue<Data> q;
	q.AddPriority(1.1f, new Data("banana"));
	q.AddPriority(2.4f, new Data("perica"));
	q.AddPriority(0.2f, new Data("kuka"));
	q.AddPriority(1.1f, new Data("posleBanane"));
	q.AddPriority(1.2f, new Data("motika"));
	q.AddPriority(1.3f, new Data("asd"));
	q.AddPriority(7.7f, new Data("123"));
	q.print();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.print();
	return 0;
}
