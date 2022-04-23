#include "Jugador.hpp"
//Constructor implementado
Jugador::Jugador()
{

}
//Implementación de métodos de acceso
void Jugador::setNickname(const string& valor)
{
    nickname = valor;
}
string Jugador::getNickname() const
{
    return nickname;
}
void Jugador::setMinutosJugados(float valor)
{
    minutosJugados = valor;
}
float Jugador::getMinutosJugados() const
{
    return minutosJugados;
}
void Jugador::setPuntuacion(float valor)
{
    puntuacion = valor;
}
float Jugador::getPuntuacion() const{
    return puntuacion;
}
