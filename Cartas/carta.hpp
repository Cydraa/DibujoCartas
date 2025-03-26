#pragma once

/** @file
*/

/** SIMBOLOS IMPRIMIBLES */
enum Simbolos { 
	CORAZON = 3, /**< Símbolo del corazón */
	DIAMANTE, /**< Símbolo del diamante */
	TREBOL, /**< Símbolo del trebol */
	PICA, /**< Símbolo del pica */
	BV = 179, /**< Barra vertical */
	ESD = 191, /**< Esquina superior derecha */
	EII = 192, /**< Esquina inferior izquierda */
	BH = 196, /**< Barra horizontal */
	EID = 217, /**< Esquina inferior derecha */
	ESI = 218 /**< Esquina superior izquierda */
};

/**
* @brief Funcion principal para el dibujo de la carta.
* 
* @param x Coordenada x que corresponde a las columnas.
* @param y Coordenada y que corresponde a las filas.
* @param denom Denomiación de las cartas.
* @param palo Palo de la carta, define el tipo de figura a usar.
*/
void DibujarCarta(short x, short y, short denom, short palo);

/**
* @brief Funcion que dibuja el marco y el fondo de la carta
*
* @param alto Altura de la carta.
* @param ancho Ancho de la carta.
* @param x Coordenada x que corresponde a las columnas.
* @param y Coordenada y que corresponde a las filas.
*/
void DibujarMarco(short alto, short ancho, short x, short y);

/**
* @brief Funcion que dibuja los símbolos centrales de la carta, que corresponden al palo y la denomiación de esta.
*
* @param alto Altura de la carta.
* @param ancho Ancho de la carta.
* @param x Coordenada x que corresponde a las columnas.
* @param y Coordenada y que corresponde a las filas.
* @param denom Denomiación de las cartas.
* @param palo Palo de la carta, define el tipo de figura a usar.
*/
void DibujarDetalles(short alto, short ancho, short x, short y, short denom, short palo);

/**
* @brief Funcion que recolorea el fondo de la consola.
*
* @param alto Altura de la ventana.
* @param ancho Ancho de la ventana.
* @param x Coordenada x que corresponde a las columnas.
* @param y Coordenada y que corresponde a las filas.
*/
void DibujarFondo(short alto, short ancho, short x, short y);