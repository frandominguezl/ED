/*
* @file ejercicio12.cpp
* @brief Implementar una función que dadas dos listas, compruebe si una está contenida en la otra
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
bool contenida(const list<T> &l1, const list<T> &l2){
    bool contiene = true;
    typename list<T>::const_iterator itr1, itr2 = l2.begin();
    
    /* Si el tamaño de la primera lista es mayor que el de la segunda, es imposible
     que esté contenida, así que ponemos el bool a false */
    if(l1.size() > l2.size()){
        contiene = false;
    }
    
    /* Comprobamos en cada iteración, si a donde apuntan los iteradores tienen el mismo valor*/
    for(itr1 = l1.begin(); itr1 != l1.end() && contiene; ++itr1){
        if(*itr1 != *itr2){
            contiene = false;
        }
        
        else{
            ++itr2;
        }
    }
    
    return contiene;
}

int main(){
    /* Creamos dos listas, de distinto tamaño (la primera menor) */
    list<int> list1;
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(1);
    
    list<int> list2;
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(1);
    list2.push_back(4);
    list2.push_back(5);
    
    if(contenida(list1, list2)){
        cout << "La lista 1 está contenida en la lista 2" << endl;
    }
    
    else{
        cout << "La lista no 1 está contenida en la lista 2" << endl;
    }
}