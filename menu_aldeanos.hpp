#ifndef MENU_ALDEANOS_HPP
#define MENU_ALDEANOS_HPP
#include <iostream>
#include "Civilizacion.hpp"
using namespace std;
void clasificar()
{
    cout << "\tClasificar Aldeanos" << endl;
    cout << "1) Ordenar por Nombre (Ascendente)" << endl;
    cout << "2) Ordenar por Edad (Descendente)" << endl;
    cout << "3) Ordenar por Salud (Descendente)" << endl;
    cout << "4) Salir" << endl;
    cout << "Selecciona una opción: ";
}
void eliminar()
{
    cout << "\tEliminar Aldeanos" << endl;
    cout << "1) Eliminar por Nombre" << endl;
    cout << "2) Eliminar Aldeanos dónde su salud sea menor a la que ingrese el usuario" << endl;
    cout << "3) Eliminar aldeanos donde su edad sea mayor o igual a 60" << endl;
    cout << "4) Salir" << endl;
    cout << "Selecciona una opción: ";
}
void agregar()
{
    cout << "\tAgregar Aldeanos" << endl;
    cout << "1) Agregar al inicio" << endl;
    cout << "2) Agregar al final" << endl;
    cout << "3) Salir" << endl;
    cout << "Selecciona una opción: ";
}
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

void menu_aldeanos(Civilizacion* c, Jugador* j)
{
    while (true)
    {
        menu_aldeanos_op(c->getNombre());
        size_t opcion_aldeanos;
        cin >> opcion_aldeanos;
        if (opcion_aldeanos == 1)
        {
            //Creación del objeto de clase Aldeano.
            Aldeano a;
            //Se le asignan los atributos a el aldeano.
            cin >> a;
            //Variable para el sub-menú.
            size_t opc;
            //Se muestra el sub-menú.
            agregar();
            cin >> opc;
            if (opc == 1)
            {
                c->agregarInicio(a);
                //Se le agrega 100 puntos al puntaje del jugador.
                float nueva;
                nueva = j->getPuntuacion() + 100;
                j->setPuntuacion(nueva);
                cout << "Han sido añadidos " << 100 << " puntos al Jugador " << j->getNickname() << endl;
            }
            else if (opc == 2)
            {
                c->agregarFinal(a);
                //Se le agrega 100 puntos al puntaje del jugador.
                float nueva;
                nueva = j->getPuntuacion() + 100;
                j->setPuntuacion(nueva);
                cout << "Han sido añadidos " << 100 << " puntos al Jugador " << j->getNickname() << endl;
            }
            else if (opc == 3)
            {
                cout << "Usted ha regresado al menú de Aldeanos" << endl;
                break;
            }
            else if (opc < 1 || opc > 3)
            {
                cout << "Ha seleccionado una opción no válida" << endl;
            }
            
        }
        if (opcion_aldeanos == 2)
        {
            if (c->empty() == true)
            {
                cout << "No se puede eliminar ya que no hay Aldeanos agregados" << endl;
            }
            else
            {
                while (true)
                {
                    eliminar();
                    size_t eliminar;
                    cin >> eliminar;
                    if (eliminar == 1)
                    {
                        c->eliminarNombre();
                        break;
                    }
                    if (eliminar == 2)
                    {
                        c->eliminarSalud();
                        break;
                    }
                    if (eliminar == 3)
                    {
                        c->eliminarEdad();
                        break;
                    }
                    if (eliminar == 4)
                    {
                        cout << "Usted ha regresado al menú de Aldeanos" << endl;
                        break;
                    }
                    if (eliminar < 1 || eliminar > 4)
                    {
                        cout << "Ha seleccionado una opción no válida" << endl;
                    }
                }
            }
        }
        if (opcion_aldeanos == 3)
        {
            if (c->empty() == true)
            {
                cout << "No se puede clasificar ya que no hay Aldeanos agregados" << endl;
            }
            else
            {
                while (true)
                {
                    clasificar();
                    size_t clasificar;
                    cin >> clasificar;
                    if (clasificar == 1)
                    {
                        c->ordenarNombre();
                        break;
                    }
                    if (clasificar == 2)
                    {
                        c->ordenarEdad();
                        break;
                    }
                    if (clasificar == 3)
                    {
                        c->ordenarSalud();
                        break;
                    }
                    if (clasificar == 4)
                    {
                        cout << "Usted ha regresado al menú de Aldeanos" << endl;
                        break;
                    }
                    if (clasificar < 1 || clasificar > 4)
                    {
                        cout << "Ha seleccionado una opción no válida" << endl;
                    }   
                } 
            }
        }
        if (opcion_aldeanos == 4)
        {
            c->buscar();
        }
        if (opcion_aldeanos == 5)
        {
            c->modificar();
        }
        if (opcion_aldeanos == 6)
        {
            c->mostrar();
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