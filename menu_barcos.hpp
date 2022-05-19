#ifndef MENU_BARCOS_HPP
#define MENU_BARCOS_HPP
#include <iostream>
#include "Civilizacion.hpp"
#include "Jugador.hpp"
using namespace std;
void menu_barcos_opc(string s)
{
    cout << "\tMenú Barcos para la civilización " << s << endl;
    cout << "1) Agregar Barco" << endl;
    cout << "2) Mostrar todos los Barcos" << endl;
    cout << "3) Buscar Barcos" << endl;
    cout << "4) Eliminar Barco" << endl;
    cout << "5) Salir" << endl;
    cout << "Seleciona una opción: ";
}
void menu_barcos(Civilizacion* c, Jugador* j)
{
    while (true)
    {
        menu_barcos_opc(c->getNombre());
        size_t opcion_barcos;
        cin >> opcion_barcos;
        if (opcion_barcos == 1)
        {
            c->capturarBarco(c);
        }
        if (opcion_barcos == 2)
        {
            c->mostrarBarcos();
        }
        if (opcion_barcos == 3)
        {
            c->buscarBarcos();
        }
        if (opcion_barcos == 4)
        {
            c->eliminarBarcos();
        }
        if (opcion_barcos == 5)
        {
            cout << "Usted ha regresado al menú de Civilizaciones" << endl;
            break;
        }
        if (opcion_barcos < 1 || opcion_barcos > 5)
        {
            cout << "Ha seleccionado una opción no válida" << endl;
        }
        

    }
    
}
#endif