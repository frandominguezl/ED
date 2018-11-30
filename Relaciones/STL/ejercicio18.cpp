/*
* @file ejercicio18.cpp
* @brief Función intercalar. Inserta en v el segundo elemento del par de pos,
 * en los lugares indicados por el primer elemento de pos
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void intercalar(vector<T> &v, vector<pair<int, T> > pos){
    typename vector<T>::iterator itr1 = v.begin();
    typename vector<pair<int, T>>::iterator itr2;
    
    /* Itero sobre el vector que contiene las posiciones y los elementos*/
    for(itr2 = pos.begin(); itr2 != pos.end(); ++itr2){
        /* Empieza en 0 hasta que diga el primer elemento de pos, y aumenta el iterador
         del vector */
        for(int i=0; i<itr2->first; i++){
            ++itr1;
        }
        
        /* Inserta en la posición determinada por el iterador, el segundo elemento de pos */
        v.insert(itr1, itr2->second);
    }
}

int main(){
    vector<int> vec;
    vector<pair<int, int>> pos;
    
    vec.push_back(1);
    vec.push_back(7);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(2);
    
    pos.push_back(pair<int, int>(3, 2));
    
    intercalar(vec, pos);
    
    vector<int>::iterator itr;
    
    for(itr = vec.begin(); itr != vec.end(); ++itr){
        cout << *itr << endl;
    }
}