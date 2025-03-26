#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "funcControl.hpp"

using std::numeric_limits;
using std::max;
using std::cin;
using std::cout;

void MoverCursor(short x, short y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Aleatorizar(int inicio, int fin)
{
    return inicio + rand() % (fin - inicio + 1);
}

void CambiarCursor(EstadoCursor estado, ModoCursor modo)
{
    CONSOLE_CURSOR_INFO ConCurInf = { modo, estado };

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}

void EstablecerTamVentana(short ancho, short alto)
{
    COORD coord = { --ancho, --alto };
    SMALL_RECT rect = { 0,0,ancho,alto };
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleScreenBufferSize(hConsola, coord);
    SetConsoleWindowInfo(hConsola, true, &rect);
}

void Desordenar(int arreglo[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        // hacer un arreglo auxiliar para comparar para aseguar que todos esten desordenados
        Intercambiar(arreglo[i], arreglo[Aleatorizar(0, n - 1)]);
    }
}

void Intercambiar(int& a, int& b)
{
    int aux = a;
    a = b;
    b = aux;
}