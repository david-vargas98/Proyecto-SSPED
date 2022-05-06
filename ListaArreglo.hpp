#ifndef LISTAARREGLO_HPP
#define LISTAARREGLO_HPP
#include "Arreglo.hpp"
//Debido a que la clase "Arreglo" es de tipo "template", la siguiente clase debe serlo también ya que se va heredar métodos.
template <class T>
class ListaArreglo : public Arreglo<T> //Se hereda los métodos "públicos" de la clase Arreglo. 
{
private:
	size_t nuevo_tam{5};  //Se usa para definir que tanto se va "expandir".
	void expandir()  //Es un método privado ya que no se quiere que el usuario expanda desde fuera.
	{
		cout << "Tam: " << nuevo_tam << endl;
		//Para acceder tanto a atributos como métodos se usa "Arreglo<T>::".
		//Ya que es un "template" se pone el nombre de la clase, luego la T y luego dos puntos para acceder al atributo así: "Arreglo<T>::tam".
		T* nuevo = new T[Arreglo<T>::tam + nuevo_tam];  //Este va ser el nuevo arreglo con el nuevo tamaño, que es igual a la suma del tamaño actual + el nuevo.
		for (size_t i = 0; i < Arreglo<T>::cont; i++)  //Se usa un "for" para copiar la información del arreglo al nuevo.
		{
			nuevo[i] = Arreglo<T>::arreglo[i];  //Se asigna la información del arreglo al nuevo.
		}
		Arreglo<T>::tam = Arreglo<T>::tam + nuevo_tam; //Se asigna el nuevo tamaño a el atributo "tam".
		delete[] Arreglo<T>::arreglo; //Se borra el arreglo viejo para liberar esa memoria.
		Arreglo<T>::arreglo = nuevo; //arreglo queda apuntando a Nulo pero aún sigue ahí, entonces se desenlazó para volver a enlazar a un nuevo elemento.
		cout << "Expandiendo a " << Arreglo<T>::tam << endl;
	}
public:
	//Constructor que no recibe nada,
	ListaArreglo() :Arreglo<T>(5) {};

	void push_back(const T& e)
	{
		if (Arreglo<T>::full())
		{
			expandir();  //Se cambia la excepción por la expansión, y se expande el arreglo.						   
		}
		Arreglo<T>::arreglo[Arreglo<T>::cont] = e;
		Arreglo<T>::cont++;
	}

	void push_front(const T& e)
	{
		if (Arreglo<T>::full())
		{
			expandir();  //Se cambia la excepción por la expansión, y se expande el arreglo. 
		}
		for (size_t i = Arreglo<T>::cont; i > 0; i--)
		{
			Arreglo<T>::arreglo[i] = Arreglo<T>::arreglo[i - 1];
		}

		Arreglo<T>::arreglo[0] = e;
		Arreglo<T>::cont++;
	}

	void insert(const T& e, size_t pos)
	{
		if (pos >= Arreglo<T>::cont)  //Primero se valida que sea una posición válida.
		{
			throw out_of_range("Invalid position");
		}
		else if (Arreglo<T>::full())
		{
			expandir();  //Y luego se expande el arreglo.
		}
		for (size_t i = Arreglo<T>::cont; i > pos; i--)
		{
			Arreglo<T>::arreglo[i] = Arreglo<T>::arreglo[i - 1];
		}
		Arreglo<T>::arreglo[pos] = e;
		Arreglo<T>::cont++;
	}
};

#endif // !LISTAARREGLO_HPP