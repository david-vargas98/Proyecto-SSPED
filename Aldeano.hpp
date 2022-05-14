#ifndef ALDEANO_HPP
#define ALDEANO_HPP
#include <iostream>
#include <iomanip>
using namespace std;
class Aldeano
{
    private:
    string nombre;
    int edad;
    string genero;
    float salud;
    public:
    Aldeano() = default;
    //Métodos set y get.
    void setNombre(const string& valor) {nombre = valor;}
    string getNombre() const {return nombre;}
    void setEdad(int valor) {edad = valor;}
    int getEdad() const {return edad;}
    void setGenero(const string& valor) {genero = valor;}
    string getGenero() const {return genero;}
    void setSalud(float valor) {salud = valor;}
    float getSalud() const {return salud;}
    //Sobrecarga de operadores.
    friend istream& operator >>(istream& is, Aldeano& a)
    {
        //Se declaran variables temporales
        string nombre, genero;
        float edad, salud;
        //Se pide al usuario agregar al jugador
        cout << "\t\tAgregar aldeano" << endl;
        cout << "Ingrese el nombre del Aldeano: ";
        cin.ignore();
        getline(is, nombre);
        cout << "Ingrese la edad del Aldeano: ";
        is >> edad;
        cout << "Ingrese el género del Aldeano: ";
        cin.ignore();
        getline(is, genero);
        cout << "Ingrese la salud del Aldeano: ";
        is >> salud;
        //Se asignan los atributos por medio de los métodos de acceso
        a.setNombre(nombre);
        a.setEdad(edad);
        a.setGenero(genero);
        a.setSalud(salud);
        return is;
    }
    friend ostream& operator <<(ostream& os, const Aldeano& a)
    {
        cout << left;
        os << setw(10) << a.getNombre() << setw(6) << a.getEdad() << setw(8) << a.getGenero() <<  setw(7) << a.getSalud() << endl;
        return os;
    }
    //Remove no sabe como eliminar un Aldeano, así que se sobrecarga el comparador "==".
    friend bool operator ==(const Aldeano& a1, const Aldeano& a2)  //Con esta sobrecarga "remove" ya sabe como eliminar un Jugador.
	{
		return a1.getNombre() == a2.getNombre();
	}
};
#endif