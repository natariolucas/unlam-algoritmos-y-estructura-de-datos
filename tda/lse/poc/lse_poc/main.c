#include <stdio.h>
#include <stdlib.h>
#include "../../../../Librerias/tda/lse/lse.h"

void mostrar_enteros(const void* a);
int comparar_enteros(const void* a, const void* b);

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

    printf("\nSe ordena la lista por insercion \n");
    ordenar_lista_insercion(&lista, comparar_enteros);
    //printf("\nSe ordena la lista por seleccion \n");
    //ordenar_lista_seleccion(&lista, comparar_enteros);


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
int comparar_enteros(const void* va, const void* vb) {
    int a,b;
    a = *(int*)va;
    b = *(int*)vb;

    if (a > b) {
        return 1;
    }

    if (a < b) {
        return -1;
    }

    return 0;
}
