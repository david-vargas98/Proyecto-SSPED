#ifndef GUERRERO_HPP
#define GUERRERO_HPP
#include <iostream>
#include <iomanip>
using namespace std;
class Guerrero
{
    private:
    string id;
    int salud;
    float fuerza;
    float escudo;
    string tipo;
    public:
    Guerrero() = default;
    //Métodos set y get
    void setId(const string& valor) {id = valor;}
    string getId() const {return id;}
    void setSalud(int valor) {salud = valor;}
    int getSalud() const {return salud;}
    void setFuerza(float valor) {fuerza = valor;}
    float getFuerza() const {return fuerza;}
    void setEscudo(float valor) {escudo = valor;}
    float getEscudo() const {return escudo;}
    void setTipo(const string& valor) {tipo = valor;}
    string getTipo() const {return tipo;}
    //Sobrecarga
    friend ostream& operator <<(ostream& os, const Guerrero& g)
    {
        cout << left;
        os << setw(6) << g.getId() << setw(7) << g.getSalud() << setw(7) << g.getFuerza() << setw(7) << g.getEscudo() << setw(5) << g.getTipo() << endl; 
        return os;
    }
};
#endif