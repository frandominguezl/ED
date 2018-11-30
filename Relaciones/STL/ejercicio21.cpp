/*
* @file ejercicio21.cpp
* @brief Clase para la gestión de pacientes en un hospital
* @author Francisco Domínguez Lorente
*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Paciente{
    string nombre;
    string apellido;
    string DNI;
    int gravedad;
};

struct prioridad{
    bool operator()(Paciente uno, Paciente otro){
        return (uno.gravedad < otro.gravedad);
    }
};

class Hospital{
private:
    priority_queue<Paciente, vector<Paciente>, prioridad> pacientes;
    map<string, Paciente> mapaDNI;
    
public:
    /*
     * @brief Constructor por defecto
     */
    Hospital(){

    }
    
    /*
     * @brief Consultos del numero de pacientes
     * @return Entero del numero de pacientes
     */
    int numPacientes(){
        return pacientes.size();
    }
    
    /*
     * @brief Consultos de si la cola está vacía
     * @return True si está vacía, false si no
     */
    bool empty(){
        return pacientes.size() == 0;
    }
    
    /*
     * @brief Devuelve el paciente más alto en la cola de prioridad
     * @return El siguiente paciente
     */
    Paciente siguientePaciente(){
        return pacientes.top();
    }
    
    /*
     * @brief Inserta un paciente en la cola
     * @param El paciente a insertar
     */
    void insertaPaciente(Paciente p){
        pacientes.push(p);
        mapaDNI.insert({p.DNI, p});
    }
    
    /*
     * @brief Borra el paciente más alto en la cola de prioridad porque ya ha sido atendido
     */
    void borraPaciente(){
        Paciente p = siguientePaciente();
        pacientes.pop();
        mapaDNI.erase(p.DNI);
    }
    
    /*
     * @brief Busca un paciente según su DNI
     * @param String correspondiente al DNI
     * @return El paciente con ese DNI
     */
    Paciente buscarPorDNI(string DNI){
        Paciente encontrado = mapaDNI.find(DNI)->second;
        
        return encontrado;
    }
};

int main(){
    Hospital listaPacientes;
    
    /* Creamos 3 instancias de pacientes y les asignamos unos valores */
    Paciente p1, p2, p3;
    p1.nombre = "Jesús";
    p1.apellido = "Gómez";
    p1.DNI = "333333333F";
    p1.gravedad = 3;
    
    p2.nombre = "María";
    p2.apellido = "López";
    p2.DNI = "57575757E";
    p2.gravedad = 5;
    
    p3.nombre = "Roberto";
    p3.apellido = "Herrera";
    p3.DNI = "12312312S";
    p3.gravedad = 7;
    
    /* Los añadimos a la instancia de la clase Hospital */
    listaPacientes.insertaPaciente(p1);
    listaPacientes.insertaPaciente(p2);
    listaPacientes.insertaPaciente(p3);
    
    /* Imprimimos el siguiente paciente */
    Paciente sig = listaPacientes.siguientePaciente();
    cout << sig.nombre << ", " << sig.apellido << ", " << sig.DNI << ", " << sig.gravedad << endl;
    
    /* Buscamos un paciente por DNI y lo mostramos. Borramos el paciente más alto en la lista de propiedad */
    Paciente DNI1 = listaPacientes.buscarPorDNI("333333333F");
    cout << DNI1.nombre << ", " << DNI1.apellido << ", " << DNI1.DNI << ", " << DNI1.gravedad << endl;
    listaPacientes.borraPaciente();
    
    /* Mostramos el siguiente paciente */
    Paciente sig1 = listaPacientes.siguientePaciente();
    cout << sig1.nombre << ", " << sig1.apellido << ", " << sig1.DNI << ", " << sig1.gravedad << endl;
}