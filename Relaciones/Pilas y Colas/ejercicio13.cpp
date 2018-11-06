/*
* @file ejercicio13.cpp
* @brief Implementar una cola con prioridad con strings que se impriman de acuerdo al numero de vocales.
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

		for(int i=0; i<s1.size(); i++){
			if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u'){
				prio_s1++;
			}
		}

		for(int i=0; i<s2.size(); i++){
			if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u'){
				prio_s2++;
			}
		}

		if(prio_s1 == prio_s2){
			return s1 > s2;
		}
			
		return prio_s1 < prio_s2;
	}
};

int main(){
	/* Creamos la cola con prioridad con nuestra clase compare y le añadimos algunos datos */
	priority_queue<string, vector<string>, compare> cola_prio;
	cola_prio.push("Lola");
	cola_prio.push("Lalo");
	cola_prio.push("Hola");
	cola_prio.push("Murcielago");
	cola_prio.push("Helado");

	/* Imprimimos ahora según la prioridad */
	while(!cola_prio.empty()){
		cout << cola_prio.top() << endl;
		cola_prio.pop();
	}
}