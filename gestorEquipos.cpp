#include "gestorEquipos.h"
#include "equipo.h"
#include "propietario.h"
#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

GestorEquipos::GestorEquipos(){

}

vector<string> GestorEquipos::getDependencias(){
    set<string> dependencias;
    for(auto propietario: propietarios){
        dependencias.insert(propietario.getDependencia());
    }

    return vector<string>(dependencias.begin(), dependencias.end());
}

void GestorEquipos::registrarEquipo(Equipo *equipo) {
    equipos.push_back(equipo);
    cout << "Equipo registrado exitosamente." << "\n";
}

void GestorEquipos::eliminarEquipo(string identificadorMac) {
    for(int i = 0; i < equipos.size(); i++){
        if(equipos[i]->getIdentificadorMac() == identificadorMac){
            equipos.erase(equipos.begin() + i);
            cout << "Equipo eliminado exitosamente." << "\n";
            return;
        }
    }        
}

string GestorEquipos::obtenerISF(string identificadorMac) {
    string isf = "";
    for (auto equipo: equipos) {
        if (equipo->getIdentificadorMac() == identificadorMac) {
            isf = equipo->obtenerISF();
        }
    }
    return isf;
}

int GestorEquipos::contarEquipos() const {
    return equipos.size();
}

bool GestorEquipos::equipoRegistrado(string identificadorMac){
    for (auto equipo: this->equipos) {
        if (equipo->getIdentificadorMac() == identificadorMac){
            return true;
        };
    }
    return false;
}

int GestorEquipos::contarEquiposPorDependencia(string dependencia) {
    int count = 0;
    for (auto equipo: equipos) {
        if (equipo->getDependencia() == dependencia) count++;
    }
    return count;
}

bool GestorEquipos::isPropietarioRegistrado(string carnetIdentidad) {
    for (auto propietario: this->propietarios) {
        if (propietario.getCarnetIdentidad() == carnetIdentidad) return true;
    }
    return false;
}

void GestorEquipos::registrarPropietario(Propietario propietario) {
    propietarios.push_back(propietario);
    cout << "Propietario registrado exitosamente." << "\n";
}

vector<Equipo *> GestorEquipos::getEquipos() {
    return this->equipos;
}

vector<Propietario> GestorEquipos::getPropietarios() {
    return this->propietarios;
}
