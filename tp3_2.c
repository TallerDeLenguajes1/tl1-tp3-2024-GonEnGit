#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIL 5
#define COL 12

void buscarMaximo(int *pMatriz);
void buscarMinimo(int *pMatriz);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    // cada fila corresponde a un año
    // cada columna un monto, los años no se guardan en la matriz
    int produccion[FIL][COL], aux;

    // cargo la matriz con numero aleatorios
    for (int i = 0; i < FIL; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            aux = 10000 + rand() % 40000; // solucioná los valores
            produccion[i][j] = aux;
        }
    }

    // muestro la matriz
    for (int i = 0; i < FIL; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (j == 11)
            {
                printf("%d\n", produccion[i][j]);
            }
            else
            {
                printf("%d ", produccion[i][j]);
            }  
        }
    }

    // sumo las filas y saco los promedios
    for (int i = 0; i < FIL; i++)
    {
        int suma = 0;
        int promedio;

        for (int j = 0; j < COL; j++)
        {
            suma += produccion[i][j];
        }
        promedio = suma / COL;
        printf("\nPromedio del a%co %d: %d", 164, i + 1, promedio);
        suma = 0;
    }
    
    // tratá de cambiar los for por funciones...
    buscarMaximo(&produccion[0][0]);
    buscarMinimo(&produccion[0][0]);

    return 0;
}

void buscarMaximo(int *pMatriz)
{
    int mayor = 0, valor, mes;

    for (int i = 0; i < FIL; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            valor = *(pMatriz + ((i * COL) + j));
            if ( valor >= mayor)
            {
                mayor = valor;
                mes = j + 1;
            }
        }
        printf("\nLa mayor producci%dn del a%co %d fue de %d en el mes %d", 162, 164, i + 1, mayor, mes);
        mayor = 0;
    }
}

void buscarMinimo(int *pMatriz)
{
    int menor = 100000, valor, mes;

    for (int i = 0; i < FIL; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            valor = *(pMatriz + ((i * COL) + j));
            if ( valor <= menor)
            {
                menor = valor;
                mes = j + 1;
            }
        }
        printf("\nLa menor producci%cn del a%co %d fue de %d en el mes %d", 162, 164, i + 1, menor, mes);
        menor = 100000;
    }
}