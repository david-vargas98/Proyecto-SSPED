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
    //Constructores
    Jugador() = default;
    Jugador(const string& nickname, float minutosJugados, float puntuacion):nickname{nickname}, minutosJugados{minutosJugados}, puntuacion{puntuacion}{}
    //Métodos de acceso
    void setNickname(const string& valor){nickname = valor;}
    string getNickname() const{return nickname;}
    void setMinutosJugados(float valor){minutosJugados = valor;}
    float getMinutosJugados() const{return minutosJugados;}
    void setPuntuacion(float valor){puntuacion = valor;}
    float getPuntuacion() const{return puntuacion;}
};

#endif