/*
* @file ejercicio04.cpp
* @brief Construir función que realice la reflexión de un árbol binario, es decir, que intercambie
* los hijos de cada uno de los nodos
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include "bintree.h"

using namespace std;

template<typename T>
void reflexion(bintree<T> &Arb)
{
  bintree<T> Ti,Td;

  if(!Arb.empty()){
    Arb.prune_left(Arb.root(), Ti);
    Arb.prune_right(Arb.root(),Td);
    reflexion(Ti);
    Arb.insert_right(Arb.root(),Ti);
    reflexion(Td);
    Arb.insert_left(Arb.root(),Td);
  }
}

int main(){
	bintree<int> arbol(7);
	typename bintree<int>::preorder_iterator itr;

	arbol.insert_left(arbol.root(), 8);
	arbol.insert_right(arbol.root(), 2);
	arbol.insert_left(arbol.root().left(), 1);
	arbol.insert_right(arbol.root().left(), 2);
	arbol.insert_right(arbol.root().left().right(), 9);
	arbol.insert_left(arbol.root().right(), 7);

	cout << "\tÁrbol antes de aplicar reflexión: " << endl;
	for(itr = arbol.begin_preorder(); itr != arbol.end_preorder(); ++itr){
		cout << *itr << endl;
	}

	// Aplicamos reflexión
	reflexion(arbol);

	cout << "\tÁrbol después de aplicar reflexión: " << endl;
	for(itr = arbol.begin_preorder(); itr != arbol.end_preorder(); ++itr){
		cout << *itr << endl;
	}
}