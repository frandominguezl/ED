/*
* @file ejercicio05.cpp
* @brief Construir función que determine la densidad de un árbol
* @author Francisco Domínguez Lorente
*
* Por densidad entendemos la suma de las profundidades de las hojas de un árbol
*/

#include <iostream>
#include <queue>
#include "bintree.h"

using namespace std;

template <typename T>
bool esHoja(const bintree<T> & A, const typename bintree<T>::node &v)
{
    return (v.left().null() && v.right().null());
}

template<typename T>
int nivel(const bintree<T> &Arb, typename bintree<T>::node n){
  int contador = 0;

  while(Arb.root() != n){
    contador++;
    n = n.parent();
  }

  return contador;
}

template <typename T>
vector<int> ListarPostNiveles(const bintree<T> &A, typename bintree<T>::node n) {

    vector<int> vec_hojas;
    queue<typename bintree<T>::node> nodos;

    if (!n.null()) {
        nodos.push(n);
        while (!nodos.empty()) {
            n = nodos.front(); nodos.pop();
            if(esHoja(A,n)){
                vec_hojas.push_back(nivel(A,n));
            }

            if (!n.left().null()){
            	nodos.push(n.left());
            }

            if (!n.right().null()){
                nodos.push(n.right());
            }
        }
    }

    return vec_hojas;
}

template<typename T>
int densidad(const bintree<T> &Arb){
   vector<int> vec_hojas = ListarPostNiveles(Arb, Arb.root());
   int profundidad = 0;

   while(!vec_hojas.empty()){
        profundidad += vec_hojas.back();
        vec_hojas.pop_back();
   }
   
   return profundidad; 
}

int main(){
	bintree<int> arbol(7);

	arbol.insert_left(arbol.root(), 8);
	arbol.insert_right(arbol.root(), 2);
	arbol.insert_left(arbol.root().left(), 1);
	arbol.insert_right(arbol.root().left(), 2);
	arbol.insert_right(arbol.root().left().right(), 9);
	arbol.insert_left(arbol.root().right(), 7);
	
	cout << "La densidad del árbol es " << densidad(arbol) << endl;
}