/*
* @file ejercicio04.cpp
* @brief Insertar elemento en una cola con una posición dada
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <queue>
 
using namespace std;

template <typename T>
void insertar(queue<T> &P, int pos, const T &x){
	queue<T> aux;

	/* Mismo procedimiento que en el ejercicio anterior, esta vez con colas */
	while(!P.empty()){
		if(P.size() == pos){
			aux.push(P.front());
			aux.push(x);
		}

		else{
			aux.push(P.front());
		}

		P.pop();
	}

	while(!aux.empty()){
		P.push(aux.front());
		aux.pop();
	}
}

int main(){
	queue<string> cola;
	string x = "Pos 3";

	cola.push("Pos 1");
	cola.push("Pos 2");
	cola.push("Pos 4");
	cola.push("Pos 5");

	insertar(cola, 3, x);

	while(!cola.empty()){
		cout << cola.front() << endl;
		cola.pop();
	}
}