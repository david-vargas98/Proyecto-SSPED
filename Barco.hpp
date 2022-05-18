#ifndef BARCO_HPP
#define BARCO_HPP
#include <iostream>
#include <stack>
#include "Guerrero.hpp"
using namespace std;
class Barco
{
    private:
    string id;
    float combustible;
    float velocidad;
    float armadura;
    stack<Guerrero> guerreros;  //Se agrega un stack de tipo guerrero.
    public:
    Barco() = default;
    //Métodos set y get.
    void setId(const string& valor) {id = valor;}
    string getId() const {return id;}
    void setCombustible(float valor) {combustible = valor;}
    float getCombustible() const { return combustible;}
    void setVelocidad(float valor) {velocidad = valor;}
    float getVelocidad() const {return velocidad;}
    void setArmadura(float valor) {armadura = valor;}
    float getArmadura() const {return armadura;}
    //Métodos:
    void agregarGuerrero(Guerrero g)
    {
        guerreros.push(g); cout << "¡El Guerrero ha sido añadido!" << endl;
    }
    void eliminarGuerrero()
    {
        if (guerreros.empty())
        {
            cout << "No se puede eliminar, ya que no hay guerreros añadidos" << endl;
        }
        else
        {
            guerreros.pop();
            cout << "¡El Guerrero ha sido eliminado!" << endl;
        }
        
    }
    void tope(){cout << "El tope es: " << endl; guerreros.top();}
};
#endif