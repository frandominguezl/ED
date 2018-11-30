/*
* @file ejercicio01.cpp
* @brief Encriptar una cadena con un map
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<char,char> Encriptar;

string encripta(string cad, const map<char,char> &codigo){
    /* Declaramos el iterador constante*/
    map<char,char>::const_iterator pos;

    /* Recorremos la cadena pasada por parámetro, asignamos el valor al iterador
     y cambiamos los valores de cada letra de la cadena*/
    for(int i=0; i<cad.length(); i++){
        pos = codigo.find(cad[i]);

        if(pos != codigo.end()){
            cad[i] = pos->second;
        }
    }

    return cad;
}

int main(){
    string cadena = "murcielago";
    string cad_mayus = "CEBOLLA";
    Encriptar cod;

    /* Bucle for para nuestro mapa de encriptación.
     Asigno a cada letra la anterior correspondiente en el abecedario.
     Si es la letra a, fuerzo a que sea sustituida por la z.*/
    for(char c = 'a'; c <= 'z'; c++){
        if(c == 'a'){
            cod[c] = 'z';
        }
        
        else{
           cod[c] = c-1; 
        }		
    }
    
    /* También necesitamos las mayúsculas, por si acaso*/
    for(char c = 'A'; c <= 'Z'; c++){
        if(c == 'A'){
            cod[c] = 'Z';
        }
        
        else{
           cod[c] = c-1; 
        }		
    }

    cout << "La primera cadena encriptada es " << encripta(cadena, cod) << endl;
    cout << "La segunda cadena encriptada es " << encripta(cad_mayus, cod) << endl;
}