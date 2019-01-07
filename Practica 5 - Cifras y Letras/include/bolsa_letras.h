/*
* @author: Francisco Domínguez Lorente
* @author: David Gómez Hernández
*/

#ifndef BOLSA_LETRAS_H
#define BOLSA_LETRAS_H

#include <iostream>
#include <algorithm>    
#include <vector>
#include "letra.h"

using namespace std;

class BolsaLetras {
private:
    vector<char> bolsa;
public:
    
/*
 * @brief Constructor por defecto vacio
 */           
    BolsaLetras();
/*
 * @brief Funcion para insertar una letra en el vector con los datos
 * @param La letra a insertar
 */          
    void insertar(const Letra &letra);
 /*
 * @brief Funcion que devuelve una letra
 * @return la letra
 */          
    char getLetra();
    
 /*
 * @brief Comprobación de la validez de la palabra pasada por parámetro
 * @param Palabra a comprobar
 * @return True si es válida, false si no
 */
    bool esValida(string sol);

/*
 * @brief Comprobación de si una letra se puede elegir
 * @param Letra a comprobar
 * @return True si es válida, false si no
 */    
    bool sePuedeElegir(char letra);
    
/*
 * @brief Iterador que puede modificar y recorrer los elementos del contenedor
 * @return El iterador
 */        
    typedef vector<char>::iterator iterator;
        
/*
 * @brief Iterador que puede recorrer los elementos del contenedor
 * @return El iterador
 */        
    typedef vector<char>::const_iterator const_iterator;
        
/*
 * @brief Devuelve el inicio del contenedor. Puede modificar.
 * @return Iterador apuntando al inicio del contenedor
 */
    BolsaLetras::iterator begin();
        
/*
 * @brief Devuelve el final del contenedor. Puede modificar.
 * @return Iterador apuntando al final del contenedor
 */
   BolsaLetras::iterator end();
       
/*
 * @brief Devuelve el inicio del contenedor
 * @return Iterador apuntando al inicio del contenedor
 */
     BolsaLetras::const_iterator begin() const;

/*
 * @brief Devuelve el finastringl del contenedor
 * @return Iterador apuntando al final del contenedor
 */
    BolsaLetras::const_iterator end() const;  

};

#endif /* BOLSA_PALABRAS_H */

