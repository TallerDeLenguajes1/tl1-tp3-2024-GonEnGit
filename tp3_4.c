#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* estructuras */
typedef struct{
    int productoID;             // crear durante ejecucion
    int cantidad;               // rand entre 1 y 10
    char *tipoProducto;         // obtener del arreglo (indexada?)
    float precioUnitario;       // rand entre 10 y 100
}producto;

// cliente usa la estructura producto, no puede estar abajo
typedef struct {
    int clienteID;             // crear durante ejecucion
    char *nombreCliente;       // los unicos ingresos por usuario
    int cantidadProductos;     // rand entre 1 y 5
    producto *productos;       // depende de cantidadProductos (crear con memoria dinamica)
}cliente;


/* prototipos */
void crearCliente(cliente *datos);
void cargarProductos(producto *datos, int maximo);
void mostrarClientes(cliente *datos, int total);

/* main */
int main(int argc, char * argv[])
{
    srand(time(NULL));

    // declaraciones
    int cantClientes = 10, auxTipo, auxID;

    // cuerpo
    while (cantClientes <= 0 || cantClientes >= 6)
    {
        printf("Ingrese la cantidad de clientes a cargar: ");
        scanf("%d", &cantClientes);
        if (0 <= cantClientes && cantClientes >= 6 )
        {
            printf("Pruebe con una cantidad entre 1 y 5.\n");
        }
    }
    // para poder mostrarlos despues podes crear un arreglo con la 
    // asignacion de memoria así al final, podes liberar 'datos' 
    // y eliminar toda la lista de la memoria
    cliente *listaClientes = (cliente *)malloc(sizeof(cliente) * cantClientes);
    for (int i = 0; i < cantClientes; i++)
    {
        crearCliente(&listaClientes[i]);
    }
    mostrarClientes(listaClientes, cantClientes);

//----------------------------------//
    free(listaClientes);

    return 0;
}

/* definiciones */
void crearCliente(cliente *datos)
{
    int auxLetras;
    char *buffer = (char *)malloc(sizeof(char) * 100);
    cliente clienteTemp;


    // primero asignas un ID:
    clienteTemp.clienteID = 100 + rand() % 100;


    // segundo tomas el nombre:
    printf("Ingrese el nombre del cliente: ");
    fflush(stdin);
    gets(buffer);
    // nombrCliente te lo dieron como puntero,
    // asignas memoria y recien copias
    auxLetras = strlen(buffer);
    clienteTemp.nombreCliente = (char *)malloc((sizeof(char) * auxLetras) + 1);
    strcpy(clienteTemp.nombreCliente, buffer);


    // tercero generas la cantidad de productos y los creas con eso
    clienteTemp.cantidadProductos = 1 + rand() % 5;
    clienteTemp.productos = (producto *)malloc(sizeof(producto) * clienteTemp.cantidadProductos);  // guardas memoria para la cantidad de productos
    cargarProductos(clienteTemp.productos, clienteTemp.cantidadProductos);

    *datos = clienteTemp;
    datos++;

    free(buffer);
}

void cargarProductos(producto *datos, int maximo)
{
    // creas un arreglo de ID para que coincidan en todos los clientes
    int IDProductos[5], auxTipo, auxCantLetras;
    for (int i = 0; i < 5; i++)
    {
        IDProductos[i] = 100 + rand() % 100;
    }
    char *TiposProductos[]={"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    producto productoTemp;

    for (int i = 0; i < maximo; i++)
    {
        auxTipo = rand() % 5;
        productoTemp.productoID = IDProductos[auxTipo];
        productoTemp.cantidad = 1 + rand() % 10;

        // asignas memoria para el tipo de producto
        auxCantLetras = strlen(TiposProductos[auxTipo]);
        productoTemp.tipoProducto = (char *)malloc((sizeof(char) * auxCantLetras) + 1);
        strcpy(productoTemp.tipoProducto,TiposProductos[auxTipo]);    // cuidad asignar con = te hace perder el puntero, quiz, te suena?

        productoTemp.precioUnitario = 10 + rand() % 90;

        *datos = productoTemp;
        datos++;
    }
}

void mostrarClientes(cliente *datos, int total)
{
    cliente clienteAMostrar;
    producto productoAMostrar;

    for (int indiceCli = 0; indiceCli < total; indiceCli++)
    {
        clienteAMostrar = *datos;

        printf("\n/--------- Ventas: --------- /\n");

        printf("\nCliente: %s -- #%d\n", clienteAMostrar.nombreCliente, clienteAMostrar.clienteID);
        printf("\n/--------Lista: --------/");
        for (int indiceProd = 0; indiceProd < clienteAMostrar.cantidadProductos; indiceProd++)
        {
            productoAMostrar = clienteAMostrar.productos[indiceProd];
            printf("\nProducto: %s -- %d\n", productoAMostrar.tipoProducto, productoAMostrar.productoID);
            printf("Cantidad: %d\n", productoAMostrar.cantidad);
            printf("Precio por unidad: %.2f$\n", productoAMostrar.precioUnitario);
        }
        datos++;        // el puntero es datos no clienteAMostrar
    }
}