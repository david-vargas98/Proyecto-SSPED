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
    //Métodos set y get:
    void setId(const string& valor) {id = valor;}
    string getId() const {return id;}
    void setCombustible(float valor) {combustible = valor;}
    float getCombustible() const { return combustible;}
    void setVelocidad(float valor) {velocidad = valor;}
    float getVelocidad() const {return velocidad;}
    void setArmadura(float valor) {armadura = valor;}
    float getArmadura() const {return armadura;}
    //Sobrecarga:
    friend bool operator ==(const Barco& b1, const Barco& b2)
	{
		return b1.getId() == b2.getId();
	}
    friend ostream& operator <<(ostream& out, Barco& b)
    {
        out << left;
        out << setw(6) << b.getId() << setw(12) << b.getCombustible() << setw(10) << b.getVelocidad() << setw(9) << b.getArmadura();
        return out;
    }
    //Métodos:
    void agregarGuerrero(Guerrero g){ guerreros.push(g); }
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
    void tope()
    {
        if (guerreros.empty())
        {
            cout << "No hay guerreros para mostrar" << endl;
        }
        else
        {
            cout << left;
            cout << setw(6) << "ID" << setw(7) << "Salud" << setw(7) << "Fuerza" << setw(7) << "Escudo" << setw(5) << "Tipo" << endl; 
            cout << guerreros.top();
            
        }
    }
    size_t size(){return guerreros.size();}
    void mostrar()
    {
        if (guerreros.empty())
        {
            cout << "No hay guerreros para mostrar" << endl;
        }
        else
        {
            stack<Guerrero> copia(guerreros);
            cout << left;
            cout << setw(6) << "ID" << setw(7) << "Salud" << setw(7) << "Fuerza" << setw(7) << "Escudo" << setw(5) << "Tipo" << endl; 
            while (!copia.empty())
            {
                auto& e = copia.top();
                cout << e;
                copia.pop();
            }
        }        
    }
    struct cmp
    {
        bool operator()(Barco* b1, Barco* b2)
        {
            return b1->getVelocidad() < b2->getVelocidad();
        }
    };
};
#endif