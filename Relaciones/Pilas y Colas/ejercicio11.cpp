/*
* @file ejercicio11.cpp
* @brief Implementar una cola con prioridad con strings que se impriman de acuerdo a una prioridad
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;



/* El struct en sí */
struct Identidad{
	string apellidos;
	string nombre;
	int prioridad;
};

/* Creamos una clase para comparar las prioridades de los struct */
class compare{
public:
	bool operator()(Identidad d1, Identidad d2){
		return d1.prioridad < d2.prioridad;
	}
};

int main(){
	/* Creamos la cola con prioridad con nuestra clase compare y le añadimos algunos datos */
	priority_queue<Identidad, vector<Identidad>, compare> cola_prio;
	cola_prio.push({"Domínguez Lorente", "Francisco", 7});
	cola_prio.push({"Beltrán Sánchez", "Francisco", 1});
	cola_prio.push({"Gómez Hernández", "David", 3});
	cola_prio.push({"Posadas Arráez", "Miguel Ángel", 9});
	cola_prio.push({"Cordero Romero", "Pablo", 2});

	/* Imprimimos ahora según la prioridad */
	while(!cola_prio.empty()){
		cout << cola_prio.top().apellidos << ", " << cola_prio.top().nombre << ", " << cola_prio.top().prioridad << endl;
		cola_prio.pop();
	}
}