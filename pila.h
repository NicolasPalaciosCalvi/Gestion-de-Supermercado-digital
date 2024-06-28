#include <stdio.h>
#include <malloc.h>
#define Pila struct _Pila
#define Pila struct _Pila *
#include "Estructuras Generales.h"


struct _Pila
{
    registroArchivo *valores;
    int postope;
};

void inicpila(Pila p);
void apilar(Pila p, registroArchivo dato);
registroArchivo desapilar(Pila p);
registroArchivo tope(Pila p);
int pilavacia(Pila p);
void leer(Pila p);
void mostrarP(Pila p);

