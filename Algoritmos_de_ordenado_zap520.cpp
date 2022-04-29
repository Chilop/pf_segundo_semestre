// Algoritmos_de_ordenado_zap520.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int numeros[6] = { 10,4,6,8,1,3 };
int i, j, aux, pos;
auto numeros_size = sizeof(numeros) / sizeof(numeros[0]);

void menu()
{
    cout << " ------------------------------------- \n\n" << endl;
    cout << " Algoritmos de ordenamiento\n" << endl;
    cout << " Elige una opcion " << endl;
    cout << " 1- Metodo de la burbuja " << endl;
    cout << " 2- metodo de insercion" << endl;
    cout << " 3- metodo de quicksort" << endl;
    cout << " 4- metodo de mergesort" << endl;
    cout << " 5- metodo de heapsort" << endl;
    cout << " 6- salir\n\n" << endl;
    cout << " --------------------------------------\n\n" << endl;
    cout << " que opcion deseas realizar?:";
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
}


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
}

void merge(int numeros[], int const izq, int const enmedio, int const der)
{
    auto const subArregloUno = enmedio - izq + 1;
    auto const subArragloDos = der - enmedio;

    // Create temp arrays
    auto* leftArray = new int[subArregloUno],
        * rightArray = new int[subArragloDos];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArregloUno; i++)
        leftArray[i] = numeros[izq + i];
    for (auto j = 0; j < subArragloDos; j++)
        rightArray[j] = numeros[enmedio + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = izq; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArregloUno && indexOfSubArrayTwo < subArragloDos) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            numeros[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            numeros[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArregloUno) {
        numeros[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArragloDos) {
        numeros[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    system("color 0B");
    
    bool ejecucion = true;
    int opc = 0;
    do
    {
        menu();
        cin >> opc;
    switch (opc)
    {
    case 1:
        cout << " has elegido el metodo de la burbuja" << endl;
        system("cls");
        cout << " El arreglo que se va a ordenar" << endl;
        for (i = 0; i < 6; i++)
        {
            cout << i << " -->" << numeros[i] << endl;
        }

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 5; j++) {
                if (numeros[j] > numeros[j + 1]) {
                    aux = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = aux;
                }
            }
        }

        cout << "Numeros Ordenados ";
        for (i = 0; i < 5; i++) {
            cout << numeros[i] << " ";
        }
        cout << endl << endl;
        break;
    case 2:
        cout << " has elegido el metodo de insercion" << endl;
        system("cls");

        cout << " El arreglo que se va a ordenar" << endl;
        for (i = 0; i < 6; i++)
        {
            cout << i << " -->" << numeros[i] << endl;
        }

        for (i = 0; i < 6; i++) {
            pos = i;
            aux = numeros[i];

            while ((pos > 0) && (numeros[pos - 1] > aux)) {
                numeros[pos] = numeros[pos - 1];
                pos--;
            }
            numeros[pos] = aux;
        }

        cout << "Numeros ordenados ";
        for (i = 0; i < 6; i++) {
            cout << numeros[i] << " ";
        }
        cout << endl << endl;
        break;
    case 3:
        cout << " has elegido el metodo de la quicksort" << endl;
        system("cls");

        cout << " El arreglo que se va a ordenar" << endl;
        for (i = 0; i < 6; i++)
        {
            cout << i << " -->" << numeros[i] << endl;
        }
        

        quicksort(numeros, 0, 6 - 1);

        cout << "Numeros ordenados ";
        for (int i = 0; i < 6; i++) 
        {
            cout << numeros[i] << " ";
        }
        cout << endl;
        cout << endl << endl;
        break;
    case 4:
        cout << " has elegido el metodo de la mergesort" << endl;
        system("cls");
        cout << " El arreglo que se va a ordenar" << endl;

        for (i = 0; i < 6; i++)
        {
            cout << i << " -->" << numeros[i] << endl;
        }
        mergeSort(numeros, 0, numeros_size - 1);
        cout << "Numeros ordenados ";
        printArray(numeros, numeros_size);
        cout << endl << endl;
        break;
    case 5:
        cout << " has elegido el metodo de la heapsort" << endl;
        system("cls");


        cout << endl << endl;
        break;
    case 6:
        if (ejecucion == true)
        {
            ejecucion = false;
        }
        cout << " saliendo..." << endl;
        break;

    default:
        break;
    }
    } while (ejecucion == true);



}

