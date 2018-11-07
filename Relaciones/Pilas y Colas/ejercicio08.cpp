/*
* @file ejercicio08.cpp
* @brief Evaluar una expresión en postfijo
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <cmath>
#include <stack>
 
using namespace std;

template <typename T>
T evaluar(string expresion, pair<char, T> variables[], int num_variables){
	stack<T> pila;
	T dcha, izq, resultado;

	for (int i=0; i < expresion.size(); ++i) {
		if ((expresion[i]>='a') && (expresion[i]<='e')){
			switch (expresion[i]){
					case 'a': pila.push(variables[0].second); break;
					case 'b': pila.push(variables[1].second); break;
					case 'c': pila.push(variables[2].second); break;
					case 'd': pila.push(variables[3].second); break;
					case 'e': pila.push(variables[4].second); break;
					}
		}

		else if(expresion[i] != ' '){
		dcha = pila.top(); pila.pop();
		izq = pila.top(); pila.pop();

		switch (expresion[i]){
			case '+': pila.push(izq+dcha); break;
			case '-': pila.push(dcha-izq); break;
			case '/': pila.push(izq/dcha); break;
			case '*': pila.push(izq*dcha); break;
			case '^': pila.push(pow(izq, dcha)); break;
			}
		}
	}

	return pila.top();
}

int main(){
	int numero_variables = 5;
	string expresion1 = "a b ^ c * d / e +";
	string expresion2 = "a b c d e + * + -";
	string expresion3 = "a b + c d  * + e * ";
	pair<char, int> exp[numero_variables], exp2[numero_variables], exp3[numero_variables];

	/* Primera expresión */
	exp[0].first = 'a';
	exp[0].second = 5;

	exp[1].first = 'b';
	exp[1].second = 3;

	exp[2].first = 'c';
	exp[2].second = 2;

	exp[3].first = 'd';
	exp[3].second = 2;

	exp[4].first = 'e';
	exp[4].second = 9;

	/* Segunda expresión */
	exp2[0].first = 'a';
	exp2[0].second = 12;

	exp2[1].first = 'b';
	exp2[1].second = 4;

	exp2[2].first = 'c';
	exp2[2].second = 7;

	exp2[3].first = 'd';
	exp2[3].second = 5;

	exp2[4].first = 'e';
	exp2[4].second = 2;

	/* Tercera expresión */
	exp3[0].first = 'a';
	exp3[0].second = 2;

	exp3[1].first = 'b';
	exp3[1].second = 6;

	exp3[2].first = 'c';
	exp3[2].second = 3;

	exp3[3].first = 'd';
	exp3[3].second = 5;

	exp3[4].first = 'e';
	exp3[4].second = 9;

	/* Imprimimos los resultados */
	cout << "Primera expresión vale: " << evaluar(expresion1, exp, numero_variables) << endl;
	cout << "Segunda expresión vale: " << evaluar(expresion2, exp2, numero_variables) << endl;
	cout << "Tercera expresión vale: " << evaluar(expresion3, exp3, numero_variables) << endl;
}