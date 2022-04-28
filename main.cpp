#include <iostream>
#include <locale.h>
#include "Videojuego.hpp"
using namespace std;
void menu()
{
    cout << "\tMenú" << endl;
    cout << "1) Agregar al inicio un Jugador" << endl;
    cout << "2) Agregar al final un Jugador" << endl;
    cout << "3) Insertar un Jugador por posición" << endl;
    cout << "4) Muestra el primer jugador" << endl;
    cout << "5) Muestra el último jugador" << endl;
    cout << "6) Ordenar" << endl;
    cout << "7) Eliminar un jugador al inicio" << endl;
    cout << "8) Eliminar un jugador al final" << endl;
    cout << "9) Eliminar un jugador por posición" << endl;
    cout << "10) Buscar " << endl;
    cout << "11) Modificar" << endl;
    cout << "12) Mostrar el estado del arreglo" << endl;
    cout << "13) Mostrar todos los jugadores del arreglo" << endl;
    cout << "14) Salir" << endl;
    cout << "Seleciona una opción: ";


}
void menu_ordenar()
{
    cout << "\tMenú Ordenar" << endl;
    cout << "1) Ordena por Nickname (Ascendente)" << endl;
    cout << "2) Ordena por Minutos jugados (Ascendente)" << endl;
    cout << "3) Ordena por Puntuación (Descendente)" << endl;
    cout << "4) Salir" << endl;
    cout << "Seleciona una opción: ";
}
void menu_buscar()
{
    cout << "\tMenú Buscar" << endl;
    cout << "1) Buscar por Nickname" << endl;
    cout << "2) Buscar por Minutos jugados" << endl;
    cout << "3) Buscar por Puntuación" << endl;
    cout << "4) Salir" << endl;
    cout << "Seleciona una opción: ";
}
int main(int arg, char* argv[])
{
     setlocale(LC_ALL, "spanish");
     size_t opcion, cantidad;
     if (arg == 1)  //En caso de no mandar el tamaño por terminal, se ingresa en ejecución.
     {
         cout << "Ingrese la cantidad de Jugadores: ";
         cin >> cantidad;
     }
     else
     {
         cantidad = stoul(argv[1]);  //En la posición "1" es dónde está el argumento o tamaño. Se convierte el string a unsigned long.
     }
     
     VideoJuego vj(cantidad);
    do
    {
        menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        vj.agregarAlInicio();
            break;
        case 2:
        vj.agregarAlFinal();
            break;
        case 3:
        vj.insertarPorPosicion();
            break;
        case 4:
        vj.primer();
            break;
        case 5:
        vj.ultimo();
            break;
        case 6:
        menu_ordenar();
        size_t opcion_or;
        cin >> opcion_or;
        switch (opcion_or)
        {
        case 1:
            vj.ordenarAscendenteNickname();
            break;
        case 2:
            vj.ordenarDescendenteMinutos();
            break;
        case 3:
            vj.ordenarDescendentePuntuacion();
            break;
        case 4:
            cout << "Usted ha regresado al menú principal" << endl;
            break;
        default:
            cout << "Ha elegido una opción no válida" << endl;
            break;
        }
            break;
        case 7:
            vj.eliminarAlInicio();
            break;
        case 8:
            vj.eliminarAlFinal();
            break;
        case 9:
            vj.eliminarPorPosicion();
            break;
        case 10:
            menu_buscar();
            size_t opcion_bus;
            cin >> opcion_bus;
            switch (opcion_bus)
            {
            case 1:
                vj.buscarPorNickname();
                break;
            case 2:
                vj.buscarPorMayorCantidadMinutos();
                break;
            case 3:
                vj.buscarPorPuntuacionAlta();
                break;
            case 4:
                cout << "Usted ha regresado al menú principal" << endl;
                break;
            default:
                cout << "Ha elegido una opción no válida" << endl;
                break;
            }
            break;
        case 11:
            vj.modificar();
            break;
        case 12:
            cout << "\tEstado del arreglo" << endl;
            vj.cantidadJugadores();
            vj.capacidad();
            vj.vacio();
            vj.lleno();
            break;
        case 13:
        vj.mostrarJugadores();
            break;
        case 14:
            cout << "Usted ha salido del programa" << endl;
            break;
        default:
            cout << "Ha seleccionado una opción no válida" << endl;
            break;
        }
    } while (opcion != 14);
    
    return 0;
}