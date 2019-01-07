/*
* @author: Francisco Domínguez Lorente
* @author: David Gómez Hernández
*/

#include <cstdlib>
#include "bolsa_letras.h"
#include "lista_palabras.h"
#include "conjunto_letras.h"

using namespace std;

string mostrarMejorPuntuacion(char opcion, int num, ListaPalabras &lista, ConjuntoLetras &conj){
    string salida;
    vector<string> palabras;

    if(opcion == 'L'){
        ListaPalabras::const_iterator iterador=lista.begin();
        for(iterador;iterador!=lista.end();iterador++){
            palabras.push_back(*iterador);
        }
        
        for(int i=0; i<(int)palabras.size(); i++){
            cout<<palabras[i]<<"  Puntuación: "<<palabras[i].size()<<endl;
            salida = palabras[i];
        }
    }
    else if(opcion == 'P'){
        ListaPalabras::const_iterator iterador = lista.begin();
        int maximo = conj.obtenerPuntos(*iterador,opcion);
        int aux;
        
        for(iterador = lista.begin(); iterador!=lista.end(); ++iterador){
            aux = conj.obtenerPuntos(*iterador, opcion);
            if(aux >= maximo){
                if(aux==maximo){
                    palabras.push_back(*iterador);
                }
                else{
                    maximo = aux;
                    palabras.clear();
                    palabras.push_back(*iterador);
                }
            }
        }

        for(int i=0; i<(int)palabras.size(); i++){
            cout<<palabras[i]<<"  Puntuación: "<<maximo<<endl;
            salida = palabras[i];
        }
    }

    return salida;
}

int main(int argc, char** argv) {

    if (argc != 5){
        cout<<"Error en el número de parámetros. Los parametros son: "<<endl;
        cout<<"1.- El fichero con palabras\n 2.- El fichero con las letras\n 3.- Número de letras a generar\n"
                "4.- Modalidad: L mayor longitud, P mayor puntuación";
        
        return 0;
    }
    
    ifstream f(argv[1]);
    if(!f){
        cout << "No puedo abrir el fichero " << argv[1] << endl;
    
        exit(0);
    }
    
    ifstream letras(argv[2]);
    if(!letras){
        cout << "No puedo abrir el fichero " << argv[2] << endl;
        
        exit(0);
    }
    
    int longitud = atoi(argv[3]);
    char opcion = argv[4][0];
    
    ConjuntoLetras conj;
    ListaPalabras D;
    
    cout << "Cargando lista_palabras..." << endl;
    f >> D;
    letras >> conj;
    
    BolsaLetras bolsa;
    
    /* Cargamos el conjunto de letras en la bolsa para que estén desordenadas */
    for (int i=0;i<conj.getNumeroLetras();i++){
        bolsa.insertar(conj.obtenerLetra(i));
    }
    
    
    bool juego = true;
    
    while(juego){
        BolsaLetras bolsajuego = conj.letrasjuego(longitud);
        ListaPalabras subDiccionario;
        string sol, mejor;
        char jugar;
    
        while(subDiccionario.empty()){
            subDiccionario = D.obtenerDisponibles(bolsajuego);
            cout << "Las letras son: ";
            for(int i=0; i<longitud; i++){
                char aux = bolsajuego.getLetra();
                cout << aux << "\t";
            }
            
            if(!subDiccionario.empty()){
                cout << "¿Cuál es tu solución?: ";
                cin >> sol;

                while(!subDiccionario.Esta(sol)){
                    cout << "Parece que esa palabra no está... Prueba con otra: ";
                    cin >> sol;
                }
                cout << "¡Solución correcta!" << endl;
                cout << "Tu solución: " << sol << ", Puntos: " << conj.obtenerPuntos(sol, opcion) << endl;
                
            }
            
            else{
                cout << "Parece que no hay palabras disponibles con esas letras... Déjame intentarlo de nuevo." << endl;
            }
        }

        /* Mostrar ahora las soluciones propuestas por el programa */
        cout << "Mis soluciones son: " << endl;
        mejor = mostrarMejorPuntuacion(opcion, longitud, subDiccionario, conj);
        cout << "Mejor solución: " << mejor << endl;
        
//        ListaPalabras::const_iterator iterador=subDiccionario.begin();
//        for(iterador;iterador!=subDiccionario.end();iterador++){
//            cout<<*iterador<<endl;
//        }
        
        cout << "¿Quieres seguir jugando? (S/N): ";
        cin >> jugar;

        if(jugar == 'S' || jugar == 's'){
            juego = true;
        }

        else if(jugar == 'N' || jugar == 'n'){
            juego = false;
        }

        else{
            cout << "Opción incorrecta. Saliendo del juego... " << endl;
            return 0;
        }
    }   
}