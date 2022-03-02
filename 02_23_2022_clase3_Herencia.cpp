// 02_23_2022_clase3_Herencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Codigo hecho por: Oscar Alejandro Rios Ramirez 
// Practica sobre herencia y encapsulamiento
// 02/25/2022_clase4_punteros.cpp
#include <iostream>
#include<string>
using namespace std;
/*
class computer
{
	// atributos
public:
	string Hardware;
	string software = "Windows";

	//metodos
	void SE() {
		cout << "system error" << endl;
	}

};
class CPU : public computer
{
	string model = "icore 7, 9th generation";
};
class HD : public computer
{
public:
	string model = "Kingston 1 TB";

};
class GC : public computer
{
public:

	string model = "Nvidia GTX 1080 4 GB";
};
class OS : public computer
{
public:
	string operativesystem = "windows XP";
};
*/
class persona {
private:
	string nombre;
	int edad;
public:
	persona(string, int); //declaracion de constructor de persona
	virtual void mostrar();// metodo virtual, con esto podemos trabajar con polimorfismo en c++

};

persona::persona(string _nombre, int _edad) // asignamos valores al constructor
{

	nombre = _nombre;
	edad = _edad;
};

void persona::mostrar() //definimos el comportamiento de la funcion o metodo de persona
{
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
	if (edad >= 18)
	{
		cout << "Es mayor de edad" << endl;
	}
};

class Alumno : public persona
{

private:
	float calificacion;
public:
	Alumno(string, int, float); // constructor
	void mostrar();

};

Alumno::Alumno(string _nombre, int _edad, float _calificacion) : persona(_nombre, _edad)
{
	calificacion = _calificacion;
};

void Alumno::mostrar()
{
	persona::mostrar();
	cout << "Calificacion: " << calificacion << endl;
};

class Profesor : public persona {
private:
	string materia;
public:
	Profesor(string, int, string);
	void mostrar();

};

Profesor::Profesor(string _nombre, int _edad, string _materia) : persona(_nombre, _edad) {
	materia = _materia;
}

void Profesor::mostrar() {
	persona::mostrar();
	cout << "Materia: " << materia << endl;
}
int main()
{
	//CPU myprocessor;

	/*
	string sentence;
	int a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;
	cout << "Escribe una oracion" << endl;
	getline(cin, sentence);


	for (int z = 0; z >= 30; z++)
	{
		switch (sentence[z])
		{
		case 'a': a++; break;
		case 'e': e++; break;
		case 'i': i++; break;
		case 'o': o++; break;
		case 'u': u++; break;
		}
		
	}
	cout << "tienes de vocales" << "\n" << "Vocal a: " << a << "\n" << "Vocal e: " << e << "\n" << "Vocal i: " << i << "\n" << "Vocal o: " << o << "\n" << "Vocal u: " << u << "\n";
	*/

	persona* Array[4];
	Array[0] = new Alumno("Oscar", 21, 8.9);
	Array[1] = new Alumno("Jair", 25, 9);
	Array[2] = new Alumno("Israel", 22, 7.9);
	Array[3] = new Profesor("MIiguel", 30, "Tecnologias de la programacion");

	Array[0]->mostrar();
	cout << "\n";
	Array[1]->mostrar();
	cout << "\n";
	Array[2]->mostrar();
	cout << "\n";
	Array[3]->mostrar();
	cout << "\n";





}


