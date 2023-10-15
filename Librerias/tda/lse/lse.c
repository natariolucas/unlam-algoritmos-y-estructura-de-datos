#include "lse.h"
#include <stdlib.h>
#include <strings.h>

void crear_lista(t_lista *pl)
{
    (*pl) = NULL;
}

int lista_vacia(const t_lista *pl) {
    return *pl == NULL;
}

int lista_llena(const t_lista *pl, size_t tam) {
    void* aux = malloc(sizeof(t_nodo) + tam);
    free(aux);
    return !aux;
}

int poner_al_final(t_lista *pl, const void *pd, size_t tam) {
    while(*pl)
        pl = &(*pl)->sig;

    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue) {
        return LISTA_LLENA;
    }

    nue->info = malloc(tam);
    if(!nue->info) {
        free(nue);
        return LISTA_LLENA;
    }

    memcpy(nue->info, pd, tam);
    nue->sig = NULL;
    nue->tam = tam;

    *pl = nue;

    return OK;
}

int poner_en_posicion(t_lista *pl, const void *pd, size_t tam, unsigned pos ) {
    while(*pl && pos) { //Si la posicion es mas grande que el final, inserta en el final
        pos--;
        pl = &(*pl)->sig;
    }

    t_nodo* nue = malloc(sizeof(t_nodo));
    if(!nue) {
        return LISTA_LLENA;
    }

    nue->info = malloc(tam);
    if(!nue->info) {
        free(nue);
        return LISTA_LLENA;
    }
    memcpy(nue->info, pd, tam);
    nue->tam = tam;

    nue->sig = *pl;
    *pl = nue;

    return OK;
}

int sacar_de_lista(t_lista* pl, void* pd, size_t tam, int(*cmp)(const void* a, const void* b)){
    int comp;
    t_nodo* elim;

    if(!*pl) {
        return LISTA_VACIA;
    }

    while(*pl && (comp = cmp(pd, (*pl)->info))!= 0 ) { //Si estuviera ordenada es ">0"
        pl = &(*pl)->sig;
    }

    if(!*pl){ //Si estuviera  ordenada validar tambien "|| comp"
        return NO_EXISTE;
    }
    elim = *pl;
    memcpy(pd, elim->info, MEN(tam, elim->tam));
    *pl = elim->sig;

    free(elim->info);
    free(elim);
    return OK;
}

void vaciar_lista(t_lista* pl) {
    while(*pl) {
        t_nodo* aux = *pl;
        *pl = aux->sig;

        free(aux->info);
        free(aux);
    }
    while(*pl) {
        t_nodo* aux = *pl;
        *pl = (*pl)->sig;

        free(aux->info);
        free(aux);
    }


}

int poner_al_principio(t_lista* pl, const void* pd, size_t tam) {
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue) {
        return LISTA_LLENA;
    }

    nue->info = malloc(tam);
    if(!nue->info) {
        free(nue);
        return LISTA_LLENA;
    }

    memcpy(nue->info, pd, tam);
    nue->tam = tam;
    nue->sig = *pl;
    *pl = nue;

    return OK;
}

int sacar_primero_lista(t_lista* pl, void* pd, size_t tam){
    if(!*pl) {
        return LISTA_VACIA;
    }
    t_nodo* elim = *pl;
    memcpy(pd, elim->info, MEN(tam, elim->tam));

    *pl = elim->sig;
    free(elim->info);
    free(elim);

    return OK;
}

int ver_primero_lista(t_lista* pl, void* pd, size_t tam){
    if(!*pl) {
        return LISTA_VACIA;
    }
    memcpy(pd, (*pl)->info, MEN(tam, (*pl)->tam));
    return OK;
}

int sacar_ultimo_lista(t_lista* pl, void* pd, size_t tam){
    if(!*pl) {
        return LISTA_VACIA;
    }

    while((*pl)->sig)
    {
        pl = &(*pl)->sig;
    }

    t_nodo* elim = *pl;
    memcpy(pd, elim->info, MEN(tam, elim->tam));
    free(elim->info);
    free(elim);
    *pl = NULL;

    return OK;
}

int ver_ultimo_lista(t_lista* pl, void* pd, size_t tam){
    if(!*pl) {
        return LISTA_VACIA;
    }

    while((*pl)->sig)
    {
        pl = &(*pl)->sig;
    }

    memcpy(pd, (*pl)->info, MEN(tam, (*pl)->tam));

    return OK;
}

void mostrar_lista(t_lista* pl, void(*accion)(const void* a)) {
    while(*pl) {
        accion((*pl)->info);
        pl = &(*pl)->sig;
    }
}

void ordenar_lista_insercion(t_lista* pl, int(*cmp)(const void* a, const void* b)) {
    t_nodo* nodo;
    t_lista lOrd;
    t_lista* plOrd;
    while(*pl) {
        //Desengancho el nodo
        nodo = *pl;
        *pl = nodo->sig;
        plOrd = &lOrd;
        while(*plOrd && cmp(nodo->info, (*plOrd)->info) > 0 ) {
            plOrd = &(*plOrd)->sig;
        }

        //lo engancho en la nueva lista
        nodo->sig = *plOrd;
        *plOrd = nodo;
    }

    //piso la lista original con la ordenada
    *pl = lOrd;
}

void ordenar_lista_seleccion(t_lista* pl, int(*cmp)(const void* a, const void* b)) {
    while(*pl) {
        t_lista *aux = pl;
        t_lista *menor = pl;

        while((*aux)->sig) {
           if(cmp((*aux)->sig->info, (*menor)->info) < 0) {
                menor = &(*aux)->sig;
           }

           aux = &(*aux)->sig;
        }

        t_nodo* primero = *menor;
        *menor = (*menor)->sig;
        primero->sig = *pl;
        *pl = primero;

        pl = &(*pl)->sig;
    }
}

void map_lista(const t_lista* pl, void(*accionMap)(void* elem, void* extra), void* param) {
    while(*pl) {
        accionMap((*pl)->info, param);
        pl = &(*pl)->sig;
    }
}


