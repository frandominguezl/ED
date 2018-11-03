/* 
* @file Diccionario.cpp
* @author Francisco Domínguez Lorente
*/

#include "Diccionario.h"
#include <string.h>
#include "Vector_Dinamico.h"
#include <iostream>

using namespace std;

Diccionario::Diccionario(){
	this->terminos = Vector_Dinamico<Termino>(0);
	this->num_terminos = 0;
}

Diccionario::Diccionario(Vector_Dinamico<Termino> terminos){
	this->terminos = terminos;
	this->num_terminos = terminos.size();
}

Diccionario::Diccionario(const Diccionario& d){
	this->terminos = d.getTerminos();
}

Vector_Dinamico<string> Diccionario::getDefs(string palabra){
	bool encontrada = false;
	int indice = -1;
        Vector_Dinamico<string> encontrados;
        
	for(int i=0; i<this->num_terminos && !encontrada; i++){
		if(this->terminos[i].getPalabra() == palabra){
			encontrada = true;
			indice = i;
		}
	}
        
        if(encontrada){
            encontrados = this->terminos[indice].getDefiniciones();
        }
        
        return encontrados;
}

void Diccionario::aniadeTermino(Termino t){
        bool encontrado=false;
        int posicion;
	this->num_terminos++;
	this->terminos.resize(num_terminos);
	
	for(int i=0; i<this->num_terminos && !encontrado; i++){
            if(t.getPalabra() < this->terminos[i].getPalabra()){
                posicion = i;
                encontrado = true;
            }
	}
        
        if(!encontrado){
            posicion = this->num_terminos-1;
        }
        
        for(int i=this->num_terminos-1; i>posicion; i--){
            this->terminos[i] = this->terminos[i-1];
        }
        
        this->terminos[posicion] = t;
}

void Diccionario::eliminarTermino(Termino t){
	int comienzo = -1;
	bool encontrado = false;

	for(int i=0; i<t.getNumDefiniciones() && !encontrado; i++){
		if(strcmp(this->terminos[i].getPalabra().c_str(), t.getPalabra().c_str()) > 0){
			comienzo = i;
			encontrado = true;
		}
	}

	for(int i=comienzo; i<this->num_terminos; i++){
		this->terminos[i+1] = this->terminos[i];
	}
	
	this->num_terminos--;
	this->terminos.resize(num_terminos);
}

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

Diccionario& Diccionario::operator=(const Diccionario& original){
		if(this != &original){
			this->terminos = original.terminos;
		}
		return *this;
}

ostream& operator << (ostream& os, const Diccionario& d){
	for(int i=0;i <d.getNumTerminos(); i++){
		for(int j=0;j<d.terminos[i].getNumDefiniciones(); j++){
			os << d.terminos[i].getPalabra()<<";";
                        os << d.terminos[i].getDefiniciones()[j] <<endl;
		}
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