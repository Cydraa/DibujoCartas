#include <iostream>
#include <cstdlib>

#include "color.hpp"

void EstablecerColor(Color colorFondo, Color colorTexto)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo * 16 + colorTexto);
}
