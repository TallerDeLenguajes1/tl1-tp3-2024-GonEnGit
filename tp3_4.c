#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// estructuras
typedef struct{
    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;
}producto;

typedef struct {
    int clienteID;
    char *nombreCliente;
    int cantidadProductos;
    producto *productos;
}cliente;

// prototipos

int main(int argc, char * argv[])
{
    srand(time(NULL));

    // variables
    int numero, auxProductos;

    // crear las estructuras de clientes
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &numero);

    for (int i = 0; i < numero; i++)
    {
        cliente *nuevo = (cliente *)malloc(sizeof(cliente));

        auxProductos = rand() % 5;
        
    }
    


    return 0;
}