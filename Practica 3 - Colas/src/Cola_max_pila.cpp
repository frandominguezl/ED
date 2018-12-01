/*
* @file Cola_max_pila.cpp
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include "Cola_max_pila.h"

using namespace std;

template<typename T> Cola_max<T>::Cola_max(){
	this->pila = stack<T>();
	this->pila_max = stack<T>();
}

template<typename T> Cola_max<T>::Cola_max(stack<T> pila, stack<T> pila_max){
	this->pila = pila;
	this->pila_max = pila_max;
}

template<typename T> Cola_max<T>::Cola_max(const Cola_max& cola){
	this->pila = cola.pila;
	this->pila_max = cola.pila;
}

template<typename T> void Cola_max<T>::poner(const T& var){
	this->pila.push(var);
	comprobarMaximo(var);
}

template<typename T> void Cola_max<T>::comprobarMaximo(const T& var){
	// Hay que cambiar toda la pila de máximos
	if(this->pila_max.top() > var){
		this->pila_max.push(var);
	}

	else{
		this->pila_max.push(pila_max.top());
	}
}

template<typename T> void Cola_max<T>::quitar(){
	this->pila.pop();
	this->pila_max.pop();
}

template<typename T> T& Cola_max<T>::frente(){
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

template<typename T> T& Cola_max<T>::maximo(){
	return pila_max.top();
}

template<typename T> bool Cola_max<T>::vacia(){
	bool vacia = false;

	if(pila.empty()){
		vacia = true;
	}

	return vacia;
}

template<typename T> int Cola_max<T>::num_elementos(){
	return this->pila.size();
}