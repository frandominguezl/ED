/*
* @file ejercicio08.cpp
* @brief Evaluar una expresión en postfijo
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <ctype.h>
#include <queue>
#include <stack>
 
using namespace std;

double evaluar(string expresion){
	queue<char> cola_aux;
	queue<int> cola_num;
	char op;
	double resultado_total = 0;

	for(int i=0; i<expresion.size(); ++i){
		if(expresion[i] != ' '){
			cola_aux.push(expresion[i]);
		}
	}

	while(!cola_aux.empty()){
		double resultado = 0;

		if(isdigit(cola_aux.front())){
			cola_num.push(cola_aux.front());
			cola_aux.pop();
		}

		else{
			op = cola_aux.front();
			cola_aux.pop();
		}

		if(op == '+'){
			while(!cola_num.empty()){
				int aux1 = cola_num.front();
				cola_num.pop();
				int aux2 = cola_num.front();
				resultado = aux1 + aux2;
				cola_num.pop();
				cola_num.push(resultado);

				resultado_total += resultado;
			}
		}

		else if(op == '-'){
			while(!cola_num.empty()){
				int aux1 = cola_num.front();
				cola_num.pop();
				int aux2 = cola_num.front();
				resultado = aux1 - aux2;
				cola_num.pop();
				cola_num.push(resultado);

				resultado_total += resultado;
			}
		}

		else if(op == '*'){
			while(!cola_num.empty()){
				int aux1 = cola_num.front();
				cola_num.pop();
				int aux2 = cola_num.front();
				resultado = aux1 * aux2;
				cola_num.pop();
				cola_num.push(resultado);

				resultado_total += resultado;
			}
		}

		else if(op == '/'){
			while(!cola_num.empty()){
				int aux1 = cola_num.front();
				cola_num.pop();
				int aux2 = cola_num.front();
				resultado = aux1 / aux2;
				cola_num.pop();
				cola_num.push(resultado);

				resultado_total += resultado;
			}
		}

		else if(op == '*'){
			while(!cola_num.empty()){
				int aux1 = cola_num.front();
				cola_num.pop();
				int aux2 = cola_num.front();
				resultado = aux1 ^ aux2;
				cola_num.pop();
				cola_num.push(resultado);

				resultado_total += resultado;
			}
		}
	}

	return resultado_total;
}

int main(){
	string expresion = "2 3 + 5 *";
	double resultado = 0;

	resultado = evaluar(expresion);

	cout << resultado << endl;
}