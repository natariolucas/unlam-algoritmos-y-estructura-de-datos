#include "cola_circular.h"
#include <stdlib.h>
#include <strings.h>

#define MEN(X, Y) (X) < (Y) ? (X) : (Y)

void crear_cola(t_cola* pc) {
    *pc = NULL;
}
int poner_en_cola(t_cola* pc , const void* pd, size_t tam) {
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue) {
        return COLA_LLENA;
    }

    nue->info = malloc(tam);
    if(!nue->info) {
        free(nue);
        return COLA_LLENA;
    }
    memcpy(nue->info, pd, tam);
    nue->tam = tam;

    if(!*pc) {
        *pc = nue;
    } else {
        nue->sig = (*pc)->sig;
    }

    (*pc)->sig = nue;
    *pc = nue;
    return OK;
}

int sacar_de_cola(t_cola* pc, void* pd, size_t tam) {
    if(!*pc) {
        return COLA_VACIA;
    }

    t_nodo* elim = (*pc)->sig;
    if( elim == elim->sig ) {
        (*pc) = NULL;
    } else {
        (*pc)->sig = elim->sig;
    }

    memcpy(pd, elim->info, MEN(tam, elim->tam));
    free(elim->info);
    free(elim);

    return OK;
}

int cola_llena(const t_cola* pc, size_t tam) {
    void* nAux = malloc(sizeof(t_nodo));
    if(!nAux) {
        return 1;
    }

    void* dAux = malloc(tam);
    if(!dAux) {
        free(nAux);
        return 1;
    }

    return 0;
}

int cola_vacia(const t_cola* pc) {
    return !*pc;
}

void vaciar_cola(t_cola* pc) {
    if(!*pc)
        return;

    while(*pc) {
        t_nodo* elim = (*pc)->sig;
        if(elim == elim->sig) {
            *pc = NULL;
        } else {
            (*pc)->sig = elim->sig;
        }

        free(elim->info);
        free(elim);
    }
}

int frente_de_cola(const t_cola* pc, void* pd, size_t tam) {
    if(!*pc)
        return COLA_VACIA;

    t_nodo* frente = (*pc)->sig;
    memcpy(pd, frente->info, MEN(tam, frente->tam));

    return OK;
}
