#include<vector>
#include "equipo.h"
#include "propietario.h"
using namespace std;
#ifndef GESTOREQUIPOS_H
#define GESTOREQUIPOS_H
class GestorEquipos {
    private:
        vector<Equipo *> equipos;
        vector<Propietario> propietarios;
    public:
        GestorEquipos();
        vector<string> getDependencias();
        void registrarEquipo(Equipo * equipo);
        void eliminarEquipo(string identificadorMac);
        string obtenerISF(string identificadorMac);
        int contarEquipos() const;
        bool equipoRegistrado(string identificadorMac);
        int contarEquiposPorDependencia(string dependencia);
        bool isPropietarioRegistrado(string carnetIdentidad);
        void registrarPropietario(Propietario propietario);
        vector<Equipo *> getEquipos();
        vector<Propietario> getPropietarios();
};
#endif