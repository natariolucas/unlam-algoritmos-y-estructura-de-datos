#include <stdio.h>
#include <stdlib.h>
#include "../../../Librerias/tda/lse_circular/pila_circular/pila_circular.h"
void debug_tope_circular(const t_pila* pp);
int main()
{
    int elem1 = 50;
    char elem2[] = "HOLA COMO ESTAS";
    int elem3 = -2019;
    t_pila miPila;

    printf("- Se crea pila \n\n");
    crear_pila(&miPila);
    printf("--- Se pone en pila %d (elem1)\n", elem1);
    poner_en_pila(&miPila, &elem1, sizeof(elem1));
    printf("--- Se pone en pila %s (elem2)\n", elem2);
    poner_en_pila(&miPila, elem2, sizeof(elem2));


    char sacarElem2[500];
    sacar_de_pila(&miPila, sacarElem2, sizeof(sacarElem2));
    printf("-- Se saco de pila: %s \n", sacarElem2);
    printf("--- Se pone en pila %d (elem3)\n", elem3);
    poner_en_pila(&miPila, &elem3, sizeof(elem3));
    debug_tope_circular(&miPila);

    int sacarElem3;
    int sacarElem1;
    ver_tope(&miPila, &sacarElem3, sizeof(sacarElem3));
    printf("--Se ve el tope: %d \n", sacarElem3);
    sacarElem3 = 0; //reset var
    debug_tope_circular(&miPila);

    sacar_de_pila(&miPila, &sacarElem3, sizeof(sacarElem3));
    printf("-- Se saco de pila: %d \n", sacarElem3);
    debug_tope_circular(&miPila);

    sacar_de_pila(&miPila, &sacarElem1, sizeof(sacarElem1));
    printf("-- Se saco de pila: %d \n", sacarElem1);
    debug_tope_circular(&miPila);

    printf("\n- Pila vacia? : %d \n", pila_vacia(&miPila));

    return 0;
}

void debug_tope_circular(const t_pila* pp) {
    if(!*pp) {
        printf("(debug-tope-circular): no-tope\n\n");
        return;
    }
    t_nodo* pTope;
    t_nodo* pSiguiente;
    pTope = *pp;
    pSiguiente = (*pp)->sig;

    printf("(debug-tope-circular): DirTope=%p || DirSig=%p || UltimoNodo:%d\n\n", (void*)pTope, (void*)pSiguiente, pTope == pSiguiente);
}
