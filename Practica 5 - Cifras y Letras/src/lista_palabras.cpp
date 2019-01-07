/*
* @author: Francisco Domínguez Lorente
* @author: David Gómez Hernández
*/

#include "lista_palabras.h"
#include "bolsa_letras.h"

ListaPalabras::ListaPalabras(){}

vector<string> ListaPalabras::palabras_longitud(int longitud){
    vector<string>resultado(longitud);
    ListaPalabras::const_iterator iterador = datos.begin();
    
    for(iterador; iterador != datos.end(); iterador++){
        if((*iterador).size() == longitud){
            resultado.push_back(*iterador);
        }            
    }
    
    return resultado; 
}

int ListaPalabras::getNumeroLetras(){
    int numero = 0;
    iterator iterador = datos.begin();
    for(iterador;iterador!=datos.end();iterador++){
        numero += (*iterador).size();
    }
    return numero;
}

bool ListaPalabras::Esta(string palabra){
    bool resultado = false;
    iterator iterador = datos.begin();
    
    for(iterador; iterador != datos.end(); iterador++){
        if(*iterador == palabra){
            resultado = true;
        }
    }
    
    return resultado;
}

ListaPalabras ListaPalabras::obtenerDisponibles(BolsaLetras letrasJuego){
    ListaPalabras soluciones;
    ListaPalabras::const_iterator iterador;
    bool correcto;

    for(iterador = ListaPalabras::begin(); iterador != ListaPalabras::end(); ++iterador){
        correcto = false;
        correcto = letrasJuego.esValida(*iterador);
        
        if(correcto){
            soluciones.insertar(*iterador);
        }   
    }
    
    return soluciones;
}

istream& operator>>(istream &is,ListaPalabras &D) {
  string palabra;
  while (is) {
    is>>palabra;
    D.insertar(palabra);
  }
  
  return is;
}

ostream& operator<<(ostream &os,const ListaPalabras &D) {
  ListaPalabras::const_iterator iterador = D.begin();

  for (iterador;iterador!=D.end();iterador++)
    os<<*iterador<<std::endl;
  return os;
}

ListaPalabras::iterator ListaPalabras::begin(){
    return datos.begin();
}

ListaPalabras::iterator ListaPalabras::end(){
    return datos.end();
}

ListaPalabras::const_iterator ListaPalabras::begin() const{
    return this->datos.cbegin();
}

ListaPalabras::const_iterator ListaPalabras::end() const{
    return this->datos.cend();
}