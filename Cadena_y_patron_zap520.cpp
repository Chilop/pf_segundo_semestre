// Cadena_y_patron_zap520.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
// Actividad de busqueda de patrones ---- Actividad 1
// Hecho por Oscar Alejandro Ríos Ramírez

#include <iostream>
#include <string>
using namespace std;
// definir los strings
string Cadena;
string patron;

unsigned int no_esta = -1;
int main()
{
    // capturar los datos para los strings
    cout << " Escribe una frase que quieras:";
    getline(cin, Cadena);
    cout << endl << endl;
    cout << " Escribe frase a buscar:";
    getline(cin, patron);
    // el .find se utiliza para buscar coincidencias entre cadenas
    // se aplica un unsigned por si en caso de que no se encuentre la palabra no se vuelva loco el programa
    if (Cadena.find(patron) == no_esta)
    {
        cout << patron << " No esta en la cadena  UnU" << endl;
    }
    else
    {
        cout << patron << " si esta en la cadena.  :D" << endl;
        
    }
}

