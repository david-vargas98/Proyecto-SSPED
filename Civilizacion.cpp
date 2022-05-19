#include "Civilizacion.hpp"
#include <iomanip>
void Civilizacion::agregarInicio(const Aldeano& a)
{
    aldeanos.push_front(a);
    cout << "El Aldeano ha sido agregado al inicio con éxito!" << endl;
}
void Civilizacion::agregarFinal(const Aldeano& a)
{
    aldeanos.push_back(a);
    cout << "El Aldeano ha sido agregado al final con éxito!" << endl;
}
bool Civilizacion::empty()
{
    if (aldeanos.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
        
}
void Civilizacion::eliminarNombre()
{
    Aldeano a;
    string nombre;
    cout << "Ingrese el nombre del Aldeano a Eliminar: ";
    cin.ignore();
    getline(cin, nombre);
    a.setNombre(nombre);
    size_t cantidad = aldeanos.size();
    aldeanos.remove(a);
    if (aldeanos.size() == cantidad)
    {
        cout << "El nombre del Aldeano no existe" << endl;
    }
    else
    {
        cout << "El Aldeano " << a.getNombre() << " ha sido eliminado!" << endl;
    }
}
void Civilizacion::eliminarSalud()
{
    float salud;
    cout << "Eliminar Aldeanos que tengan la salud menor a: ";
    cin >> salud;
    aldeanos.remove_if([salud] (Aldeano& a) {return a.getSalud() < salud;});
    size_t cantidad = aldeanos.size();
    cout << "¡Los Aldeanos con salud menor a " << salud << " han sido eliminados!" << endl; 
}
void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if([] (Aldeano& a) {return a.getEdad() >= 60;});
    cout << "¡Los Aldeanos de 60 años o mayores han sido eliminados!" << endl; 
}
void Civilizacion::ordenarNombre()
{
    aldeanos.sort([] (const Aldeano& a1, const Aldeano& a2) {return a1.getNombre() < a2.getNombre();});
    cout << "¡Los Aldeanos han sido ordenados de manera Ascendente por Nombre!" << endl;
}
void Civilizacion::ordenarEdad()
{
    aldeanos.sort([] (const Aldeano& a1, const Aldeano& a2) {return a1.getEdad() > a2.getEdad();});
    cout << "¡Los Aldeanos han sido ordenados de manera Descendente por Edad!" << endl;
}
void Civilizacion::ordenarSalud()
{
    aldeanos.sort([] (const Aldeano& a1, const Aldeano& a2) {return a1.getSalud() > a2.getSalud();});
    cout << "¡Los Aldeanos han sido ordenados de manera Descendente por Salud!" << endl;
}
void Civilizacion::buscar()
{
    string nombre;
    size_t encontrado = 0;
    cout << "Ingrese el nombre del aldeano que desea buscar: ";
    cin.ignore();
    getline(cin, nombre);
    Aldeano a;
    a.setNombre(nombre);
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
        {
            Aldeano& aldeano = *it;
            if (aldeano == a)
            {
                cout << left;
                cout << setw(10) << "Nombre" << setw(6) << "Edad" << setw(10) << "Genero" << setw(7) << "Salud" << endl;
                cout << aldeano;
                encontrado++;
            }
        }
        if (encontrado == 0)
        {
            cout << "El Aldeano buscado no fue encontrado" << endl;
        }        
}
void Civilizacion::modificar()
{
    string nombre;
    size_t encontrado = 0;
    cout << "Ingrese el nombre del aldeano que desea modificar: ";
    cin.ignore();
    getline(cin, nombre);
    Aldeano a;
    a.setNombre(nombre);
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
        {
            Aldeano& aldeano = *it;
            if (aldeano == a)
            {
                cout << left;
                cout << setw(10) << "Nombre" << setw(6) << "Edad" << setw(8) << "Genero" << setw(7) << "Salud" << endl;
                cout << aldeano;
                encontrado++;
                //Declaración de variable para menú.
                size_t modificar_aldeano;
                while (true)
                {
                    //Menú para las modificaciones del Aldeano.
                    cout << "\tModificar Aldeano" << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Edad" << endl;
                    cout << "3) Género" << endl;
                    cout << "4) Salud" << endl;
                    cout << "5) Salir" << endl;
                    cout << "Elija el atributo que desea modificar: ";
                    cin >> modificar_aldeano;
                    if (modificar_aldeano == 1)
                    {
                        //Se declara una variable temporal.
                        string nuevo;
                         //Se pide ingresar el nuevo valor del atributo.
                        cout << "Ingrese el nuevo Nombre: ";
                        cin.ignore();
                        getline(cin, nuevo);
                        //Se asigna el nuevo valor a el atributo del objeto.
                        aldeano.setNombre(nuevo);
                        cout << "¡El Nombre ha sido modificado con éxito!" << endl;
                        break;
                    }
                    if (modificar_aldeano == 2)
                    {
                        int nuevo;
                        cout << "Ingrese la nueva Edad: ";
                        cin >> nuevo;
                        aldeano.setEdad(nuevo);
                        cout << "¡La Edad ha sido modificada con éxito!" << endl;
                        break;
                    }
                    if (modificar_aldeano == 3)
                    {
                        string nuevo;
                        cout << "Ingrese el nuevo Género: ";
                        cin.ignore();
                        getline(cin, nuevo);
                        aldeano.setGenero(nuevo);
                        cout << "¡El Género ha sido modificado con éxito!" << endl;
                        break;
                    }
                    if (modificar_aldeano == 4)
                    {
                        float nuevo;
                        cout << "Ingrese la nueva Salud: ";
                        cin >> nuevo;
                        aldeano.setSalud(nuevo);
                        cout << "¡La Salud ha sido modificada con éxito!" << endl;
                        break;
                    }
                    if (modificar_aldeano == 5)
                    {
                        cout << "Usted ha regresado al menú de Aldeanos" << endl;
                        break;
                    }
                    if (modificar_aldeano < 1 || modificar_aldeano > 5)
                    {
                        cout << "Ha seleccionado una opción no válida" << endl;
                    }
                }
            }
        }
        if (encontrado == 0)
        {
            cout << "El Aldeano buscado no fue encontrado" << endl;
        }
}
void Civilizacion::mostrar()
{
    if (aldeanos.empty())
    {
        cout << "No hay Aldeanos agregados" << endl;
    }
    else
    {
        size_t cont = 0;
        cout << left;
        cout << setw(10) << "Nombre" << setw(6) << "Edad" << setw(10) << "Genero" << setw(7) << "Salud" << endl;
        for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
        {
            Aldeano& aldeano = *it;
            cout << aldeano;
        }   
    }
}
//Métodos para los barcos:
void Civilizacion::capturarBarco(Civilizacion* c)
{
    //Declaración de variables.
    string id;
    float combustible;
    //Declaración e instancia del puntero.
    Barco *b = new Barco();
    cout << "Ingrese el ID del barco: ";
    cin.ignore();
    getline(cin, id);
    cout << "Ingrese el combustible del barco: ";
    cin >> combustible;
    //Se le dan valor a los atributos.
    b->setId(id);
    b->setCombustible(combustible);
    b->setVelocidad(0.0);
    b->setArmadura(100.0);
    //Se agrega el barco a la civilización.
    c->agregarBarco(b);
}
void Civilizacion::agregarBarco(Barco* b)
{
    puerto.push_back(b);
    cout << "¡El Barco ha sido añadido con éxito!" << endl;
}
void Civilizacion::mostrarBarcos()
{
    cout << left;
    cout << setw(6) << "ID" << setw(12) << "Combustible" << setw(10) << "Velocidad" << setw(9) << "Armadura" << setw(21) << "Cantidad de Guerreros" << endl;
    for (auto e: puerto)
    {
        cout << setw(6) << e->getId() << setw(12) << e->getCombustible() << setw(10) << e->getVelocidad() << setw(9) << e->getArmadura() << setw(21) << e->size() << endl;
    }
    cout << endl;
}