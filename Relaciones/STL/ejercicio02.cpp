/*
* @file ejercicio02.cpp
* @brief Desencriptar una cadena con un map
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<char,char> Desencriptar;

string desencripta(string cad, const map<char,char> &codigo){
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
    string cadena = "ltqbhdkzfn";
    string cad_mayus = "BDANKKZ";
    Desencriptar cod;

    /* Bucle for para nuestro mapa de desencriptación.
     Asigno a cada letra la siguiente correspondiente en el abecedario.
     Si es la letra z, fuerzo a que sea sustituida por la a.*/
    for(char c = 'a'; c <= 'z'; c++){
        if(c == 'a'){
            cod['z'] = 'a';
        }
        
        else{
           cod[c-1] = c; 
        }		
    }
    
    /* También necesitamos las mayúsculas, por si acaso*/
    for(char c = 'A'; c <= 'Z'; c++){
        if(c == 'A'){
            cod['Z'] = 'A';
        }
        
        else{
           cod[c-1] = c; 
        }		
    }

    cout << "La primera cadena desencriptada es " << desencripta(cadena, cod) << endl;
    cout << "La segunda cadena desencriptada es " << desencripta(cad_mayus, cod) << endl;
}