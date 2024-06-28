#ifndef ARREGLO_H_INCLUDED
#define ARREGLO_H_INCLUDED

#include <string.h>
#include "lista2.h"
#include "Estructuras Generales.h"

///ESTRUCTURA DE ARREGLO DE LISTAS
typedef struct
{
    char categoria[30]; ///Categoria del super
    nodo2 * listadeProductos;
} celdaArreglo;

/// PROTOTIPADO ARREGLO DE LISTAS
int alta(celdaArreglo arreglo[], int validos, registroArchivo reg,int interruptor);
int buscarPosicion(celdaArreglo arreglo[], int validos, char categoria[]);
int agregarCategoria(celdaArreglo arreglo[], int validos, char categoria[]);
int buscarPosicionProducto(celdaArreglo arreglo[], int validos, char producto[]);

#endif // ARREGLO_H_INCLUDED
