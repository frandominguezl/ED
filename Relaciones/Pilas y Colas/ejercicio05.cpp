/*
* @file ejercicio05.cpp
* @brief Verificar si un string es un palíndromo con una cola y una pila
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <queue>
#include <stack>
 
using namespace std;

bool palindromo(string cad){
	queue<char> cola_aux;
	stack<char> pila_aux;
	bool es_palindromo = false;

	for(int i=0; i<cad.size(); ++i){
		cola_aux.push(cad[i]);
		pila_aux.push(cad[i]);
	}

	while(!cola_aux.empty()){
		if(pila_aux.top() == cola_aux.front()){
			es_palindromo = true;
		}

		else{
			es_palindromo = false;
		}

		cola_aux.pop();
		pila_aux.pop();
	}

	return es_palindromo;
}

int main(){
	string cadena = "Amad a la dama";

	if(palindromo(cadena)){
		cout << "La cadena `" << cadena << "´ es un palíndromo" << endl;
	}

	else{
		cout << "La cadena `" << cadena << "´ no es un palíndromo" << endl;
	}
}