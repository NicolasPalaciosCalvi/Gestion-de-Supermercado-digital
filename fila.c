///FUNCIONES FILAS
#include "fila.h"

void inicFila(Fila * fila)
{
    fila->inicio = inicListaDobleFilas();
    fila->fin = inicListaDobleFilas();
}

Fila* agregar(Fila* fila, user personita,int totalC)
{
    nodoFilas* nuevo = crearNodoDobleFilas(personita,totalC);

    if (fila->inicio == NULL) {
        fila->inicio = nuevo;
    } else {
        fila->fin = agregarFinalDobleFilas(fila->fin, nuevo);
    }


    return fila;
}

void mostrarF(Fila* fila)
{
    nodoFilas* actual = fila->inicio;

    if (actual == NULL) {
        printf("La fila está vacía.\n");
        return;
    }

    printf("Usuarios en la fila:\n");
    while (actual != NULL) {
        printf("Nombre: %s Total de compra: %d==", actual->dato.nombre, actual->total);
        actual = actual->sig;
    }
    printf("\n");
}

user extraer(Fila* fila)
{
    user resp;

    if(fila->inicio != NULL)
    {
        resp = verPrimero(fila->inicio);

        fila->inicio = borrarPrimerNodoFila(fila->inicio);

        if(fila->inicio == NULL)
        {
            fila->fin = inicListaDobleFilas();
        }
    }
    return resp;
}

user primero(Fila * fila)
{
    user resp;
    if(fila->inicio != NULL)
    {
        resp = verPrimero(fila->inicio);
    }
    return resp;
}

int filaVacia(Fila * fila)
{
    int resp=0;
    if(fila->inicio == NULL)
    {
        resp = 1;
    }
    return resp;
}











