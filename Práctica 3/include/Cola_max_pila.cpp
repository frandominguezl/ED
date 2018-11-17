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
    this->posicion = 0;
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
    T max;
    this->pila.push(var);
    
    if(pila_max.empty()){
        max = (int) 0;
    }
    
    else{
        max = (T) maximo();
    }
    
    if(var < (T) max){
        pila_max.push(var);
        posicion = pila_max.size() - 1;
    }
    
    else{
        while(pila_max.size() != posicion){
            pila_max.pop();
        }
        
        for(int i=pila_max.size(); i<pila.size(); i++){
            pila_max.push(var);
        }
    }
}

template<class T> void Cola<T>::comprobarMaximo(const T& var){
    
    if(var < maximoAnterior()){
        posicion = pila_max.size();
    }
    
    else{
        while(pila_max.size() != posicion+1){
            pila_max.pop();
            pila_max.push(var);
        }
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
    
    // Quitamos el máximo del final de pila
    pila_max.pop();    
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

	if(pila.empty()){
            vacia = true;
	}

	return vacia;
}

template<class T> int Cola<T>::num_elementos(){
	return this->pila.size();
}

#endif