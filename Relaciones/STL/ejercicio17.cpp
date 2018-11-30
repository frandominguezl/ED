/*
* @file ejercicio17.cpp
* @brief TDA Vector Dinámico usando list
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <list>
using namespace std;

template <class T>
class Vector_Dinamico{
    private:
        list<T> datos;
        int nelementos;
    
    public:
        /*
         * @brief Constructor por defecto
         */
        Vector_Dinamico(){
            this->datos = list<T>(0);
            this->nelementos = datos.size();
        }
        
        /*
         * @brief Consultor del tamaño
         * @return El tamaño
         */
        int size() const{
            return this->nelementos;
        }
        
        /*
         * @brief Consultor de si el vector está vacío
         * @return True si está vacía, false si no
         */
        bool empty(){
            return this->nelementos == 0;
        }
        
        /*
         * @brief Insertar al final
         */
        void insertar(const T& x){
            datos.push_back(x);
            nelementos++;
        }
        
        /*
         * @brief Devuelve el vector completo
         */
        void imprimir(){
            typename list<T>::iterator itr = datos.begin();
            
            for(itr; itr != datos.end(); ++itr){
                cout << *itr << endl;
            }
        }
        
        /*
         * @brief Sobrecarga del operador []
         * @param El elemento al que se quiere acceder
         * @return Referencia al elemento en la posición i
         */
        T operator[](const int i){
            typename list<T>::iterator itr = datos.begin();
            int contador = 0;
            T elemento;
            bool encontrado = false;
            
            while(itr != datos.end() && !encontrado){
                if(contador == i){
                    elemento = *itr;
                    encontrado = true;
                }
                
                else{
                    ++itr;
                    contador++;
                }
            }
            
            return elemento;
        }
};

int main(){
    /* Instanciamos Vector_Dinamico */
    Vector_Dinamico<int> vec;
    
    /* Añadimos algunos elementos */
    vec.insertar(3);
    vec.insertar(8);
    vec.insertar(12);
    vec.insertar(13);
    
    if(vec.empty()){
        cout << "El vector está vacío" << endl;
    }
    
    else{
        cout << "El tamaño del vector es: " << vec.size() << endl;
    }
    
    /* Accedemos al elemento 3, por ejemplo */
    cout << "El elemento en la posición 3 es " << vec[3] << endl;
    
    /* Imprimimos el vector */
    vec.imprimir();
}