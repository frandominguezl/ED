/* @file Diccionario.cpp
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <string>
#include <vector>
#include "Diccionario.h"
#include "Termino.h"
#include "Vector_Dinamico.h"

Diccionario::Diccionario(){
	this->terminos = Vector_Dinamico<Termino>(int 0);
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

void Diccionario::aniadeTermino(Termino t){
	this->num_terminos++;
	this->terminos.resize(num_terminos);
	this->terminos[num_terminos] = t;
}

void Diccionario::eliminarDefinicion(Termino t){
	for(int i=0; i<this->num_terminos; i++){
		if(terminos[i] == t){

			terminos[i] = null;
			for(int j=i; i<num_terminos; i++){
				terminos[j+1] = terminos[j];
			}
			num_terminos--;
		}
	}
}

Vector_Dinamico<Termino> filtrarIntervalo(char ini, char fin){

}

Vector_Dinamico<Termino> filtrarPalabraClave(string palabra){
	Vector_Dinamico<Termino>(int 0) encontrados;

	for(int i=0; i<num_terminos; i++){
		for(int j=0; j<terminos[i].getNumDefiniciones(); j++){
			if(terminos[i].definiciones[j] == palabra){
				encontrados.aniadeTermino(terminos[i]);
			}
		}
	}

	return encontrados;
}

vector<double> recuentoDefiniciones(Diccionario d){
	vector<double> totales (3);
	int num_total=0, asociadas_palabra=0;
	double promedio;

	num_total = d.getNumTerminos();
	totales[0] = num_total;

	for(int i=0; i<num_total; i++){
		int asociadas_local=0;

		for(int j=0; j<d.terminos[i].getNumDefiniciones(); j++){
			asociadas_local++;
		}

		if(asociadas_local > asociadas_palabra){
			asociadas_palabra = asociadas_local;
		}
	}

	totales[1] = asociadas_palabra;

	int suma_defs = 0;
	for(int i=0; i<num_total; i++){
		for(int j=0; j<d.terminos[i].getNumDefiniciones(); j++){
			suma++;
		}
	}

	promedio = suma/num_total;
	totales[2] = promedio;

	return totales;
}