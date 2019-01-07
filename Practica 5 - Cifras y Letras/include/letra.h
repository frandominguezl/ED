/*
* @author: Francisco Domínguez Lorente
* @author: David Gómez Hernández
*/

#ifndef LETRA_H
#define LETRA_H

#include <iostream>
using namespace std;

/*
 * @brief TDA Letra
 */

class Letra{
private:
    char letra;
    int num_apariciones;
    int puntuacion;

public:

/*
 * @brief Constructor por defecto
 */
    Letra();
    
/*
 * @brief Constructor por parámetros
 * @param La letra a introducir
 * @param El número de apariciones de la letra
 * @param La puntuación de la letra
 */
    Letra(char letra, int num_apariciones, int puntuacion);
    
/*
 * @brief Establecer la letra
 * @param La letra a establecer
 */
    void setLetra(char letra);
    
/*
 * @brief Establecer el número de apariciones de la letra
 * @param Número de apariciones de la letra
 */
    void setNumeroApariciones(int num_apariciones);
    
/*
 * @brief Establecer la puntuación de la letra
 * @param La puntuación de la letra
 */
    void setPuntuacion(int puntuacion); 
    
/*
 * @brief Consultor básico de la letra
 * @return La letra
 */
    inline char getLetra() const {return this->letra;};
    
/*
 * @brief Consultor básico del número de apariciones
 * @return Entero con el número de apariciones de la letra
 */
    inline int getNumeroApariciones() const {return this->num_apariciones;};
    
/*
 * @brief Consultor básico del número de la puntuación de la letra
 * @return Entero con la puntuación de la letra
 */
    inline int getPuntuacion() const {return this->puntuacion;};
/*
 * @brief Escribe en un flujo de salida una Letra
 * @param os flujo de entrada
 * @param letra el objeto Letra que se escribe
 * @return el flujo de entrada
 */ 
    friend ostream& operator << (ostream &os, const Letra &letra);
/*
 * @brief Escribe en un flujo de salida una Letra
 * @param os flujo de salida
 * @param letra el objeto Letra que se escribe
 * @return el flujo de salida
 */
    friend istream& operator >> (istream &is, Letra &letra);
    
    bool operator<(const Letra& otro)const;
};

#endif

