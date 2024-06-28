#ifndef ESTRUCTURAS_GENERALES_H_INCLUDED
#define ESTRUCTURAS_GENERALES_H_INCLUDED

/// ESTRUCTURAS

typedef struct{
 int stock;
 char nombre[30];
 float precio;
 int preciosCuidados;///Si es 1 esta en precios cuidados, si es 0 no aparece
}producto;


typedef struct{
    producto dato;
    char categoria[50];
}registroArchivo;

typedef struct{
    char nombre[50];
    char contrasena[50];
} user;

#endif // ESTRUCTURAS_GENERALES_H_INCLUDED
