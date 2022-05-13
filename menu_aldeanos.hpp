#ifndef MENU_ALDEANOS_HPP
#define MENU_ALDEANOS_HPP
#include <iostream>
#include "Civilizacion.hpp"
using namespace std;
void menu_aldeanos_op(string s)
{
    cout << "\tMenú Aldeanos para la Civilización " << s << endl;
    cout << "1) Agregar Aldeano" << endl;
    cout << "2) Eliminar Aldeano" << endl;
    cout << "3) Clasificar Aldeanos" << endl;
    cout << "4) Buscar Aldeano" << endl;
    cout << "5) Modificar Aldeano" << endl;
    cout << "6) Mostrar Aldeanos" << endl;
    cout << "7) Salir" << endl;
    cout << "Seleciona una opción: ";
}

void menu_aldeanos(Civilizacion* c)
{
    while (true)
    {
        menu_aldeanos_op(c->getNombre());
        size_t opcion_aldeanos;
        cin >> opcion_aldeanos;
        if (opcion_aldeanos == 1)
        {
            /* code */
        }
        if (opcion_aldeanos == 2)
        {
            /* code */
        }
        if (opcion_aldeanos == 3)
        {
            /* code */
        }
        if (opcion_aldeanos == 4)
        {
            /* code */
        }
        if (opcion_aldeanos == 5)
        {
            /* code */
        }
        if (opcion_aldeanos == 6)
        {
            /* code */
        }
        if (opcion_aldeanos == 7)
        {
            cout << "Usted ha regresado al menú de Civilizaciones" << endl;
            break;
        }
        else if (opcion_aldeanos < 1 || opcion_aldeanos > 7)
        {
            cout << "Ha seleccionado una opción no válida" << endl;
        }
        
    }
    
}
#endif