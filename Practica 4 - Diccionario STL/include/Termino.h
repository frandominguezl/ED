/*
* @author: Domíngez Lorente Francisco
* @author: Gómez Hernández David
*/

#ifndef terminoH
#define terminoH

#include <string>
#include <vector>
#include <utility>

using namespace std;

/*
* @brief TDA Termino
*/

class Termino{
private:
    pair <string, vector<string>> termino;
    int num_definiciones;
    
public:

/*
 * @brief Constructor por defecto
 */
	Termino();

/*
 * @brief Constructor por parámetros
 */
	Termino(string palabra, vector<string> definiciones);

/*
 * @brief Constructor por copia
 * @param El Término del que se hace la copia. No se modifica
 */
	Termino(const Termino& t);

/*
 * @brief Consultor de número de definiciones
 * @return Número de definiciones de la palabra
 */
	inline int getNumDefiniciones() const{return this->termino.second.size();};

/*
 * @brief Consultor de la palabra
 * @return La palabra
 */
	inline string getPalabra() const{return this->termino.first;};
	
/*
 * @brief Consultor de los significados
 * @return Significado
 */
	inline vector<string> getDefiniciones() const {return this->termino.second;};

/*
 * @brief Consultor del significado i
 * @param El índice del significado que queremos obtener 
 * @return Significado
 */        
        inline string getDefinicion(int i) const {return this->termino.second[i];} // Implementar el iterador
        
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
 * @brief Iterador que puede modificar y recorrer los elementos del contenedor
 * @return El iterador
 */        
        typedef vector<string>::iterator iterator;
        
/*
 * @brief Iterador que puede recorrer los elementos del contenedor
 * @return El iterador
 */        
        typedef vector<string>::const_iterator const_iterator;

/*
 * @brief Devuelve el inicio del contenedor. Puede modificar.
 * @return Iterador apuntando al inicio del contenedor
 */
        inline Termino::iterator begin(){return this->termino.second.begin();}
        
/*
 * @brief Devuelve el final del contenedor. Puede modificar.
 * @return Iterador apuntando al final del contenedor
 */
        inline Termino::iterator end() {return this->termino.second.end();}
       
/*
 * @brief Devuelve el inicio del contenedor
 * @return Iterador apuntando al inicio del contenedor
 */
        inline Termino::const_iterator begin() const{return this->termino.second.cbegin();};

/*
 * @brief Devuelve el final del contenedor
 * @return Iterador apuntando al final del contenedor
 */
        inline Termino::const_iterator end() const{return this->termino.second.cend();};        
        
/*
 * @brief Sobrecarga del operador de asignación de término
 * @return Referencia al término
 */
	Termino& operator =(const Termino& original);

/*
 * @brief Sobrecarga del operador menor, para comparar
 */
        bool operator <(const Termino& otro) const;
        
/*
 * @brief Sobrecarga del operador de salida
 */
        friend ostream& operator <<(ostream& os, const Termino& d);
        

};

#endif
