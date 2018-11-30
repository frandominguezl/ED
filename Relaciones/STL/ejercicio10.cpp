/*
* @file ejercicio10.cpp
* @brief Implementar una función que dadas dos listas, devuelva una ordenada resultante
 * de la mezcla entre ambas
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
void ordenar(list<T> &l)
{
    typename list<T>::iterator itr, ant;
    itr = l.begin();
    ++itr;
    while (itr != l.end()) {
        ant = itr;
        --ant;
        if(*ant > *itr) {
            while (*ant>*itr && ant!=l.begin())
                --ant;
            
                if (ant==l.begin() && (*ant>*itr)){
                    l.insert(l.begin(),*itr);
                }
                
                else {
                    ++ant;
                    l.insert(ant,*itr);
                }
            itr = l.erase(itr);
        } 
        else ++itr;
    } 
}

template <typename T>
list<T> mezclar(const list<T> &l1, const list<T> &l2){
    list<T> resultado;
    typename list<T>::const_iterator itr1, itr2;
    
    for(itr1 = l1.begin(); itr1 != l1.end(); ++itr1){
        resultado.push_back(*itr1);
    }
    
    for(itr2 = l2.begin(); itr2 != l2.end(); ++itr2){
        resultado.push_back(*itr2);
    }
    
    ordenar(resultado);
    
    return resultado;
}

int main(){
    list<int> list1, list2, list_mezclada;
    
    list1.push_back(0);
    list1.push_back(2);
    list1.push_back(4);
    list1.push_back(3);
    
    list2.push_back(6);
    list2.push_back(1);
    list2.push_back(5);
    list2.push_back(7);
    
    list_mezclada = mezclar(list1, list2);
    
    list<int>::iterator itr;
    for(itr = list_mezclada.begin(); itr != list_mezclada.end(); ++itr){
        cout << *itr << endl;
    }
}