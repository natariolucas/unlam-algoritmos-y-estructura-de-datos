#include "lde.h"
#include <stdlib.h>
#include <strings.h>

void crear_lista(t_lista* pl) {
    *pl = NULL;
}

int insertar_en_orden(t_lista* pl, const void* pd, size_t tam, fnCmp cmp){
    t_nodo* aux_sig = *pl,
            *aux_ant = aux_sig ? aux_sig->ant : NULL;

    while(aux_ant && cmp(pd, aux_ant->info) < 0) {
        aux_sig = aux_ant;
        aux_ant = aux_ant->ant;
    }

    while(aux_sig && cmp(pd, aux_sig->info) > 0 ) {
        aux_ant = aux_sig;
        aux_sig = aux_sig->sig;
    }

    if( (aux_sig && cmp(pd, aux_sig->info) == 0 ) || (aux_ant && cmp(pd, aux_ant->info) == 0 ) ) {
        return DUPLICADO;
    }

    t_nodo* nue = (t_nodo*) malloc(sizeof(t_nodo));
    if(!nue) {
        return LISTA_LLENA;
    }
    nue->info = malloc(tam);
    if(!nue->info) {
        free(nue);
        return LISTA_LLENA;
    }
    nue->tam = tam;
    memcpy(nue->info, pd, tam);

    nue->sig = aux_sig;
    nue->ant = aux_ant;
    if(aux_ant)
        aux_ant->sig = nue;
    if(aux_sig)
        aux_sig->ant = nue;

    *pl = nue;

    return OK;

}

int sacar_de_lista(t_lista* pl, void* pd, size_t tam, fnCmp cmp) {
    t_nodo* elim = *pl;

    while(elim && cmp(pd, elim->info) < 0) {
        elim = elim->ant;
    }

    while(elim && cmp(pd, elim->info) > 0) {
        elim = elim->sig;
    }

    if(!elim || cmp(pd, elim->info) !=0) {
        return NO_EXISTE;
    }

    memcpy(pd, elim->info, MEN(tam, elim->tam));

    elim->ant->sig = elim->sig;
    elim->sig->ant = elim->ant;
    *pl = elim->sig ? elim->sig : elim->ant;

    free(elim->info);
    free(elim);

    return OK;
}

int primero_lista(t_lista* pl, void* pd, size_t tam) {
    if(!*pl)
        return LISTA_VACIA;

    while((*pl)->ant)
        *pl = (*pl)->ant;

    memcpy(pd, (*pl)->info, MEN(tam, (*pl)->tam));

    return OK;
}

int siguiente_lista(t_lista* pl, void* pd, size_t tam) {
    if((!*pl) || !(*pl)->sig) {
        return 0;
    }

    *pl = (*pl)->sig;
    memcpy(pd, (*pl)->info, MEN(tam, (*pl)->tam));

    return 1;
}
