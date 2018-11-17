/*
* @file Cola_max_vd.cpp
* @author Francisco Domínguez Lorente
*/

#ifndef COLA_MAX_VD_H
#define COLA_MAX_VD_H

#include <iostream>
#include <vector>
#include "Cola_max_vd.h"

using namespace std;

template <class T> Cola<T>::Cola(){
    this->principal = vector<T>();
    this->maximos = vector<T>();
    this->posicion = 0;
}

template<class T> Cola<T>::Cola(vector<T> principal, vector<T> maximos){
    this->principal = principal;
    this->maximos = maximos;
}

template <class T> Cola<T>::Cola(const Cola &cola){
	this->principal = cola.principal;
	this->maximos = cola.maximos;
}

template <class T> T& Cola<T>::maximo(){
	return this->maximos.back();
}

template <class T> T& Cola<T>::frente(){
	return this->principal.front();
}

template <class T> void Cola<T>::poner(const T& var){
    T max;
    this->principal.push_back(var);
    
    if(maximos.empty()){
        max = (int) 0;
    }
    
    else{
        max = (T) maximo();
    }
    
    if(var < max){
        maximos.push_back(var);
        posicion = maximos.size() - 1;
    }
    
    else{
        for(int i=maximos.size(); i>posicion; i--){
            maximos.pop_back();
        }
        
        for(int i=maximos.size(); i<principal.size(); i++){
            maximos.push_back(var);
        }
    }
}

template <class T> void Cola<T>::quitar(){
	vector<T> aux;
        principal[0]=-1;
        
	for(int i=0; i<this->principal.size(); i++){
            if(principal[i]!=-1)
		aux.push_back(this->principal[i]);
	}
	
	this->principal=aux;
	aux.clear();
        maximos[maximos.size()-1]=-1;
        
	for(int i=0; i<this->maximos.size(); i++){
            if(maximos[i]!=-1)
		aux.push_back(this->maximos[i]);
	}
        
	this->maximos=aux;
}

template <class T> bool Cola<T>::vacia(){
	return principal.empty();
}

#endif