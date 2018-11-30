/*
* @file ejercicio09.cpp
* @brief Resolver el problema anterior pero sobre la lista pasada por referencia
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
void inversa(list<T> &l){
    list<T> aux;
    typename list<T>::iterator itr;
    
    /* Insertamos en el frente de la pila auxiliar a donde a punta el iterador */
    for(itr = l.begin(); itr != l.end(); ++itr){
        aux.push_front(*itr);
    }
    
    /* Borramos todos los elementos de la pila */
    l.clear();
    
    /* Volvemos a meter los elementos a la pila, que ya están invertidos */
    for(itr = aux.begin(); itr != aux.end(); ++itr){
        l.push_back(*itr);
    }
}

int main(){
    /* Creamos una lista y le añadimos unos valores de ejemplo */
    list<int> list1;
    list1.push_back(2);
    list1.push_back(1);
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(5);
    list1.push_back(3);
    
    /* Llamamos a la función inversa y a continuación mostramos la lista */
    inversa(list1);
    
    list<int>::iterator itr;
    
    for(itr = list1.begin(); itr != list1.end(); ++itr){
        cout << *itr << endl;
    }
}