#ifndef CIVILIZACION_HPP
#define CIVILIZACION_HPP
#include <iostream>
using namespace std;
class Civilizacion
{
    private:
    string nombre;
    int posx;
    int posy;
    public:
    //Constructores
    Civilizacion() = default;
    Civilizacion(const string& nombre, int posx, int posy):nombre{nombre}, posx{posx}, posy{posy}{} 
    //Métodos de acceso set y get
    void setNombre(const string& valor) { nombre = valor; }
    string getNombre() const { return nombre; }
    void setPosx(int valor) { posx = valor; }
    int getPosy() const { return posx; }
    void setPosy(int valor) { posy = valor; }
    int getPosy() const { return posy; }

};
#endif