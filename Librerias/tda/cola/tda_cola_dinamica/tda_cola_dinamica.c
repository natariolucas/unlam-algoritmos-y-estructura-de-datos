#include "tda_cola_dinamica.h"
#include <stdlib.h>
#include <string.h>

void crear_cola(t_cola* pc) {
    pc->ult = pc->pri = NULL;
}

int poner_en_cola(t_cola* pc, const void* elem, size_t tam) {
    t_nodo* nue = malloc(sizeof(t_nodo));
    if(!nue) {
        return COLA_LLENA;
    }

    nue->info = malloc(tam);
    if(!nue->info) {
        free(nue);
        return COLA_LLENA;
    }
    memcpy(nue->info, elem, tam);
    nue->tam = tam;
    nue->sig = NULL;

    if(pc->ult) {
        pc->ult->sig = nue;
    } else {
        pc->pri = nue;
    }

     pc->ult = nue;
    return OK;
}

int sacar_de_cola(t_cola* pc, void* elem, size_t tam){
    if(!pc->pri) {
        return COLA_VACIA;
    }

    t_nodo* nae = pc->pri;
    memcpy(elem, nae->info, menor(tam, pc->pri->tam));
    pc->pri = nae->sig;

    if(!pc->pri) { //Era el ultimo elemento de la cola
        pc->ult = NULL;
    }

    free(nae->info);
    free(nae);

    return OK;
}
int cola_llena(t_cola* pc, size_t tam) {
    t_nodo* nue = malloc(sizeof(t_nodo));
    if(!nue) {
        return COLA_LLENA;
    }

    void* info = malloc(tam);
    if(!info) {
        free(nue);
        return COLA_LLENA;
    }

    return COLA_NO_LLENA;
}

int cola_vacia(t_cola* pc) {
    if(!pc->pri) {
        return COLA_VACIA;
    }

    return COLA_NO_VACIA;
}

void vaciar_cola(t_cola *pc) {
    t_nodo* nae;

    while(!pc->pri) {
        nae = pc->pri;
        pc->pri = nae->sig;

        free(nae->info);
        free(nae);
    }
    pc->ult = NULL;
}

int frente_de_cola(t_cola* pc, void* elem, size_t tam) {
    if(!pc->pri) {
        return COLA_VACIA;
    }

    memcpy(elem, pc->pri->info, menor(tam, pc->pri->tam));

    return OK;
}

size_t menor(size_t tam1, size_t tam2) {
    if (tam1 < tam2) {
        return tam1;
    }

    return tam2;
}
