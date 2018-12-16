/*
* @file ejercicio11.cpp apartado C
* @brief Diseñar un programa para dar el recorrido en postorden, dados los recorridos
* en inorden y preorden
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <stack>
#include "bintree.h"

using namespace std;

template<typename T>
int altura(const bintree<T> &Arb){
	int altura;
	stack<typename bintree<T>::node> pila;

	if(Arb.root().null()){
		return 0;
	}

	pila.push(Arb.root());

	while(true){
        int num_elem = pila.size();
        if(num_elem == 0){
            return (altura-1);
        }

        altura++;
        
        while(num_elem > 0){
            typename bintree<T>::node nodo = pila.top(); pila.pop();
            if(!nodo.left().null()){
                pila.push(nodo.left());
            }

            if(!nodo.right().null()){
                pila.push(nodo.right());
            }

            num_elem--;
        }  
    }
}

int main(){
	bintree<int> arbol(7);

	arbol.insert_left(arbol.root(), 8);
	arbol.insert_right(arbol.root(), 2);
	arbol.insert_left(arbol.root().left(), 1);
	arbol.insert_right(arbol.root().left(), 2);
	arbol.insert_right(arbol.root().left().right(), 9);
	arbol.insert_left(arbol.root().right(), 7);

	cout << "La altura es: " << altura(arbol) << endl;
}