/*
* @file ejercicio01.cpp
* @brief Construir función que determine cual es la hoja más profunda de un árbol binario
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <queue>
#include "bintree.h"

using namespace std;

template <typename T>
queue<typename bintree<T>::node> ListarPostNiveles(const bintree<T> &A, typename bintree<T>::node n) {
  queue<typename bintree<T>::node> nodos, aux;

  if (!n.null()){
    nodos.push(n);

    while (!nodos.empty()){
      n = nodos.front(); nodos.pop();
      aux.push(*n);

      if (!n.left().null()){
        nodos.push(n.left());
      }

      if (!n.right().null()){
        nodos.push(n.right());
      }
    }
  }

  return aux;
}
template<typename T>
typename bintree<T>::node mas_profunda(const bintree<T> &Arb){
  queue<typename bintree<T>::node> result = ListarPostNiveles(Arb, Arb.root());

  return result.back();
}

int main(){
	bintree<int> arbol(7);
	typename bintree<int>::node profundo;

	arbol.insert_left(arbol.root(), 8);
	arbol.insert_right(arbol.root(), 2);
	arbol.insert_left(arbol.root().left(), 1);
	arbol.insert_right(arbol.root().left(), 2);
	arbol.insert_right(arbol.root().left().right(), 9);
	arbol.insert_left(arbol.root().right(), 7);
	profundo = mas_profunda(arbol);

	cout << "La hoja más profunda es: "<< *profundo << endl;
}