#include "pila.h"
#include "Estructuras Generales.h"

void inicpila(Pila p)
{
    registroArchivo *aux;
    aux = (registroArchivo *)malloc(50 * sizeof(registroArchivo));
    p->valores = aux;
    p->postope = 0;
}

void apilar(Pila p, registroArchivo dato)
{
    int index = p->postope;
    p->valores[index] = dato;
    p->postope = p->postope + 1;
}

registroArchivo desapilar(Pila p)
{
    registroArchivo z = p->valores[p->postope - 1];
    p->postope--;
    return z;
}

registroArchivo tope(Pila p)
{
    return p->valores[p->postope - 1];
}

int pilavacia(Pila p)
{
    return (p->postope == 0);
}

void leer(Pila p)
{
    registroArchivo aux;
    if (p->postope < 50)
    {
        printf("Ingrese los datos del producto:\n");
        printf("Nombre: ");
        fflush(stdin);
        gets(aux.dato.nombre);
        printf("Stock: ");
        fflush(stdin);
        scanf("%d", &aux.dato.stock);
        printf("Precio: ");
        fflush(stdin);
        scanf("%f", &aux.dato.precio);
        printf("¿Está en precios cuidados? (1 para Sí, 0 para No): ");
        fflush(stdin);
        scanf("%d", &aux.dato.preciosCuidados);
        printf("Categoría: ");
        fflush(stdin);
        gets(aux.categoria);

        apilar(p, aux);
    }
    else
        printf("Error: la pila está llena\n");
}

void mostrarP(Pila p) {
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for (i = 0; i < p->postope; i++) {
        printf("| Nombre: %s, Categoria: %s,Precio: %.2f, Stock: %d |\n",p->valores[i].dato.nombre,p->valores[i].categoria,p->valores[i].dato.precio,p->valores[i].dato.stock);
    }
    printf("\nBase .............................................. Tope\n\n");
}
