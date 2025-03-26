#pragma once

/** @file
*/

/** ESTADO DEL CURSOR */
enum EstadoCursor {
	APAGADO,    /**< Cursor no visible */
	ENCENDIDO   /**< Cursor visible */
};

/** MODOS DEL CURSOR */
enum ModoCursor {
	MINI = 5,       /**< Tama&ntilde;o de cursor peque&ntilde;o */
	NORMAL = 40,    /**< Tama&ntilde;o de cursor mediano  */
	SOLIDO = 80     /**< Tama&ntilde;o de cursor grande */
};

/**
* \brief Mueve el cursor de la consola a una coordenada dada x,y.
*
* @param x Coordenada x que corresponde a las columnas.
* @param y Coordenada y que corresponde a las filas.
*/
void MoverCursor(short x, short y);

/**
* @brief Aleatoriza valores dentro de un rango dado.
*
* @param inicio Inicio del rango.
* @param fin Fin del rango.
* @return Un número al azar dentro del rango especificado.
*/
int Aleatorizar(int inicio, int fin);

/**
* @brief Cambia las propiedades del cursor.
*
* @param estado Estado del cursor, puede estar ENCENDIDO (visible) o APAGADO (invisible).
* @param modo Modo del cursor, cambia su visualización.
*/

void CambiarCursor(EstadoCursor estado, ModoCursor modo = NORMAL);

/**
* @brief Cambia el tamaño de la ventana a las dimensiones dadas.
*
* @param ancho Ancho en unidad de columnas.
* @param alto Altura en unidad de filas.
*/
void EstablecerTamVentana(short ancho, short alto);

void Desordenar(int arreglo[], int n);
void Intercambiar(int& a, int& b);