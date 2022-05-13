#ifndef CIVILIZACION_HPP
#define CIVILIZACION_HPP
#include <iostream>
#include <list>
#include "Aldeano.hpp"
using namespace std;
class Civilizacion
{
    private:
    string nombre;
    int posx;
    int posy;
    list<Aldeano> aldeanos;  //Se incluye un list de aldeanos.
    public:
    //Constructores
    Civilizacion() = default;
    Civilizacion(const string& nombre, int posx, int posy):nombre{nombre}, posx{posx}, posy{posy}{} 
    //Métodos de acceso set y get
    void setNombre(const string& valor) { nombre = valor; }
    string getNombre() const { return nombre; }
    void setPosx(int valor) { posx = valor; }
    int getPosx() const { return posx; }
    void setPosy(int valor) { posy = valor; }
    int getPosy() const { return posy; }
    //Sobrecargas
    friend ostream& operator <<(ostream& os, const Civilizacion& c)
    {
        os << "Nombre: " << c.getNombre() << endl;
        os << "Posición en X: " << c.getPosx() << endl;
        os << "Posición en Y: " << c.getPosy() << endl;
        return os;
    }
};
#endif