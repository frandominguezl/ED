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

template<typename T> Cola<T>::Cola(){
	this->pila = stack<T>();
	this->pila_max = stack<T>();
}

template<typename T> Cola<T>::Cola(stack<T> pila, stack<T> pila_max){
	this->pila = pila;
	this->pila_max = pila_max;
}

template<typename T> Cola<T>::Cola(const Cola& cola){
	this->pila = cola.pila;
	this->pila_max = cola.pila;
}

template<typename T> void Cola<T>::poner(const T& var){
	this->pila.push(var);
	comprobarMaximo(var);
}

template<typename T> void Cola<T>::comprobarMaximo(const T& var){
	// Hay que cambiar toda la pila de máximos
	if(this->pila_max.top() > var){
		this->pila_max.push(var);
	}

	else{
		this->pila_max.push(pila_max.top());
	}
}

template<typename T> void Cola<T>::quitar(){
	this->pila.pop();
	this->pila_max.pop();
}

template<typename T> T& Cola<T>::frente(){
	stack<T> pila_aux;

	while(!this->pila.empty()){
		pila_aux.push(this->pila.top());
		this->pila.pop();
	}

	T frente = pila_aux.top();

	while(!pila_aux.empty()){
		this->pila.push(pila_aux.top());
		pila_aux.pop();
	}

	return frente;
}

template<typename T> T& Cola<T>::maximo(){
	return pila_max.top();
}

template<typename T> bool Cola<T>::vacia(){
	bool vacia = false;

	if(pila.empty()){
		vacia = true;
	}

	return vacia;
}

template<typename T> int Cola<T>::num_elementos(){
	return this->pila.size();
}

#endif