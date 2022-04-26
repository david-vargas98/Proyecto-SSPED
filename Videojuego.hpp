#ifndef VIDEOJUEGO_HPP
#define VIDEOJUEGO_HPP
#include "Arreglo.hpp"
#include "Jugador.hpp"
class VideoJuego
{
private:
    Arreglo<Jugador> jugadores;  //Administradora de objetos de la clase Jugador.
public:
//Constructores
    VideoJuego(size_t cantidad):jugadores{cantidad}{};
    VideoJuego();
    ~VideoJuego() = default;
//Métodos de acceso
    void agregarAlInicio();
    void agregarAlFinal();
    void insertarPorPosicion();
    void eliminarAlInicio();
    void eliminarAlFinal();
    void eliminarPorPosicion();
    void ordenarAscendenteNickname(); //Usando una función lambda.
    void ordenarDescendenteMinutos(); //Usando una función lambda.
    void ordenarDescendentePuntuacion(); //Usando una función lambda.
    void buscarPorNickname();
    void buscarPorPuntuacionAlta(); //El Jugador con la puntuacion más alta.
    void buscarPorMayorCantidadMinutos(); //El Jugador con la cantidad de minutos jugados más alta.
};
#endif