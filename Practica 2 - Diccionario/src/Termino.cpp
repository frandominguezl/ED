/* @file Termino.cpp
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <string>
#include "Termino.h"
#include "Vector_Dinamico.h"

Termino::Termino(){
	this->palabra = null;
	this->definiciones = Vector_Dinamico<string*> int(0);
	this->num_definiciones = definiciones.size();
}

Termino::Termino(string palabra, string* definiciones){
	this->palabra = palabra;
	this->definiciones = Vector_Dinamico<string*> v(definiciones.length());
	this->num_definiciones = definiciones.size();

	for(int i=0; i<num_definiciones; i++){
		this->definiciones[i] = definiciones[i];
	}
}

Termino::Termino(const Termino& t){
	this->palabra = t.getPalabra();
	this->definiciones = t.getDefiniciones();
	this->num_definiciones = t.getNumDefiniciones();
}

void Termino::setPalabra(string palabra){
	this->palabra = palabra;
}

void Termino::aniadeDefinicion(string* def){
	this->num_definiciones++;
	this->definiciones.resize(num_definiciones);
	this->definiciones[num_definiciones] = def;
}

Termino& Termino::operator =(const Termino& original){
	if(this != &original){
		this->palabra = original.getPalabra();
		this->definiciones = original.getDefiniciones();
		this->num_definiciones = original.getNumDefiniciones();
	}

	return *this;
}

ostream& operator <<(ostream &os, const Termino &p){
	os << p.palabra; << endl;

	for(int i=0; i<p.num_definiciones; i++){
		os << p.definiciones[i] << endl;
	}

	return os;
}

istream& operator >>(istream &is, const Termino &p){
	is >> p.getPalabra(); >> p.getNumDefiniciones();

	for(int i=0; i<p.num_definiciones; i++){
		is >> p.definiciones[i] << endl;
	}

	return is;
}