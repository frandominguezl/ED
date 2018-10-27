/* 
* @file "Diccionaro.h"
* @brief Fichero de cabecera de Diccionario.cpp
* @author Francisco Domínguez Lorente
*/

#include <string.h>
#include "Termino.h"
#include "Vector_Dinamico.h"

#ifndef diccionarioH
#define diccionarioH

using namespace std;

/*
* @brief TDA Termino
*/

class Diccionario{
private:
	Vector_Dinamico<Termino> terminos;	// Conjunto de términos
	int num_terminos;					// Número de términos del diccionario

public:

/*
* @brief Constructor por defecto
*/
	Diccionario();

/*
* @brief Constructor por parámetros
*/
	Diccionario(Vector_Dinamico<Termino> terminos);

/*
* @brief Constructor por copia
* @param El Diccionario del que se hace la copia. No se modifica
*/
	Diccionario(const Diccionario& d);

/*
* @brief Consultor de las definiciones asociadas a la palabra de un término
* @param La palabra de la que queremos obtener las definiciones
* @return Todas las definiciones de una palabra
*/
	inline Vector_Dinamico<string> getDefs(Termino palabra) const{return palabra.getDefiniciones();};

/*
* @brief Consultor de todos los términos del diccionario
* @return La palabra
*/
	inline Vector_Dinamico<Termino> getTerminos() const{return this->terminos;};
	
/*
* @brief Consultor del numero de términos del diccionario
* @return Numero de términos del diccionario
*/
	inline int getNumTerminos() const{return this->num_terminos;};

/*
* @brief Añadir un término al diccionario y lo ordena
* @param El término que se quiere añadir
*/
	void aniadeTermino(const Termino t);

/*
* @brief Elimina un término del diccionario
* @param El término a eliminar
*/
	void eliminarTermino(Termino t);

/*
* @brief Filtrar por intervalo. Obtener los términos cuya palabra asociada esté entre @param1 y @param2
* @param1 Caracter de inicio del intervalo
* @param2 Caracter de fin del intervalo
* @return Los términos encontrados en dicho intervalo
*/
	Diccionario filtrarIntervalo(char ini, char fin);

/*
* @brief Filtrado por palabra clave. Obtener los términos en cuya definición aparezca la palabra clave @param
* @param La palabra clave
* @return Los términos encontrados 
*/
	Diccionario filtrarPalabraClave(string palabra);

/*
* @brief Recuento de definiciones. Obtener número total de definiciones, máximo de definiciones asociadas a una
* palabra y el promedio de definiciones por palabra
* @param Un diccionario del que hacer recuento
* @return Vector con los tres datos pedidos, en ese orden
*/
	void recuentoDefiniciones(int& num_total, int& asociadas_palabra, float& promedio);

/*
* @brief: Sobrecarga de operadores de entrada y salida
*/
friend ostream& operator <<(ostream& os, const Diccionario& t);
friend istream& operator >>(istream& is, Diccionario& t);

};

#endif