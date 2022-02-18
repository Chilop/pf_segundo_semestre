// Practica_2_PG2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Programa Propiedad de Oscar Alejandro Ríos Ramírez 

#include <iostream>
#include <math.h>
using namespace std;




int main()
{

    float a;
    float b;
    float result;

    cout << " Expresion given (n*m) / (n / m)^m > 10 = TRUE" << endl;

    cout << " Give me the first number " << endl;
    cin >> a;
    cout << " Give me the second number " << endl;
    cin >> b;

    float Advanced = a / b;

    result = (a * b) / pow(Advanced, b);

    if (result > 10)
    {
        cout << result << "  TRUE , si es mayor a 10 " << endl;
    }
    else 
    {
        cout  << result << "  False , no es mayor a 10 " << endl;
    }


    

    return 0;




}

