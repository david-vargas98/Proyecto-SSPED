#ifndef CIVILIZACION_HPP
#define CIVILIZACION_HPP
#include <iostream>
#include <list>
#include "Aldeano.hpp"
#include "Barco.hpp"
#include <list>
using namespace std;
class Civilizacion
{
    private:
    string nombre;
    int posx;
    int posy;
    list<Aldeano> aldeanos;  //Se incluye un list de aldeanos.
    list<Barco*> puerto;  //Se añade un list de punteros de tipo Barco.
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
    //Métodos de interfaz.
    void agregarInicio(const Aldeano& a);
    void agregarFinal(const Aldeano& a);
    bool empty();
    void eliminarNombre();
    void eliminarSalud();
    void eliminarEdad();
    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();
    void buscar();
    void modificar();
    void mostrar();
    //Método de la list de Barcos:
    void agregarBarco(Barco* b)
    {
        puerto.push_back(b);
        cout << "¡El Barco ha sido añadido con éxito!" << endl;
    }
};
#endif