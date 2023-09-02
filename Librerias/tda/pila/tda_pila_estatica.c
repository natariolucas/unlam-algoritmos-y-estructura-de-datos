#include "tda_pila_estatica.h"
#include <string.h>

void crear_pila(pila *pp) {
    pp->tope = TAM_VEC;
}

int poner_en_pila(pila* pp, const void* elem, size_t tamElem) {
    if(pp->tope < tamElem + sizeof(size_t)) {
        return PILA_LLENA;
    }
    //guardo elemento
    pp->tope -= tamElem;
    memcpy(pp->vec + pp->tope, elem, tamElem);

    //guardo tamanio del elemento
    pp->tope -= sizeof(size_t);
    memcpy(pp->vec + pp->tope, &tamElem, sizeof(size_t));
    return OK;
}

int sacar_de_pila(pila* pp, void* elem, size_t tamElem) {
    if(pp->tope == TAM_VEC) {
        return PILA_VACIA;
    }

    //Leo tamanio del elemento guardado
    size_t tamElemGuardado;
    memcpy(&tamElemGuardado, pp->vec + pp->tope, sizeof(size_t));
    pp->tope += sizeof(size_t);

    //Leo y guardo el elemento guardado
    memcpy(elem, pp->vec + pp->tope, menor(tamElem, tamElemGuardado));
    pp->tope += tamElemGuardado;

    return OK;
}

void vaciar_pila(pila *pp) {
    pp->tope = TAM_VEC;
}

int pila_vacia(const pila* pp) {
    if (pp->tope == TAM_VEC)
        return PILA_VACIA;

    return PILA_NO_VACIA; //Esto quedaria mas lindo con booleanos
}

int pila_llena(const pila* pp, size_t tamElem) {
    if (pp->tope < sizeof(size_t) + tamElem) {
        return PILA_LLENA;
    }

    return PILA_NO_LLENA; //Esto quedaria mas lindo con booleanos
}

int ver_tope(const pila *pp, void* elem, size_t tamElem){
    if (pp->tope == TAM_VEC)
        return PILA_VACIA;

    //Leo tamanio del elemento guardado
    int tamElemGuardado;
    memcpy(&tamElemGuardado, pp->vec + pp->tope, sizeof(size_t));

    //Leo y guardo el elemento guardado
    memcpy(elem, pp->vec + pp->tope, menor(tamElem, tamElemGuardado));

    return OK;
}

size_t menor(size_t tam1, size_t tam2) {
    if (tam1 < tam2)
        return tam1;

    return tam2;
}
