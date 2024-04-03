#include<string>
using namespace std;
#ifndef PROPIETARIO_H
#define PROPIETARIO_H
    class Propietario {
        private:
            string nombre, apellidos, dependencia, carnetIdentidad;
        
        public:
            Propietario();
            Propietario(string nombre, string apellidos, string dependecia, string carnetIdentidad);
            void setNombre(string);
            void setDependencia(string);
            void setCarnetIdentidad(string);
            void setApellidos(string);
            string getNombre();
            string getDependencia();
            string getCarnetIdentidad();
            string getApellidos();
    };
#endif