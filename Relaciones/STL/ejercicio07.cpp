/*
* @file ejercicio07.cpp
* @brief Dada una lista, borrar los elementos duplicados sin ordenar previamente
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
void elimina_duplicados(list<T> &l){
    typename list<T>::iterator p;
    
    for(p = l.begin(); p != l.end(); ++p) {
        typename list<T>::iterator q = p;
        ++q;
        
        while (q != l.end()) {
            if (*p == *q){
                q = l.erase(q);
            }

            else{
                ++q;
            }
        }
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
    
    /* Llamamos a la función eliminar_duplicados y a continuación mostramos la lista */
    elimina_duplicados(list1);
    
    list<int>::iterator itr;
    
    for(itr = list1.begin(); itr != list1.end(); ++itr){
        cout << *itr << endl;
    }
}