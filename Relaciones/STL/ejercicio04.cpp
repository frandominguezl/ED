/*
* @file ejercicio04.cpp
* @brief En base al ejercicio anterior, devolver un multimap para consultar las palabras
 * que aparecen un número determinado de veces
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

typedef map<string,int> Conteo;

map<string,int> contar(string nom_fich){
    /* Declaramos las variables, en concreto nuestro archivo de tipo ifstream,
     la palabra que vamos a ir tomando una a una del fichero, y el mapa donde
     almacenaremos el conteo de todas las palabras */
    ifstream archivo;
    string palabra;
    Conteo mapa_cont;
    
    archivo.open(nom_fich);
    if (archivo.is_open()){
        /* Mientras archivo tenga palabras, almacénalas en el mapa */
        while(archivo >> palabra){
            mapa_cont[palabra]++;
        }
    
        archivo.close();
    }

    else{
        cout << "No se ha podido abrir el archivo";
    }
    
    return mapa_cont;
}

vector<string> veces(const map<string,int> &palabras, int num){
    vector<string> resultado;
    Conteo::const_iterator pos;
    int contador = 0;
    
    for(pos = palabras.begin(); pos != palabras.end(); ++pos){
        if(pos->second == num){
            resultado.push_back(pos->first);
        }
    }
    
    return resultado;
}

int main(){
    Conteo cont = contar("prueba.txt");
    /* El archivo prueba.txt contiene exactamente lo siguiente:
     hola que tal hola que */
    Conteo::iterator pos;
    vector<string> claves;
    int num;
    
    cout << "Introduce el número de veces a buscar: ";
    cin >> num;
    
    claves = veces(cont, num);
    
    cout << "Las palabras que aparecen " << num << " veces son: ";
    
    for(int i=0; i<claves.size(); i++){
        cout << claves[i] << endl;
    }
    
    /* El resultado, probado con el número dos, es que las palabras hola y que aparecen
     2 veces.*/
}