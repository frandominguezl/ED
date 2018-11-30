/*
* @file ejercicio19.cpp
* @brief Clase para pilotos de Fórmula 1
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

struct Piloto{
    string nombre;
    string apellido;
    int pos;
    string escuderia;
};

class PilotosF1{
    private:
        list<Piloto> pilotos;
        
    public:
        /*
         * @brief Constructor por defecto
         */
        PilotosF1(){
            this->pilotos = list<Piloto>(0);
        }
        
        /*
         * @brief Consultos del numero de pilotos
         * @return Número de pilotos
         */
        int numPilotos(){
            return this->pilotos.size();
        }
        
        /*
         * @brief Constructor de si está vacía la lista de pilotos
         * @return True si está vacía, false si no
         */
        bool empty(){
            return numPilotos() == 0;
        }
        
        /*
         * @brief Insertar un piloto en la lista
         * @param El piloto a insertar
         */
        void insertar(Piloto pil){
            pilotos.push_back(pil);
        }
        
        /*
         * @brief Comienzo de la lista. Necesario para iterar.
         * @return Iterador que apunta al comienzo de la lista
         */
        list<Piloto>::iterator begin(){
            return pilotos.begin();
        }
        
        /*
         * @brief Final de la lista. Necesario para iterar.
         * @return Iterador que apunta al final de la lista
         */
        list<Piloto>::iterator end(){
            return pilotos.end();
        }
        
        /*
         * @brief Consultor de un piloto según una posición
         * @param La posición
         * @return El piloto en esa posición
         */
        Piloto getPiloto(int pos){
            if(pos < numPilotos()){
                list<Piloto>::iterator itr;
                
                for(int i=0; i<pos; i++){
                    ++itr;
                }
                
                return *itr;
            }
        }
        
        /*
         * @brief Método auxiliar para consultar el apellido
         * @param El piloto a consultar su apellido
         * @return Su apellido
         */
        string getApellido(Piloto p){
            return p.apellido;
        }
        
        /*
         * @brief Devuelve un piloto según su apellido
         * @param El apellido a buscar
         * @return El piloto cuyo apellido coincide con el parámetro
         */
        Piloto getPilotoApellido(string apellido){
            list<Piloto>::iterator itr = pilotos.begin();
            bool encontrado = false;
            
            for(int i=0; i<numPilotos() && !encontrado; i++){
                if(getApellido(*itr) == apellido){
                    encontrado = true;
                }
                
                else{
                    ++itr;
                }
            }
            
            return *itr;
        }
};

int main(){
    /* Instanciamos 3 pilotos y uno auxiliar para el encontrado */
    Piloto pil1, pil2, pil3, encontrado;
    PilotosF1 pilotos;
    
    pil1.nombre= "Fernando";
    pil1.apellido = "Alonso";
    pil1.pos = 1;
    pil1.escuderia = "Renault";
    pilotos.insertar(pil1);
    
    pil2.nombre= "Yuji";
    pil2.apellido = "Ide";
    pil2.pos = 2;
    pil2.escuderia = "Super Aguri";
    pilotos.insertar(pil2);
    
    pil3.nombre= "Timo";
    pil3.apellido = "Glock";
    pil3.pos = 3;
    pil3.escuderia = "Toyota";
    pilotos.insertar(pil3);
    
    /* Mostramos todos los pilotos */
    list<Piloto>::iterator itr;
    
    for(itr = pilotos.begin(); itr != pilotos.end(); ++itr){
        cout << "Nombre: " << itr->nombre << endl;
        cout << "Apellido: " << itr->apellido << endl;
        cout << "Posición: " << itr->pos << endl;
        cout << "Escudería: " << itr->escuderia << endl;
        cout << endl;
    }
    
    /* Buscamos una coincidencia según un apellido y lo mostramos */
    encontrado = pilotos.getPilotoApellido("Ide");
    cout << "Nombre: " << encontrado.nombre << endl;
    cout << "Apellido: " << encontrado.apellido << endl;
    cout << "Posición: " << encontrado.pos << endl;
    cout << "Escudería: " << encontrado.escuderia << endl;
}