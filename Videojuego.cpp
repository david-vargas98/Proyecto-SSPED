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
    jugadores.pop_front();
}
void VideoJuego::eliminarAlFinal()
{
    jugadores.pop_back();
}
void VideoJuego::eliminarPorPosicion()
{
    //Se declara una variable para pasar la posición a eliminar.
    size_t pos;
    cout << "¿Cuál es la posición del Jugador que desea eliminar?" << endl;
    cin >> pos;
    jugadores.erase(pos);
}
void VideoJuego::primer()
{
    cout << "Primer Jugador:" << endl;
    cout << jugadores.front();
}
void VideoJuego::ultimo()
{
    cout << "Último Jugador:" << endl;
    cout << jugadores.back();
}
void VideoJuego::ordenarAscendenteNickname() //Usando una función lambda.
{
    //Se declara la función lambda:
    auto cmp = [] (const Jugador& j1, const Jugador& j2) { return j1.getNickname() > j2.getNickname(); };
    jugadores.sort(cmp, true); //Se manda el comparador y "true" indicando que será orden ascendente.
    cout << "Se ha ordenado por Nickname de manera Ascendente" << endl;
}
void VideoJuego::ordenarDescendenteMinutos() //Usando una función lambda.
{
    //Se declara la función lambda:
    auto cmp = [] (const Jugador& j1, const Jugador& j2) { return j1.getMinutosJugados() > j2.getMinutosJugados(); };
    jugadores.sort(cmp, false);  //Se manda el comparador y "false" indicando que será orden descendente.
    cout << "Se ha ordenado por Número de mminutos jugados de manera Descendente" << endl;
}
void VideoJuego::ordenarDescendentePuntuacion()  //Usando una función lambda.
{
    //Se declara la función lambda:
    auto cmp = [] (const Jugador& j1, const Jugador& j2) { return j1.getPuntuacion() > j2.getPuntuacion(); };
    jugadores.sort(cmp, false);
    cout << "Se ha ordenado por Puntuación de manera Descendente" << endl;
} 
void VideoJuego::buscarPorNickname()
{
    //Se declara una variable para el nickname a buscar.
    string nickname;
    cout << "Ingresa el Nickname a buscar: ";
    cin.ignore();
    getline(cin, nickname);
    //Se instncia un objeto de jugador temporal.
    Jugador j;
    //Se asigna el nombre a buscar del personaje.
    j.setNickname(nickname);
    //Se declara la función lambda.
    auto cmp = [] (const Jugador& j1, const Jugador& j2) { return j1.getNickname() == j2.getNickname(); };
    //En caso de devolver el puntero hacia la dirección, se asigna.
    Jugador* encontrado = jugadores.find(cmp, j);
    if (encontrado)
    {
        cout << "					Jugador encontrado:" << endl;
        cout << *encontrado << endl;
    }
    else
    {
        cout << "					No existe el Jugador" << endl;
				cout << endl;
    }
    
}
void VideoJuego::buscarPorPuntuacionAlta() //El Jugador con la puntuacion más alta.
{
    //Se declara una variable para la puntuación a buscar.
    float puntuacion;
    cout << "Ingresa la Puntuación a buscar: ";
    cin >> puntuacion;
    //Se instncia un objeto de jugador temporal.
    Jugador j;
    //Se asigna la puntuación a buscar del personaje.
    j.setPuntuacion(puntuacion);
    //Se declara la función lambda.
    auto cmp = [] (const Jugador& j1, const Jugador& j2) { return j1.getPuntuacion() == j2.getPuntuacion(); };
    //En caso de devolver el puntero hacia la dirección, se asigna.
    Jugador* encontrado = jugadores.find(cmp, j);
    if (encontrado)
    {
        cout << "					Jugador encontrado:" << endl;
        cout << *encontrado << endl;
    }
    else
    {
        cout << "					No existe el Jugador" << endl;
				cout << endl;
    }
}
void VideoJuego::buscarPorMayorCantidadMinutos() //El Jugador con la cantidad de minutos jugados más alta.
{
    //Se declara una variable para los minutos jugados a buscar.
    float minutos;
    cout << "Ingresa los Minutos Jugados a buscar: ";
    cin >> minutos;
    //Se instncia un objeto de jugador temporal.
    Jugador j;
    //Se asigna la puntuación a buscar del personaje.
    j.setMinutosJugados(minutos);
    //Se declara la función lambda.
    auto cmp = [] (const Jugador& j1, const Jugador& j2) { return j1.getMinutosJugados() == j2.getMinutosJugados(); };
    //En caso de devolver el puntero hacia la dirección, se asigna.
    Jugador* encontrado = jugadores.find(cmp, j);
    if (encontrado)
    {
        cout << "					Jugador encontrado:" << endl;
        cout << *encontrado << endl;
    }
    else
    {
        cout << "					No existe el Jugador" << endl;
				cout << endl;
    }
}
void VideoJuego::mostrarJugadores()
{
    jugadores.mostrar();
}