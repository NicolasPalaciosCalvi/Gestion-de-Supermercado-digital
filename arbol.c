#include "arbol.h"
#include "Estructuras Generales.h"

/// FUNCIONES ARBOL
nodoArbol *inicArbol()
{
    return NULL;
}

nodoArbol *crearnodoArbol(producto dato)
{
    nodoArbol *aux = malloc(sizeof(nodoArbol));
    aux->dato = dato;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbol *buscar(nodoArbol *arbol, producto productito)
{
    if (arbol != NULL)
    {
        if (productito.precio == arbol->dato.precio)
        {
            return arbol;
        }
        else if (productito.precio > arbol->dato.precio)
        {
            return buscar(arbol->der, productito);
        }
        else
        {
            return buscar(arbol->izq, productito);
        }
    }
    return NULL;
}

nodoArbol * insertar(nodoArbol * arbol,producto productito)
{
    if (arbol == NULL)
    {
        arbol = crearnodoArbol(productito);
    }
    else
    {
        if (productito.precio > arbol->dato.precio)
        {
            arbol->der = insertar(arbol->der, productito);
        }
        else
        {
            arbol->izq = insertar(arbol->izq, productito);
        }
    }
    return arbol;
}

void mostrar(nodoArbol *arbol)
{
    printf("Producto:%s\n", arbol->dato.nombre);
    printf("Precio total de %s : %2.f\n",arbol->dato.nombre, arbol->dato.precio);
    printf("------------------------------------------------\n");

}

void preorder(nodoArbol *arbol)
{
    if (arbol != NULL)
    {
        mostrar(arbol);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbol *arbol)
{
    if (arbol != NULL)
    {
        inorder(arbol->izq);
        mostrar(arbol);
        inorder(arbol->der);
    }
}

void postorder(nodoArbol * arbol)
{
    if (arbol != NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrar(arbol);
    }
}

float totalCarrito (nodoArbol* arbolito)
{
    float total = 0;

    if (arbolito!= NULL)
    {
        if(arbolito->dato.precio>= 0)
            total= arbolito->dato.precio + totalCarrito(arbolito->izq)+ totalCarrito(arbolito->der);

    }
    return total;
}

nodoArbol* borrarNodo(nodoArbol* arbol, char productito[])
{
    int rta = 0;
    nodoArbol *aux = arbol;

    if (arbol == NULL)
    {
        return arbol;
    }

    if (strcmpi(arbol->dato.nombre, productito) == 0)
    {
        if (arbol->der != NULL && arbol->izq != NULL)
        {
            aux = nodoMasIzq(arbol->der);
            arbol->dato = aux->dato;
            arbol->der = borrarNodo(arbol->der, productito);
        }
        else
        {
            if (arbol->der == NULL && arbol->izq == NULL)
            {
                free(arbol);
                return NULL;
            }
            else if (arbol->der == NULL)
            {
                nodoArbol *temp = arbol->izq;
                free(arbol);
                return temp;
            }
            else
            {
                nodoArbol *temp = arbol->der;
                free(arbol);
                return temp;
            }
        }
        rta = 1;
    }

    if (rta == 0)
    {
        arbol->izq = borrarNodo(arbol->izq, productito);
    }
    if (rta == 0)
    {
        arbol->der = borrarNodo(arbol->der, productito);
    }

    return arbol;
}

nodoArbol *nodoMasIzq(nodoArbol *aux)
{
    while (aux && aux->izq != NULL)
    {
        aux = aux->izq;
    }
    return aux;

}
