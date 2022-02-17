// Sucesion_de_fibonacci.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
int main()
{
	int fib=1;
	int a=1;
	int b=0;
	int n;

	cout << "Cuantos numeros quieres de la sucesion de fibonacci?" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		fib = a + b;
		cout << fib << " ";
		a = b;
		b = fib;

	}
	cout << "\n";
	
	system("pause");
	system("cls");


	float D;
	float d;
	float area;
	cout << "calcularemos el area de un rombo\n" << "para ello coloca los datos para calcular su area" << endl;
	cout << "Diagonal mayor" << endl;
	cin >> D;
	cout << "Diagonal menor" << endl;
	cin >> d;

	area = D * d / 2;
	cout << "El area del rombo es: " << area << endl;


	system("pause");
	system("cls");

	int numero;

	cout << "Introduzca un numero que no sea negativo" << endl;
	cin >> numero;

	if (numero / 2 == 0)
	{
		cout << "Es par" << endl;
	}
	else 
	{
		cout << "Es impar" << endl;
	}
	
	system("pause");
	system("cls");

	int numfac;
	int fac = 1;

	cout << "Calculos para factoriales" << endl;

	cout << "Introduce un numero para sacar su factorial" << endl;
	cin >> numfac;

	for (int i = 1; i <= numfac; i++)
	{
		fac = fac * 1;

	}

	cout << "El factorial del numero que diste es: " << fac << endl;


	cout << "Son programas basicos que se hicieron con cariño y esfuerzo °?°" << endl;


	return 0;
}

