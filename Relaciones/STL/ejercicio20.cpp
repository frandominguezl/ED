/*
* @file ejercicio20.cpp
* @brief Contabilizar de forma eficiente el número de veces que aparece cada par de coordenadas
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <map>
using namespace std;

class MapaCoordenadas{
private:
    map<pair<float, float>, int> mapa;
    
public:
    /*
     * @brief Constructor por defecto
     */
    MapaCoordenadas(){
        
    }
    
    /*
     * @brief Inserta en el mapa un par de coordenadas
     * @param EL par de coordenadas a insertar
     */
    void insertar(pair<float, float> coordenadas){
        map<pair<float, float>, int>::iterator enc = mapa.find({coordenadas.first, coordenadas.second});
        
        /* Iteramos sobre el mapa. Si llegamos al final, es decir, si no se ha encontrado ese par
         de coordenadas, se inserta en el mapa con el valor de veces 1. En caso contrario, se incrementa el 
         número de veces que aparece */
        if(enc == mapa.end()){
            mapa.insert({{coordenadas.first, coordenadas.second}, 1});
        }
        
        else{
            ++enc->second;
        }
    }
    
    /*
     * @brief Consultor para saber si el mapa está vacío
     * @return True si está vacío, false si no
     */
    bool empty(){
        return mapa.empty();
    }
    
    /*
     * @brief Consultor para saber el número de coordenadas registradas en el mapa
     * @return Entero con el número de coordenadas del mapa
     */
    int numCoordenadas(){
        return mapa.size();
    }
    
    /*
     * @brief Consultor de cuántas veces se ha repetido un par de coordenadas en el mapa
     * @param El par de coordenadas a consultar
     * @return Entero con el número de veces que aparece
     */
    int numRepetidas(pair<float, float> coordenadas){
        return mapa.find({coordenadas.first, coordenadas.second})->second;
    }
    
    /*
     * @brief Método para facilitar la impresión del mapa
     */
    void imprimirMapa(){
        map<pair<float, float>, int>::iterator itr;
    
        for(itr = mapa.begin(); itr != mapa.end(); ++itr){
            cout << "Coordenadas: " << itr->first.first << ", " << itr->first.second << " Veces: " << itr->second << endl;
        }
    }
};

int main(){
    /* Creamos una instancia de la clase MapaCoordenadas y le metemos algunas coordenadas */
    MapaCoordenadas mapa;
    
    mapa.insertar(pair<float, float>(1.0, 1.0));
    mapa.insertar(pair<float, float>(1.5, 1.0));
    mapa.insertar(pair<float, float>(2.0, 3.0));
    mapa.insertar(pair<float, float>(1.0, 1.0));
    
    /* Imprimimos el mapa actual */
    mapa.imprimirMapa();
    
    /* Imprimimos el número de veces que aparece en el mapa las coordenadas (1.0, 1.0)*/
    cout << mapa.numRepetidas(pair<float, float>(1.0, 1.0)) << endl;
}