#include "lista2.h"
#include "Estructuras Generales.h"

///FUNCIONES DE LISTAS DOBLES PARA ADL///

///Inicializar una lista Doble:

nodo2 * inicListaDoble()
{
    return NULL;
}

///Crear un Nodo:

nodo2 * crearNodoDoble(producto dato)
{
    nodo2 *aux=(nodo2*) malloc(sizeof(nodo2));

    aux->dato = dato;
    aux->ante = NULL;
    aux->sig = NULL;

    return aux;
}

///Agregar Nodo al principio de una Lista Doble:

nodo2 * agregarPpioDoble (nodo2 * lista, nodo2 * nuevo)
{
    nuevo->sig = lista;
    if(lista != NULL)
    {
        lista->ante = nuevo;
    }
    return nuevo;
}


///Agregar un Nodo en Orden a una Lista Doble:

/// esta mal por la estructura

nodo2 * agregarEnOrdenDoble(nodo2 * lista, nodo2 * nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        if(strcmp(nuevo->dato.nombre,lista->dato.nombre)<0)
        {
            lista = agregarPpioDoble(lista, nuevo);
        }
        else
        {
            nodo2 * ante = lista;
            nodo2 * seg= lista->sig;

            while((seg != NULL) && (strcmp(nuevo->dato.nombre, seg->dato.nombre)>0))
            {
                ante = seg;
                seg = seg->sig;
            }

            ante->sig = nuevo;
            nuevo->ante = ante;
            nuevo->sig = seg;

            if(seg!=NULL)
            {
                seg->ante = nuevo;
            }
        }
    }
    return lista;
}

///Agregar un Nodo al Final de una Lista Doble:

nodo2 * agregarFinalDoble(nodo2 * lista, nodo2 * nuevo)
{
    if (lista == NULL)
    {
        return nuevo;
    }
    else
    {
        nodo2 *seg = lista;

        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }

        seg->sig = nuevo;
        nuevo->ante = seg;

        return lista;
    }
}

///Recorrer y mostrar una Lista Doble:

void recorrerYmostrar(nodo2 * lista,int num)
{
    while(lista != NULL)
    {
        escribir(lista,num);
        lista = lista->sig;
    }

}

void escribir(nodo2 * aux,int num)
{
    if(aux->dato.stock>0){
          printf("\nProducto: %s", aux->dato.nombre);
    printf("\nPrecio: $%.2f", aux->dato.precio);
    if(num==0)printf("\nSi es de Precios Cuidados 1, sino es 0 : %i", aux->dato.preciosCuidados);
    printf("\nStock: %i",aux->dato.stock);
    }

}

///Borrar Nodos de una Lista Doble:
nodo2* borrarNodoBuscado(nodo2* lista, char producto[]) {
    nodo2* aux = lista;
    nodo2* anterior = NULL;

    while (aux != NULL) {
        if (strcmpi(aux->dato.nombre, producto) == 0) {
            if (anterior == NULL) {
                lista = aux->sig;
            } else {
                anterior->sig = aux->sig;
            }
            free(aux);
            printf("Producto eliminado exitosamente.\n");
            return lista;
        }

        anterior = aux;
        aux = aux->sig;
    }

    printf("El producto no se encontró en la lista.\n");
    return lista;
}


///FUNCIONES DE LISTAS DOBLES PARA FILAS////

///Inicializar una lista Doble:

nodoFilas * inicListaDobleFilas()
{
    return NULL;
}

///Crear un Nodo:

nodoFilas * crearNodoDobleFilas(user dato,float totalC)
{
    nodoFilas *aux=(nodoFilas*) malloc(sizeof(nodoFilas));

    aux->dato = dato;
    aux->total=totalC;
    aux->ante = NULL;
    aux->sig = NULL;

    return aux;
}

///Agregar un Nodo al Final de una Lista Doble:

nodoFilas * agregarFinalDobleFilas(nodoFilas * lista, nodoFilas * nuevo)
{
    if (lista == NULL)
    {
        return nuevo;
    }
    else
    {
        nodoFilas *seg = lista;

        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }

        seg->sig = nuevo;
        nuevo->ante = seg;

        return lista;
    }
}

///Recorrer y mostrar una Lista Doble:

void recorrerYmostrarFilas(nodoFilas * lista)
{
    while(lista != NULL)
    {
        escribirFilas(lista);
        lista = lista->sig;
    }

}

void escribirFilas(nodoFilas * aux)
{
    printf("\nNombre: %i", aux->dato.nombre);
    printf("\nContraseña: %i", aux->dato.contrasena);
}

///Borrar Primer nodo de una Lista Doble:

nodoFilas * borrarPrimerNodoFila(nodoFilas * lista)
{
    if (lista == NULL)
    {
        return NULL;
    }
    else
    {
        nodoFilas *aux = lista;
        lista = lista->sig;

        if (lista)
        {
            lista->ante = NULL;
        }

        free(aux);

        return lista;
    }
}

///Funcion ver primero:
user verPrimero(nodoFilas* lista)
{
    user rta;

    if(lista)
    {
        rta = lista->dato;
    }
    return rta;
}
