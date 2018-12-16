/*
* @file ejercicio03.cpp
* @brief Construir función que compruebe si un árbol binario es completo o no
* @author Francisco Domínguez Lorente
*
* Se dice que un árbol binario es completo si en el último nivel tiene todas sus hojas
*/

#include <iostream>
#include <cmath>
#include "bintree.h"

using namespace std;

int max(int uno,int dos){
    int resultado;

    if(uno > dos){
      resultado = uno;
    }

    else{
      resultado = dos;   
    }
}

template<typename T>
int altura(const bintree<T> &Arb, typename bintree<T>::node aux){

    if(!aux.null()){
      return (1+max(altura(Arb, aux.left()), altura(Arb,aux.right())));
    }

    else{
      return -1;
    }      
}

template<typename T>
bool completo(const bintree<T> &Arb){
  bool comp = false;

  if((pow(2,altura(Arb, Arb.root())+1)-1) == Arb.size()){
    comp = true;
  }

  return comp;
}

int main(){
	bintree<int> arbol(7);

	arbol.insert_left(arbol.root(), 8);
	arbol.insert_right(arbol.root(), 2);
	arbol.insert_left(arbol.root().left(), 1);
	arbol.insert_right(arbol.root().left(), 2);
	arbol.insert_left(arbol.root().right(), 9);
	arbol.insert_right(arbol.root().right(), 7);

  if(completo(arbol)){
    cout << "El árbol es completo" << endl;
  }

  else{
    cout << "El árbol no es completo" << endl;
  }
}