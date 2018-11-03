/* @file Termino.cpp
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <string>
#include "Termino.h"
#include "Vector_Dinamico.h"

using namespace std;

Termino::Termino(){
	this->palabra = '\n';
	this->definiciones = Vector_Dinamico<string>(0);
	this->num_definiciones = definiciones.size();
}

Termino::Termino(string palabra, Vector_Dinamico<string> definiciones){
	this->palabra = palabra;
	this->definiciones = definiciones;
	this->num_definiciones = definiciones.size();
}

Termino::Termino(const Termino& t){
	this->palabra = t.getPalabra();
	this->definiciones = t.getDefiniciones();
	this->num_definiciones = t.getNumDefiniciones();
}

void Termino::setPalabra(string palabra){
	this->palabra = palabra;
}

void Termino::aniadeDefinicion(string def){
	this->definiciones.resize(definiciones.size()+1);
	this->definiciones[definiciones.size()-1] = def;
        this->num_definiciones++;
}

Termino& Termino::operator =(const Termino& original){
	if(this != &original){
		this->palabra = original.getPalabra();
		this->num_definiciones = original.getNumDefiniciones();
                this->definiciones = original.getDefiniciones();
        }

	return *this;
}