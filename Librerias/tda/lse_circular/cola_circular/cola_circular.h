#ifndef COLA_CIRCULAR_H_INCLUDED
#define COLA_CIRCULAR_H_INCLUDED

#include <stddef.h>

#define OK 1
#define COLA_LLENA 2
#define COLA_VACIA 3

typedef struct s_nodo {
    void* info;
    size_t tam;
    struct s_nodo* sig;
} t_nodo;

typedef t_nodo* t_cola;


void crear_cola(t_cola* pc);
int poner_en_cola(t_cola* pc , const void* pd, size_t tam);
int sacar_de_cola(t_cola* pc, void* pd, size_t tam);
int cola_llena(const t_cola* pc, size_t tam);
int cola_vacia(const t_cola* pc);
void vaciar_cola(t_cola* pc);
int frente_de_cola(const t_cola* pc, void* pd, size_t tam);
#endif // COLA_CIRCULAR_H_INCLUDED
