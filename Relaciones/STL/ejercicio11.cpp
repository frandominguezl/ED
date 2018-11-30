/*
* @file ejercicio11.cpp
* @brief Implementar una función que dadas dos listas, devuelva una ordenada resultante
 * de la mezcla entre ambas
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

void inserta_antes(list<int> &l, int x){
   list<int>::iterator itr, next;
   
   for(itr = l.begin(); itr != l.end(); ++itr){
       next = itr;
       ++next;
       
       if(*itr == x){
           l.insert(next, x-1);
       }
   }
}

int main(){
    /* Creamos una lista y le añadimos unos valores de ejemplo */
    list<int> list1;
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(1);
    list1.push_back(5);
    list1.push_back(3);
    
    inserta_antes(list1, 2);
    
    list<int>::iterator itr;
    
    for(itr = list1.begin(); itr != list1.end(); ++itr){
        cout << *itr << endl;
    }
}