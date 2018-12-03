/*
* @file Termino.cpp (STL)
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include "Termino.h"

using namespace std;

Termino::Termino(){
    this->termino.first = '\n';
    this->termino.second = vector<string>(0);
    this->num_definiciones = termino.second.size();
}

Termino::Termino(string palabra, vector<string> definiciones){
    this->termino.first = palabra;
    this->termino.second = definiciones;
    this->num_definiciones = definiciones.size();
}

Termino::Termino(const Termino& t){
    this->termino.first = t.getPalabra();
    this->termino.second = t.getDefiniciones();
    this->num_definiciones = t.getNumDefiniciones();
}

void Termino::setPalabra(string palabra){
    this->termino.first = palabra;
}

void Termino::aniadeDefinicion(string def){
    this->termino.second.push_back(def);
}

Termino::iterator Termino::begin(){
    return this->termino.second.begin();    
}

Termino::iterator Termino::end(){
    return this->termino.second.end();
}

Termino::const_iterator Termino::begin() const{
    return this->termino.second.cbegin();
}

Termino::const_iterator Termino::end() const{
    return this->termino.second.cend();
}

Termino& Termino::operator =(const Termino& original){
	if(this != &original){
		this->termino.first = original.getPalabra();
		this->num_definiciones = original.getNumDefiniciones();
                this->termino.second = original.getDefiniciones();
        }

	return *this;
}

ostream& Termino::operator<< (ostream & os, const Termino & t){
    Termino::const_iterator it;
    
    for(it = t.begin(); it != t.end(); ++it){
        os << t.getPalabra() << "-->" << (*it) << endl;
    }
    
    return os;
}