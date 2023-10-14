#ifndef TDA_COLA_ESTATICA_H_INCLUDED
#define TDA_COLA_ESTATICA_H_INCLUDED

#include <stddef.h>

#define TAM_COLA  500
#define OK 1
#define COLA_LLENA 2
#define COLA_VACIA 3
#define COLA_NO_LLENA 4
#define COLA_NO_VACIA 5

typedef struct {
    char vec[TAM_COLA];
    int frente;
    int fondo;
    int tam_disp;
}t_cola;

void crear_cola(t_cola *pc);
int poner_en_cola(t_cola* pc, const void* pd, size_t tam);
int sacar_de_cola(t_cola* pc, void* pd, size_t tam);
int cola_llena(t_cola* pc, size_t tam);
int cola_vacia(t_cola *pc);
void vaciar_cola(t_cola *pc);
int frente_de_cola(t_cola* pc, void* elem, size_t tam);

int menor(int tam1, int tam2);

#endif // TDA_COLA_ESTATICA_H_INCLUDED
