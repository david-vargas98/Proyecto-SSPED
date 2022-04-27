#include "Videojuego.hpp"
//Métodos de acceso
void VideoJuego::agregarAlInicio()
{
    if (jugadores.full())  //Se valida que el arreglo de Jugadores no esté lleno.
    {
        cout << "No se puede agregar más Jugadores" << endl;
    }
    else
    {
        //Se crea una instancia de Jugador para almacenar el que se va a ingresar.
        Jugador j;
        //Se usa la sobrecarga de la clase jugador para capturar un jugador.
        cin >> j;
        //Se agrega al arreglo el personaje.
        jugadores.push_front(j);
    }
}
void VideoJuego::agregarAlFinal()
{
    if (jugadores.full())
    {
        cout << "No se puede agregar más Jugadores" << endl;
    }
    else
    {
        //Se crea una instancia de Jugador para almacenar el que se va a ingresar.
        Jugador j;
        //Se usa la sobrecarga de la clase jugador para capturar un jugador.
        cin >> j;
        //Se agrega al arreglo el personaje.
        jugadores.push_back(j);
    }
}
void VideoJuego::insertarPorPosicion()
{
    if (jugadores.full())
    {
        cout << "No se puede agregar más Jugadores" << endl;
    }
    else
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
}
void VideoJuego::eliminarAlInicio()
{
    if (jugadores.empty())
    {
        cout << "No se puede eliminar ya que el Arreglo está vacío" << endl;
    }
    else
    {
        jugadores.pop_front();
    }
}
void VideoJuego::eliminarAlFinal()
{
    if (jugadores.empty())
    {
        cout << "No se puede eliminar ya que el Arreglo está vacío" << endl;
    }
    else
    {
        jugadores.pop_back();
    }
}
void VideoJuego::eliminarPorPosicion()
{
    if (jugadores.empty())
    {
        cout << "No se puede eliminar ya que el Arreglo está vacío" << endl;
    }
    else
    {
        //Se declara una variable para pasar la posición a eliminar.
        size_t pos;
        cout << "¿Cuál es la posición del Jugador que desea eliminar?" << endl;
        cin >> pos;
        jugadores.erase(pos);
    }
}
void VideoJuego::primer()
{
    if (jugadores.empty())
    {
        cout << "No se puede mostrar el primer Jugador ya que el Arreglo está vacío" << endl;
    }
    else
    {
        cout << "Primer Jugador:" << endl;
        cout << jugadores.front();
    }
}
void VideoJuego::ultimo()
{
    if (jugadores.empty())
    {
        cout << "No se puede mostrar el último Jugador ya que el Arreglo está vacío" << endl;
    }
    else
    {
        cout << "Último Jugador:" << endl;
        cout << jugadores.back();
    }
}
void VideoJuego::ordenarAscendenteNickname() //Usando una función lambda.
{
    if (jugadores.empty())
    {
        cout << "No se puede ordenar ya que el Arreglo está vacío" << endl;
    }
    else
    {
        //Se declara la función lambda:
        auto cmp = [] (const Jugador& j1, const Jugador& j2) { return j1.getNickname() > j2.getNickname(); };
        jugadores.sort(cmp, true); //Se manda el comparador y "true" indicando que será orden ascendente.
        cout << "Se ha ordenado por Nickname de manera Ascendente" << endl;
    }
}
void VideoJuego::ordenarDescendenteMinutos() //Usando una función lambda.
{
    if (jugadores.empty())
    {
        cout << "No se puede ordenar ya que el Arreglo está vacío" << endl;
    }
    else
    {
        //Se declara la función lambda:
        auto cmp = [] (const Jugador& j1, const Jugador& j2) { return j1.getMinutosJugados() > j2.getMinutosJugados(); };
        jugadores.sort(cmp, false);  //Se manda el comparador y "false" indicando que será orden descendente.
        cout << "Se ha ordenado por Número de mminutos jugados de manera Descendente" << endl;
    }
}
void VideoJuego::ordenarDescendentePuntuacion()  //Usando una función lambda.
{
    if (jugadores.empty())
    {
        cout << "No se puede ordenar ya que el Arreglo está vacío" << endl;
    }
    else
    {
        //Se declara la función lambda:
        auto cmp = [] (const Jugador& j1, const Jugador& j2) { return j1.getPuntuacion() > j2.getPuntuacion(); };
        jugadores.sort(cmp, false);
        cout << "Se ha ordenado por Puntuación de manera Descendente" << endl;
    }
} 
void VideoJuego::buscarPorNickname()
{
    if (jugadores.empty())
    {
        cout << "No se puede buscar ya que el Arreglo está vacío" << endl;
    }
    else
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
}
void VideoJuego::buscarPorPuntuacionAlta() //El Jugador con la puntuacion más alta.
{
    if (jugadores.empty())
    {
        cout << "No se puede buscar ya que el Arreglo está vacío" << endl;
    }
    else
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
}
void VideoJuego::buscarPorMayorCantidadMinutos() //El Jugador con la cantidad de minutos jugados más alta.
{
    if (jugadores.empty())
    {
        cout << "No se puede buscar ya que el Arreglo está vacío" << endl;
    }
    else
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
}
void VideoJuego::mostrarJugadores()
{
    if (jugadores.empty())
    {
        cout << "No se puede mostrar los Jugadores ya que el Arreglo está vacío" << endl;
    }
    else
    {
        jugadores.mostrar();
    }
}
void VideoJuego::cantidadJugadores()
{
    cout << "Cantidad de Jugadores: " << jugadores.size() << endl;
}
void VideoJuego::capacidad()
{
    cout << "Capacidad: " << jugadores.max_size() << endl;
}
void VideoJuego::lleno()
{
    cout << "Lleno: " << jugadores.full() << endl;
}
void VideoJuego::vacio()
{
    cout << "Vacío: " << jugadores.empty() << endl;
}
void VideoJuego::modificar()
{
    if (jugadores.empty())
    {
        cout << "No se puede modificar ya que el Arreglo está vacío" << endl;
    }
    else
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
            cout << *encontrado << endl << endl;
            //Declaración de varibale para el menú.
            size_t opcion_mod;
            //Se inicia un ciclo.
            while (true)
            {
                //Menú para las modificaciones del Jugador.
                cout << "\tModificar" << endl;
                cout << "1) Nickname" << endl;
                cout << "2) Minutos Jugados" << endl;
                cout << "3) Puntuación" << endl;
                cout << "4) Salir" << endl;
                cout << "Elija el atributo que desa modificar: ";
                cin >> opcion_mod;
                if (opcion_mod == 1)
                {
                    //Se declara una variable temporal.
                    string nuevo;
                    //Se pide ingresar el nuevo valor del atributo.
                    cout << "Ingrese el nuevo Nickname: ";
                    cin.ignore();
                    getline(cin, nuevo);
                    //Se asigna el nuevo valor a el atributo del objeto.
                    encontrado->setNickname(nuevo);  //Se utiliza la flecha, ya que estamos haciendo referencia a un puntero.
                    cout << "El Nickname ha sido modificado con éxito!" << endl;
                    break; //Se utliza para romper el ciclo.
                }
                if (opcion_mod == 2)
                {
                    float nuevo_min;
                    cout << "Ingrese los nuevos Minutos Jugados: ";
                    cin >> nuevo_min;
                    encontrado->setMinutosJugados(nuevo_min);
                    cout << "Los Minutos Jugados han sido modificados con éxito!" << endl;
                    break;
                }
                if (opcion_mod == 3)
                {
                    float nuevo_pun;
                    cout << "Ingrese la nuevas Puntuación: ";
                    cin >> nuevo_pun;
                    encontrado->setPuntuacion(nuevo_pun);
                    cout << "La Puntuación han sido modificada con éxito!" << endl;
                    break;
                }
                if (opcion_mod == 4)
                {
                    cout << "Usted ha salido del programa" << endl;
                    break;
                }
                else if (opcion_mod < 1 || opcion_mod > 4)
                {
                     cout << "Ha seleccionado una opción no válida" << endl;
                }
            }
        }
        else
        {
            cout << "					No existe el Jugador" << endl;
	    	cout << endl;
        }
    }
}