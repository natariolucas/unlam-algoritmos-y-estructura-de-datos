#include "tda_cola_estatica.h"
#include <string.h>

void crear_cola(t_cola *pc) {
    pc->tam_disp = TAM_COLA;
    pc->fondo = 0;
    pc->frente = 0;
}

int poner_en_cola(t_cola* pc, const void* pd, size_t tam) {
    int ini, fin;
    if (pc->tam_disp < tam+sizeof(size_t)) {
        return COLA_LLENA;
    }

    //inserto el tamaño del elemento
    ini = menor(TAM_COLA - pc->fondo, sizeof(size_t));
    if(ini) {
        memcpy(pc->vec + pc->fondo, &tam, ini);
    }

    fin = sizeof(size_t) - ini;
    if(fin){
        memcpy(pc->vec, ((char*)&tam)+ini, fin);
    }
    pc->fondo = fin ? fin : pc->fondo + ini;

    //(TAM_COLA - pc->fondo) es cuanto espacio tengo antes que se me corte el vector
    // ---------frente####################fondo(497)---(500)

    //intserto el elemento
    ini = menor(TAM_COLA - pc->fondo, tam);
    if(ini) {
        memcpy(pc->vec + pc->fondo, pd, ini);
    }

    fin = tam - ini;
    if(fin){
        memcpy(pc->vec, ((char*)pd)+ini, fin);
    }

    pc->fondo = fin ? fin : pc->fondo + ini;
    pc->tam_disp = pc->tam_disp - tam - sizeof(size_t);

    return OK;
}

int sacar_de_cola(t_cola * pc, void* elem, size_t tam) {
    int ini, fin;
    size_t tam_dato_cola;

    if (pc->tam_disp == TAM_COLA) {
        return COLA_VACIA;
    }

    //Extraigo tamanio del dato guardado
    if( (ini = menor(TAM_COLA - pc->frente, sizeof(size_t)))) {
        memcpy(&tam_dato_cola, pc->vec + pc->frente, ini);
    }

    if((fin = sizeof(size_t)-ini)) {
        memcpy(((char*)&tam_dato_cola)+ini, pc->vec, fin);
    }
    pc->frente = fin ? fin : pc->frente + sizeof(size_t);

    //Extraigo el dato guardado
    if( (ini = menor(TAM_COLA - pc->frente, tam_dato_cola))) {
        memcpy(elem, pc->vec + pc->frente, menor(ini,tam));
    }

    if ((fin = tam-ini) && tam-ini > 0) {
        memcpy(((char*)elem)+ini, pc->vec, menor(fin, tam-ini));
    }
    pc->frente = fin ? fin : pc->frente + tam_dato_cola;
    pc->tam_disp += sizeof(size_t) + tam_dato_cola;

    return OK;

}

int cola_llena(t_cola *pc, size_t tam) {
    if (tam+sizeof(size_t) > pc->tam_disp) {
        return COLA_LLENA;
    }

    return COLA_NO_LLENA;
}

int cola_vacia(t_cola *pc) {
    if (pc->tam_disp == TAM_COLA) {
        return COLA_VACIA;
    }

    return COLA_NO_VACIA;
}

void vaciar_cola(t_cola *pc ) {
    pc->frente = pc->fondo;
    pc->tam_disp = TAM_COLA;
}

int frente_de_cola(t_cola *pc, void* pd, size_t tam) {
    int ini, fin;
    size_t tam_dato_cola;

    if(pc->tam_disp == TAM_COLA) {
        return COLA_VACIA;
    }

    //consulto tamanio del elemento guardado
    if((ini = menor(TAM_COLA-pc->frente, sizeof(size_t)))) {
        memcpy(&tam_dato_cola, pc->vec + pc->frente, ini);
    }
    if( (fin = sizeof(size_t) - ini )) {
        memcpy(((char*)&tam_dato_cola), pc->vec, fin);
    }

    //copio el elemento guardado
    if((ini = menor(TAM_COLA - pc->frente, tam_dato_cola))) {
        memcpy(pd, pc->vec + pc->frente, menor(ini, tam));
    }
    if((fin = tam_dato_cola - ini) && tam-ini > 0 ) {
        memcpy(((char*)pd)+ini,pc->vec, menor(fin, tam-ini));
    }

    return OK;

}

int menor(int tam1, int tam2) {
    if (tam1 < tam2) {
        return tam1;
    }

    return tam2;
}
