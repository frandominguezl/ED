/*
* @file ejercicio09.cpp
* @brief Laberinto con matrices
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <queue>
#include <stack>
 
using namespace std;

const int num_filas = 4, num_cols = 4;

bool salida_laberinto(char laberinto[][num_cols], int n_filas, int n_cols){
	queue<int> posiciones;
	bool valido = true, solucion = false;

	/* Supongo que la entrada está el posición {0,0} y la salida en la'{n_filas-1, n_cols-1} */
	if(laberinto[0][0] != 'E' || laberinto[n_filas-1][n_cols-1] != 'S'){
		valido = false;
	}

	if(valido){
		/* Si es válido, recorro la matriz entera viendo en qué posiciones hay un 1. Las almaceno en la cola posiciones.*/
		for(int i=0; i<n_filas; i++){
			for(int j=0; j<n_cols; j++){
				if((int) laberinto[i][j] == 1){
					posiciones.push(i);
					posiciones.push(j);
				}	
			}
		}

		/* Saco de la cola dos elementos, el primero es la i del bucle for, osea, la fila y
		el segundo es la j del bucle for, es decir, la columna. Los almaceno en dos variables */
		while(!posiciones.empty() && !solucion){
			int pos_fil = 0, pos_col = 0;
			pos_fil = posiciones.front();
			posiciones.pop();
			pos_col = posiciones.front();
			posiciones.pop();

			if((int) laberinto[0][1] != 1 && (int) laberinto[1][0] != 1){
				solucion = false;
			}

			else if((int) laberinto[n_filas-2][n_cols-1] != 1 && (int) laberinto[n_filas-1][n_cols-2] != 1){
				solucion = false;
			}

			else{
				if((int) laberinto[pos_fil+1][pos_col] == 1 || (int) laberinto[pos_fil][pos_col+1] == 1 ||
			   	   (int) laberinto[pos_fil][pos_col-1] == 1){
					solucion = true;
				}

				else{
					solucion = false;
				}
			}
		}
	}

	return solucion;
	
}

int main(){
	char laberinto1[num_filas][num_cols] = {{'E', 1, 0, 0},
									   	      {0, 1, 0, 0},
									   		  {0, 1, 0, 1},
									   		  {0, 1, 1, 'S'}};

	char laberinto2[num_filas][num_cols] = {{'E', 1, 0, 1},
									   	      {1, 1, 1, 1},
									   		  {0, 1, 1, 0},
									   		  {1, 1, 0, 'S'}};

	if(salida_laberinto(laberinto1, num_filas, num_cols)){
		cout << "Se puede llegar a la salida del laberinto 1" << endl;
	}

	else{
		cout << "No se puede llegar a la salida del laberinto 2" << endl;
	}

	if(salida_laberinto(laberinto2, num_filas, num_cols)){
		cout << "Se puede llegar a la salida del laberinto 2" << endl;
	}

	else{
		cout << "No se puede llegar a la salida del laberinto 2" << endl;
	}
}