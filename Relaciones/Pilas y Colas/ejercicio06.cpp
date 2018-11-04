/*
* @file ejercicio06.cpp
* @brief Implementar TDA Cola usando como representación dos pilas
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <stack>
 
using namespace std;

template <typename T>

class Cola{
private:
	stack<T> pila, pila_aux;

public:
	Cola(){
		this->pila = stack<T>();
		this->pila_aux = stack<T>();
	}

	Cola(stack<T> pila, stack<T> pila_aux){
		this->pila = pila;
		this->pila_aux = pila_aux;
	}

	Cola(const Cola& cola){
		this->pila = cola.pila;
		this->pila_aux = cola.pila_aux;
	}

	void push(const T& var){
		this->pila.push(var);
	}

	void pop(){
		/* Almacenamos los valores de nuestra pila, en la pila auxiliar */
		while(!pila.empty()){
			pila_aux.push(pila.top());
			pila.pop();
		}

		/* Borramos el primer dato de pila_aux */
		pila_aux.pop();

		/* Metemos de nuevo los valores en nuestra pila */
		while(!pila_aux.empty()){
			pila.push(pila_aux.top());
			pila_aux.pop();
		}
	}

	T& front(){
		/* Con front queremos acceder al primer elemento que ha entrado. Como estamos trabajando
		con pilas, este elemento será el último al que accedamos en la pila. Por eso, volcamos la pila
		en nuestra pila_aux, para así tener el primer elemento como el primero al que podemos acceder
		de pila_aux */
		while(!pila.empty()){
			pila_aux.push(pila.top());
			pila.pop();
		}

		T& front = pila_aux.top();

		/* Ahora tenemos que dejar nuestra pila como estaba */
		while(!pila_aux.empty()){
			pila.push(pila_aux.top());
			pila_aux.pop();
		}

		return front;
	}

	T& back(){
		/* Tan simple como devolver el primer elemento al que podemos acceder de nuestra pila */
		return this->pila.top();
	}

	bool empty(){
		/* Las pilas tienen su propia función para determinar si están vacías o no, así que... eso */
		return this->pila.empty();
	}

	int size(){
		/* Misma lógica que para empty() */
		return this->pila.size();
	}

	bool operator<(Cola<T>& cola){
		bool es_menor = true;
		bool comparables = true;

		if(this->pila.size() != cola.size()){
			comparables = false;
		}

		while(!this->pila.empty() && comparables && es_menor){
			if(this->pila.top() < cola.pila.top()){
				es_menor = true;
			}

			else{
				es_menor = false;
			}
		}

		return es_menor;
	}

	bool operator==(Cola<T>& cola){
		bool iguales = true;
		bool comparables = true;

		if(this->pila.size() != cola.size()){
			comparables = false;
		}

		while(!this->pila.empty() && comparables && iguales){
			if(this->pila.top() == cola.pila.top()){
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
	Cola<int> cola1;
	cola1.push(1);
	cola1.push(2);
	cola1.push(3);

	/* Probamos diversas funciones */
	cout << "El tamaño de la cola 1 es: " << cola1.size() << endl;
	cout << "El último elemento en entrar ha sido: " << cola1.back() << endl;
	cout << "El primer dato en entrar fue: " << cola1.front() << endl;
	cout << "¿La cola está vacía? (1 está vacía, 0 no): " << cola1.empty() << endl;
	cout << "Eliminamos el primer elemento que entró" << endl;
	cola1.pop();
	cout << "¿Cuál es el elemento que entró segundo?: " << cola1.front() << endl;

	/* Vamos a crear dos colas adicionales para comprobar los operadores sobrecargados */
	Cola<int> cola2;
	cola2.push(0);
	cola2.push(1);
	cola2.push(2);

	Cola<int> cola3;
	cola3.push(1);
	cola3.push(2);
	cola3.push(3);

	if(cola2<cola1){
		cout << "La cola 2 es menor que la cola 1" << endl;
	}

	else{
		cout << "La cola 1 es menor que la cola 2" << endl;
	}

	if(cola3==cola1){
		cout << "Las colas 1 y 3 son iguales" << endl;
	}

	else{
		cout << "Las colas 1 y 3 no son iguales" << endl;
	}
}