///*
//* @author: Francisco Domínguez Lorente
//* @author: David Gómez Hernández
//*/
//
//#include <iostream>
//#include <fstream>
//#include "lista_palabras.h"
//#include "conjunto_letras.h"
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <time.h>
//using namespace std;
//
//struct letras_cantidad{
//    char l;
//    double F;
//};
//
//int main(int argc, char** argv){
//    
//    if (argc != 4){
//        cout << "Error en el número de parámetros. Los parametros son: " << endl;
//        cout << "1. El fichero con palabras\n 2. El fichero con las letras\n 3. Fichero de salida\n";
//        
//        return 0;
//    }
//    
//    ifstream f(argv[1]);
//    if(!f){
//        cout << "No puedo abrir el fichero " << argv[1] << endl;
//    
//        return 0;
//    }
//    
//    ifstream letras(argv[2]);
//    if(!letras){
//        cout << "No puedo abrir el fichero " << argv[2] << endl;
//        
//        return 0;
//    }
//    
//    cout<<"Cargando lista_palabras..."<<endl;
//    ListaPalabras D;
//    f>>D;
//    cout<<"Operación correcta"<<endl;
//    
//    cout<<"Cargando conjunto de letras..."<<endl;
//    ConjuntoLetras conj;
//    letras>>conj;
//    cout<<"Operacion correcta"<<endl;
//    
//    /* Deberíamos comprobar si el fichero de salida está vacío */
//    ofstream salida(argv[3]);
//    if(!letras){
//        cout << "No puedo abrir el fichero " << argv[3] << endl;
//        
//        return 0;
//    }
//    salida << "#Letra   Cantidad"<<endl;
//
//    int numero_letras=D.getNumeroLetras();
//    
//    cout<<"El numero total de letras es de "<<numero_letras<<endl;
//
//    set<Letra>::const_iterator itrconj = conj.begin();
//    vector<letras_cantidad> letras_conjunto;
//    
//    for(itrconj;itrconj!=conj.end();itrconj++){
//        letras_cantidad tmp;
//        tmp.F=0;
//        tmp.l=(*itrconj).getLetra();
//        letras_conjunto.push_back(tmp);
//    }
//    
//    set<string>::const_iterator iterador= D.begin();
//    for(iterador; iterador!=D.end(); iterador++){
//        string p=*iterador;
//        for(int i=0;i<p.size();i++){
//            transform(p.begin(),p.end(),p.begin(),::toupper);
//            for(int j=0;j<letras_conjunto.size();j++){
//                if((letras_conjunto[j].l == p[i])){
//                    letras_conjunto[j].F++;
//                }
//            }
//        }
//    }
//    cout<<endl;
//    
//    double frecuencia;
//    for(int i=0;i<letras_conjunto.size();i++){
//        frecuencia=(letras_conjunto[i].F * 1.0 / numero_letras)*100;
//        salida<<letras_conjunto[i].l<<"         "<<frecuencia<<endl;
//    }
//    
//}