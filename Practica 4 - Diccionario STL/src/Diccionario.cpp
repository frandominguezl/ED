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

// Comprobar
vector<string> Diccionario::getDefs(string palabra){
    const_iterator found;
    bool encontrada = false;
    Termino aux;
    
    for(found = terminos.begin(); found != terminos.end() && !encontrada; ++found){
        Termino t = *found;
        if(t.getPalabra() == palabra){
            encontrada = true;
            aux = *found;
        }
    }
    
    return aux.getDefiniciones();
}

void Diccionario::aniadeTermino(Termino t){
    this->terminos.insert(t);
}

void Diccionario::eliminarTermino(Termino t){
    this->terminos.erase(t);
}

// Comprobar
Diccionario Diccionario::filtrarIntervalo(char ini, char fin){
    Diccionario encontrado;
    bool parar = false;
    string palabra;
    const_iterator itr;
    
    for(itr = terminos.begin(); itr != terminos.end() && !parar; ++itr){
        Termino aux = *itr;
        palabra = aux.getPalabra();
        
        if(palabra[0] >= ini && palabra[0] <= fin){
            encontrado.aniadeTermino(*itr);
        }
        
        else{
            parar = true;
        }
    }
    
    return encontrado;
}

// Comprobar
Diccionario Diccionario::filtrarPalabraClave(string palabra){
    Diccionario encontrados;
    const_iterator itr;

    for(itr = terminos.begin(); itr != terminos.end(); ++itr){
        Termino t = *itr;
        Termino aux;
        bool incluido = true;
        
        for(int i=0; i<t.getNumDefiniciones(); i++){
            if(t.getDefiniciones()[i].find(palabra) != string::npos){
                aux.setPalabra(t.getPalabra());
                aux.aniadeDefinicion(t.getDefiniciones()[i]);
                incluido = false;
            }
        }
        
        if(!incluido){
            encontrados.aniadeTermino(t);
        }
    }

    return encontrados;
}

// Comprobar
void Diccionario::recuentoDefiniciones(int& num_total, int& asociadas_palabra, float& promedio){
    int total=0, asociadas=0;
    int numDefs = this->getNumTerminos();
    const_iterator itr;
    
    for(itr = terminos.begin(); itr != terminos.end(); ++itr){
        Termino aux = *itr;
        
        total += aux.getNumDefiniciones();
        
        if(aux.getNumDefiniciones() > asociadas){
            asociadas = aux.getNumDefiniciones();
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

// Comprobar
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