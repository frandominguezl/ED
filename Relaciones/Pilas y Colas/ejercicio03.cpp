/*
* @file ejercicio03.cpp
* @brief Insertar elemento en una pila con una posición dada
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <stack>
 
using namespace std;

template <typename T>
void insertar(stack<T> &P, int pos, const T &x){
	stack<T> aux;

	/* Vamos recorriendo los elementos de la pila pasada por parámetro. Si el tamaño de la pila coincide
	con el pasado por el parámetro pos, almacenará en la pila aux el elemento de dicha posición, y después
	el elemento x pasado como argumento. En caso contrario, simplemente almacena el elemento correspondiente
	en aux. */
	while(!P.empty()){
		if(P.size() == pos){
			aux.push(P.top());
			aux.push(x);
		}
		else{
			aux.push(P.top());
		}
		
		P.pop();
	}

	/* Tenemos que darle la vuelta a la pila para mostrarla como ha entrado */
	while(!aux.empty()){
		P.push(aux.top());
		aux.pop();
	}
}

int main(){
	/* Declaración de la pila y del elemento que queremos insertar. Añadimos también algunos
	elemenos a la pila */
	stack<string> pila;
	string x = "Pos 3";

	pila.push("Pos 1");
	pila.push("Pos 2");
	pila.push("Pos 4");
	pila.push("Pos 5");

	/* Llamamos a la función para que inserte en pila, el elemento x en la posición 3 y mostramos
	el resultado obtenido */
	insertar(pila, 3, x);

	while(!pila.empty()){
		cout << pila.top() << endl;
		pila.pop();
	}
}