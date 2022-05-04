#include "igrac.h"

Igrac::Igrac():
	m_broj(0)
{
	m_oznaka = m_ime = m_prezime = m_reprezentacija = nullptr;
}

Igrac::Igrac(char* oznaka, char* ime, char* prezime, char* reprezentacija, int broj):
	m_broj(broj)
{
	m_oznaka = new char[strlen(oznaka) + 1];
	strcpy(m_oznaka, oznaka);
	m_ime = new char[strlen(ime) + 1];
	m_prezime = new char[strlen(prezime) + 1];
	m_reprezentacija = new char[strlen(reprezentacija) + 1];
	strcpy(m_ime, ime);
	strcpy(m_prezime, prezime);
	strcpy(m_reprezentacija, reprezentacija);
}

Igrac& Igrac::operator=(const Igrac& other){
	m_broj = other.m_broj;
	delete[] m_oznaka;
	m_oznaka = new char[strlen(other.m_oznaka) + 1];
	strcpy(m_oznaka, other.m_oznaka);
	delete[] m_ime;
	m_ime = new char[strlen(other.m_ime) + 1];
	delete[] m_prezime;
	m_prezime = new char[strlen(other.m_prezime) + 1];
	delete[] m_reprezentacija;
	m_reprezentacija = new char[strlen(other.m_reprezentacija) + 1];
	strcpy(m_ime, other.m_ime);
	strcpy(m_prezime, other.m_prezime);
	strcpy(m_reprezentacija, other.m_reprezentacija);
	return *this;
}

Igrac::~Igrac(){
	delete[] m_oznaka;
	delete[] m_ime;
	delete[] m_prezime;
	delete[] m_reprezentacija;
}

std::ostream& operator<<(std::ostream& ostr, const Igrac& igrac){
	ostr << igrac.m_oznaka << " " << igrac.m_ime << " " << igrac.m_prezime << std::endl;
	return ostr;
}
