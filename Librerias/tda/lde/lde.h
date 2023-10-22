#ifndef LDE_H_INCLUDED
#define LDE_H_INCLUDED

#include <stddef.h>

#define OK 1
#define LISTA_LLENA 2
#define LISTA_VACIA 3
#define DUPLICADO 4
#define NO_EXISTE 5

#define MEN(X,Y) (X) < (Y) ? (X) : (Y)

typedef struct s_nodo {
    void* info;
    size_t tam;
    struct s_nodo *sig, *ant;
} t_nodo;

typedef t_nodo* t_lista;
typedef int(*fnCmp)(const void* a, const void* b);

void crear_lista(t_lista* pl);
int insertar_en_orden(t_lista* pl, const void* pd, size_t tam, fnCmp cmp);
int sacar_de_lista(t_lista* pl, void* pd, size_t tam, fnCmp cmp);
int primero_lista(t_lista* pl, void* pd, size_t tam);
int siguiente_lista(t_lista* pl, void* pd, size_t tam);

#endif // LDE_H_INCLUDED
