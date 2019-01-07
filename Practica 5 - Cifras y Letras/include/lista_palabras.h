/*
* @author: Francisco Domínguez Lorente
* @author: David Gómez Hernández
*/

#ifndef __ListaPalabras_h__
#define __ListaPalabras_h__
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "bolsa_letras.h"

using namespace std;
class ListaPalabras{
private:
    set<string> datos;
public:
        
/*
 * @brief Construye un ListaPalabras vacío.
 */
    ListaPalabras();
    
/*
 * @brief Devuelve el numero de palabras en el ListaPalabras
 * @return Numero de palabras
 */
    inline int size() const{return datos.size();};
/*
 * @brief Inserta una palabra en la lista
 * @param palabra a insertar en la lista
 */    
    inline void insertar(string palabra){datos.insert(palabra);};
/*
 * @brief Funcion para ver si la lista está vacía
 * @return devuelve true si la lista está vacía y false lo contrario
 */        
    inline bool empty() const{return datos.empty();};
/*
 * @brief Funcion que devuelve una lista con las palabras que tienen los caracteres de la cadena
 * @param Bolsa de letras conteniendo las letras con las que vamos a jugar
 * @return Devuelve la nueva lista que se va a usar dentro del juego
 */            
    ListaPalabras obtenerDisponibles(BolsaLetras letrasJuego);
/*
 * @brief Funcion que devuelve el numero de letra total de todas las palabras de la lista
 * @return Devuelve el numero de letras de la lista
 */                
    int getNumeroLetras();
    
/*
 * @brief Obtiene todas las palabras en el ListaPalabras de una longitud dada
 * @param longitud la longitud de las palabras de salida
 * @return un vector con las palabras de longitud especificada en el parámetro de entrada
 */
    vector<string> palabras_longitud(int longitud);

/*
 * @brief Indica si una palabra está en el ListaPalabras o no
 * @param palabra la palabra que se quiere buscar
 * @return true si la palabra esta en el ListaPalabras. false en caso contrario
 */
    bool Esta(string palabra);

/*
 * @brief Lee de un flujo de entrada un ListaPalabras
 * @param is flujo de entrada
 * @param D el objeto donde se realiza la lectura.
 * @return el flujo de entrada
 */
    friend istream & operator>>(istream & is, ListaPalabras &D);

/*
 * @brief Escribe en un flujo de salida un ListaPalabras
 * @param os flujo de salida
 * @param D el objeto ListaPalabras que se escribe
 * @return el flujo de salida
 */
    friend ostream & operator<<(ostream & os, const ListaPalabras &D);

/*
 * @brief Iterador que puede modificar y recorrer los elementos del contenedor
 * @return El iterador
 */        
    typedef set<string>::iterator iterator;
        
/*
 * @brief Iterador que puede recorrer los elementos del contenedor
 * @return El iterador
 */        
    typedef set<string>::const_iterator const_iterator;
        
/*
 * @brief Devuelve el inicio del contenedor. Puede modificar.
 * @return Iterador apuntando al inicio del contenedor
 */
    ListaPalabras::iterator begin();
        
/*
 * @brief Devuelve el final del contenedor. Puede modificar.
 * @return Iterador apuntando al final del contenedor
 */
    ListaPalabras::iterator end();
    
/*
 * @brief Devuelve el inicio del contenedor
 * @return Iterador apuntando al inicio del contenedor
 */
    ListaPalabras::const_iterator begin() const;

/*
 * @brief Devuelve el final del contenedor
 * @return Iterador apuntando al final del contenedor
 */
    ListaPalabras::const_iterator end() const;    
        
};
#endif
