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


}
void menu_ordenar()
{
    cout << "\tMenú Ordenar" << endl;
    cout << "1) Ordena por Nickname (Ascendente)" << endl;
    cout << "2) Ordena por Minutos jugados (Ascendente)" << endl;
    cout << "3) Ordena por Puntuación (Descendente)" << endl;
}
int main()
{
     setlocale(LC_ALL, "spanish");
     int opcion, cantidad;
     cout << "Ingrese la cantidad de Jugadores: ";
     cin >> cantidad;
     VideoJuego vj(cantidad);
    do
    {
        menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:

            break;
        
        default:
            break;
        }
    } while (opcion != 14);
    
    return 0;
}