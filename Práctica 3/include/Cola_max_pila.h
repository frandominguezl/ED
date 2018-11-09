/*
* @file Cola_max_pila.h
* @brief Fichero de cabecera de Cola_max_pila
* @author Francisco Domínguez Lorente
*/

#ifndef PILA_MAX_H
#define PILA_MAX_H

#include <iostream>
#include <stack>
 
using namespace std;

/*
* TDA Cola_max_pila
*/

template <typename T> class Cola_max{
private:
	stack<T> pila, pila_max;

public:
/*
* @brief Constructor por defecto
*/
	Cola_max();

/*
* @brief Constructor por parámetros
*/
	Cola_max(stack<T> pila, stack<T> pila_max);

/*
* @brief Constructor por copia
* @param La cola de la que se hace la copia. No se modifica
*/
	Cola_max(const Cola_max& cola);

/*
* @brief Insertar un elemento en la cola
* @param El elemento a insertar
*/
	void poner(const T& var);

/*
* @brief Comprobar y actualizar el máximo
* @param El valor que acabamos de insertar en la pila
*/
	void comprobarMaximo(const T& var);

/*
* @brief Eliminar elemento de la cola. Elimina el elemento que acaba de entrar
*/
	void quitar();

/*
* @brief Devuelve el elemento del frente, el primero en entrar
* @return El elemento
*/
	T& frente();

/*
* @brief Devuelve el máximo actual en la cola
* @return El máximo de la pila
*/
	T& maximo();
 
/*
* @brief Comprueba si la cola 
* @return Devuelve true si está vacía, false si no lo está
*/
	bool vacia();

/*
* @brief Devuelve el número de elementos que contiene la cola
* @return Número de elementos de la cola
*/
	int num_elementos();
};

#endif