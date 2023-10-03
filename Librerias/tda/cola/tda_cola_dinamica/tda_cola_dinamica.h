#ifndef TDA_COLA_DINAMICA_H_INCLUDED
#define TDA_COLA_DINAMICA_H_INCLUDED

#include <stddef.h>

#define OK 1
#define COLA_LLENA 2
#define COLA_NO_LLENA 3
#define COLA_VACIA 4
#define COLA_NO_VACIA 5
typedef struct Snodo {
    void* info;
    size_t tam;
    struct Snodo* sig;
} t_nodo;

typedef struct {
    t_nodo* pri;
    t_nodo* ult;
} t_cola;


// A (pri) --> B --> C --> D (ult)
// --frente----           ---fondo---
// "Se agrega por el fondo y se quita por el frente"

void crear_cola(t_cola* pc);
int poner_en_cola(t_cola* pc, const void* elem, size_t tam);
int sacar_de_cola(t_cola* pc, void* elem, size_t tam);
int cola_llena(t_cola* pc, size_t tam);
int cola_vacia(t_cola *pc);
void vaciar_cola(t_cola *pc);
int frente_de_cola(t_cola* pc, void* elem, size_t tam);

size_t menor(size_t tam1, size_t tam2);
#endif // TDA_COLA_DINAMICA_H_INCLUDED
