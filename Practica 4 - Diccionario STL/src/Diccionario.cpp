#include "Diccionario.h"
#include <iostream>

using namespace std;

Diccionario::Diccionario(){
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
    Diccionario::const_iterator found;
    bool encontrada = false;
    Termino aux;
    
    for(found = terminos.begin(); found != terminos.end() && !encontrada; ++found){
        if(found->getPalabra() == palabra){
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
    Diccionario::const_iterator itr;
    
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
    Diccionario::const_iterator itr;

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
    num_total=asociadas_palabra=0;
    promedio=0.0;
    Diccionario::const_iterator itr;
    
    for(itr = Diccionario::begin(); itr != Diccionario::end(); ++itr){
        Termino aux = *itr;
        num_total += aux.getNumDefiniciones();
        if(aux.getNumDefiniciones() > asociadas_palabra){
            asociadas_palabra = aux.getNumDefiniciones();
        }
    }
    promedio=num_total/this->terminos.size();
}

Diccionario::iterator Diccionario::begin(){
    return terminos.begin();
}

Diccionario::iterator Diccionario::end(){
    return terminos.end();
}

Diccionario::const_iterator Diccionario::begin() const{
    return this->terminos.cbegin();
}

Diccionario::const_iterator Diccionario::end() const{
    return this->terminos.cend();
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