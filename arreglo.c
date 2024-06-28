#include "arreglo.h"
#include "lista2.h"
#include "Estructuras Generales.h"

///FUNCIONES ADL
int alta(celdaArreglo arreglo[], int validos, registroArchivo reg, int interruptor) {
    int pos = buscarPosicion(arreglo, validos, reg.categoria);
    if (pos == -1) {
        validos = agregarCategoria(arreglo, validos, reg.categoria);
        pos = validos - 1;
    }
if(interruptor!=1){
    producto productito;
    strcpy(productito.nombre, reg.dato.nombre);
    productito.preciosCuidados = reg.dato.preciosCuidados;
    productito.stock = reg.dato.stock;
    productito.precio = reg.dato.precio;
    nodo2 *aux = crearNodoDoble(productito);
    arreglo[pos].listadeProductos = agregarEnOrdenDoble(arreglo[pos].listadeProductos, aux);
}
    return validos;
}

int buscarPosicion(celdaArreglo arreglo[], int validos, char categoria[])
{
    int rta = -1;
    int i = 0;
    while ((i < validos) && (rta == -1))
    {
        if (strcmpi(arreglo[i].categoria, categoria) == 0)
        {
            rta = i;
            break;
        }
        i++;
    }
    return rta;
}

int buscarPosicionProducto(celdaArreglo arreglo[], int validos, char producto[]) {
    for (int i = 0; i < validos; i++) {
        nodo2* listaProductos = arreglo[i].listadeProductos;

        while (listaProductos != NULL) {
            if (strcmpi(listaProductos->dato.nombre, producto) == 0) {
                return i;
            }
            listaProductos = listaProductos->sig;
        }
    }

    return -1;
}

int agregarCategoria(celdaArreglo arreglo[], int validos, char categoria[])
{
    strcpy(arreglo[validos].categoria, categoria);
    arreglo[validos].listadeProductos = inicListaDoble();
    validos++;

    return validos;
}
