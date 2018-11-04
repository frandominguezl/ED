/*
* @file ejercicio01.cpp
* @brief Construir función que modifique una pila
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
void substituye(stack<T> &P, const T &x, const T &y){
	stack<T> aux;	// Pila auxiliar
	T valor = 0;	// Elemento de tipo T que almacenará el valor del elemento top() de cada pila

	while(!P.empty()){
		valor = P.top();

		if(valor == x){ 	// Compruebo si valor coincide con el parámetro x
			aux.push(y);	// Si es así, meto en la pila auxiliar el valor del parámetro y
		}

		else{
			aux.push(valor); // Si no, meto en la pila auxiliar el valor
		}

		P.pop();		// Saco el elemento de la pila y vuelvo a iterar
	}

	while(!aux.empty()){	// En este bucle simplemente vuelvo a meter los elementos en la pila que han pasado por parámetro
		valor = aux.top();	// para que salgan en el mismo orden
		P.push(valor);
		aux.pop();
	}
}

int main(){
	stack<int> pila;
	int x=1, y=2;

	pila.push(7);
	pila.push(1);
	pila.push(3);
	pila.push(1);
	pila.push(1);

	substituye(pila, x, y);

	while(!pila.empty()){
		cout << pila.top() << endl;
		pila.pop();
	}
}