#include "Jugador.hpp"
#include <iomanip>

void Jugador::agregarFinal(const Civilizacion& c)
{ 
    civilizaciones.push_back(c); 
    cout << "La Civilización " << c.getNombre() << " ha sido agregada con éxito!" << endl;
}
void Jugador::agregarInicio(const Civilizacion& c)
{ 
    civilizaciones.push_front(c);
    cout << "La Civilización " << c.getNombre() << " ha sido agregada con éxito!" << endl;
}
void Jugador::insertarPosicion(const Civilizacion& c, size_t pos) 
{ 
    if (pos > civilizaciones.size()) 
    { 
        cout << "La posición no es válida, debe haber elementos continuos en la lista" << endl;
    }
    else if (pos == civilizaciones.size()) 
    { 
        civilizaciones.push_back(c); 
        cout << "La Civilización " << c.getNombre() << " ha sido insertada en la posición " << pos << " con éxito!" << endl;
    }
    else
    {
        civilizaciones.insert(c, pos);
        cout << "La Civilización " << c.getNombre() << " ha sido insertada en la posición " << pos << " con éxito!" << endl;
    } 
}
void Jugador::primeraCivilizacion()
{
    if (civilizaciones.empty())
    {
        cout << "No se puede mostrar la primer Civilización ya que el Arreglo está vacío" << endl;
    }
    else
    {
        cout << "Primer Civilización:" << endl;
        cout << civilizaciones.front();
    }
}
void Jugador::ultimaCivilizacion() 
{
    if (civilizaciones.empty())
    {
        cout << "No se puede mostrar la última Civilización ya que el Arreglo está vacío" << endl;
    }
    else
    {
        cout << "Última Civilización:" << endl;
        cout << civilizaciones.back();
    }  
}
void Jugador::ordenarNombre() 
{
    if (civilizaciones.empty())
    {
        cout << "No se puede ordenar ya que el Arreglo de Civilizaciones está vacío" << endl;
    }
    else
    {
        civilizaciones.sort( [] (const Civilizacion& c1, const Civilizacion& c2) { return c1.getNombre() > c2.getNombre(); }, true);
        cout << "Se ha ordenado por Nombre de manera Ascendente" << endl;
    }
}
void Jugador::ordenarPosY()
{
    if (civilizaciones.empty())
    {
        cout << "No se puede ordenar ya que el Arreglo de Civilizaciones está vacío" << endl;
    }
    else
    {
        civilizaciones.sort( [] (const Civilizacion& c1, const Civilizacion& c2) { return c1.getPosy() > c2.getPosy(); }, true);
        cout << "Se ha ordenado por Posición en Y de manera Ascendente" << endl;
    }
}
void Jugador::ordenarPosX()
{
    if (civilizaciones.empty())
    {
        cout << "No se puede ordenar ya que el Arreglo de Civilizaciones está vacío" << endl;
    }
    else
    {
        civilizaciones.sort( [] (const Civilizacion& c1, const Civilizacion& c2) { return c1.getPosx() > c2.getPosx(); }, true);
        cout << "Se ha ordenado por Posición en X de manera Ascendente" << endl;
    }
    
}
void Jugador::eliminar()  //No se valida ya que sino la encuentra, manda un mensaje.
{
    //Se declara una variable para el nombre de civilización a buscar.
    string eliminar;
    int cont = 0;
    cout << "¿Cuál es el nombre de la civilización que desea eliminar?" << endl;
    cin.ignore();
    getline(cin, eliminar);
    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        if (civilizaciones[i].getNombre() == eliminar)
        {
            civilizaciones.erase(i);
            cout << "La civilización " << eliminar << " ha sido borrada con éxito!" << endl;
            cont++;
        }
    }
    if (cont == 0)
    {
        cout << "No se encontró la civilización que desea eliminar" << endl;
    }
}
void Jugador::buscar()  //No se valida ya que sino la encuentra, manda un mensaje.
{
    //Se declara una variable para la civilización a buscar.
        string nombre;
        cout << "Ingresa el nombre de la civilización a buscar: ";
        cin.ignore();
        getline(cin, nombre);
        //Se instncia un objeto de Civilización temporal.
        Civilizacion c;
        //Se asigna el nombre a buscar de la civilización.
        c.setNombre(nombre);
        //Se declara la función lambda.
        auto cmp = [] (const Civilizacion& c1, const Civilizacion& c2) { return c1.getNombre() == c2.getNombre(); };
        //En caso de devolver el puntero hacia la dirección, se asigna.
        Civilizacion* encontrado = civilizaciones.find(cmp, c);
        if (encontrado)
        {
            cout << "\tCivilización encontrada:" << endl;
            cout << *encontrado << endl;
        }
        else
        {
            cout << "\tNo existe la Civilización" << endl;
	    	cout << endl;
        }
}
void Jugador::modificar()  //No se valida ya que sino la encuentra, manda un mensaje.
{
    string nombre;
        cout << "Ingresa el nombre de la civilización a buscar: ";
        cin.ignore();
        getline(cin, nombre);
        //Se instncia un objeto de Civilización temporal.
        Civilizacion c;
        //Se asigna el nombre a buscar de la civilización.
        c.setNombre(nombre);
        //Se declara la función lambda.
        auto cmp = [] (const Civilizacion& c1, const Civilizacion& c2) { return c1.getNombre() == c2.getNombre(); };
        //En caso de devolver el puntero hacia la dirección, se asigna.
        Civilizacion* encontrado = civilizaciones.find(cmp, c);
        if (encontrado)
        {
            cout << "\tCivilización encontrada:" << endl;
            cout << *encontrado << endl;
            //Declaración de varibale para el menú.
            size_t opcion_mod;
            //Se inicia un ciclo.
            while (true)
            {
                //Menú para las modificaciones de la civilización.
                cout << "\tModificar Civilización" << endl;
                cout << "1) Nombre" << endl;
                cout << "2) Posición en X" << endl;
                cout << "3) Posición en Y" << endl;
                cout << "4) Salir" << endl;
                cout << "Elija el atributo que desea modificar: ";
                cin >> opcion_mod;
                if (opcion_mod == 1)
                {
                    //Se declara una variable temporal.
                    string nuevo;
                    //Se pide ingresar el nuevo valor del atributo.
                    cout << "Ingrese el nuevo Nombre: ";
                    cin.ignore();
                    getline(cin, nuevo);
                    //Se asigna el nuevo valor a el atributo del objeto.
                    encontrado->setNombre(nuevo);  //Se utiliza la flecha, ya que estamos haciendo referencia a un puntero.
                    cout << "El Nombre ha sido modificado con éxito!" << endl;
                    break; //Se utliza para romper el ciclo.
                }
                if (opcion_mod == 2)
                {
                    int x;
                    cout << "Ingrese la nueva Posición en X: ";
                    cin >> x;
                    encontrado->setPosx(x);
                    cout << "La Posición en X ha sido modificada con éxito!" << endl;
                    break;
                }
                if (opcion_mod == 3)
                {
                    int y;
                    cout << "Ingrese la nueva Posición en Y: ";
                    cin >> y;
                    encontrado->setPosy(y);
                    cout << "La Posición en Y ha sido modificada con éxito!" << endl;
                    break;
                }
                if (opcion_mod == 4)
                {
                    cout << "Usted ha salido del menú modificar Civilización" << endl;
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
            cout << "\tNo existe la Civilización" << endl;
	    	cout << endl;
        }

}
void Jugador::resumen()
{
    if (civilizaciones.empty())
    {
        cout << "No hay Civilizaciones en el Arreglo" << endl;
    }
    else
    {
        cout << left;
        cout << setw(10) << "Nombre" << setw(15) << "Posición en X" << setw(13) << "Posición en Y" << endl;
		for (size_t i = 0; i < civilizaciones.size(); i++)
		{
			cout << setw(10) << civilizaciones[i].getNombre() << setw(14) << civilizaciones[i].getPosx() <<
            setw(13) << civilizaciones[i].getPosy() << endl;
		}
    }
}