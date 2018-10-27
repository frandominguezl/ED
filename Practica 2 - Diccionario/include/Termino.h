/* 
* @file "Termino.h"
* @brief Fichero de cabecera de Termino.cpp
* @author Francisco Domínguez Lorente
*/

#include <string>
#include "Vector_Dinamico.h"

#ifndef terminoH
#define terminoH

using namespace std;

/*
* @brief TDA Termino
*/

class Termino{
private:
	string palabra;			// Palabra
	Vector_Dinamico<string> definiciones;	// Significado de la palabra
	int num_definiciones;

public:

/*
* @brief Constructor por defecto
*/
	Termino();

/*
* @brief Constructor por parámetros
*/
	Termino(string palabra, Vector_Dinamico<string> definiciones);

/*
* @brief Constructor por copia
* @param El Término del que se hace la copia. No se modifica
*/
	Termino(const Termino& t);

/*
* @brief Consultor de número de definiciones
* @return Número de definiciones de la palabra
*/
	inline int getNumDefiniciones() const{return num_definiciones;};

/*
* @brief Consultor de la palabra
* @return La palabra
*/
	inline string getPalabra() const{return palabra;};
	
/*
* @brief Consultor del significado
* @return Significado
*/
	inline Vector_Dinamico<string> getDefiniciones() const{return definiciones;};

/*
* @brief Establecer la palabra
* @param La palabra
*/
	void setPalabra(string palabra);

/*
* @brief Añade una definición a la palabra
* @param La definición a añadir
*/
	void aniadeDefinicion(string def);

/*
* @brief Sobrecarga del operador de asignación
*/
	Termino& operator =(const Termino& original);

/*
* @brief Sobrecarga de operadores de entrada y salida
*/
friend ostream& operator <<(ostream& os, const Termino& t);
friend istream& operator >>(istream& is, Termino& t);

};

#endif