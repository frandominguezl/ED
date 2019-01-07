/*
* @author: Francisco Domínguez Lorente
* @author: David Gómez Hernández
*/

#include "letra.h"

Letra::Letra(){
    this->letra = '\0';
    this->num_apariciones = 0;
    this->puntuacion = 0;
}

Letra::Letra(char letra, int num_apariciones, int puntuacion){
    setLetra(letra);
    setNumeroApariciones(num_apariciones);
    setPuntuacion(puntuacion);
}

void Letra::setLetra(char letra){
    this->letra = letra;
}

void Letra::setNumeroApariciones(int num_apariciones){
    this->num_apariciones = num_apariciones;
}

void Letra::setPuntuacion(int puntuacion){
    this->puntuacion = puntuacion;
}

bool Letra::operator<(const Letra& otro) const{
    return letra < otro.getLetra();
}

ostream& operator << (ostream &os, const Letra &letra){
    os<<letra.getLetra()<<"      "<<letra.getNumeroApariciones()<<"      "<<letra.getPuntuacion()<<endl;
    return os;
}

istream& operator >> (istream &is, Letra &letra){
    char caux;
    int apaux, puntaux;
    if(!is.eof()){
        is>>caux>>apaux>>puntaux;
        letra.setLetra(caux);
        letra.setNumeroApariciones(apaux);
        letra.setPuntuacion(puntaux);
    }
    return is;
}