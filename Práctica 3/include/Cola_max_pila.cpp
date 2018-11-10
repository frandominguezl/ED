/*
* @file Cola_max_pila.cpp
* @author Francisco Domínguez Lorente
*/

#ifndef PILA_MAX_H
#define PILA_MAX_H

#include <iostream>
#include <stack>
#include "Cola_max_pila.h"

using namespace std;

template<class T> Cola<T>::Cola(){
    this->pila = stack<T>();
    this->pila_max = stack<T>();
}

template<class T> Cola<T>::Cola(stack<T> pila, stack<T> pila_max){
    this->pila = pila;
    this->pila_max = pila_max;
}

template<class T> Cola<T>::Cola(const Cola& cola){
    this->pila = cola.pila;
    this->pila_max = cola.pila_max;
}

template<class T> void Cola<T>::poner(const T& var){
    this->pila.push(var);
    this->pila_max.push(var);
    comprobarMaximo(var);
}

template<class T> void Cola<T>::comprobarMaximo(const T& var){
    int max = this->pila.size();
    
    if(var > maximo()){
        while(!pila_max.empty()){
            pila_max.pop();
        }
        
        for(int i=0; i<max; i++){
            pila_max.push(var);
        }
    }
    
    else if(var < maximo()){
        pila_max.push(var);
    }
}

template<class T> void Cola<T>::quitar(){
    stack<T> pila_aux;
    
    // Eliminamos primero el frente de la pila
    while(!pila.empty()){
        pila_aux.push(pila.top());
        pila.pop();
    }
    
    pila_aux.pop();
    
    while(!pila_aux.empty()){
        pila.push(pila_aux.top());
        pila_aux.pop();
    }
    
    // Lo mismo para la pila de máximos
    while(!pila_max.empty()){
        pila_aux.push(pila_max.top());
        pila_max.pop();
    }
    
    pila_aux.pop();
    
    while(!pila_aux.empty()){
        pila_max.push(pila_aux.top());
        pila_aux.pop();
    }    
}

template<class T> T& Cola<T>::frente(){
	stack<T> pila_aux;
        
	while(!pila.empty()){
		pila_aux.push(pila.top());
		pila.pop();
	}

	T& frente = pila_aux.top();

	while(!pila_aux.empty()){
		pila.push(pila_aux.top());
		pila_aux.pop();
	}

	return frente;
}

template<class T> T& Cola<T>::maximo(){
	return pila_max.top();
}

template<class T> bool Cola<T>::vacia(){
	bool vacia = false;

	if(pila.empty() && pila_max.empty()){
		vacia = true;
	}

	return vacia;
}

template<class T> int Cola<T>::num_elementos(){
	return this->pila.size();
}

#endif