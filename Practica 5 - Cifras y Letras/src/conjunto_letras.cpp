/*
* @author: Francisco Domínguez Lorente
* @author: David Gómez Hernández
*/

#include "conjunto_letras.h"
#include <string>

ConjuntoLetras::ConjuntoLetras(){}

ConjuntoLetras::ConjuntoLetras(set<Letra> conjunto){
    this->conjunto = conjunto;
}

void ConjuntoLetras::aniadeLetra(Letra l){
    this->conjunto.insert(l);
}

void ConjuntoLetras::eliminarLetra(Letra l){
    this->conjunto.erase(l);
}

BolsaLetras ConjuntoLetras::letrasjuego(int longitud){
    BolsaLetras generada;
    srand(time(NULL));
    int repeticiones[conjunto.size()] = {0};
    int aniadidos=0, aleatorio;

    while(aniadidos < longitud){
        ConjuntoLetras::iterator itr = conjunto.begin();

        aleatorio = rand() % (conjunto.size()-1);

        int x=0;
        while(x<aleatorio){
            ++itr;
            ++x;
        }

        repeticiones[aleatorio]++;
        if(repeticiones[aleatorio] <= itr->getNumeroApariciones()){
            generada.insertar(*itr);
            aniadidos++;
        }
    }
    
    return generada;
}

Letra ConjuntoLetras::obtenerLetra(int pos){
    int contador = 0;
    
    if(pos > getNumeroLetras()){
        cerr << "La posición indicada no se puede encontrar" << endl;
    }
    
    set<Letra>::const_iterator itr = conjunto.begin();
    Letra resultado;
    bool encontrada = false;
    
    for(itr; itr != this->conjunto.end() && !encontrada; ++itr){
        if(contador == pos){
            resultado = *itr;
            encontrada = true;
        }
        
        contador++;
    }
    
    return resultado;
}

int ConjuntoLetras::obtenerPuntos(string palabra, char opcion){
    int puntos = 0;
    set<Letra>::iterator itr;
    Letra aux;
    
    if(opcion == 'L'){
        puntos = palabra.size();
    }
    
    else if(opcion == 'P'){
        
        for(int i=0; i < palabra.size(); i++){
          for(itr = this->conjunto.begin(); itr != this->conjunto.end(); ++itr){
            aux = *itr;
            //Transformamos las letras de la palabra en mayuscula para que las detecte el if
            transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
            if(palabra[i] == aux.getLetra()){
                puntos += aux.getPuntuacion();
                        
                }
            }
        }  
    }
    
    
    return puntos;
}

ConjuntoLetras::iterator ConjuntoLetras::begin(){
    return conjunto.begin();
}

ConjuntoLetras::iterator ConjuntoLetras::end(){
    return conjunto.end();
}

ConjuntoLetras::const_iterator ConjuntoLetras::begin() const{
    return this->conjunto.cbegin();
}

ConjuntoLetras::const_iterator ConjuntoLetras::end() const{
    return this->conjunto.cend();
}

ostream& operator << (ostream &os, const ConjuntoLetras &conjunto){
    set<Letra>::const_iterator iterador = conjunto.begin();
    os << "#Letra Cantidad Puntos" << endl;
    
    for(iterador; iterador != conjunto.end(); iterador++){
        os << *iterador;
    }
    
    return os;
}


istream& operator >> (istream &is, ConjuntoLetras &conjunto){
    string inicio;
    Letra aux;
    getline(is,inicio,'\n');
    if(inicio == "#Letra Cantidad Puntos"){   
        do{
            is >> aux;
            conjunto.aniadeLetra(aux);
        }while(!is.eof());
    }
    else
        cerr<<"El formato no es el correcto"<<endl;
    return is;
}