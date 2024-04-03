#include<string>
#include "propietario.h"
using namespace std;

Propietario::Propietario(){
    
}
// Constructor implementation
Propietario::Propietario(string nombre, string apellidos, string dependecia, string carnetIdentidad) {
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->dependencia = dependecia;
    this->carnetIdentidad = carnetIdentidad;
}

// Getter and setter implementations
string Propietario::getNombre() {
    return nombre;
}

void Propietario::setNombre(string nombre) {
    this->nombre = nombre;
}

string Propietario::getApellidos() {
    return apellidos;
}

void Propietario::setApellidos(string apellidos) {
    this->apellidos = apellidos;
}

string Propietario::getDependencia() {
    return this->dependencia;
}

void Propietario::setDependencia(string dependencia) {
    this->dependencia = dependencia;
}

string Propietario::getCarnetIdentidad() {
    return carnetIdentidad;
}

void Propietario::setCarnetIdentidad(string carnetIdentidad) {
    this->carnetIdentidad = carnetIdentidad;
}
