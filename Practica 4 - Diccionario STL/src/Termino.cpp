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

iterator Termino::begin(){
    return this->termino.second.begin();    
}

iterator Termino::end(){
    return this->termino.second.end();
}

iterator& Termino::operator++(){
    return iterator++;
}

iterator& Termino::operator--(){
    return iterator--;
}

iterator& Termino::operator*(){
    return *iterator;
}

iterator& Termino::operator=(const iterator& itr){
    if(this != &itr){
        this = itr;
    }
    
    return *this;
}

bool Termino::operator==(const iterator& itr){
    return iterator==itr;
}

bool Termino::operator!=(const iterator& itr){
    return iterator!=itr;
}

const_iterator Termino::begin() const{
    return this->termino.second.cbegin();
}

const_iterator Termino::end() const{
    return this->termino.second.cend();
}

const_iterator& Termino::operator++(){
    return const_iterator++;
}

const_iterator& Termino::operator--(){
    return const_iterator--;
}

const_iterator& Termino::operator*(){
    return *const_iterator;
}

const_iterator& Termino::operator=(const const_iterator& itr){
    if(this != &itr){
        this = itr;
    }
    
    return *this;
}

bool Termino::operator==(const const_iterator& itr){
    return const_iterator==itr;
}

bool Termino::operator!=(const const_iterator& itr){
    return const_iterator!=itr;
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
        os << t.termino.first << "-->" << (*it) << endl;
    }
    
    return os;
}