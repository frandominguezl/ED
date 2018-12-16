/*
* @file ejercicio02.cpp
* @brief Construir función que dado un objeto node y un árbol, determine el nivel del nodo en el árbol
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include "bintree.h"

using namespace std;

template<typename T>
int nivel(const bintree<T> &Arb, typename bintree<T>::node n){
  int contador = 0;

  /* Iteramos sobre el árbol. En cada iteración, comprobamos si la raíz del árbol es distinta del nodo
  En caso afirmativo, aumentamos nuestra variable contador y al nodo actual, le asignamos su nodo padre.
  De tal forma, vamos subiendo en el árbol hasta llegar a la raíz, y aumentando la variable */
  while(Arb.root() != n){
    contador++;
    n = n.parent();
  }

  return contador;
}

int main(){
	bintree<int> arbol(7);
  int niv;

	arbol.insert_left(arbol.root(), 8);
	arbol.insert_right(arbol.root(), 2);
	arbol.insert_left(arbol.root().left(), 1);
	arbol.insert_right(arbol.root().left(), 2);
	arbol.insert_right(arbol.root().left().right(), 9);
	arbol.insert_left(arbol.root().right(), 7);

  // Buscamos el nodo en profundidad 1
	niv = nivel(arbol, arbol.root().left());

	cout << niv << endl;
}