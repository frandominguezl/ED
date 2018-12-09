/*
* @author: Domíngez Lorente Francisco
* @author: Gómez Hernández David
*/

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <string>
#include <set>
#include "Termino.h"

using namespace std;

/*
* @brief TDA Termino
*/

class Diccionario{
private:
    set<Termino> terminos;	// Conjunto de términos
    int num_terminos;	// Número de términos del diccionario

public:

/*
 * @brief Constructor por defecto
 */
	Diccionario();

/*
* @brief Constructor por parámetros
*/
	Diccionario(set<Termino> terminos);

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
	vector<string> getDefs(string palabra);

/*
 * @brief Consultor de todos los términos del diccionario
 * @return La palabra
 */
	inline set<Termino> getTerminos() const{return this->terminos;};
	
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
 * @brief Iterador que puede modificar y recorrer los elementos del contenedor
 * @return El iterador
 */        
        typedef set<Termino>::iterator iterator;
        
/*
 * @brief Iterador que puede recorrer los elementos del contenedor
 * @return El iterador
 */        
        typedef set<Termino>::const_iterator const_iterator;
        
/*
 * @brief Devuelve el inicio del contenedor. Puede modificar.
 * @return Iterador apuntando al inicio del contenedor
 */
        Diccionario::iterator begin();
        
/*
 * @brief Devuelve el final del contenedor. Puede modificar.
 * @return Iterador apuntando al final del contenedor
 */
        Diccionario::iterator end();
       
/*
 * @brief Devuelve el inicio del contenedor
 * @return Iterador apuntando al inicio del contenedor
 */
        Diccionario::const_iterator begin() const;

/*
 * @brief Devuelve el final del contenedor
 * @return Iterador apuntando al final del contenedor
 */
        Diccionario::const_iterator end() const;        
        
/*
 * @brief sobrecarga del operador igual
 * @param Diccionario a asignar
 */	
        Diccionario& operator=(const Diccionario& original);
        
/*
 * @brief Sobrecarga de operador de salida
 */
        friend ostream& operator <<(ostream& os, const Diccionario& d);

/*
 * @brief Sobrecarga de operador de entrada
 */
        friend istream& operator >>(istream& is, Diccionario& d);

};

#endif
