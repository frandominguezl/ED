/*
* @file ejercicio16.cpp
* @brief Secuencias de valores iguales
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

template <typename T>
list<pair<T, int> > comprimir(const list<T> &l){
	list<pair<T, int>> resultado;
	typename list<T>::const_iterator itr1 = l.begin(), itr2 = l.begin();
	int contador;

	/* Planteamos un bucle while que itere mientras que ninguno de los iteradores
	haya llegado al final */
	while(itr1 != l.end() && itr2 != l.end()){
		contador = 0;
		itr1 = itr2;
		bool coincide = true;

		/* Con el booleano comprobamos hasta dónde se repite un elemento */
		while(coincide){
			/* Si son iguales a donde apuntan los iteradores, aumentamos el contador y el iterador */
			if(*itr1 == *itr2){
				contador++;
				++itr2;
			}

			/* En caso contrario salimos del bucle */
			else{
				coincide = false;
			}
		}

		/* Insertamos en la lista el resultado, que se corresponde al elemento actual del primer
		iterador, y al contador, el número de veces que aparece. También aumentamos el iterador */
		resultado.push_back(pair<T, int>(*itr1, contador));
		++itr1;
	}

	return resultado;
}

template <typename T>
list<T> descomprimir(const list<pair<T, int> > &lc){
	typename list<pair<T, int>>::const_iterator itr;
	list<T> resultado;

	/* Dos bucles for, el primero itera sobre la lista pasada por argumento,
	el segundo itera por cada segundo elemento (el número de veces) del iterador
	y va metiendo el correspondiente valor en la lista resultado */
	for(itr = lc.begin(); itr != lc.end(); ++itr){
		for(int i=0; i<itr->second; i++){
			resultado.push_back(itr->first);
		}
	}

	return resultado;
}

int main(){
	list<int>list1, lista_descomprimida;
	list<pair<int,int> > lista_comprimida;

	/* Creamos todas las listas necesarias, y asiganmos a la primera unos valores */
	list1.push_back(1);
	list1.push_back(1);
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(2);
	list1.push_back(2);
	list1.push_back(2);
	list1.push_back(2);
	list1.push_back(2);
	list1.push_back(7);
	list1.push_back(7);
	list1.push_back(7);
	list1.push_back(7);
	list1.push_back(7);
	list1.push_back(12);
	list1.push_back(1);
	list1.push_back(1);
	list1.push_back(5);
	list1.push_back(5);

        /* Aplicamos la función y creamos un iterador. A continuación mostramos la lista comprimida */
	lista_comprimida = comprimir(list1);
	list<pair<int, int>>::iterator itr_comp;

	cout << "	Lista comprimida: " << endl;
	for(itr_comp = lista_comprimida.begin(); itr_comp != lista_comprimida.end(); ++itr_comp){
		cout << itr_comp->first << ", " << itr_comp->second << endl;
	}

        /* Aplicamos la función y creamos un iterador. A continuación mostramos la lista descomprimida */
	lista_descomprimida = descomprimir(lista_comprimida);
	list<int>::iterator itr_desc;

	cout << "	Lista descomprimida: " << endl;
	for(itr_desc = lista_descomprimida.begin(); itr_desc != lista_descomprimida.end(); ++itr_desc){
		cout << *itr_desc << endl;
	}
}