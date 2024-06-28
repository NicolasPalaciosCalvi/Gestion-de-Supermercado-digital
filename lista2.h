#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Estructuras Generales.h"

///ESTRUCTURA LISTA DOBLE PARA ADL
typedef struct
{
    producto dato;
    struct nodo2* sig;
    struct nodo2* ante;
}nodo2;

///ESTRUCTURA LISTA DOBLE PARA FILA
typedef struct
{
    user dato;
    float total;
    struct nodoFilas* sig;
    struct nodoFilas* ante;
}nodoFilas;

///PROTOTIPADO LISTA DOBLES PARA EL ADL///
nodo2 * inicListaDoble();

nodo2 * crearNodoDoble(producto dato);

nodo2 * agregarPpioDoble (nodo2 * lista, nodo2 * nuevo);

nodo2 * agregarFinalDoble(nodo2 * lista, nodo2 * nuevo);

nodo2 * agregarEnOrdenDoble(nodo2 * lista, nodo2 * nuevo);

void recorrerYmostrar(nodo2 * lista,int num);

void escribir(nodo2 * aux,int num);

nodo2 * borrarNodoBuscado(nodo2 * lista, char producto[]);

///PROTOTIPADO LISTA DOBLES PARA FILAS///

nodoFilas * inicListaDobleFilas();

nodoFilas * crearNodoDobleFilas(user dato,float totalC);

nodoFilas * agregarFinalDobleFilas(nodoFilas * lista, nodoFilas * nuevo);

void recorrerYmostrarFilas(nodoFilas * lista);

void escribirFilas(nodoFilas * aux);

nodoFilas * borrarPrimerNodoFila(nodoFilas * lista);

user verPrimero(nodoFilas * lista);

#endif // LISTA2_H_INCLUDED
