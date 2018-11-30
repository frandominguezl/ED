/*
* @file ejercicio08.cpp
* @brief Mostrar una lista en orden inverso
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
list<T> inversa(const list<T> &l){
    list<T> aux;
    typename list<T>::const_iterator itr;
    
    /* Insertamos en el frente de la pila auxiliar a donde a punta el iterador */
    for(itr = l.begin(); itr != l.end(); ++itr){
        aux.push_front(*itr);
    }
    
    return aux;
}

int main(){
    /* Creamos una lista y le añadimos unos valores de ejemplo */
    list<int> list1, inver;
    list1.push_back(2);
    list1.push_back(1);
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(5);
    list1.push_back(3);
    
    /* Llamamos a la función inversa y a continuación mostramos la lista */
    inver = inversa(list1);
    
    list<int>::iterator itr;
    
    for(itr = inver.begin(); itr != inver.end(); ++itr){
        cout << *itr << endl;
    }
}