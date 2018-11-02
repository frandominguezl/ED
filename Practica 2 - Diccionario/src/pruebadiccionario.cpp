#include "Diccionario.h"
#include "Termino.h"
#include "Vector_Dinamico.h"
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Diccionario mi_diccionario;
   f >> mi_diccionario; //Cargamos en memoria el diccionario
   cout << mi_diccionario;
   
   // Obtener las definiciones asociadas a una palabra
   string palabra1 = "duke";

   cout << "Las definiciones asociadas a la palabra " << palabra1 << " son: " << endl;

   if(mi_diccionario.getDefs(palabra1).size() == 0){
       cout << "    El término no tiene definiciones." << endl;
   }
   
   else{
    for(int i=0; i<mi_diccionario.getDefs(palabra1).size(); i++){
      cout << mi_diccionario.getDefs(palabra1)[i] << endl;
    }      
   }


   // Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
   char ini = 'a', fin = 'b';

   cout << "El (sub)diccionario de términos comprendidos entre " << ini << " y " << fin << " es: " << endl;
   cout << mi_diccionario.filtrarIntervalo(ini, fin) << endl;

   // Obtener el (sub)diccionario de términos asociados a una palabra clave
   string palabra2 = "james";

   cout << "El (sub)diccionario de términos asociados a la palabra " << palabra2 << " es: " << endl;
   cout << mi_diccionario.filtrarPalabraClave(palabra2) << endl;
   
   // Obtener el recuento de las definiciones
   int num_total=0, asociadas_palabra=0;
   float media=0;
   
   cout << "El recuento de definiciones es: " << endl;
   mi_diccionario.recuentoDefiniciones(num_total, asociadas_palabra, media);
   cout << "Total: " << num_total << ", Asociadas a una palabra: " << asociadas_palabra << ", Media: " << media << endl;
   /* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  
    Algunas sugerencias: 
    - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"   
    - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
    - Cualquier otra funcionalidad que considereis de interes 
   */

}
