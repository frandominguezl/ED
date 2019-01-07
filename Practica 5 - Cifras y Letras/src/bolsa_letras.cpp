/*
* @author: Francisco Domínguez Lorente
* @author: David Gómez Hernández
*/

#include "bolsa_letras.h"

BolsaLetras::BolsaLetras() {}

void BolsaLetras::insertar(const Letra &letra){
    int apariciones = letra.getNumeroApariciones();
    for(unsigned i=0;i<apariciones;i++){
        bolsa.push_back(letra.getLetra());
    }
    random_shuffle(bolsa.begin(), bolsa.end());
}

bool BolsaLetras::esValida(string sol){
    bool valida = true;
    BolsaLetras bolsa_aux = (*this);

    //Transformamos en mayúsculas porque en el fichero letras.txt los caracteres están en mayusculas
    transform(sol.begin(), sol.end(), sol.begin(), ::toupper);

    for(int i=0; i<sol.size() && valida; i++){
        valida = bolsa_aux.sePuedeElegir(sol[i]);
    }

    return valida;
}

bool BolsaLetras::sePuedeElegir(char letra){
    BolsaLetras::iterator itr;
    bool valida=false;

    for (itr = BolsaLetras::begin() ;itr != BolsaLetras::end() && !valida; ++itr){
        if(letra == *itr){
            valida=true;
            this->bolsa.erase(itr);
        }
    }
    return valida;
}

char BolsaLetras::getLetra(){
    BolsaLetras::iterator iterador = BolsaLetras::begin();
    char resultado = *iterador;
    bolsa.erase(iterador);
    return resultado;
}

BolsaLetras::iterator BolsaLetras::begin(){
    return bolsa.begin();
}

BolsaLetras::iterator BolsaLetras::end(){
    return bolsa.end();
}

BolsaLetras::const_iterator BolsaLetras::begin() const{
    return this->bolsa.cbegin();
}

BolsaLetras::const_iterator BolsaLetras::end() const{
    return this->bolsa.cend();
}