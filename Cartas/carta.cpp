#include <iostream>
#include "funcControl.hpp"
#include "color.hpp"
#include "carta.hpp"

using std::cout;

void DibujarFondo(short alto, short ancho, short x, short y)
{
    EstablecerColor(VERDE, BLANCO);

    for (int r = 1; r <= alto; r++)
    {
        for (int espacio = 1; espacio <= ancho; ++espacio)
        {
            cout << " ";
        }

        MoverCursor(0, ++y);
    }
}

void DibujarCarta(short x, short y, short denom, short palo)
{
    const short alto(11);
    const short ancho(15);

    DibujarMarco(alto, ancho, x, y);
    DibujarDetalles(alto, ancho, x, y, denom, palo);
}

void DibujarMarco(short alto, short ancho, short x, short y)
{
    EstablecerColor(BLANCO, NEGRO);

    MoverCursor(x, y);
    cout << (char)ESI;
    for (int caract = 1; caract <= ancho - 2; caract++)
    {
        cout << (char)BH;
    }
    cout << (char)ESD;

    MoverCursor(x, ++y);
    for (int r = 1; r <= alto - 2; r++)
    {
        cout << (char)BV;
        for (int espacio = 1; espacio <= ancho - 2; espacio++)
        {
            cout << " ";
        }
        cout << (char)BV;

        MoverCursor(x, ++y);
    }

    cout << (char)EII;
    for (int caract = 1; caract <= ancho - 2; caract++)
    {
        cout << (char)BH;
    }
    cout << (char)EID;

}

void DibujarDetalles(short alto, short ancho, short x, short y, short denom, short palo)
{

    if (palo == CORAZON || palo == DIAMANTE)
    {
        EstablecerColor(BLANCO, ROJO);
    }
    else if (palo == TREBOL || palo == PICA)
    {
        EstablecerColor(BLANCO, NEGRO);
    }

    short centroX, centroY, offsetY, offsetX;

    centroX = x + ((ancho + 1) / 2) - 1;
    centroY = y + ((alto + 1) / 2) - 1;

    MoverCursor(x + 1, y + 1);
    switch (denom)
    {
    case 1: cout << "A"; break;
    case 11: cout << "J"; break;
    case 12: cout << "Q"; break;
    case 13: cout << "K"; break;
    default: cout << denom; break;
    }

    if (denom == 10)
    {
        MoverCursor(x + (ancho - 1) - 2, y + (alto - 1) - 1);
        cout << denom;
    }
    else
    {
        MoverCursor(x + (ancho - 1) - 1, y + (alto - 1) - 1);
        switch (denom)
        {
        case 1: cout << "A"; break;
        case 11: cout << "J"; break;
        case 12: cout << "Q"; break;
        case 13: cout << "K"; break;
        default: cout << denom; break;
        }
    }

    MoverCursor(x + 1, y + 2);
    cout << (char)palo;

    MoverCursor(x + (ancho - 1) - 1, y + (alto - 1) - 2);
    cout << (char)palo;

    switch (denom)
    {

    case 1:
        offsetY = -2;
        MoverCursor(centroX, centroY + offsetY);
        cout << (char)palo;

        offsetY = -1;
        offsetX = -1;

        for (int i = 1; i <= ((alto - 1) / 2) - 1; ++i)
        {

            MoverCursor(centroX + offsetX, centroY + offsetY);
            cout << (char)palo;

            MoverCursor(centroX + offsetX + i * 2, centroY + offsetY);
            cout << (char)palo;

            offsetX -= 1;
            offsetY += 1;

        }

        offsetX = -2;
        offsetY = 1;

        MoverCursor(centroX + offsetX, centroY + offsetY);

        for (int i = 1; i <= (alto - 1) / 2; ++i)
        {
            cout << (char)palo;
        }

        break;

    case 2:

        offsetY = -1;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX, centroY - offsetY);
            cout << (char)palo;

            offsetY += 2;
        }
        break;

    case 3:
        offsetY = -1;
        for (int i = 1; i <= 3; i++)
        {
            MoverCursor(centroX, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }
        break;

    case 4:
        offsetY = 0;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX - 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        offsetY = 0;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX + 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }
        break;

    case 5:
        offsetY = 0;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX - 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        MoverCursor(centroX, centroY);
        cout << (char)palo;

        offsetY = 0;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX + 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }
        break;

    case 6:
        offsetY = -1;
        for (int i = 1; i <= 3; i++)
        {
            MoverCursor(centroX - 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        offsetY = -1;
        for (int i = 1; i <= 3; i++)
        {
            MoverCursor(centroX + 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }
        break;

    case 7:
        offsetY = -1;
        for (int i = 1; i <= 3; i++)
        {
            MoverCursor(centroX - 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        MoverCursor(centroX, centroY - 1);
        cout << (char)palo;

        offsetY = -1;
        for (int i = 1; i <= 3; i++)
        {
            MoverCursor(centroX + 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }
        break;

    case 8:
        offsetY = -1;
        for (int i = 1; i <= 3; i++)
        {
            MoverCursor(centroX - 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        MoverCursor(centroX, centroY - 1);
        cout << (char)palo;

        MoverCursor(centroX, centroY + 1);
        cout << (char)palo;

        offsetY = -1;
        for (int i = 1; i <= 3; i++)
        {
            MoverCursor(centroX + 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }
        break;

    case 9:
        offsetY = -2;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX - 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        offsetY = 2;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX - 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        MoverCursor(centroX, centroY);
        cout << (char)palo;

        offsetY = -2;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX + 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        offsetY = 2;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX + 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }
        break;

    case 10:
        offsetY = -2;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX - 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        offsetY = 2;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX - 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        MoverCursor(centroX, centroY - 2);
        cout << (char)palo;

        MoverCursor(centroX, centroY + 2);
        cout << (char)palo;

        offsetY = -2;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX + 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }

        offsetY = 2;
        for (int i = 1; i <= 2; i++)
        {
            MoverCursor(centroX + 2, centroY + offsetY - 1);
            cout << (char)palo;

            offsetY += 2;
        }
        break;

    case 11:
        offsetX = -1;
        offsetY = -2;

        MoverCursor(centroX + offsetX, centroY + offsetY);
        for (int i = 1; i < (alto + 1) / 2; ++i)
        {
            cout << (char)palo;
        }

        offsetX = 1;
        offsetY = -1;
        for (int i = 1; i <= ((((alto - 1) / 2) + 1) / 2); ++i)
        {
            MoverCursor(centroX+offsetX, centroY + offsetY);
            cout << (char)palo;
            offsetY += 1;
        }

        offsetX = -3;
        offsetY = 1;
        MoverCursor(centroX+offsetX, centroY + offsetY);
        cout << (char)palo;

        offsetX = -2;
        offsetY = 2;

        for (int i = 1; i <= ((alto + 1) / 2) / 2; ++i)
        {
            MoverCursor(centroX+offsetX, centroY+offsetY);
            cout << (char)palo;
            offsetX += 1;
        }

        break;

    case 12:
        offsetX = -2;
        offsetY = -2;

        MoverCursor(centroX + offsetX, centroY + offsetY);
        for (int i = 1; i <= (alto - 1) / 2; ++i)
        {
            cout << (char)palo;
            offsetX += 1;
        }

        offsetX = -3;
        offsetY = -1;
        for (int i = 3; i < (alto - 1) / 2; ++i)
        {
            MoverCursor(centroX+offsetX, centroY + offsetY);
            cout << (char)palo;
            offsetY += 1;
        }

        offsetX = 3;
        offsetY = -1;
        for (int i = 3; i < (alto - 1) / 2; ++i)
        {
            MoverCursor(centroX + offsetX, centroY + offsetY);
            cout << (char)palo;
            offsetY += 1;
        }

        offsetX = -2;
        offsetY = 1;

        MoverCursor(centroX + offsetX, centroY + offsetY);
        for (int i = 1; i <= (alto - 1) / 2; ++i)
        {
            cout << (char)palo;
            offsetX += 1;
        }

        offsetY = 2;
        offsetX = 1;
        MoverCursor(centroX+offsetX, centroY + offsetY);
        cout << (char)palo;

        offsetY = 3;
        offsetX = 2;

        MoverCursor(centroX+offsetX, centroY + offsetY);
        for (int i = 3; i < (alto - 1) / 2; ++i)
        {
            cout << (char)palo;
        }

        break;

    case 13:
        offsetY = -2;
        for (int i = 1; i <= (alto-1)/2; ++i)
        {
            MoverCursor(centroX - 1, centroY + offsetY);
            cout << (char)palo;
            offsetY += 1;

        }

        offsetY = -2;
        offsetX = 2;
        for (int i = 1; i <= (((alto - 1) / 2)+1)/2; ++i)
        {
            MoverCursor(centroX + offsetX, centroY + offsetY);
            cout << (char)palo;
            offsetY += 1;
            offsetX -= 1;

        }

        offsetX = 1;
        for (int i = 1; i <= (((alto - 1) / 2) - 1) / 2; ++i)
        {
            MoverCursor(centroX + offsetX, centroY + offsetY);
            cout << (char)palo;
            offsetY += 1;
            offsetX += 1;

        }
        break;

    }

}