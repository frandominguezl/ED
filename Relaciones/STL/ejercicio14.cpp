/*
* @file ejercicio14.cpp
* @brief Clase de vector disperso
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
class vdisperso {
    private:
        list<pair<int, T>> coefs;
        int n;
        
    public:
        /* @brief Constructor por copia 
         * @param El vector del que se copia, no se modifica
         */
        vdisperso(const vector<T> &v){
            typename vector<T>::const_iterator itr;
            this->n = 0;

            /* Metemos en la lista de coeficientes, los elementos que sean
            distintos de 0 */
            for(itr = v.begin(); itr != v.end(); ++itr){
                if(*itr != 0){
                    coefs.push_back(pair<int, T>(n, *itr));
                }

                ++n;
            }
        }

        /* @brief Asigna a la posición i, el elemento x
         * @param i La posición a insertar
         * @param x El elemento a insertar
         */
        void asignar_coeficiente(int i, const T &x){
            typename list<pair<int, T>>::iterator itr = coefs.begin();
            bool encontrado = false;

            for(itr = coefs.begin(); itr != coefs.end() && !encontrado; ++itr){
                if(itr->first == i){
                        itr->second = x;
                        encontrado = true;
                }
            }

            if(!encontrado){
                coefs.push_back(pair<int, T>(i, x));
            }
        }

        /* @brief Devuelve el vector con los elementos de coefs, no con las posiciones
         * @return Un vector de elementos, incluidos los nulos
         */
        vector<T> convertir() const{
            vector<T> convertido;
            typename vector<T>::iterator itr_conv = convertido.begin();
            typename list<pair<int, T>>::const_iterator itr = coefs.begin();

            /* Iteramos sobre los n elementos. Si el primer elemento de coefs coincide
             con el iterador del bucle, se mete en el nuevo vector el segundo elemento. En 
             caso contratio, se mete el 0 */
            for(int i=0; i<n; i++){
                if(itr->first == i){
                    convertido.push_back(itr->second);
                    ++itr;
                }

                else{
                    convertido.push_back(0);
                    ++itr_conv;
                }
            }
            
            return convertido;
        }
        
        /*
         * @brief Método para facilitar la impresión del vector disperso
         */
        void imprimir(){
            typename list<pair<int, T>>::iterator itr;
            
            for(itr = coefs.begin(); itr != coefs.end(); ++itr){
                cout << itr->first << ", " << itr->second << endl;
            }
        }
};

int main(){
    vector<int> vec, vec_convert;
    
    /* Añadimos al vector elemento, la mayoría de ellos son 0 */
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(2);
    
    /* Creamos el objeto de vector disperso, lo imprimimos y a continuación asignamos a otra
     variable de tipo vector el resultado de convertir() */
    vdisperso<int> v_dis(vec);    
    v_dis.imprimir();    
    vec_convert = v_dis.convertir();
    
    for(int i=0; i<vec_convert.size(); i++){
        cout << vec_convert[i] << endl;
    }
}