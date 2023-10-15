#ifndef LSE_H_INCLUDED
#define LSE_H_INCLUDED

#include <stddef.h>

#define LISTA_LLENA 1
#define OK 2
#define LISTA_VACIA 3
#define NO_EXISTE 4
#define MEN(X,Y) ( (X) <= (Y) ? (X) : (Y) )

typedef int(*cmp)(const void* a, const void* b);
typedef void(*accion)(const void* a);

typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo* t_lista;

void crear_lista(t_lista* pl);
int lista_vacia(const t_lista *pl);
int lista_llena(const t_lista *pl, size_t tam);
void vaciar_lista(t_lista* pl);
int poner_al_principio(t_lista* pl, const void *pd, size_t tam);
int sacar_primero_lista(t_lista* pl, void* pd, size_t tam);
int ver_primero_lista(t_lista* pl, void* pd, size_t tam);
int poner_al_final(t_lista *pl, const void* pd, size_t tam);
int ver_ultimo_lista(t_lista* pl, void* pd, size_t tam);

void mostrar_lista(t_lista* pl, void(*accion)(const void* a));
int poner_en_posicion(t_lista *pl, const void *pd, size_t tam, unsigned pos );
int sacar_de_lista(t_lista* pl, void *pd, size_t tam, int(*cmp)(const void* a, const void* b));

void ordenar_lista_insercion(t_lista *pl, int(*cmp)(const void* a, const void* b));
void ordenar_lista_seleccion(t_lista *pl, int(*cmp)(const void* a, const void* b));

void map_lista(const t_lista* pl, void(*accionMap)(void* elem, void* extra), void* param);
#endif // LSE_H_INCLUDED
