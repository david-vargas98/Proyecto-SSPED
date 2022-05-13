#ifndef MENU_CIVILIZACIONES_HPP
#define MENU_CIVILIZACIONES_HPP
#include <iostream>
#include "Jugador.hpp"
#include "menu_aldeanos.hpp"
using namespace std;
void menu_ordenar_civilizaciones()
{
    cout << "\tMenú Ordenar Civilizaciones" << endl;
    cout << "1) Ordena Nombre (Ascendente)" << endl;
    cout << "2) Ordena por Posición en X (Ascendente)" << endl;
    cout << "3) Ordena por Posición en Y (Ascendente)" << endl;
    cout << "4) Salir" << endl;
    cout << "Seleciona una opción: ";
}
void menu_civilizaciones_op(string j)
{
    cout << "\tMenú Civilizaciones para el Jugador " << j << endl;
    cout << "1) Agregar civilización al final" << endl;
    cout << "2) Agregar civilización al inicio" << endl;
    cout << "3) Insertar civilización" << endl;
    cout << "4) Primera civilización" << endl;
    cout << "5) Última civilización" << endl;
    cout << "6) Ordenar" << endl;
    cout << "7) Eliminar civilización" << endl;
    cout << "8) Buscar civilización" << endl;
    cout << "9) Modificar civilización" << endl;
    cout << "10) Resumen" << endl;
    cout << "11) Salir" << endl;
    cout << "Seleciona una opción: ";
}
void menu_civilizaciones(Jugador* resultado)
{
    while (true)
    {
        menu_civilizaciones_op(resultado->getNickname());  //Se le manda el nombre de quién operará el menú.
        size_t opcion_civi;                 
        cin >> opcion_civi;
        if (opcion_civi == 1)
        {
            Civilizacion c;
            string nombre;
            cout << "Nombre de la civilización: ";
            cin.ignore();
            getline(cin, nombre);
            int x;
            cout << "Posición en X: ";
            cin >> x;
            int y;
            cout << "Posición en Y: ";
            cin >> y;
            c.setNombre(nombre);
            c.setPosx(x);
            c.setPosy(y);
            resultado->agregarFinal(c);
        }
        else if (opcion_civi == 2)
        {
            Civilizacion c;
            string nombre;
            cout << "Nombre de la civilización: ";
            cin.ignore();
            getline(cin, nombre);
            int x;
            cout << "Posición en X: ";
            cin >> x;
            int y;
            cout << "Posición en Y: ";
            cin >> y;
            c.setNombre(nombre);
            c.setPosx(x);
            c.setPosy(y);
            resultado->agregarInicio(c);
        }
        else if (opcion_civi == 3)
        {
            Civilizacion c;
            string nombre;
            cout << "Nombre de la civilización: ";
            cin.ignore();
            getline(cin, nombre);
            int x;
            cout << "Posición en X: ";
            cin >> x;
            int y;
            cout << "Posición en Y: ";
            cin >> y;
            c.setNombre(nombre);
            c.setPosx(x);
            c.setPosy(y);
            size_t pos;
            cout << "¿En que posición válida desea insertar la civilización?" << endl;
            cin >> pos;
            resultado->insertarPosicion(c, pos);
        }
        else if (opcion_civi == 4)
        {
            resultado->primeraCivilizacion();
        }
        else if (opcion_civi == 5)
        {
            resultado->ultimaCivilizacion();
        }
        else if (opcion_civi == 6)
        {
            size_t ordena;
            menu_ordenar_civilizaciones();
            cin >> ordena;
            switch (ordena)
            {
            case 1:
                resultado->ordenarNombre();
                break;
            case 2:
                 resultado->ordenarPosX();
                break;
            case 3:
                resultado->ordenarPosY();
                break;
            case 4:
                cout << "Usted ha regresado al menú de Civilizaciones" << endl;
                break;
            default:
                cout << "Ha elegido una opción no válida" << endl;
                break;
            }  
        }
        else if (opcion_civi == 7)
        {
            resultado->eliminar();
        }
        else if (opcion_civi == 8)
        {
            Civilizacion* encontrada;
            encontrada = resultado->buscar();
            if (encontrada != nullptr)
            {
                menu_aldeanos(encontrada);
            }
            
        }
        else if (opcion_civi == 9)
        {
            resultado->modificar();
        }
        else if (opcion_civi == 10)
        {
            resultado->resumen();
        }
        else if (opcion_civi == 11)
        {
            cout << "Usted ha regresado al menú principal" << endl;
            break;
        }
        else if (opcion_civi < 1 || opcion_civi > 11)
        {
            cout << "Ha seleccionado una opción no válida" << endl;
        }
    }
}
#endif 