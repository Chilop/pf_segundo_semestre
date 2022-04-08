// Practica de el ahorcado 
#include <iostream>
#include<string>
#include <time.h>
using namespace std;

int main()
{
   // declaracion de lo que se va a usar
    string palabras[5] = { "arbol", "balon", "carro", "bambu", "tifon" };
    //generacion de aletoriedad en las palabras y una pista
    srand(time(0));
    int palabraalazar = rand() % 5;
    int letrarevelada = rand() % palabras[palabraalazar].length();
    //declaracion de vidas
    int vidas = 5;
    // iniciar la palabra y ver que palabra se eligio
    string palabraadivinada = "";
    string palabraAdescubrir = palabras[palabraalazar];

    cout << "Juego del Ahorcado" << endl;
    cout << "se tienen palabras de 5 letras las cuales se va a mostrar una pista de las palabras" << endl;

    //imprime las letras de la palabra seleccionada
    for (int i = 0; i < palabras[palabraalazar].length(); i++)
    {
       
        if (i == letrarevelada) {
            palabraadivinada += palabras[palabraalazar][letrarevelada];
            palabraAdescubrir[i] = '-';
        }
       
        if (i != letrarevelada) {
            palabraadivinada += "_";
        }
    }

    // elementos dentro de la ejecucion del ahorcado
    cout << palabraadivinada << endl;
    bool Juego = true;
    bool palabraacertada = false;
    bool victoria = false;
    int aciertos = 0;
    char letra;

    //Comienza el Juego
    while (Juego) {

        palabraacertada = false;
        aciertos = 0;

        cout << "Tienes " << vidas << " vidas" << endl;
        cout << "la palabra es: " << palabraadivinada << endl;
        cout << "Escribe una letra para adivinar las letras de la palabra: " << endl;
        cin >> letra;

        //Busca la letra en la palabra
        for (int i = 0; i < palabraAdescubrir.length(); i++)
        {
            if (palabraAdescubrir[i] != '-' && palabraAdescubrir[i] == letra) {
                palabraAdescubrir[i] = '-';
                palabraadivinada[i] = letra;
                palabraacertada = true;
            }
        }

        if (palabraacertada) {
            cout << "le atinaste a una letra de la palabra" << endl;
        }
        else {
            cout << "Has Perdido una vida!" << endl;
            vidas--;
        }

        //revisa si la palabra ya fue adivinada
        for (int i = 0; i < palabraAdescubrir.length(); i++)
        {
            if (palabraAdescubrir[i] == '-') {
                aciertos++;
            }
        }

        //Cuando pierdes al acabarse las vidas
        if (vidas == 0) {
            cout << "Se te acabaron las vidas, la palabra era: " << palabras[palabraalazar] << endl;
        }

        //Cuando ganas al adivinar la palabra
        if (aciertos == palabraAdescubrir.length()) {
            cout << "Has adivinado la palabra n.n : " << palabras[palabraalazar] << endl;
            Juego = false;
        }

        //Cuando el juego termina
        if (vidas == 0 || victoria) {
            Juego = false;
        }
    }

    cout << "Game Over, GG" << endl;

}
