/*
* @file ejercicio05.cpp
* @brief Determinar las opciones que se han pasado al ejecutar un programa
* @author Francisco DomÃ­nguez Lorente
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef map<string,string> Parametros;

map<string, string> params(string cad){
    Parametros aux;
    
    for(int i=0; i<cad.size(); i++){
        if(cad[i] == '-'){
            if(cad[i+1] == 'z'){
            aux.insert({"-z", "OpciÃ³n -z"});
            }

            else if(cad[i+1] == 'x'){
                aux.insert({"-x", "OpciÃ³n -x"});
            }

            else if(cad[i+1] == 'f'){
                aux.insert({"-f", "ParÃ¡metro de archivo"});
            }

            else{
                aux.insert({"?", "ParÃ¡metro desconocido"});
            }
        }
    }
    
    return aux;
}

int main(){
    string comando = "tar -z -x -f fichero";
    Parametros pars = params(comando);
    Parametros::iterator pos;
    
    for(pos = pars.begin(); pos != pars.end(); ++pos){
        cout << "ParÃ¡metro: " << pos->first << ", descripciÃ³n: " << pos->second << endl;
    }
}
