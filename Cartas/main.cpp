/*
Nombre: main.cpp
Descripcion: Este programa dibuja cartas de denominacion, palo y posicion aleatorias.
             Controles:
              Presionar cualquier tecla para dibujar una carta.
              Presionar ESC para salir del programa.
              Elaborado en Visual Studio 2022.
Autores: Ana Paulina Sortillon Sortillon y Jovanna Amiraxel Reyes Casillas
Fecha: 25/02/2025
*/

#include <iostream>
#include <conio.h>
#include <cstdlib>

#include "carta.hpp"
#include "color.hpp"
#include "funcControl.hpp"

// TAMAÑO DE LA VENTANA
// Define el tamaño de la ventana del juego en columnas y renglones.

#define VENTANA_ANCHO 120
#define VENTANA_ALTO 30

// ACOTACION DEL AREA IMPRIMIBLE
// Se definen la region dentro de la ventana en donde se pueden imprimir las cartas en columnas y renglones.
#define MIN_ANCHO 5
#define MAX_ANCHO (VENTANA_ANCHO-20)
#define MIN_ALTO 8
#define MAX_ALTO (VENTANA_ALTO-13)

//TECLAS
#define ESCAPE 27

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //Establece fondo y ventana
    EstablecerTamVentana(VENTANA_ALTO, VENTANA_ANCHO);
    DibujarFondo(VENTANA_ALTO, VENTANA_ANCHO, 0, 0);

    short x, y, denom, palo;
    char tecla;
    int arreglo[52];

    for (int i = 0; i < 52; ++i)
    {
        arreglo[i] = i;
    }

    srand(time(NULL));

    MoverCursor(0, 0);
    EstablecerColor(VERDE, NEGRO);

    cout << char(CORAZON) << char(PICA) << "\255\220CHAME UNA CARTA!" << char(TREBOL) << char(DIAMANTE) << endl;
    cout << "Este programa imprime cartas de la baraja inglesa de manera aleatoria." << endl;
    cout << "Presiona cualquier tecla para imprimir la carta y presiona ESC para salir del programa." << endl;

    CambiarCursor(APAGADO, SOLIDO);

    int i = 0;

    Desordenar(arreglo, 52);
    while (true)
    {
            if (_kbhit )
            {
                tecla = _getch();
                if (tecla == ESCAPE) break;
                if (i > 52) i = 0;
                denom = (arreglo[i] % 13) + 1;
                palo = (arreglo[i]) / 13 + 3;
                x = 10;
                y = 10;
                DibujarCarta(x, y, denom, palo);
                ++i;
            }

        /*x = Aleatorizar(MIN_ANCHO, MAX_ANCHO);
        y = Aleatorizar(MIN_ALTO, MAX_ALTO);
        denom = Aleatorizar(1, 13);
        palo = Aleatorizar(CORAZON, PICA);*/

    }
   return 0;

}
