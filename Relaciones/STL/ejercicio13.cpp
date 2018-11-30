/*
* @file ejercicio13.cpp
* @brief Dadas dos listas, una que contiene n elementos y otra que contiene una serie de posiciones
 * de la lista anterior, construir una función que devuelva otra lista que contenga los elementos de
 * la primera lista, pero solo de las posiciones marcadas por la otra lista
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
list<T> lista_posiciones(const list<T> &l, const list<T> &li){
    list<T> resultado;
    int cont = 0;
    typename list<T>::const_iterator itrl = l.begin(), itrli = li.begin();
    
    /* Recorremos mientras que el contador sea distinto del tamaño de la lista
     Comprobamos si el contador (la posición actual) es igual a donde apunta el
     iterador de la lista de posiciones, en ese caso metemos el elemento de la lista
     en la pila resultado e incrementamos el iterador de la lista de posiciones.*/
    while(cont != l.size()){
        if(cont == *itrli){
           resultado.push_back(*itrl);
           ++itrli;
        }
        
        cont++;
        ++itrl;
    }
    
    return resultado;
}

int main(){
    /* Creamos dos listas */
    list<int> lista;
    lista.push_back(3);
    lista.push_back(4);
    lista.push_back(5);
    lista.push_back(8);
    
    list<int> list_pos;
    list_pos.push_back(2);
    list_pos.push_back(3);
    
    list<int> resultado = lista_posiciones(lista, list_pos);
    
    list<int>::iterator it;
    
    for(it = resultado.begin(); it != resultado.end(); ++it){
        cout << *it << endl;
    }
}