/*
* @file Diccionario.cpp (STL)
* @author Francisco Domínguez Lorente
*/

#include "Diccionario.h"
#include <iostream>

using namespace std;

Diccionario::Diccionario(){
    this->terminos = set<Termino>(0);
    this->num_terminos = 0;
}

Diccionario::Diccionario(set<Termino> terminos){
    this->terminos = terminos;
    this->num_terminos = terminos.size();
}

Diccionario::Diccionario(const Diccionario& d){
    this->terminos = d.getTerminos();
}

// Rehacer
vector<string> Diccionario::getDefs(string palabra){
    const_iterator found = terminos.find(palabra);
    Termino aux;
    
    if(found != terminos.end()){
        aux = *found;
    }
    
    return aux.getDefiniciones();
}

void Diccionario::aniadeTermino(Termino t){
    this->terminos.insert(t);
}

void Diccionario::eliminarTermino(Termino t){
    this->terminos.erase(t);
}

// Rehacer
Diccionario Diccionario::filtrarIntervalo(char ini, char fin){
    Diccionario encontrado;
    bool parar = false;
    string palabra;

    for(int i=0; i<this->terminos.size() && !parar; i++){
            palabra = this->terminos[i].getPalabra();

            if(palabra[0] >= ini && palabra[0] <= fin){
                    encontrado.aniadeTermino(this->terminos[i]);
            }

            else{
                parar = true;
            }
    }

    return encontrado;
}

// Rehacer
Diccionario Diccionario::filtrarPalabraClave(string palabra){
    unsigned posicion=0;
    Diccionario encontrados;

    for(int i=0; i<this->getNumTerminos(); i++){
        Termino t;
        bool incluido = true;

            for(int j=0; j<this->terminos[i].getNumDefiniciones(); j++){
                if(terminos[i].getDefiniciones()[j].find(palabra) != string::npos){
                    t.setPalabra(this->terminos[i].getPalabra());
                    t.aniadeDefinicion(this->terminos[i].getDefiniciones()[j]);
                    incluido = false;
                }
            }

        if(!incluido){
            encontrados.aniadeTermino(t);
        }
    }

    return encontrados;
}

// Rehacer
void Diccionario::recuentoDefiniciones(int& num_total, int& asociadas_palabra, float& promedio){
    int total=0, asociadas=0;
    int numDefs = this->getNumTerminos();
    float prom=0;

    for(int i=0; i<terminos.size(); i++){
            total += terminos[i].getNumDefiniciones();

            if(terminos[i].getNumDefiniciones() > asociadas){
                    asociadas = terminos[i].getNumDefiniciones();
            }
    }

    num_total = total;
    asociadas_palabra = asociadas;
    promedio = (1.0*total/numDefs);
}

iterator Diccionario::begin(){
    return terminos.begin();
}

iterator Diccionario::end(){
    return terminos.end();
}

iterator& Diccionario::operator++(){
    return iterator++;
}

iterator& Diccionario::operator--(){
    return iterator--;
}

iterator& Diccionario::operator*(){
    return *iterator;
}

iterator& Diccionario::operator=(const iterator& itr){
    if(this != &itr){
        this = itr;
    }
    
    return *this;
}

bool Diccionario::operator==(const iterator& itr){
    return iterator==itr;
}

bool Diccionario::operator!=(const iterator& itr){
    return iterator!=itr;
}

const_iterator Diccionario::begin() const{
    return this->terminos.cbegin();
}

const_iterator Diccionario::end() const{
    return this->terminos.cend();
}

const_iterator& Diccionario::operator++(){
    return const_iterator++;
}

const_iterator& Diccionario::operator--(){
    return const_iterator--;
}

const_iterator& Diccionario::operator*(){
    return *const_iterator;
}

const_iterator& Diccionario::operator=(const const_iterator& itr){
    if(this != &itr){
        this = itr;
    }
    
    return *this;
}

bool Diccionario::operator==(const const_iterator& itr){
    return const_iterator==itr;
}

bool Diccionario::operator!=(const const_iterator& itr){
    return const_iterator!=itr;
}

Diccionario& Diccionario::operator=(const Diccionario& original){
    if(this != &original){
        this->terminos = original.terminos;
    }
    return *this;
}

ostream& operator<< (ostream & os, const Diccionario & d){
    Diccionario::const_iterator it;
    
    for(it = d.begin(); it != d.end(); ++it){
        os << *it;
    }
    
    return os;
}

istream& operator >> (istream &is, Diccionario &p){
    string aux;
    string anterior = "\0";
    
    
    getline(is, aux, ';');
    do{
        Termino taux;
        do{
            if(anterior == "\0" || aux != anterior){
                taux.setPalabra(aux);
                anterior = aux;
                getline(is, aux, '\n');
                taux.aniadeDefinicion(aux);
            }
            else{
                getline(is, aux, '\n');
                taux.aniadeDefinicion(aux);
            }

            if(!is.eof())
                getline(is, aux, ';');
        }while(aux == anterior);

        p.aniadeTermino( taux );
        
    }while(!is.eof());

    return is;
}