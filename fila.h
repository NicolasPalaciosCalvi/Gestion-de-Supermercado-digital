#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "lista2.h"
#include "Estructuras Generales.h"


///ESTRUCTURA FILA
typedef struct
{
    struct nodoFilas* inicio;
    struct nodoFilas* fin;
}Fila;

///PROTOTIPADO FILA
void inicFila(Fila * fila);

void mostrarF(Fila * fila);

Fila* agregar(Fila * fila , user personita,int totalC);

user extraer(Fila * fila);


user primero(Fila * fila);

int filaVacia(Fila* fila);


#endif // FILA_H_INCLUDED
