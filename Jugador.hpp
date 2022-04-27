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
    //Sobrecarga de operadores in&out
    friend istream& operator >>(istream& is, Jugador& j)
    {
    //Se declaran variables temporales
    string n;
    float m, p;
    //Se pide al usuario agregar al jugador
    cout << "\t\tAgregar jugador" << endl;
    cout << "Ingrese el Nickname: ";
    cin.ignore();
    getline(is, n);
    cout << "Ingrese los minutos jugados: ";
    is >> m;
    cout << "Ingrese la puntuación: ";
    is >> p;
    //Se asignan los atributos por medio de los métodos de acceso
    j.setNickname(n);
    j.setMinutosJugados(m);
    j.setPuntuacion(p);
    return is;
    }
    friend ostream& operator <<(ostream& os, const Jugador& j)
    {
        os << "Nickname: " << j.getNickname() << endl;
        os << "Minutos Jugados: " << j.getMinutosJugados() << endl;
        os << "Puntuación: " << j.getPuntuacion() << endl;
        return os;
    }
};

#endif