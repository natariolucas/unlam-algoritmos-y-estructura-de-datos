#include "tda_pila_dinamica.h"
#include <stdlib.h>
#include <string.h>

void crear_pila(pila* pp) {
    *pp = NULL;
}
int poner_en_pila(pila *pp, const void* elem, size_t tamElem) {
    Nodo* nue = malloc(sizeof(Nodo));
    if(!nue) {
        return SIN_MEMORIA;
    }

    void* pd = malloc(tamElem);
    if(!pd) {
        free(nue);
        return SIN_MEMORIA;
    }
    memcpy(pd, elem, tamElem);

    nue->sig = *pp;
    nue->elem = pd;
    nue->tamElem = tamElem;
    *pp = nue;

    return OK;
}

int sacar_de_pila(pila *pp, void* elem, size_t tamElem) {
    //tamElem en este caso es el tamaño disponible en la variable que se va a usar para guardar el elemento
    if(!*pp) {
        return PILA_VACIA;
    }
    Nodo* nae = *pp;
    *pp = nae->sig;

    memcpy(elem, nae->elem, menor(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);

    return OK;
}

void vaciar_pila(pila *pp){
    Nodo* nae;
    while(*pp) {
        nae = *pp;
        *pp = nae->sig;
        free(nae->elem);
        free(nae);
    }
}
int pila_vacia(const pila *pp){
    return !*pp;
}
int pila_llena(const pila *pp, size_t tamElem){
    Nodo* tmp = malloc(sizeof(Nodo));
    if(!tmp) {
        return PILA_LLENA;
    }

    void* pd = malloc(tamElem);
    if(!pd) {
        free(tmp);
        return PILA_LLENA;
    }

    return PILA_NO_LLENA;
}

int ver_tope(const pila *pp, void* elem, size_t tamElem) {
    if(!*pp) {
        return PILA_VACIA;
    }

    Nodo* tope = *pp;
    memcpy(elem, tope->elem, menor(tamElem, tope->tamElem));

    return OK;
}

size_t menor(size_t tam1, size_t tam2) {
    if (tam1 < tam2)
        return tam1;

    return tam2;
}

