/*
* @file ejercicio07.cpp
* @brief Implementar TDA Pila usando como representación dos colas
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <queue>
 
using namespace std;

template <typename T>

class Pila{
private:
	queue<T> cola, cola_aux;

public:
	Pila(){
		this->cola = queue<T>();
		this->cola_aux = queue<T>();
	}

	Pila(queue<T> cola, queue<T> cola_aux){
		this->cola = cola;
		this->cola_aux = cola_aux;
	}

	Pila(const Pila& pila){
		this->cola = pila.cola;
		this->cola_aux = pila.cola_aux;
	}

	void push(const T& var){
		this->cola.push(var);
	}

	void pop(){
		/* Almacenamos los valores de nuestra cola, en la cola auxiliar */
		while(!cola.empty()){
			cola_aux.push(cola.front());
			cola.pop();
		}

		/* Borramos el primer dato de cola_aux */
		cola_aux.pop();

		/* Metemos de nuevo los valores en nuestra cola */
		while(!cola_aux.empty()){
			cola.push(cola_aux.front());
			cola_aux.pop();
		}
	}

	T& top(){
		/* Las colas tienen su propia función para devolver el último que entra */
		return this->cola.back();
	}

	bool empty(){
		/* Las colas tienen su propia función para determinar si están vacías o no, así que... eso */
		return this->cola.empty();
	}

	int size(){
		/* Misma lógica que para empty() */
		return this->cola.size();
	}

	bool operator<(Pila<T>& pila){
		bool es_menor = true;
		bool comparables = true;

		if(this->cola.size() != pila.size()){
			comparables = false;
		}

		while(!this->cola.empty() && comparables && es_menor){
			if(this->cola.front() < pila.top()){
				es_menor = true;
			}

			else{
				es_menor = false;
			}
		}

		return es_menor;
	}

	bool operator==(Pila<T>& pila){
		bool iguales = true;
		bool comparables = true;

		if(this->cola.size() != pila.size()){
			comparables = false;
		}

		while(!this->cola.empty() && comparables && iguales){
			if(this->cola.front() == pila.top()){
				iguales = true;
			}

			else{
				iguales = false;
			}
		}

		return iguales;
	}
};

int main(){
	Pila<int> pila1;
	pila1.push(1);
	pila1.push(2);
	pila1.push(3);

	/* Probamos diversas funciones */
	cout << "El tamaño de la pila 1 es: " << pila1.size() << endl;
	cout << "El último elemento en entrar ha sido: " << pila1.top() << endl;
	cout << "¿La pila está vacía? (1 está vacía, 0 no): " << pila1.empty() << endl;
	cout << "Eliminamos el primer elemento que entró" << endl;
	pila1.pop();
	cout << "¿Cuál es ahora el tamaño de la pila 1?: " << pila1.size() << endl;

	/* Vamos a crear dos colas adicionales para comprobar los operadores sobrecargados */
	Pila<int> pila2;
	pila2.push(0);
	pila2.push(1);
	pila2.push(2);

	Pila<int> pila3;
	pila3.push(1);
	pila3.push(2);
	pila3.push(3);

	if(pila2<pila1){
		cout << "La pila 2 es menor que la pila 1" << endl;
	}

	else{
		cout << "La pila 1 es menor que la pila 2" << endl;
	}

	if(pila3==pila1){
		cout << "Las pilas 1 y 3 son iguales" << endl;
	}

	else{
		cout << "Las pilas 1 y 3 no son iguales" << endl;
	}
}