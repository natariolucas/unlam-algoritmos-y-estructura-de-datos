#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED
typedef void (*fnMostrarElemento)(void* elem, int indice);
void mostrarVector(void* vec, int ce, size_t tamElem, fnMostrarElemento mostrar);


#endif // VECTORES_H_INCLUDED
