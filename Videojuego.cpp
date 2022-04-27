#include "Videojuego.hpp"
//Métodos de acceso
void VideoJuego::agregarAlInicio()
{
    //Se crea una instancia de Jugador para almacenar el que se va a ingresar.
    Jugador j;
    //Se usa la sobrecarga de la clase jugador para capturar un jugador.
    cin >> j;
    //Se agrega al arreglo el personaje.
    jugadores.push_front(j);
}
void VideoJuego::agregarAlFinal()
{
    //Se crea una instancia de Jugador para almacenar el que se va a ingresar.
    Jugador j;
    //Se usa la sobrecarga de la clase jugador para capturar un jugador.
    cin >> j;
    //Se agrega al arreglo el personaje.
    jugadores.push_back(j);
}
void VideoJuego::insertarPorPosicion()
{
    //Se declara una variable para pasar la posición válida.
    size_t pos;
    //Se crea una instancia de Jugador para almacenar el que se va a ingresar.
    Jugador j;
    //Se usa la sobrecarga de la clase jugador para capturar un jugador.
    cin >> j;
    //Se agrega al arreglo el personaje.
    cout << "¿En qué posición válida desea agregar al jugador?" << endl;
    cin >> pos;
    jugadores.insert(j, pos);
}
void VideoJuego::eliminarAlInicio()
{

}
void VideoJuego::eliminarAlFinal()
{

}
void VideoJuego::eliminarPorPosicion()
{

}
void VideoJuego::ordenarAscendenteNickname() //Usando una función lambda.
{

}
void VideoJuego::ordenarDescendenteMinutos() //Usando una función lambda.
{

}
void VideoJuego::ordenarDescendentePuntuacion()
{
    //Usando una función lambda.
} 
void VideoJuego::buscarPorNickname()
{

}
void VideoJuego::buscarPorPuntuacionAlta() //El Jugador con la puntuacion más alta.
{

}
void VideoJuego::buscarPorMayorCantidadMinutos() //El Jugador con la cantidad de minutos jugados más alta.
{

}
void VideoJuego::mostrarJugadores()
{
    jugadores.mostrar();
}