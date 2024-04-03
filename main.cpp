#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <typeinfo>
#include "propietario.h"
#include "equipo.h"
#include <set>
#include "gestorEquipos.h"
using namespace std;

int main() {
    cout << "Bienvenido al sistema de gestion de equipos." << "\n";
    
    bool isCarnetBien = false;
    GestorEquipos gestorEquipos;
    string nombre, apellidos, carnetIdentidad,dependencia;
    
    do{
        fflush(stdin);
        cout<<"Seleccione la opcion a realizar:\n1- Registrar Equipo \n2- Registrar Propietario\n";
        cout<<"3- Cantidad de equipos disponibles\n4- Cantidad de equipos disponibles por dependencia\n";
        cout<<"5- Eliminar equipo\n6- Obtener ISF\n7- Salir\n";

        int option;
        cin>>option;

        switch (option)
        {
        case 1:{
            cout<<"Tipos de equipos disponibles:\n1- Telefono 2- Laptop\n";
            cout<<"Seleccione el tipo de equipo a registrar: ";
            int option2;
            cin>>option2;
            if(option2 == 1){
                cout<<"Propietarios disponibles:\n";
                if(gestorEquipos.getPropietarios().size() == 0){
                    cout<<"No hay propietarios registrados\n";
                    break;
                }

                int i = 0;
                for(auto propietario: gestorEquipos.getPropietarios()){
                    cout<<"#"<<++i<<": "<<propietario.getNombre()<<" "<<propietario.getApellidos()<<" "<<propietario.getCarnetIdentidad()<<"\n";
                }

                cout<<"Seleccione el propietario del equipo: ";
                int propietarioIndex;
                cin>>propietarioIndex;
                propietarioIndex--;
                if(propietarioIndex < 0 || propietarioIndex >= gestorEquipos.getPropietarios().size()){
                    cout<<"Propietario no valido\n";
                    break;
                }

                cout<<"Introduzca el numero de etecsa: ";
                string numeroEtecsa;
                cin>>numeroEtecsa;
                bool ok = true;
                for(auto u: numeroEtecsa){
                    if(!isdigit(u)){
                        cout<<"El numero de etecsa debe ser un numero\n";
                        ok = false;
                        break;
                    
                    }
                }

                if(!ok){
                    break;
                }

                cout<<"Introduzca el sistema operativo: ";
                string sistemaOperativo;
                cin>>sistemaOperativo;
                cout<<"Introduzca el identificador mac: ";
                string identificadorMac;
                cin>>identificadorMac;
                gestorEquipos.registrarEquipo(new Telefono(numeroEtecsa, gestorEquipos.getPropietarios()[propietarioIndex].getCarnetIdentidad(), gestorEquipos.getPropietarios()[propietarioIndex].getDependencia(), sistemaOperativo, identificadorMac));
            }else if(option2 == 2){
                cout<<"Propietarios disponibles:\n";
                int i = 0;
                for(auto propietario: gestorEquipos.getPropietarios()){
                    cout<<"#"<<++i<<": "<<propietario.getNombre()<<" "<<propietario.getApellidos()<<" "<<propietario.getCarnetIdentidad()<<"\n";
                }

                cout<<"Seleccione el propietario del equipo: ";
                int propietarioIndex;
                cin>>propietarioIndex;
                propietarioIndex--;
                if(propietarioIndex < 0 || propietarioIndex >= gestorEquipos.getPropietarios().size()){
                    cout<<"Propietario no valido\n";
                    break;
                }

                cout<<"Introduzca la capacidad: ";
                int capacidad;
                cin>>capacidad;
                cout<<"Introduzca la unidad(ejemplo M, T, G): ";
                char unidad;
                cin>>unidad;
                cout<<"Introduzca el sistema operativo: ";
                string sistemaOperativo;
                cin>>sistemaOperativo;
                cout<<"Introduzca el identificador mac: ";
                string identificadorMac;
                cin>>identificadorMac;
                gestorEquipos.registrarEquipo(new Laptop(gestorEquipos.getPropietarios()[propietarioIndex].getCarnetIdentidad(), gestorEquipos.getPropietarios()[propietarioIndex].getDependencia(), sistemaOperativo, identificadorMac, capacidad, unidad));
            }else{
                cout<<"Opcion no valida\n";
            }

            break;
        }
        case 2:{
            while(1){
                cout<<"Introduzca su carnet identidad: ";
                cin>>carnetIdentidad;
                bool ok = true;
                for(auto u: carnetIdentidad){
                    if(!isdigit(u)){
                        ok = false;
                    }
                }

                if(carnetIdentidad.size() == 11 && ok){
                    break;
                }else{
                    cout<<"El carnet debe tener 11 digitos\n";
                }
            }

            if(gestorEquipos.isPropietarioRegistrado(carnetIdentidad)){
                cout<<"Este propieario ya esta registrado\n";
                break;
            }

            fflush(stdin);
            cout<<"Introduzca el nombre del propietario: ";
            getline(cin, nombre);
            fflush(stdin);
            cout<<"Introduzca los apellidos del propietario: ";
            getline(cin, apellidos);
            
            cout<<"Introduzca la dependencia ejemplo uclv: ";
            cin>>dependencia;
            gestorEquipos.registrarPropietario(Propietario(nombre, apellidos, dependencia, carnetIdentidad));
            break;
        }
        case 3:{
            cout<<"Cantidad de equipos disponibles: "<<gestorEquipos.contarEquipos()<<"\n";
            break;
        }
        case 4:{
            cout<<"Dependencias disponibles:\n";
            int i = 0;
            for(auto dependencia: gestorEquipos.getDependencias()){
                cout<<"#"<<++i<<": "<<dependencia<<"\n";
            }
            cout<<"Seleccione la dependencia: ";
            int index;
            cin>>index;
            index--;
            if(index < 0 || index >= gestorEquipos.getDependencias().size()){
                cout<<"Dependencia no valida\n";
                break;
            }
            cout<<"Cantidad de equipos disponibles en la dependencia "<<gestorEquipos.getDependencias()[index]<<": "<<gestorEquipos.contarEquiposPorDependencia(gestorEquipos.getDependencias()[index])<<"\n";
            break;
        }
        case 5:{
            cout<<"Identificadores de mac disponibles:\n";
            int i = 0;
            for(auto equipo: gestorEquipos.getEquipos()){
                cout<<"#"<<++i<<": "<<equipo->getIdentificadorMac()<<"\n";
            }
            int index;
            cout<<"Seleccione el identificador mac del equipo a eliminar: ";
            cin>>index;
            index--;
            if(index < 0 || index >= gestorEquipos.getEquipos().size()){
                cout<<"Identificador mac no valido\n";
                break;
            }
            gestorEquipos.eliminarEquipo(gestorEquipos.getEquipos()[index]->getIdentificadorMac());

            break;
        }
        case 6:{
            cout<<"Identificadores de mac disponibles:\n";
            int i = 0;
            for(auto equipo: gestorEquipos.getEquipos()){
                cout<<"#"<<++i<<": "<<equipo->getIdentificadorMac()<<"\n";
            }
            
            int index;
            cout<<"Seleccione el identificador mac del equipo: ";
            cin>>index;
            index--;
            if(index < 0 || index >= gestorEquipos.getEquipos().size()){
                cout<<"Identificador mac no valido\n";
                break;
            }
            cout<<"ISF del equipo: "<<gestorEquipos.getEquipos()[index]->obtenerISF()<<"\n";
            break;
        }
        case 7:{
            return 0;
        }
        default:
            break;
        }
    }while(1);
}
