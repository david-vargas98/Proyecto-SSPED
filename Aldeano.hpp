#ifndef ALDEANO_HPP
#define ALDEANO_HPP
#include <iostream>
using namespace std;
class Aldeano
{
    private:
    string nombre;
    int edad;
    string genero;
    float salud;
    public:
    Aldeano() = default;

    void setNombre(const string& valor) {nombre = valor;}
    string getNombre() const {return nombre;}
    void setEdad(int valor) {edad = valor;}
    int getEdad() const {return edad;}
    void setGenero(const string& valor) {genero = valor;}
    string getGenero() const {return genero;}
    void setSalud(float valor) {salud = valor;}
    float getSalud() const {return salud;}
};
#endif