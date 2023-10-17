#include "pila_circular.h"
#include <stdlib.h>
#include <strings.h>
#define MEN(X,Y) (X) < (Y) ? (X) : (Y)

void crear_pila(t_pila* pp) {
    *pp = NULL;
}

int poner_en_pila(t_pila* pp, const void* pd, size_t tam) {
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue) {
        return PILA_LLENA;
    }
    nue->info = malloc(tam);
    if(!nue->info) {
        free(nue);
        return PILA_LLENA;
    }

    memcpy(nue->info, pd, tam);
    nue->tam = tam;

    if(!*pp) {
        *pp = nue;
    } else {
        nue->sig = (*pp)->sig;
    }

    (*pp)->sig = nue;

    return OK;
}

int sacar_de_pila(t_pila* pp, void* pd, size_t tam) {
    if(!*pp) {
        return PILA_VACIA;
    }

    t_nodo* elim = (*pp)->sig; //Desengancho
    //engancho
    if(elim == elim->sig) {
        *pp = NULL; //Caso borde al sacar el ultimo elemento de la pila
    } else {
        (*pp)->sig = elim->sig;
    }

    memcpy(pd, elim->info, MEN(tam, elim->tam));

    free(elim->info);
    free(elim);

    return OK;
}

void vaciar_pila(t_pila* pp) {
    if(!*pp) {
        return;
    }

    while(*pp != (*pp)->sig ) {
            t_nodo* elim = (*pp)->sig;
            (*pp)->sig = elim->sig;

            free(elim->info);
            free(elim);
    }

    free((*pp)->info);
    free(*pp);
    *pp = NULL;
}

int pila_vacia(const t_pila* pp) {
    return *pp == NULL;
}

int pila_llena(const t_pila* pp, size_t tam) {
    void* mNodo = malloc(sizeof(t_nodo));
    if(!mNodo){
        return 1;
    }

    void* mTam = malloc(tam);
    if(!mTam) {
        free(mNodo);
        return 1;
    }

    return 0;
}

int ver_tope(const t_pila* pp, void* pd, size_t tam) {
    if(!*pp) {
        return PILA_VACIA;
    }
    t_nodo* tope = (*pp)->sig;

    memcpy(pd, tope->info, MEN(tam, tope->tam));

    return OK;
}
