/*
* @file ejercicio02.cpp
* @brief String contiene una configuración de paréntesis correcta
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <string.h>
#include <stack>
 
using namespace std;

/* Por configuración de paréntesis correcta, entiendo que haya los mismos
   de apertura como de cierre. Lo ideal sería llevar un contador, y que 
   la función devuelva true, si ese contador acaba en 0 (incrementaría por
   cada paréntesis que se abra, y decrementaría por cada cierre). */

bool parentesis_correctos(string expresion){
	int contador = 0;
	bool resultado = false;
	stack<char> aux;

	/* Metemos en el pila aux, cada carácter del string que nos han pasado por parámetro */

	for(int i=0; i<expresion.size(); ++i){
		aux.push(expresion[i]);
	}

	/* Aumentamos el contador si el elemento actual es un paréntesis abierto,
	y lo decrementamos en caso contrario. Si está bien, saldrá 0. */

	while(!aux.empty()){
		if(aux.top() == ')'){
			contador--;
		}

		else if(aux.top() == '('){
			contador++;
		}

		aux.pop();
	}

	/* Si el primer carácter no es el cierre de un paréntesis (no queremos eso), y
	el contador es 0, lo hemos hecho bien */

	if(contador == 0 && expresion[0] != ')'){
		resultado = true;
	}

	return resultado;
}

int main(){
	/* Creamos la pila de string, y le metemos unos cuantos elementos de prueba */

	stack<string> pila;
	pila.push("(hola)");
	pila.push("((hola))");
	pila.push("((hola)");
	pila.push("hola)");
	pila.push(")hola(");

	/* Llamamos a la función parentesis_correctos para cada elemento de la pila. Imprimimos
	un mensaje dependiendo del resultado obtenido */
	
	while(!pila.empty()){
		if(parentesis_correctos(pila.top())){
			cout << "El elemento " << pila.size() << " es correcto" << endl;
		}

		else{
			cout << "El elemento " << pila.size() << " no es correcto" << endl;
		}

		pila.pop();
	}
}