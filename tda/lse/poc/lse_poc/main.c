#include <stdio.h>
#include <stdlib.h>
#include "../../../../Librerias/tda/lse/lse.h"

void mostrar_enteros(const void* a);

int main()
{
    int ultimo, primero;
    t_lista lista;
    crear_lista(&lista);

    int elems[10] = {2, 6, 2, 3 ,7 ,8 ,1 ,2 ,3, 5};

    //-------------------------------------------------------
    printf("Usando poner al principio para insertar: 2, 6, 2, 3 ,7 ,8 ,1 ,2 ,3, 5 \n");
    for(int i = 0; i<=9; i++) {
        poner_al_principio(&lista, &elems[i], sizeof(int));
    }

    printf("\nSe muestra la lista entera: \n");
    mostrar_lista(&lista, mostrar_enteros);

    printf("\nSe vacia la lista\n");
    vaciar_lista(&lista);

    printf("\nSe muestra la lista entera: \n");
    mostrar_lista(&lista, mostrar_enteros);

    //------------------------------------------------------
    printf("\n------------------------------------------------------\n");
    printf("\nUsando poner al final para insertar: 2, 6, 2, 3 ,7 ,8 ,1 ,2 ,3, 5 \n");
    for(int i = 0; i<=9; i++) {
        poner_al_final(&lista, &elems[i], sizeof(int));
    }

    printf("\nSe muestra primero de la lista:");
    ver_primero_lista(&lista, &primero, sizeof(int));
    printf("%d\n",primero);
    primero = -1;

    printf("\nSe muestra ultimo de la lista:");
    ver_ultimo_lista(&lista, &ultimo, sizeof(int));
    printf("%d\n",ultimo);
    ultimo = -1;

    printf("\nSe muestra la lista entera: \n");
    mostrar_lista(&lista, mostrar_enteros);

    printf("\nLista llena? %d \n", lista_llena(&lista, sizeof(int)));
    printf("\nLista vacia? %d \n", lista_vacia(&lista));

    printf("\nSe vacia la lista\n");
    vaciar_lista(&lista);

    printf("\nLista llena? %d \n", lista_llena(&lista, sizeof(int)));
    printf("\nLista vacia? %d \n", lista_vacia(&lista));

    printf("\nSe muestra primero de la lista:");
    ver_primero_lista(&lista, &primero, sizeof(int));
    printf("%d\n",primero);

    printf("\nSe muestra ultimo de la lista:");
    ver_ultimo_lista(&lista, &ultimo, sizeof(int));
    printf("%d\n",ultimo);

}

void mostrar_enteros(const void* a) {
    printf("-Elemento: %d\n", *((int*)a));
}
