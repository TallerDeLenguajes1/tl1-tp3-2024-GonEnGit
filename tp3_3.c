#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // declaraciones
    char *buff;
    int cantidad;

    // reservas ... ?
    buff = (char *) malloc(sizeof(char) * 100);               // le das a buff un tamaño para 100 letras
    char ** nombres = (char **)malloc(sizeof(char *) * 5);    // reservo la memoria de las 5 filas
    /*
        (linea 13), CUIDADO, acá tenias un error grande, en un puntero doble
        se reserva el tamaño de un puntero no de un tipo de variable
        por eso usas '(char *) * 5' y no solo '(char) * 5'
    */


    printf("\nIngrese 5 nombres: \n");
    for (int i = 0; i < 5; i++)
    {
        gets(buff);     // tomo un nombre en buff
        cantidad = strlen(buff);
        nombres[i] = (char *)malloc((sizeof(char) * cantidad) + 1);
        strcpy(nombres[i], buff);
    }

    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre: %s\n", nombres[i]);
    }
    printf("\n");

    free(buff);     // no te comas los free
    free(nombres);

    return 0;
}