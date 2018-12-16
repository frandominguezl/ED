/*
* @file ejercicio09.cpp
* @brief Construir función que determine si dos árboles binarios son similares
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include "bintree.h"

using namespace std;

/* Función recursiva para ir comprobando cada nodo de cada árbol */
bool nodosIguales(typename bintree<int>::node nodo1, typename bintree<int>::node nodo2) {

  if(nodo1.null() && nodo2.null()){
    return true;
  }

  if(nodo1.null() || nodo2.null()){
  	return false;
  }
    
  if(!nodosIguales(nodo1.left(), nodo2.left())){
  	return false;
  }

  if(!nodosIguales(nodo1.right(), nodo2.right())){
  	return false;
  }
  	
  return true;
}

template<typename T>
bool similares(const bintree<T> &Arb1, const bintree<T> &Arb2){
	bool similares = false;
    typename bintree<T>::node nodo1 = Arb1.root();
    typename bintree<T>::node nodo2 = Arb2.root();

    /* Llamamos a la función recursiva, empezando en la raíz de cada árbol */
    if(nodosIguales(nodo1, nodo2)){
    	similares = true;
    }

    return similares;
}

int main(){
	bintree<int> arbol1(7), arbol2(12);

	arbol1.insert_left(arbol1.root(), 8);
	arbol1.insert_right(arbol1.root(), 2);
	arbol1.insert_left(arbol1.root().left(), 1);
	arbol1.insert_right(arbol1.root().left(), 2);
	arbol1.insert_right(arbol1.root().left().right(), 9);

	arbol2.insert_left(arbol2.root(), 1);
	arbol2.insert_right(arbol2.root(), 7);
	arbol2.insert_left(arbol2.root().left(), 11);
	arbol2.insert_right(arbol2.root().left(), 7);
	arbol2.insert_right(arbol2.root().left().right(), 4);

	if(similares(arbol1, arbol2)){
		cout << "Los árboles son similares" << endl;
	}

	else{ 
		cout << "Los árboles no son similares" << endl;
	}
}