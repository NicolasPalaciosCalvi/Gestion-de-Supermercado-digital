#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Estructuras Generales.h"

///ESTRUCTURA ARBOL
typedef struct ///Se inserta segun el precio del producto
{
    producto dato;
    struct nodoArbol *izq;
    struct nodoArbol *der;
} nodoArbol;

///PROTOTIPADO ARBOL
nodoArbol *inicArbol();
nodoArbol *crearnodoArbol(producto dato);
nodoArbol *buscar(nodoArbol *arbol, producto productito);
nodoArbol * insertar(nodoArbol * arbol, producto productito);
void mostrar(nodoArbol *arbol);
void preorder(nodoArbol *arbol);
void inorder(nodoArbol *arbol);
void postorder(nodoArbol *arbol);
float totalCarrito (nodoArbol* arbolito);
nodoArbol* borrarNodo(nodoArbol*,char[]);
nodoArbol * nodoMasIzq (nodoArbol*);

#endif // ARBOL_H_INCLUDED
