/*
* @file Cola_max_vd.h
* @brief Fichero de cabecera de Cola_max_vd
* @author Francisco Domínguez Lorente
*/

#ifndef pila_max_vd_h
#define pila_max_vd_h

#include <iostream>
#include <vector>
 
using namespace std;

/*
* TDA Cola_max_vd
*/

template <class T> class Cola{
private:
	vector<T> principal, maximos;
        int posicion;

public:
/*
* @brief Constructor por defecto
*/
	Cola();

/*
* @brief Constructor por parámetros
*/
	Cola(vector<T> principal, vector<T> maximos);
        
/*
* @brief Constructor por copia
* @param La cola de la que se hace la copia. No se modifica
*/
	Cola(const Cola& cola);

/*
* @brief Insertar un elemento en la cola
* @param El elemento a insertar
*/
	void poner(const T& var);

/*
* @brief Eliminar elemento de la cola. Elimina el elemento que acaba de entrar.
*/
	void quitar();

/*
* @brief Devuelve el elemento del frente, el primero en entrar
* @return El elemento
*/
	T& frente();

/*
* @brief Devuelve el máximo actual en la cola de máximos
* @return El máximo de la cola
*/
	T& maximo();
 
/*
* @brief Comprueba si la cola está vacía
* @return Devuelve true si está vacía, false si no lo está
*/
	bool vacia();

/*
* @brief Devuelve el número de elementos que contiene la cola
* @return Número de elementos de la cola
*/
	inline int num_elementos() {return this->principal.size(); };
};

#include "Cola_max_vd.cpp"
#endif