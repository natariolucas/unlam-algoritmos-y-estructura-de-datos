#ifndef TDA_PILA_DINAMICA_H_INCLUDED
#define TDA_PILA_DINAMICA_H_INCLUDED

#include <stddef.h>
#define OK 1
#define SIN_MEMORIA 2
#define PILA_VACIA 3
#define PILA_LLENA 4
#define PILA_NO_LLENA 5


typedef struct Snodo {
    void* elem;
    size_t tamElem;
    struct Snodo* sig;
} Nodo;

typedef Nodo* pila;

void crear_pila(pila *pp);
int poner_en_pila(pila *pp, const void* elem, size_t tamElem);
int sacar_de_pila(pila *pp, void* elem, size_t tamElem);  //tamElem en este caso es el tamaño disponible en la variable que se va a usar para guardar el elemento
void vaciar_pila(pila *pp);
int pila_vacia(const pila *pp);
int pila_llena(const pila *pp, size_t tamElem);
int ver_tope(const pila *pp, void* elem, size_t tamElem);

size_t menor(size_t tam1, size_t tam2);

#endif // TDA_PILA_DINAMICA_H_INCLUDED
