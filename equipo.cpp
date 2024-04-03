#include<string>
#include "equipo.h"
using namespace std;
Equipo::Equipo(string carnetPropietario, string dependencia, string sistemaOperativo, string identificadorMac) {
    this->carnetPropietario = carnetPropietario;
    this->dependencia = dependencia;
    this->sistemaOperativo = sistemaOperativo;
    this->identificadorMac = identificadorMac;
}

Equipo::Equipo() {

}

bool Equipo::operator==(Equipo &equipo) {
    return this->identificadorMac == equipo.getIdentificadorMac();
}

string Equipo::getSistemaOperativo() {
    return sistemaOperativo;
}

string Equipo::getIdentificadorMac() {
    return identificadorMac;
}

string Equipo::getDependencia() {
    return dependencia;
}

string Equipo::getCarnetPropietario() {
    return carnetPropietario;
}

void Equipo::setSistemaOperativo(string sistemaOperativo) {
    this->sistemaOperativo = sistemaOperativo;
}

void Equipo::setIdentificadorMac(string identificadorMac) {
    this->identificadorMac = identificadorMac;
}

void Equipo::setDependencia(string dependencia) {
    this->dependencia = dependencia;
}

void Equipo::setCarnetPropietario(string carnetPropietario) {
    this->carnetPropietario = carnetPropietario;
}

Telefono::Telefono(string numeroEtecsa, string carnetPropietario, string dependencia, string sistemaOperativo, string identificadorMac)
     : Equipo(carnetPropietario, dependencia, sistemaOperativo, identificadorMac) {
    this->numeroEtecsa = numeroEtecsa;
}

Telefono::Telefono() {

}

string Telefono::obtenerISF() {
    string isf = "T";
    for (auto c: this->identificadorMac) {
        if (isdigit(c)) continue;
        isf += c;
    }

    return isf;
}

string Telefono::getNumeroEtecsa() {
    return numeroEtecsa;
}

Laptop::Laptop(string carnetPropietario, string dependencia, string sistemaOperativo, string identificadorMac, int capacidad, char unidad) : Equipo(carnetPropietario, dependencia, sistemaOperativo, identificadorMac) {
    this->capacidad = capacidad;
    this->unidad = unidad;
}

Laptop::Laptop() {

}

string Laptop::obtenerISF() {
    string isf = "L";
    for (auto c: this->identificadorMac) {
        if (isdigit(c)) continue;
        isf += c;
    }

    return isf;
}

int Laptop::getCapacidad() {
    return capacidad;
}

char Laptop::getUnidad() {
    return unidad;
}

void Laptop::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

void Laptop::setUnidad(char unidad) {
    this->unidad = unidad;
}

