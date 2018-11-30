/*
* @file ejercicio06.cpp
* @brief Dada una lista y un dato, eliminar ese dato en todas las posiciones en las que aparezca
 * dentro de esa lista
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
void elimina(list<T> &l, const T &x){
    /* La única variable que nos hará falta será una lista auxiliar */
    list<T> aux;

    while(!l.empty()){
        if(l.front() == x){
            l.pop_front();
        }
        
        else{
            aux.push_back(l.front());
            l.pop_front();
        }
    }
    
    while(!aux.empty()){
        l.push_front(aux.front());
        aux.pop_front();
    }
}

int main(){
    /* Creamos una lista y le añadimos unos valores de ejemplo */
    list<int> list1;
    list1.push_back(2);
    list1.push_back(1);
    list1.push_back(1);
    list1.push_back(1);
    list1.push_back(1);
    list1.push_back(5);
    list1.push_back(3);
    
    /* Llamamos a la función eliminar y a continuación mostramos la lista */
    elimina(list1, 1);
    
    while(!list1.empty()){
        cout << list1.back() << endl;
        list1.pop_back();
    }
}