#include<string>
using namespace std;

#ifndef EQUIPO_H
#define EQUIPO_H
    class Equipo {
        protected:
            string sistemaOperativo, identificadorMac, dependencia, carnetPropietario;
        public:
            Equipo(string, string, string, string);
            Equipo();
            string getSistemaOperativo();
            string getIdentificadorMac();
            string getDependencia();
            string getCarnetPropietario();
            void setSistemaOperativo(string);
            void setIdentificadorMac(string);
            void setDependencia(string);
            void setCarnetPropietario(string);
            bool operator==(Equipo&);
            virtual string obtenerISF() = 0;
    };

    class Telefono : public Equipo {
        private:
            string numeroEtecsa;
        public:
            Telefono(string numeroEtecsa, string carnetPropietario, string dependencia, string sistemaOperativo, string identificadorMac);
            Telefono();
            string getNumeroEtecsa();
            void setNumeroEtecsa(string);
            string obtenerISF() override;
    };

    class Laptop : public Equipo {
        private:
            int capacidad;
            char unidad;
        public:
            Laptop(string, string, string, string, int, char);
            Laptop();
            int getCapacidad();
            char getUnidad();
            void setCapacidad(int);
            void setUnidad(char);
            string obtenerISF() override;
    };
#endif