/*
* @file ejercicio10.cpp
* @brief Construir función a la que se le pasen un árbol y dos valores y determine de forma
* eficiente los valores presentes en el árbol, comprendidos entre esos dos valores
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
#include "bintree.h"

using namespace std;

/* Función recursiva para comprobar los valores. Se pasa una lista por referencia
para almacenar ahí los valores */
template<typename T>
void buscar(typename bintree<T>::node raiz, T a, T b, list<T> &result){ 

   if(raiz.null()){
	return; 
   }
  
   if(a < *raiz){
	buscar(raiz.left(), a, b, result); 
   }
  
   if(a <= *raiz && b >= *raiz){
	result.push_back(*raiz); 
   }
  
   if(b > *raiz){
	buscar(raiz.right(), a, b, result);  
   }
} 

template <typename T>
list<T> comprendidos(const bintree<T> &Arb, T a, T b){
	list<T> comprendidos;
	typename bintree<T>::node raiz = Arb.root();

	buscar(raiz, a, b, comprendidos);

    return comprendidos;
}

int main(){
	bintree<int> arbol(7);
	list<int> comp;

	arbol.insert_left(arbol.root(), 8);
	arbol.insert_right(arbol.root(), 2);
	arbol.insert_left(arbol.root().left(), 1);
	arbol.insert_right(arbol.root().left(), 2);
	arbol.insert_right(arbol.root().left().right(), 9);
	arbol.insert_left(arbol.root().right(), 7);
	
	comp = comprendidos(arbol, 2, 8);

    while(!comp.empty()){
      cout << comp.back() << endl;
      comp.pop_back();
    }
}