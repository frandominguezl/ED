/* @file Diccionario.cpp
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <string.h>
#include "Diccionario.h"
#include "Termino.h"
#include "Vector_Dinamico.h"

using namespace std;

Diccionario::Diccionario(){
	this->terminos = Vector_Dinamico<Termino>(0);
	this->num_terminos = terminos.size();
}

Diccionario::Diccionario(Vector_Dinamico<Termino> terminos){
	this->terminos = terminos;
	this->num_terminos = terminos.size();
}

Diccionario::Diccionario(const Diccionario& d){
	this->terminos = d.terminos;
	this->num_terminos = d.num_terminos;
}

void Diccionario::aniadeTermino(const Termino t){
	this->num_terminos++;
	this->terminos.resize(num_terminos);
	
	for(int i=0; i<this->num_terminos; i++){

		if(strcmp(this->terminos[i].getPalabra().c_str(), t.getPalabra().c_str()) > 0){
			for(int j=this->num_terminos-1; j>i; j--){
				this->terminos[j] = this->terminos[j+1];
			}

			this->terminos[i] = t;
		}
	}
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

}

Diccionario Diccionario::filtrarPalabraClave(string palabra){
	unsigned posicion=0;
	Diccionario encontrados;
	bool incluido = false;

	for(int i=0; i<this->num_terminos; i++){
		for(int j=0; j<this->terminos[i].getNumDefiniciones(); j++){

			posicion = this->terminos[i].getDefiniciones()[j].find(palabra);
			if(posicion != string::npos && !incluido){
				encontrados.terminos[i] = this->terminos[i];
				incluido = true;
			}

			if(posicion != string::npos){
				encontrados.terminos[i].getDefiniciones()[j] = this->terminos[i].getDefiniciones()[j];
				
			}
		}

	incluido = false;
	}

	return encontrados;
}

void Diccionario::recuentoDefiniciones(int& num_total, int& asociadas_palabra, float& promedio){
	int total=0, asociadas=0;
	int numDefs = this->getNumTerminos();
	float prom=0;

	for(int i=0; i<this->getNumTerminos(); i++){
		total += terminos[i].getNumDefiniciones();

		if(terminos[i].getNumDefiniciones() > asociadas){
			asociadas_palabra = terminos[i].getNumDefiniciones();
		}
	}

	num_total = total;
	asociadas_palabra = asociadas;
	promedio = prom/numDefs;

}

ostream& operator <<(ostream& os, const Diccionario& d){
	for(int i=0; i<d.getNumTerminos(); i++){
		for(int j=0; j<d.getTerminos()[i].getNumDefiniciones(); j++){
			os << d.getTerminos()[i];
		}
	}

	return os;
}

istream& operator >>(istream &is, Termino& t){
	string palabra, definicion;

	getline(is, palabra, ';');
	getline(is, definicion);

	t.setPalabra(palabra);
	t.aniadeDefinicion(definicion);
	getline(is, palabra, ';');

	while(strcmp(t.getPalabra().c_str(), palabra.c_str()) == 0){
		getline(is, definicion);
		t.aniadeDefinicion(definicion);
		getline(is, palabra, ';');
	}

	return is;
}