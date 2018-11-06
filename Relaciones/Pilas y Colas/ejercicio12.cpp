/*
* @file ejercicio12.cpp
* @brief Implementar una cola con prioridad con strings que se impriman de acuerdo a una prioridad.
* En caso de tener misma prioridad, que salga por orden alfabético
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;

/* Creamos una clase para comparar las prioridades de los struct */
class compare{
public:
	bool operator()(string s1, string s2){
		int prio_s1 = 0, prio_s2 = 0;

		if(s1[0] < s2[0]){
			prio_s2++;
		}

		else if(s1[0] > s2[0]){
			prio_s1++;
		}

		else{
			if(s1.size() < s2.size()){
				for(int i=0; i<s1.size(); i++){
					if(s1[i] < s2[i]){
						prio_s2++;
					}

					else{
						prio_s1++;
					}
				}
			}

			else{
				for(int i=0; i<s2.size(); i++){
					if(s2[i] < s1[i]){
						prio_s1++;
					}

					else{
						prio_s2++;
					}
				}
			}
		}

		return prio_s1 > prio_s2;
	}
};

int main(){
	/* Creamos la cola con prioridad con nuestra clase compare y le añadimos algunos datos */
	priority_queue<string, vector<string>, compare> cola_prio;
	cola_prio.push("Domínguez Lorente");
	cola_prio.push("Beltrán Sánchez");
	cola_prio.push("Gómez Hernández");
	cola_prio.push("Posadas Arráez");
	cola_prio.push("Cordero Romero");

	/* Imprimimos ahora según la prioridad */
	while(!cola_prio.empty()){
		cout << cola_prio.top() << endl;
		cola_prio.pop();
	}
}