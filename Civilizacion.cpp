#include "Civilizacion.hpp"
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