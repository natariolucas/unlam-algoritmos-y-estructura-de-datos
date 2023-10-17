#ifndef PILA_CIRCULAR_H_INCLUDED
#define PILA_CIRCULAR_H_INCLUDED

#include <stddef.h>

#define OK 1
#define PILA_LLENA 2
#define PILA_VACIA 3


typedef struct s_nodo {
    void* info;
    size_t tam;
    struct s_nodo* sig;
} t_nodo;

typedef t_nodo* t_pila;

void crear_pila(t_pila* pp);
int poner_en_pila(t_pila* pp, const void* pd, size_t tam);
int sacar_de_pila(t_pila* pp, void* pd, size_t tam);
void vaciar_pila(t_pila* pp);
int pila_vacia(const t_pila* pp); // 1|0
int pila_llena(const t_pila* pp, size_t tam); //1|0
int ver_tope(const t_pila* pp, void* pd, size_t tam);
#endif // PILA_CIRCULAR_H_INCLUDED
