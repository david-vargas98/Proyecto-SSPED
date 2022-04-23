#ifndef JUGADOR_HPP
#define JUGADOR_HPP
#include<iostream>
using namespace std;
class Jugador
{
    private:
    string nickname;
    float minutosJugados;
    float puntuacion;
    public:
    //Constructor
    Jugador();
    //Métodos de acceso
    void setNickname(const string& valor);
    string getNickname() const;
    void setMinutosJugados(float valor);
    float getMinutosJugados() const;
    void setPuntuacion(float valor);
    float getPuntuacion() const;
};

#endif