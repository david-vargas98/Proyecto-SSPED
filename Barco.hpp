#ifndef BARCO_HPP
#define BARCO_HPP
#include <iostream>
using namespace std;
class Barco
{
    private:
    string id;
    float combustible;
    float velocidad;
    float armadura;
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
};
#endif