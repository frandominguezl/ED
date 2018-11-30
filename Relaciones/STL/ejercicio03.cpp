/*
* @file ejercicio03.cpp
* @brief Contar el número de veces que aparece una palabra dentro de un archivo
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
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

int main(){
    Conteo cont = contar("prueba.txt");
    /* El archivo prueba.txt contiene exactamente lo siguiente:
     hola que tal hola que */
    Conteo::iterator pos;
    
    for(pos = cont.begin(); pos != cont.end(); ++pos){
        cout << pos->first << " " << pos->second << endl;
    }
    
    /* El resultado con el archivo introducido es:
     hola 2
     que 2
     tal 1 */
}