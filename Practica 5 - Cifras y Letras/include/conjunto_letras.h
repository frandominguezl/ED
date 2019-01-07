/*
* @author: Francisco Domínguez Lorente
* @author: David Gómez Hernández
*/

#ifndef CONJUNTO_LETRAS_H
#define CONJUNTO_LETRAS_H

#include <set>
#include <fstream>
#include "letra.h"
#include "bolsa_letras.h"

using namespace std;

class ConjuntoLetras{
private:
    set<Letra> conjunto;
    
public:

/*
 * @brief Constructor por defecto
 */
    ConjuntoLetras();
    
/*
 * @brief Constructor por parámetros
 * @param Conjunto de letras
 */
    ConjuntoLetras(set<Letra> conjunto);
    
/*
 * @brief Consultos del número de letras en el conjunto
 * @return Entero con el número de letras
 */
    inline int getNumeroLetras(){return this->conjunto.size();};
    
/*
 * @brief Añadir una letra al conjunto
 * @param La letra a añadir
 */
    void aniadeLetra(const Letra l);     

/*
 * @brief Eliminar una letra del conjunto
 * @param La letra a eliminar
 */
    void eliminarLetra(Letra l);
    
/*
 * @brief Obtener la letra dada por la posición del parámetro
 * @param Posición de la letra que se quiere obtener
 * @return La letra encontrada
 */
    Letra obtenerLetra(int pos);
    
/*
 * @brief Obtener la puntuación de la palabra dada por parámetro
 * @param Palabra a obtener la puntuación
 * @param Opción del juego
 * @return Entero con la puntuación
 */
    int obtenerPuntos(string palabra, char opcion);
    
 /*
 * @brief Funcion que desordena el vector y devuelve una bolsa con las letras que se van a usar para jugar
 * @param numero de letras que ha introducido el usuario con las que quiere jugar
 * @return bolsa necesaria para el juego
 */          
    BolsaLetras letrasjuego(int longitud);
    
/*
 * @brief Iterador que puede modificar y recorrer los elementos del contenedor
 * @return El iterador
 */        
    typedef set<Letra>::iterator iterator;
        
/*
 * @brief Iterador que puede recorrer los elementos del contenedor
 * @return El iterador
 */        
    typedef set<Letra>::const_iterator const_iterator;
        
/*
 * @brief Devuelve el inicio del contenedor. Puede modificar.
 * @return Iterador apuntando al inicio del contenedor
 */
    ConjuntoLetras::iterator begin();
        
/*
 * @brief Devuelve el final del contenedor. Puede modificar.
 * @return Iterador apuntando al final del contenedor
 */
    ConjuntoLetras::iterator end();
       
/*
 * @brief Devuelve el inicio del contenedor
 * @return Iterador apuntando al inicio del contenedor
 */
    ConjuntoLetras::const_iterator begin() const;

/*
 * @brief Devuelve el finastringl del contenedor
 * @return Iterador apuntando al final del contenedor
 */
    ConjuntoLetras::const_iterator end() const;  
    
/*
 * @brief Lee de un flujo de entrada un ConjuntoLetras
 * @param is flujo de entrada
 * @param conjunto el objeto donde se realiza la lectura.
 * @return el flujo de entrada
 */
    friend istream& operator >> (istream &is, ConjuntoLetras &conjunto);
    
/*
 * @brief Escribe en un flujo de salida un ConjuntoLetras
 * @param os flujo de salida
 * @param conjunto el objeto ListaPalabras que se escribe
 * @return el flujo de salida
 */
    friend ostream& operator << (ostream & os, const ConjuntoLetras &conjunto);
};


#endif

