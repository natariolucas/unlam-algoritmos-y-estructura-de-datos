#include <stdio.h>
#include <stdlib.h>
#include "../../../Librerias/tda/pila/tda_pila_estatica.h"
int main()
{
    int elem1 = 50;
    char elem2[] = "HOLA COMO ESTAS";
    int elem3 = -2019;
    pila miPila;

    crear_pila(&miPila);
    poner_en_pila(&miPila, &elem1, sizeof(elem1));
    poner_en_pila(&miPila, elem2, sizeof(elem2));


    char sacarElem2[500];
    sacar_de_pila(&miPila, sacarElem2, sizeof(sacarElem2));
    printf("Texto: %s \n", sacarElem2);

    poner_en_pila(&miPila, &elem3, sizeof(elem3));

    int sacarElem3;
    int sacarElem1;
    sacar_de_pila(&miPila, &sacarElem3, sizeof(sacarElem3));
    sacar_de_pila(&miPila, &sacarElem1, sizeof(sacarElem1));

    printf("Elem 3: %d \n", sacarElem3);
    printf("Elem 1: %d \n", sacarElem1);
    printf("Pila vacia? : %d \n", pila_vacia(&miPila) == PILA_VACIA);

    return 0;
}
