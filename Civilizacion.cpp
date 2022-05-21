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
    if (puerto.empty())
    {
        cout << "¡El puerto está vacío!" << endl;
    }
    else
    {
        cout << left;
        cout << setw(6) << "ID" << setw(12) << "Combustible" << setw(10) << "Velocidad" << setw(9) << "Armadura" << setw(21) << "Cantidad de Guerreros" << endl;
        for (auto e: puerto)
        {
            cout << setw(6) << e->getId() << setw(12) << e->getCombustible() << setw(10) << e->getVelocidad() << setw(9) << e->getArmadura() << setw(21) << e->size() << endl;
        }
        cout << endl;
    }
}
void Civilizacion::buscarBarcos()
{
    cout << "Ingrese el ID del Barco que desea buscar: ";
    string ID;
    cin.ignore();
    getline(cin, ID);
    Barco* b = new Barco();
    b->setId(ID);
    int band = 0;
    for (auto e: puerto)
    {
        if (*e == *b)
        {
            cout << "¡Barco encontrado!" << endl;
            band = 1;
            while (true)
            {
                cout << "\tMenú Guerreros para el Barco " << e->getId() << endl;
                cout << "1) Agregar Guerrero" << endl;
                cout << "2) Eliminar Guerrero" << endl;
                cout << "3) Mostrar último Guerrero" << endl;
                cout << "4) Mostrar todos los Guerreros" << endl;
                cout << "5) Salir" << endl;
                cout << "Seleciona una opción: ";
                size_t opc;
                cin >> opc;
                if (opc == 1)
                {
                    Guerrero g;
                    cout << "Ingrese el ID del Guerrero: ";
                    string id;
                    cin.ignore();
                    getline(cin, id);
                    cout << "Ingrese la Salud del Guerrero: ";
                    int salud;
                    cin >> salud;
                    cout << "Ingrese la Fuerza del Guerrero: ";
                    float fuerza;
                    cin >> fuerza;
                    cout << "Ingrese el Escudo del Guerrero: ";
                    float escudo;
                    cin >> escudo;
                    cout << "Ingrese el tipo de Guerrero: ";
                    string tipo;
                    cin.ignore();
                    getline(cin, tipo);

                    g.setId(id);
                    g.setSalud(salud);
                    g.setFuerza(fuerza);
                    g.setEscudo(escudo);
                    g.setTipo(tipo);

                    e->agregarGuerrero(g);
                    cout << "¡El Guerrero ha sido agregado con éxito!" << endl;
                }
                if (opc == 2)
                {
                    e->eliminarGuerrero();                    
                }
                if (opc == 3)
                {
                    e->tope();
                }
                if (opc == 4)
                {
                    e->mostrar();
                }
                if (opc == 5)
                {
                    cout << "Usted ha regresado al menú de Barcos" << endl;
                    break;
                }
                if (opc < 1 || opc > 5)
                {
                    cout << "Ha seleccionado una opción no válida" << endl;
                }
            }
        }     
    }
    if (band == 0)
    {
        cout << "El Barco buscado no existe" << endl;
    }  
}
void Civilizacion::eliminarBarcos()
{
    if (puerto.empty())
    {
        cout << "¡El puerto está vacío, no se puede eliminar Barcos!" << endl;
    }
    else
    {
        while (true)
        {
            cout << "Eliminar por:" << endl;
            cout << "1) ID" << endl;
            cout << "2) Combustible menor a" << endl;
            cout << "3) Salir" << endl;
            cout << "Seleciona una opción: "; 
            size_t opc;
            cin >> opc;
            if (opc == 1)
            {
                cout << "Ingrese el ID del Barco que desea eliminar: ";
                string ID;
                cin.ignore();
                getline(cin, ID);
                Barco* b = new Barco();
                b->setId(ID);
                int eliminado = 0;
                for (auto e : puerto)
                {
                    if (*e == *b)
                    {
                        puerto.remove(e);
                        delete e;
                        cout << "¡El Barco ha sido eliminado!" << endl;
                        eliminado = 1;
                        break;
                    }
                }
                if (eliminado == 0)
                {
                    cout << "El Barco a eliminar no existe" << endl;
                }
                
                break;
            }
            if (opc == 2)
            {
                cout << "Eliminar Barcos con combustible menor a: ";
                float combus;
                cin >> combus;
                puerto.remove_if([combus](Barco* b){return b->getCombustible() < combus;});
                cout << "¡Los Barcos con combustible menor a " << combus << " han sido eliminados" << endl;
                break;
            }
            if (opc == 3)
            {
                cout << "Usted ha regresado al menú de Barcos" << endl;
                break;
            }
            if (opc < 1 || opc >3)
            {
                cout << "Ha seleccionado una opción no válida" << endl;
            }
        }
    }   
}