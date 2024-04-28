#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // declaraciones
    char *buff = (char *) malloc(sizeof(char) * 100);                    // le das a buff un tamaño para 100 letras;
    int totalNombres, totalLetras;

    printf("Cuantos nombres se van ingresar? ");
    scanf("%d", &totalNombres);
    char ** nombres = (char **)malloc(sizeof(char *) * totalNombres);    // reservo la memoria de las X filas
    /*
        (linea 13), CUIDADO, en un puntero doble se reserva el tamaño 
        de un puntero no de un tipo de variable por eso usas 
        '(char *) * 5' y no solo '(char) * 5'
    */

    printf("\nIngrese %d nombres: \n", totalNombres);
    for (int i = 0; i < totalNombres; i++)
    {
        printf("Nombre #%d: ", i+1);
        fflush(stdin);
        gets(buff);                                                     // tomo un nombre en buff
        totalLetras = strlen(buff);                                     // tomo largo del nombre
        nombres[i] = (char *)malloc((sizeof(char) * totalLetras) + 1);  // reservo memoria para el nombre
        strcpy(nombres[i], buff);                                       // copio el nombre al arreglo
    }

    printf("\n");
    for (int i = 0; i < totalNombres; i++)
    {
        printf("Nombre guardado #%d: %s\n",i+1, nombres[i]);
        free(nombres[i]);
        // no basta con liberar el puntero a nombres
        // tambien tenes que liberar cada puntero del
        // arreglo nombre
    }
    printf("\n");


    free(nombres);
    free(buff);

    return 0;
}