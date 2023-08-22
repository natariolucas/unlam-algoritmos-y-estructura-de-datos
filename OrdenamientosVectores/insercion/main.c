#include <stdio.h>
#include <stdlib.h>
#include "../../Librerias/vectores/vectores.h"
#include "../../Librerias/vectores/vectores_ordenamientos.h"

void mostrarEntero(void* elem, int i);

int main()
{
    int vec[] = {34, 13, 8, 21, 1, 2, 5, 3};
    mostrarVector(vec, 8, sizeof(int), mostrarEntero);
    ordenarInsercion(vec, 8);

    printf("\n\n");
    mostrarVector(vec, 8, sizeof(int), mostrarEntero);

    return 0;
}

void mostrarEntero(void* elem, int i){
    printf("Posicion: %d ---- Elemento: %d \n", i, *(int*)elem);
}
