/*
* @file ejercicio10.cpp
* @brief TDA Ventana
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <queue>
#include <stack>
 
using namespace std;

template <typename T>
class Ventana{
private:
	stack<T> pila_izq, pila_der, pila_aux;

public:
	Ventana(){
		this->pila_izq = stack<T>();
		this->pila_der = stack<T>();
	}
	void Insertar(T elem){
		this->pila_izq.push(elem);
	}

	void MoverDerecha(){
		this->pila_der.push(pila_izq.top());
		this->pila_izq.pop();
	}

	void MoverIzquierda(){
		this->pila_izq.push(pila_der.top());
		this->pila_der.pop();
	}

	void Borrar(T elem){
		while(!pila_izq.empty()){
			if(pila_izq.top() == elem){
				pila_izq.pop();
			}

			else{
				pila_der.push(pila_izq.top());
				pila_izq.pop();
			}
		}

		while(!pila_der.empty()){
			pila_izq.push(pila_der.top());
			pila_der.pop();
		}
	}

	void Imprime(){
		while(!pila_izq.empty()){
			cout << pila_izq.top() << endl;
			pila_aux.push(pila_izq.top());
			pila_izq.pop();
		}

		while(!pila_aux.empty()){
			pila_izq.push(pila_aux.top());
			pila_aux.pop();
		}

		cout << endl;
	}
};

int main(){
	Ventana<int> window;

	window.Insertar(1);
	window.Insertar(2);
	window.Insertar(3);
	window.Insertar(4);

	cout << "Imprimimos la pila" << endl;
	window.Imprime();

	cout << "Movemos a la derecha e imprimimos" << endl;
	window.MoverDerecha();
	window.Imprime();

	cout << "Movemos a la izquierda nuevamente e imprimimos"  << endl;
	window.MoverIzquierda();
	window.Imprime();

	cout << "Borramos el elemento '2' e imprimimos" << endl;
	window.Borrar(2);
	window.Imprime();
}