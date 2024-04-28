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

/* No trates de usar dobles en este */

/* prototipos */
void crearCliente(cliente *nuevoCliente);
void cargarProductos(producto *nuevoProducto, int maximo);
void mostrarClientes(cliente *entradaCliente, int total);
float totalProductos(producto *datos);

/* main */
int main(int argc, char * argv[])
{
    srand(time(NULL));

    // declaraciones
    int cantClientes = 10, auxTipo, auxID;

    // cuerpo
    while (cantClientes <= 0 || cantClientes >= 6)
    {
        printf("\nIngrese la cantidad de clientes a cargar: ");
        scanf("%d", &cantClientes);
        if (0 <= cantClientes && cantClientes >= 6)
        {
            printf("Pruebe con una cantidad entre 1 y 5.\n");
        }
    }
    // para poder mostrarlos despues, podes crear un arreglo con la 
    // asignacion de memoria así al final, podes liberar 'listaClientes'
    // y eliminar toda la lista de la memoria
    cliente *listaClientes = (cliente *)malloc(sizeof(cliente) * cantClientes);
    for (int i = 0; i < cantClientes; i++)
    {
        crearCliente(&listaClientes[i]);
    }
    printf("\n/--------- Ventas: ---------/\n");
    mostrarClientes(listaClientes, cantClientes);
    printf("\n");

//----------------------------------//
    free(listaClientes);

    return 0;
}

/* definiciones */
void crearCliente(cliente *nuevoCliente)
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
    // nombreCliente te lo dieron como puntero,
    // asignas memoria y recien copias
    auxLetras = strlen(buffer);
    clienteTemp.nombreCliente = (char *)malloc((sizeof(char) * auxLetras) + 1);
    strcpy(clienteTemp.nombreCliente, buffer);


    // tercero generas la cantidad de productos y los creas con eso
    clienteTemp.cantidadProductos = 1 + rand() % 5;
    clienteTemp.productos = (producto *)malloc(sizeof(producto) * clienteTemp.cantidadProductos);  // guardas memoria para la cantidad de productos
    cargarProductos(clienteTemp.productos, clienteTemp.cantidadProductos);

    // asignas los datos recien creado a un espacio en la lista
    *nuevoCliente = clienteTemp;
    // y moves la lista al siguiente espacio
    nuevoCliente++;

    free(buffer);
}

void cargarProductos(producto *nuevoProducto, int maximo)
{
    int auxTipo, auxCantLetras;
    char *TiposProductos[]={"Galleta", "Snack", "Cigarrillo", "Caramelo", "Bebida"};
    producto productoTemp;

    for (int i = 0; i < maximo; i++)
    {
        productoTemp.productoID = 100 + rand() % 100;
        productoTemp.cantidad = 1 + rand() % 10;

        // asignas memoria para el tipo de producto
        auxTipo = rand() % 5;
        auxCantLetras = strlen(TiposProductos[auxTipo]);
        productoTemp.tipoProducto = (char *)malloc((sizeof(char) * auxCantLetras) + 1);
        strcpy(productoTemp.tipoProducto,TiposProductos[auxTipo]);    // cuidad asignar con = te hace perder el puntero, quiz, te suena?

        productoTemp.precioUnitario = 10 + rand() % 90;

        *nuevoProducto = productoTemp;
        nuevoProducto++;
    }
}

void mostrarClientes(cliente *entradaCliente, int total)
{
    cliente clienteAMostrar;
    producto productoAMostrar;

    for (int indiceCli = 0; indiceCli < total; indiceCli++)
    {
        float precioTotalPorProducto, precioTotalPorCliente = 0;    // como lo veas estas variables tienen nombres muy largos
        clienteAMostrar = *entradaCliente;

        printf("\nCliente: %s -- ID: %d ---- Pedido: \n", clienteAMostrar.nombreCliente, clienteAMostrar.clienteID);
        for (int indiceProd = 0; indiceProd < clienteAMostrar.cantidadProductos; indiceProd++)
        {
            productoAMostrar = clienteAMostrar.productos[indiceProd];
            printf("\nProducto: %s -- #%d\n", productoAMostrar.tipoProducto, productoAMostrar.productoID);
            printf("Cantidad: %d\n", productoAMostrar.cantidad);
            printf("Precio por unidad: %.2f$\n", productoAMostrar.precioUnitario);

            precioTotalPorProducto = totalProductos(&productoAMostrar);
            printf("\n~Total por %ss: $%.2f\n", productoAMostrar.tipoProducto, precioTotalPorProducto);

            precioTotalPorCliente += precioTotalPorProducto;
        }
        printf("\n~~Total del cliente #%d: $%.2f\n", clienteAMostrar.clienteID, precioTotalPorCliente);
        printf("\n/------------------------------/\n");

        entradaCliente++;        // el puntero es datos no clienteAMostrar
    }
}

float totalProductos(producto *datos)
{
    return datos->cantidad * datos->precioUnitario;
}