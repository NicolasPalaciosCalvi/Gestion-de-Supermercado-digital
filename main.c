#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "Estructuras Generales.h"
#include "arbol.h"
#include "lista2.h"
#include "arreglo.h"
#include "pila.h"
#include <time.h>
#include <stdbool.h>

///PROTOTIPADO
void registrarUsuario();
user iniciarSesion(int*);
void atenderClientes(Fila*);
void CargarMercaderia();
void mostrarRegistroArchivo();
int pasarArchiCategoriaAdlCategoria(celdaArreglo [],int );
void altaDeProductos(celdaArreglo [],int );
int validarProducto(nodo2 *, char  []);
void recorrerADL(celdaArreglo [],int );
void pasarAdlCategoriaBDProducto(celdaArreglo [], int );
void mostrarBaseDeDatos(int);
int pasarBDPaAdlCategoria(celdaArreglo []);
nodoArbol * cargarCarrito(celdaArreglo[], int );
int verificarStock(celdaArreglo [], int, int, char []);
float calcular(celdaArreglo [], int, int, char []);
void actualizarStock(nodo2 *,int,char []);
void actualizarAdl(celdaArreglo [], int );
void actualizacion(celdaArreglo [],int,char []);
void pilaPreciosCuidados(Pila*,celdaArreglo [],int );
Fila* confirmarCompra(user, nodoArbol*, celdaArreglo [], int );
int obtenerNumeroStock();
float obtenerNumeroFloat();
int esMayorQueCero(int);

int main()
{
    Fila *filita;
    inicFila(&filita);
    nodoArbol* arbol;
    arbol = inicArbol();

    celdaArreglo adlCategoria[7];
    int validos = 0;

    validos=pasarBDPaAdlCategoria(adlCategoria);

    int ingresoExitoso=0;
    user usuario;
    int opcion;
    int contLogin=0;
    int opcionAdmin;
    int opcionUsuario;
    char nombreP[50];
    Pila pilita;
    inicpila(&pilita);
    char eleccionAdmin='s';
    char eleccionUsuario='s';
    producto productito;
    float totalCar=0;

    printf("\n");
    printf("**********************************************\n");
    printf("*     Bienvenido a Prime Choice Market       *\n");
    printf("**********************************************\n");
    sleep(2);
    system("cls");
    do
    {
        if(ingresoExitoso!=-1)
        {
            printf("\n");
            printf("  =============== SISTEMA DE REGISTRO Y LOGIN ===============  \n");
            printf("||  Opciones:                                                ||\n");
            printf("||   1. Registrar nuevo usuario                              ||\n");
            printf("||   2. Iniciar sesion                                       ||\n");
            printf("||   3. Salir                                                ||\n");
            printf("  ===========================================================\n\n");

            printf("\nIngrese el numero de la opcion que desee: ");
            scanf("%d", &opcion);
        }
        sleep(1,5);
        system("cls");

        switch (opcion)
        {
        case 1:
            registrarUsuario();
            sleep(2);
            system("cls");
            break;
        case 2:

            usuario=iniciarSesion(&ingresoExitoso);
            sleep(3);
            system("cls");
            if(ingresoExitoso==1&&strcmpi(usuario.nombre,"admin")==0)
            {

                printf("================ Bienvenido al sistema de Admin ================\n");
                do
                {
                    printf("OPCIONES DE MENU:\n");
                    printf("1. Dar de alta un producto\n");
                    printf("2. Actualizar datos de productos\n");
                    printf("3. Dar de baja un producto\n");
                    printf("4. Atender la fila\n");
                    printf("5. Ver productos\n");
                    printf("================================================================\n\n");

                    printf("\nIngrese el numero de la opcion que desee: ");
                    fflush(stdin);
                    scanf("%d", &opcionAdmin);
                    switch(opcionAdmin)
                    {
                    case 1:
                        system("cls");
                        altaDeProductos(adlCategoria,validos);
                        pasarAdlCategoriaBDProducto(adlCategoria,validos);
                        validos=pasarBDPaAdlCategoria(adlCategoria);
                        validos=pasarArchiCategoriaAdlCategoria(adlCategoria,validos);
                        mostrarBaseDeDatos(1);
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        actualizarAdl(adlCategoria,validos);
                        pasarAdlCategoriaBDProducto(adlCategoria, validos);
                        validos=pasarBDPaAdlCategoria(adlCategoria);
                        validos=pasarArchiCategoriaAdlCategoria(adlCategoria,validos);
                        sleep(2);
                        system("cls");
                        break;
                    case 3:
                        system("cls");
                        printf("Ingrese el nombre del producto que desea borrar: ");
                        fflush(stdin);
                        gets(nombreP);
                        int pos = buscarPosicionProducto(adlCategoria, validos, nombreP);
                        if (pos > -1)
                        {
                            adlCategoria[pos].listadeProductos = borrarNodoBuscado(adlCategoria[pos].listadeProductos, nombreP);
                            pasarAdlCategoriaBDProducto(adlCategoria, validos);
                            validos=pasarBDPaAdlCategoria(adlCategoria);
                            sleep(2);
                            system("pause");
                        }
                        else
                        {
                            printf("El producto no se encontro en la lista.\n");
                            sleep(2);
                            system("pause");
                        }
                        break;
                    case 4:
                        system("cls");
                        atenderClientes(&filita);
                        break;
                    case 5:
                        system("cls");
                        mostrarBaseDeDatos(1);
                        system("pause");
                        system("cls");
                        break;
                    default:
                        printf("\n LA OPCION INGRESADA NO ES VALIDA");
                        break;
                    }
                    printf("\nDesea volver a elegir una opcion? S/N \n");
                    fflush(stdin);
                    scanf("%c",&eleccionAdmin);
                    sleep(2);
                    system("cls");
                }
                while(eleccionAdmin=='s');
            }
            else if(ingresoExitoso==1)
            {
                printf("================ Bienvenido al sistema %s ================\n",usuario.nombre);
                do
                {
                    printf("OPCIONES DE MENU:\n");
                    printf("1. Ver productos\n");
                    printf("2. Ver PRECIOS CUIDADOS\n");
                    printf("3. Cargar productos al carrito\n");
                    printf("4. Ver carrito\n");
                    printf("5. Sacar producto del carrito\n");
                    printf("6. Confirmar compra\n");
                    printf("=============================================================\n\n");

                    printf("\nIngrese el numero de la opcion que desee: ");
                    fflush(stdin);
                    scanf("%d", &opcionUsuario);
                    switch(opcionUsuario)
                    {
                    case 1:
                        system("cls");
                        mostrarBaseDeDatos(0);
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        pilaPreciosCuidados(&pilita,adlCategoria,validos);
                        mostrarP(&pilita);
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        system("cls");
                        arbol=cargarCarrito(adlCategoria,validos);

                        break;
                    case 4:
                        system("cls");
                        inorder (arbol);
                        float total = totalCarrito(arbol);
                        printf("\nTOTAL: %.2f",total);
                        break;
                    case 5:
                        system("cls");
                        printf("Ingrese el nombre del producto que desea sacar del carrito: ");
                        fflush(stdin);
                        gets(productito.nombre);
                        arbol = borrarNodo(arbol,productito.nombre);
                        printf("Producto borrado exitosamente. ");
                        break;
                    case 6:
                        system("cls");
                        filita=confirmarCompra(usuario,arbol,adlCategoria,validos);
                        printf("\nVuelva pronto!");

                        break;
                    default:
                        printf("\n LA OPCION INGRESADA NO ES VALIDA");
                        break;
                    }

                    printf("\nDesea volver a elegir una opcion? S/N \n");
                    fflush(stdin);
                    scanf("%c",&eleccionUsuario);
                    sleep(2);
                    system("cls");
                }
                while(eleccionUsuario=='s');
            }

            else
                opcion=4;
            break;
        case 3:
            printf("Saliendo del programa. Hasta luego!!\n");
            sleep(2);
            system("cls");
            break;
        default:
            system("cls");
            if(contLogin<2)
                printf("OPCION INVALIDA\nPor favor, ingrese una opcion valida.\n");
            contLogin++;
            ingresoExitoso=0;
            if(3-contLogin==1)
                printf("\nLe queda %d intento.",3-contLogin);
            else
                printf("\nLe quedan %d intentos.",3-contLogin);
            sleep(4);
            system("cls");
        }
    }
    while (opcion != 3 && contLogin<3);



    atenderClientes(filita);

    return 0;
}

///FUNCIONES DE REGISTRO

void registrarUsuario()
{
    user usuario;
    FILE *archivo;
    archivo = fopen("usuarios.bin", "ab");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("\n---------------REGISTRO NUEVO USUARIO ---------------\n");
    do
    {
        printf("\nIngrese el nombre de usuario: ");
        fflush(stdin);
        gets(usuario.nombre);
    }
    while(isalpha(usuario.nombre) && isspace(usuario.nombre));

    printf("\nIngrese la clave: ");
    char caracter;
    char contrasena[19];
    int i = 0;
    while (i < 20 - 1)
    {
        caracter = getch();

        if (caracter == 13)
        {
            break;
        }

        if (caracter == 8 && i > 0)
        {
            printf("\b \b");
            i--;
            continue;
        }

        contrasena[i++] = caracter;
        printf("*");
    }
    contrasena[i] = '\0';

    strcpy(usuario.contrasena, contrasena);
    fwrite(&usuario, sizeof(user), 1, archivo);

    fclose(archivo);

    printf("\n\nUsuario registrado exitosamente.\n");
    printf("\n-----------------------------------------------------\n");
}

user iniciarSesion(int*encontrado)
{
    *encontrado=-1;
    user usuario;
    user login;
    char contrasena[19];
    FILE *archivo;
    archivo = fopen("usuarios.bin", "rb");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    printf("\n---------------  INICIO DE SESION  ---------------\n");
    do
    {
        printf("\nIngrese el nombre de usuario: ");
        fflush(stdin);
        gets(usuario.nombre);
    }
    while(isalpha(usuario.nombre) && isspace(usuario.nombre));


    printf("\nIngrese la clave: ");
    char caracter;
    int i = 0;
    while (i < 20 - 1)
    {
        caracter = getch();

        if (caracter == 13)
        {
            break;
        }

        if (caracter == 8 && i > 0)
        {
            printf("\b \b");
            i--;
            continue;
        }

        contrasena[i++] = caracter;
        printf("*");
    }
    contrasena[i] = '\0';

    strcpy(usuario.contrasena, contrasena);



    while (fread(&login, sizeof(user), 1, archivo) > 0)
    {
        if ((strcmp(login.nombre, usuario.nombre) == 0) && (strcmp(login.contrasena, usuario.contrasena) == 0))
        {
            printf("\n\nINICIO DE SESION EXITOSO\n");
            *encontrado = 1;
            break;
        }
    }

    if (*encontrado!=1)
    {
        *encontrado=-1;
        printf("\nCREDENCIALES INCORRECTAS. INICIO DE SESION FALLIDO\n");
    }
    printf("\n---------------------------------------------------\n");
    fclose(archivo);

    return usuario;
}


///FUNCIONES ADMIIN
void atenderClientes(Fila*fila)
{
    system("cls");
    int opcion=0;
    user pri;
    char eleccion;
    if(!filaVacia(fila))
    {
        do
        {
            printf("Seleccione que desea realizar\n");
            printf("1) Ver toda la fila\n");
            printf("2) Ver al primero\n");
            printf("3) Atender al primero\n");
            printf("4) Atender toda la fila\n");
            printf("Otro para salir...\n");
            printf("\nIngrese el numero de la opcion que desee: ");
            scanf("%d", &opcion);
            system("cls");
            switch(opcion)
            {
            case 1:
                mostrarF(fila);
                break;
            case 2:
                pri=primero(fila);
                printf("El primero en la fila es:%s\n",pri.nombre);
                sleep(3);
                break;
            case 3:
                extraer(fila);
                printf("Cliente atendido de forma exitosa!\n");
                mostrarF(fila);
                sleep(3);
                break;
            case 4:
                system("cls");
                while(!filaVacia(fila))
                {
                    mostrarF(fila);
                    extraer(fila);
                    sleep(2);
                    system("cls");
                }
                printf("Se han atendido todos los clientes.");
                sleep(2);

                break;
            default:
                printf("Volviendo al menu...");
                sleep(2);
                break;
            }
            if(!filaVacia(fila)&&(opcion > 0 && opcion < 5))
            {
                printf("Desea volver a elegir una opcion? S/N \n");
                fflush(stdin);
                scanf("%c",&eleccion);
            }
            else eleccion='n';

            system("cls");
        }
        while(eleccion=='s');
    }
    system("cls");
}

void CargarMercaderia()
{

    registroArchivo reg;
    char eleccion='s';
    FILE * archiCategorias;
    archiCategorias = fopen("categorias.bin","ab");

    if (archiCategorias!=NULL)
    {

        while(eleccion=='s')
        {

            printf("\nFrutas y verduras, Lacteos, Carnes, Bebidas, Higiene Personal,\nArtículos de Limpieza, Conservas y alimentos enlatados,\n Alimentos envasados.");

            printf("\nCategoria: ");
            fflush(stdin);
            gets(reg.categoria);

            printf("\n s/n.");
            fflush(stdin);
            scanf("%c",&eleccion);

            fwrite(&reg,sizeof(registroArchivo),1,archiCategorias);
        }

        fclose(archiCategorias);
    }

}

void mostrarRegistroArchivo()
{

    FILE *archi = fopen("categorias.bin", "rb");
    registroArchivo alum;

    if (archi)
    {
        while (fread(&alum, sizeof(registroArchivo),1, archi)>0)
        {
            puts("\n ---------------------------\n");
            printf ("categorias: %s \n", alum.categoria);
            puts("\n ---------------------------\n");
        }
        fclose(archi);
    }
}

int pasarArchiCategoriaAdlCategoria(celdaArreglo adlCategoria[30],int validos)
{

    registroArchivo reg;
    FILE * archiCategorias;
    archiCategorias = fopen("categorias.bin","rb");
    int i=0;
    if (archiCategorias)
    {
        while (fread(&reg, sizeof(registroArchivo),1, archiCategorias)>0)
        {
            validos = alta (adlCategoria,validos,reg,1);
        }
        fclose(archiCategorias);
    }


    return validos;
}

void altaDeProductos(celdaArreglo adlCategoria[30],int validos)
{
    char eleccion='s';
    registroArchivo prod;

    for(int i=0; i<validos; i++)
    {
        eleccion='s';
        printf("\nUsted esta en la categoria: %s",adlCategoria[i].categoria);

        printf("\nSi desea saltar de categoria presione n, sino s: ");
        fflush(stdin);
        scanf("%c",&eleccion);

        while(eleccion=='s')
        {
            printf("\nIngrese el nombre del producto: ");
            fflush(stdin);
            gets(prod.dato.nombre);

            int flag= validarProducto(adlCategoria[i].listadeProductos,prod.dato.nombre);

            if(flag==0)
            {


                printf("\nIngrese el precio del producto: $");
                prod.dato.precio = obtenerNumeroFloat();
                while (prod.dato.precio == -1|| !esMayorQueCero(prod.dato.precio))
                {
                    printf("Ingrese un numero valido: ");
                    prod.dato.precio = obtenerNumeroFloat();
                }

                printf("\nIngrese el stock del producto: ");


                prod.dato.stock = obtenerNumeroStock();
                while (prod.dato.stock == -1 || !esMayorQueCero(prod.dato.stock))
                {
                    printf("Ingrese un numero valido y mayor que cero: ");
                    prod.dato.stock =obtenerNumeroStock();
                }

                printf("\nIngrese el 1 si es de precio cuidado, sino 0: ");
                fflush(stdin);
                scanf("%i",&prod.dato.preciosCuidados);

                strcpy(prod.categoria,adlCategoria[i].categoria);

                validos=alta(adlCategoria,validos,prod,0);
            }
            else
                printf("\nEse producto ya existe.");


            printf("Desea seguir cargando productos en la categoria %s s/n: ",adlCategoria[i].categoria);
            fflush(stdin);
            scanf("%c",&eleccion);
        }
        system("cls");

    }
}

int validarProducto(nodo2 * lista, char nombre [])
{

    int rta = 0;
    nodo2 *actual = lista;

    while (actual != NULL)
    {
        if (strcmpi(actual->dato.nombre, nombre) == 0)
            rta = 1;

        actual = actual->sig;
    }

    return rta;
}

void recorrerADL(celdaArreglo adl[],int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("\n----Categoria %s----",adl[i].categoria);
        recorrerYmostrar(adl[i].listadeProductos,0);

    }
}

void pasarAdlCategoriaBDProducto(celdaArreglo adlCategoria[30], int validos)
{
    FILE *baseDeDatos;
    baseDeDatos = fopen("BaseDeDatosProductos.bin", "wb");

    if (baseDeDatos != NULL)
    {
        for (int i = 0; i < validos; i++)
        {
            if (adlCategoria[i].listadeProductos != NULL)
            {
                while(adlCategoria[i].listadeProductos != NULL)
                {
                    registroArchivo reg;
                    strcpy(reg.categoria, adlCategoria[i].categoria);
                    strcpy(reg.dato.nombre, adlCategoria[i].listadeProductos->dato.nombre);
                    reg.dato.precio = adlCategoria[i].listadeProductos->dato.precio;
                    reg.dato.stock = adlCategoria[i].listadeProductos->dato.stock;
                    reg.dato.preciosCuidados = adlCategoria[i].listadeProductos->dato.preciosCuidados;

                    fwrite(&reg, sizeof(registroArchivo), 1, baseDeDatos);
                    adlCategoria[i].listadeProductos = adlCategoria[i].listadeProductos->sig;
                }

            }
        }
        fclose(baseDeDatos);
    }
}

void mostrarBaseDeDatos(int interruptor)
{
    FILE *archi;
    archi = fopen("BaseDeDatosProductos.bin", "rb");
    registroArchivo reg;
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~BASE DE DATOS~~~~~~~~~~~~~~~~~~~~~~~");
    if (archi)
    {
        while (fread(&reg, sizeof(registroArchivo),1, archi)>0)
        {
            if(interruptor==1||(interruptor==0&&reg.dato.stock>0))
            {
                printf("\n ------------categoria: %s---------------\n", reg.categoria);
                printf (" \n", reg.categoria);
                printf("\nProducto:%s",reg.dato.nombre);
                printf("\nPrecio:%.2f",reg.dato.precio);
                if(interruptor==1)
                    printf("\nSi es de Precios Cuidados 1, sino es 0 : %i",reg.dato.preciosCuidados);
                printf("\nStock:%i",reg.dato.stock);
                printf("\n -----------------------------------------\n");
            }

        }

    }
    fclose(archi);
}

int pasarBDPaAdlCategoria(celdaArreglo adl[])
{

    FILE *archi;
    archi = fopen("BaseDeDatosProductos.bin", "rb");
    registroArchivo reg;
    int validos=0;

    if (archi)
    {
        while (fread(&reg, sizeof(registroArchivo),1, archi)>0)
        {
            validos = alta (adl,validos,reg,0);

        }
        fclose(archi);
    }
    return validos;
}

int obtenerNumeroStock()
{
    int num;
    if (scanf("%d", &num) != 1)
    {
        while (getchar() != '\n');
        return -1;
    }
    return num;
}

float obtenerNumeroFloat()
{
    float num;
    if (scanf("%f", &num) != 1)
    {
        while (getchar() != '\n');
        return -1;
    }
    return num;
}

int esMayorQueCero(int num)
{
    if (num > 0)
    {
        return 1;
    }
    return 0;
}
///FUNCIONES USUARIO
nodoArbol * cargarCarrito(celdaArreglo adlCategoria[], int validos)
{
    producto productito;
    char eleccion;
    int cantidad;
    int i=0;
    nodoArbol * aux;
    aux=inicArbol();

    printf("\n---------CARRITO---------");
    while(i<validos && adlCategoria[i].listadeProductos!=NULL)
    {

        printf("\n\-----catalogo de %s-----",adlCategoria[i].categoria);
        recorrerYmostrar(adlCategoria[i].listadeProductos,0);
        printf("\n---------------------------");
        if(i==0)
        {
            printf("\nDesea comprar productos de esta categoria o avanzar? s/a \n");
            fflush(stdin);
            scanf("%c",&eleccion);
        }
        else
        {
            printf("\nDesea comprar productos de esta categoria, o avanzar/retroceder de categoria? s/a/r \n");
            fflush(stdin);
            scanf("%c",&eleccion);
            if(eleccion=='r')
            {
                i--;
                continue;
            }
        }

        while(eleccion== 's')
        {
            printf("Que producto desea comprar?");
            fflush(stdin);
            gets(productito.nombre);

            printf("Cuantos %s desea comprar?",productito.nombre);
            productito.stock = obtenerNumeroStock();
            while (productito.stock == -1 || !esMayorQueCero(productito.stock))
            {
                printf("Ingrese un numero valido y mayor que cero: ");
                productito.stock =obtenerNumeroStock();
            }
            cantidad=productito.stock;

            int rta=verificarStock(adlCategoria,i,cantidad,productito.nombre);

            if(rta==0)
                printf("\nLo sentimos!\n No hay suficiente stock para realizar su compra.");
            else if (rta==-1)
                printf("\nNo existe ese producto.");

            if(rta==0||rta==-1)
            {
                printf("\nDesea reintentar su seleccion o comprar otro producto de %s? Ingrese s/n.",adlCategoria[i].categoria);
                fflush(stdin);
                scanf("%c",&eleccion);
            }
            else
            {
                productito.precio=calcular(adlCategoria,i,cantidad,productito.nombre);
                aux=insertar(aux,productito);
                inorder(aux);

                actualizarStock(adlCategoria[i].listadeProductos,cantidad,productito.nombre);
                pasarAdlCategoriaBDProducto(adlCategoria, validos);
                validos=pasarBDPaAdlCategoria(adlCategoria);
                validos=pasarArchiCategoriaAdlCategoria(adlCategoria,validos);
                printf("Desea seleccionar nuevamente un producto dentro de %s? Ingrese s/n.",adlCategoria[i].categoria);
                fflush(stdin);
                scanf("%c",&eleccion);
            }
        }
        i++;
        system("cls");
    }

    return aux;
}

int verificarStock(celdaArreglo adl[], int pos, int cant, char prod[])
{
    int rta = -1;

    nodo2 *actual = adl[pos].listadeProductos;
    while (actual != NULL)
    {
        if (strcmpi(actual->dato.nombre, prod) == 0)
        {
            if (cant <= actual->dato.stock)
                rta = 1;
            else
                rta = 0;
        }
        actual = actual->sig;
    }

    return rta;
}

float calcular(celdaArreglo adl[], int pos, int cantidad, char nombre[])
{
    float rta = -1.0;

    nodo2 *actual = adl[pos].listadeProductos;

    while (actual != NULL)
    {
        if (strcmpi(actual->dato.nombre, nombre) == 0)
        {
            rta = actual->dato.precio * cantidad;
            break;
        }
        actual = actual->sig;
    }

    return rta;
}

void actualizarStock(nodo2 * lista,int stock,char nombre[])
{

    while(lista!=NULL)
    {
        if(strcmpi(lista->dato.nombre,nombre)==0)
            lista->dato.stock-=stock;

        lista=lista->sig;
    }
}

void actualizarAdl(celdaArreglo adlCategoria[], int validos)
{
    int flag = 0;
    char categoria[50];
    char prod[50];
    printf("¿Que categoria desea actualizar? \n");
    fflush(stdin);
    gets(categoria);
    int pos = buscarPosicion(adlCategoria, validos, categoria);
    printf("¿Que producto desea actualizar dentro de %s? \n", categoria);
    fflush(stdin);
    gets(prod);

    while (adlCategoria[pos].listadeProductos != NULL && flag == 0)
    {
        if (strcmpi(adlCategoria[pos].listadeProductos->dato.nombre, prod) == 0)
            flag = 1;
        else
            adlCategoria[pos].listadeProductos = adlCategoria[pos].listadeProductos->sig;
    }

    if (flag == 1)
    {
        actualizacion(adlCategoria, pos, prod);
    }
}
void actualizacion(celdaArreglo adlCategoria[],int pos,char prod[])
{
    system("cls");
    char eleccion;
    printf("Se ha encontrado correctamente el producto %s!\n",adlCategoria[pos].listadeProductos->dato.nombre);
    printf("Desea cambiarle el precio al producto? S/N \n");
    fflush(stdin);
    scanf("%c",&eleccion);
    if(eleccion=='s')
    {
        printf("Ingrese el nuevo precio del producto: $");
        adlCategoria[pos].listadeProductos->dato.precio = obtenerNumeroFloat();
        while (adlCategoria[pos].listadeProductos->dato.precio == -1|| !esMayorQueCero(adlCategoria[pos].listadeProductos->dato.precio))
        {
            printf("Ingrese un numero valido: ");
            adlCategoria[pos].listadeProductos->dato.precio = obtenerNumeroFloat();
        }

    }
    system("cls");
    printf("Desea cambiarle el stock al producto? S/N \n");
    fflush(stdin);
    scanf("%c",&eleccion);
    if(eleccion=='s')
    {
        printf("Ingrese el nuevo stock del producto: ");

        adlCategoria[pos].listadeProductos->dato.stock = obtenerNumeroStock();
        while (adlCategoria[pos].listadeProductos->dato.stock == -1 || !esMayorQueCero(adlCategoria[pos].listadeProductos->dato.stock))
        {
            printf("Ingrese un numero valido y mayor que cero: ");
            adlCategoria[pos].listadeProductos->dato.stock =obtenerNumeroStock();
        }
        if(adlCategoria[pos].listadeProductos->dato.stock<1)
        {
            adlCategoria[pos].listadeProductos = borrarNodoBuscado(adlCategoria[pos].listadeProductos, prod);
        }
    }
    system("cls");
    printf("Desea asignar/eliminar el producto a precios cuidados? S/N \n");
    fflush(stdin);
    scanf("%c",&eleccion);
    if(eleccion=='s')
    {
        printf("Si el producto va a pertenecer a precios cuidados ingrese 1, si no, 0: ");
        fflush(stdin);
        scanf("%d",&adlCategoria[pos].listadeProductos->dato.preciosCuidados);
    }
    system("cls");
    printf("PRODUCTO ACTUALIZADO CORRECTAMENTE");
    sleep(3);
    system("cls");
}

void pilaPreciosCuidados(Pila* pilita, celdaArreglo adl[], int validos)
{
    registroArchivo archipila;

    for (int i = 0; i < validos; i++)
    {
        nodo2* aux = adl[i].listadeProductos;

        while (aux != NULL)
        {
            if (aux->dato.preciosCuidados == 1)
            {
                strcpy(archipila.categoria, adl[i].categoria);
                archipila.dato = aux->dato;
                apilar(pilita, archipila);
            }
            aux = aux->sig;
        }
    }
}

Fila* confirmarCompra(user usuario, nodoArbol *arbol, celdaArreglo adlCategoria[], int validos)
{

    Fila* filon;
    inicFila(&filon);
    char efectuar;
    float total = totalCarrito(arbol);
    agregar(&filon, usuario, total);
    printf("Compra realizada con exito!\n");
    return filon;
}
