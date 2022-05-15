// Practica_quicksort_Chilo_y_Kevin.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Hacer que el programa cree libros mediante structs
// Despues hacer que se organizen
// al final usar un metodo de busqueda


#include <iostream>
#include<string>
using namespace std;


struct agregarlibro {
    int DNS;
    int numpaginas;
    string Nombre;
    string autor;
} libros[6];

class objaux
{
public:
    int _DNS;
    int _numpaginas;
    string _nombre;
    string _autor;
    objaux(int,int,string,string);
    virtual void mostrar();

};

objaux::objaux(int a, int b, string c,string d)
{
    _DNS = a;
    _numpaginas = b;
    _nombre = c;
    _autor = d;
};

void objaux::mostrar(){
    cout << " DNS:" << _DNS << endl;
    cout << " Num.paginas:" << _numpaginas << endl;
    cout << " Nombre del libro:" << _nombre << endl;
    cout << " Autor:" << _autor << endl;
};




void menu()
{
    cout << " ---------------------------------------------------------- \n\n" << endl;
    cout << " Esto es una simulacion de crear libros y buscarlos mediante su codigo de libro" << endl;
    cout << " 1- Introducir un libro" << endl;
    cout << " 2- Buscar el libro" << endl;
    cout << " 3 salir \n\n" << endl;
    cout << " ---------------------------------------------------------- " << endl << endl;
    cout << " cual es tu opcion?:" << endl;
};

int divide(int* array, int inicio, int final) {
    int izq;
    int der;
    int pivote;
    int temp;

    pivote = array[inicio];
    izq = inicio;
    der = final;

    // Mientras no se cruzen los índices
    while (izq < der) {
        while (array[der] > pivote) {
            der--;
        }

        while ((izq < der) && (array[izq] <= pivote)) {
            izq++;
        }

        // Si todavía no se cruzan los indices seguimos intercambiando
        if (izq < der) {
            temp = array[izq];
            array[izq] = array[der];
            array[der] = temp;
        }
    }

    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[der];
    array[der] = array[inicio];
    array[inicio] = temp;

    // La nueva posición del pivot
    return der;
};

void quicksort(int* array, int inicio, int final)
{
    int pivote;

    if (inicio < final) {
        pivote = divide(array, inicio, final);

        // Ordeno la lista de los menores
        quicksort(array, inicio, pivote - 1);

        // Ordeno la lista de los mayores
        quicksort(array, pivote + 1, final);
    }
};


int main()
{
    objaux* lib[6];
    int opc;
    bool salir = true;
    do
    {
    MENU:
        menu();
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << " Empezando ejecucion de agregar libros" << endl;
            system("pause");
            system("cls");

            cout << " Agregando libros " << endl;
            for (int i = 0; i <= 5; i++)
            {
                cout << endl << endl;
                cout << " Agrega el DNS (num. de registro del libro):";
                cin >> libros[i].DNS;
                cout << endl;
                cout << " Agrega el numero de paginas del libro:";
                cin >> libros[i].numpaginas;
                cout << endl;
                cin.ignore();
                cout << " Agrega el nombre del libro:";
                getline(cin, libros[i].Nombre);
                cout << endl;
                cout << " Agrega el nombre del autor:";
                getline(cin, libros[i].autor);
            }


            goto MENU;
        case 2:
            cout << " Ordenando libros" << endl;
            for (int i = 0; i < 6; i++)
            {
                lib[i] = new objaux(libros->DNS, libros->numpaginas, libros->Nombre, libros->autor);
            }
             
            cout << " Buscando libro..." << endl;
            cout << " Que libro quieres buscar por su ID?:";
            int bus;
            cin >> bus;
            cout << " Imprimiendo libro" << endl;
            if (bus == 1)
            {
                lib[0]->mostrar();
                
            }else 
                if (bus == 2)
                {
                     lib[1]->mostrar();
                }else
                    if (bus == 3)
                    {
                         lib[2]->mostrar();
                    }else
                        if (bus == 4)
                        {
                            lib[3]->mostrar();
                        }else
                            if (bus == 5)
                            {
                               lib[4]->mostrar();
                            }else
                                if (bus == 6)
                                {
                                    lib[5]->mostrar();
                                }

            break;
        case 3:

            if (salir == true)
            {
                salir = false;
            }

            break;
        default:
            cout << " Elige una opcion mmhuevo" << endl;

        }
    } while (salir == true);

    return 0;
}
